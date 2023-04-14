#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <omp.h>

#define NUM_THREADS 4

typedef struct {
    uint8_t r, g, b;
} pixel_t;

typedef struct {
    int width, height;
    pixel_t *data;
} image_t;

image_t *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    char magic[3];
    int width, height, maxval;
    fscanf(fp, "%2s %d %d %d\n", magic, &width, &height, &maxval);
    if (magic[0] != 'P' || magic[1] != '6' || maxval != 255) {
        fprintf(stderr, "Error: invalid image format\n");
        exit(1);
    }

    image_t *image = malloc(sizeof(image_t));
    image->width = width;
    image->height = height;
    image->data = malloc(sizeof(pixel_t) * width * height);

    fread(image->data, sizeof(pixel_t), width * height, fp);
    fclose(fp);

    return image;
}

void save_image(const char *filename, image_t *image) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fprintf(fp, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, sizeof(pixel_t), image->width * image->height, fp);
    fclose(fp);
}

image_t *grayscale(image_t *image) {
    image_t *result = malloc(sizeof(image_t));
    result->width = image->width;
    result->height = image->height;
    result->data = malloc(sizeof(pixel_t) * image->width * image->height);

    #pragma omp parallel for num_threads(NUM_THREADS)
    for (int i = 0; i < image->width * image->height; i++) {
        pixel_t *pixel = &image->data[i];
        uint8_t gray = 0.2126 * pixel->r + 0.7152 * pixel->g + 0.0722 * pixel->b;
        result->data[i] = (pixel_t) { gray, gray, gray };
    }

    return result;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s input output\n", argv[0]);
        exit(1);
    }

    image_t *image = load_image(argv[1]);
    image_t *result = grayscale(image);
    save_image(argv[2], result);

    free(image->data);
    free(image);
    free(result->data);
    free(result);

    return 0;
}
