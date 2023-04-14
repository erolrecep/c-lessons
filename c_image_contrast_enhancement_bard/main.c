#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// This function enhances the contrast of an image.
//
// image: The image to be enhanced.
// width: The width of the image.
// height: The height of the image.
void contrast_enhancement(unsigned char *image, int width, int height) {
  // Calculate the mean of the image.
  double mean = 0.0;
  for (int i = 0; i < width * height; i++) {
    mean += image[i];
  }
  mean /= width * height;

  // Calculate the standard deviation of the image.
  double std_dev = 0.0;
  for (int i = 0; i < width * height; i++) {
    double val = image[i] - mean;
    std_dev += val * val;
  }
  std_dev = sqrt(std_dev / width * height);

  // Apply the contrast enhancement.
  for (int i = 0; i < width * height; i++) {
    double val = image[i] - mean;
    val = val / std_dev * 255.0;
    image[i] = (unsigned char)val;
  }
}

int main() {
  // Load the image.
  unsigned char *image = stbi_load("image.png", &width, &height, NULL, 0);
  if (image == NULL) {
    printf("Error loading image\n");
    return 1;
  }

  // Enhance the contrast of the image.
  contrast_enhancement(image, width, height);

  // Save the image.
  stbi_write_png("enhanced_image.png", width, height, 1, image, 0);

  // Free the image.
  stbi_image_free(image);

  return 0;
}
