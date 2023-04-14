#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

int main() {
    FILE *fp;
    char *filename = "input.ppm";
    char *output_filename = "output.ppm";
    char buffer[100];
    int w, h, max;
    pixel *image, *output;
    int i, j, k, l;
    int r, g, b;
    int kernel[3][3] = {{-1,-1,-1}, {-1,8,-1}, {-1,-1,-1}};

    // read input PPM image file
    fp = fopen(filename, "rb");
    fgets(buffer, sizeof(buffer), fp);
    fscanf(fp, "%d %d", &w, &h);
    fscanf(fp, "%d", &max);
    fgetc(fp);

    // allocate memory for image data
    image = (pixel*) malloc(w * h * sizeof(pixel));
    output = (pixel*) malloc(w * h * sizeof(pixel));

    // read image data
    for (i = 0; i < w*h; i++) {
        image[i].red = fgetc(fp);
        image[i].green = fgetc(fp);
        image[i].blue = fgetc(fp);
    }

    // close input file
    fclose(fp);

    // apply 3x3 convolution operation
    for (i = 1; i < h-1; i++) {
        for (j = 1; j < w-1; j++) {
            r = g = b = 0;
            for (k = -1; k <= 1; k++) {
                for (l = -1; l <= 1; l++) {
                    r += image[(i+k)*w+j+l].red * kernel[k+1][l+1];
                    g += image[(i+k)*w+j+l].green * kernel[k+1][l+1];
                    b += image[(i+k)*w+j+l].blue * kernel[k+1][l+1];
                }
            }
            output[i*w+j].red = (unsigned char) (r > 255 ? 255 : (r < 0 ? 0 : r));
            output[i*w+j].green = (unsigned char) (g > 255 ? 255 : (g < 0 ? 0 : g));
            output[i*w+j].blue = (unsigned char) (b > 255 ? 255 : (b < 0 ? 0 : b));
        }
    }

    // write output PPM image file
    fp = fopen(output_filename, "wb");
    fprintf(fp, "P6\n%d %d\n%d\n", w, h, max);
    for (i = 0; i < w*h; i++) {
        fputc(output[i].red, fp);
        fputc(output[i].green, fp);
        fputc(output[i].blue, fp);
    }

    // close output file
    fclose(fp);

    // free memory
    free(image);
    free(output);

    return 0;
}
