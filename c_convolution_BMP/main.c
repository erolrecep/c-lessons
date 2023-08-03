#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Function to apply convolution operation to a BMP image
void applyConvolution(uint8_t* image, int width, int height, int kernelSize, int* kernel) {
    uint8_t* tempImage = malloc(width * height * sizeof(uint8_t));

    int kernelOffset = kernelSize / 2;
    int sum, i, j, k, l, m, n;

    for (i = kernelOffset; i < height - kernelOffset; i++) {
        for (j = kernelOffset; j < width - kernelOffset; j++) {
            sum = 0;

            for (k = -kernelOffset; k <= kernelOffset; k++) {
                for (l = -kernelOffset; l <= kernelOffset; l++) {
                    m = i + k;
                    n = j + l;

                    sum += image[m * width + n] * kernel[(k + kernelOffset) * kernelSize + (l + kernelOffset)];
                }
            }

            tempImage[i * width + j] = sum;
        }
    }

    // Copy the result back to the original image
    for (i = 0; i < width * height; i++) {
        image[i] = tempImage[i];
    }

    free(tempImage);
}

int main() {
    FILE* file = fopen("input.bmp", "rb");

    if (file == NULL) {
        printf("Failed to open the input BMP file.\n");
        return 1;
    }

    // Read the BMP header
    uint8_t header[54];
    fread(header, sizeof(uint8_t), 54, file);

    // Read the image dimensions
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bitsPerPixel = *(int*)&header[28];

    // Calculate the image size in bytes
    int imageSize = width * height * (bitsPerPixel / 8);

    // Allocate memory for the image
    uint8_t* image = malloc(imageSize * sizeof(uint8_t));

    // Read the image data
    fread(image, sizeof(uint8_t), imageSize, file);

    fclose(file);

    // Define the convolution kernel
    int kernelSize = 3;
    int kernel[9] = {
        0, -1, 0,
        -1, 5, -1,
        0, -1, 0
    };

    // Apply the convolution operation
    applyConvolution(image, width, height, kernelSize, kernel);

    // Save the result as a new BMP image
    FILE* outputFile = fopen("output.bmp", "wb");

    if (outputFile == NULL) {
        printf("Failed to create the output BMP file.\n");
        free(image);
        return 1;
    }

    // Write the BMP header
    fwrite(header, sizeof(uint8_t), 54, outputFile);

    // Write the image data
    fwrite(image, sizeof(uint8_t), imageSize, outputFile);

    fclose(outputFile);
    free(image);

    printf("Convolution operation completed successfully.\n");

    return 0;
}
