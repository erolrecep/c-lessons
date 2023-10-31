#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10


// Make array with random values
float *make_random_2D_array(){
	/* Allocate memory for defined with MACROs */
	float *myArray = malloc(sizeof(float) * WIDTH * HEIGHT);

	for (size_t w = 0; w < WIDTH; w++)
		for (size_t h = 0; h < HEIGHT; h++)
			myArray[WIDTH*w+h] = rand();
	
	return myArray;
}

// Fill dynamic array with the same values
float *fill_2D_array(float value){
	/* Allocate memory for defined with MACROs */
	float *myArray = malloc(sizeof(float) * WIDTH * HEIGHT);

	for (size_t w = 0; w < WIDTH; w++)
		for (size_t h = 0; h < HEIGHT; h++)
			myArray[WIDTH*w+h] = value;
	
	return myArray;
}

/* Print dynamic array as 2D matrix */
void print_array(float *array){
	for (size_t w = 0; w < WIDTH; w++)
	{
		for (size_t h = 0; h < HEIGHT; h++)
		{
			printf("%.2f ", array[WIDTH * w + h]);
		}
		printf("\n");
	}
}

/* Print dynamic array as 2D matrix */
void print_2D_array(float **array){
	for (size_t w = 0; w < WIDTH; w++)
	{
		for (size_t h = 0; h < HEIGHT; h++)
		{
			printf("%.2f ", array[w][h]);
		}
		printf("\n");
	}
}

float **create_random_2d_array() {
  float **array = malloc(HEIGHT * sizeof(float *));
  if (array == NULL) {
    return NULL;
  }
  for (size_t i = 0; i < HEIGHT; i++) {
    array[i] = malloc(WIDTH * sizeof(float));
    if (array[i] == NULL) {
      return NULL;
    }
    for (size_t j = 0; j < WIDTH; j++) {
      array[i][j] = rand();
    }
  }
  return array;
}


int main(int argc, char const *argv[])
{
	srand(time(NULL));

	float *mainArray = make_random_2D_array();
	print_array(mainArray);

	float *otherArray = fill_2D_array(9.3);
	print_array(otherArray);

	float **TwoDArray = create_random_2d_array();
	print_2D_array(TwoDArray);

	free(mainArray);
	free(otherArray);
	free(TwoDArray);

	return 0;
}