#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <errno.h>


double standard_deviation(double *numbers, int n) {
  // Calculate the mean.
  double mean = 0.0;
  for (int i = 0; i < n; i++) {
    mean += numbers[i];
  }
  mean /= n;

  // Calculate the variance.
  double variance = 0.0;
  for (int i = 0; i < n; i++) {
    variance += (numbers[i] - mean) * (numbers[i] - mean);
  }
  variance /= n - 1;

  // Calculate the standard deviation.
  double standard_deviation = sqrt(variance);
  return standard_deviation;
}


typedef struct {
	int rows;
	int columns;
	float **data;
}dataset;


dataset memory_allocate(int rows, int cols){
	dataset myDataset;
	myDataset.rows = rows;
	myDataset.columns = cols;

	myDataset.data = malloc(sizeof(float*) * myDataset.rows);
	if (myDataset.data == NULL)
	{
		fprintf(stderr, "%s : %s\n", strerror(errno), "memory allocation error for the dataset");
		exit(1);
	}

	for (int i = 0; i < myDataset.rows; i++)
	{
		myDataset.data[i] = malloc(sizeof(float) * myDataset.columns);
	}

	return myDataset;
}


void print_dataset(dataset myDataset){
	for (int row = 0; row < myDataset.rows; ++row)
	{
		for (int col = 0; col < myDataset.columns; ++col)
		{
			printf("[%f] ", myDataset.data[row][col]);
		}
		printf("\n");
	}
}


int main(int argc, char const **argv)
{
	/* Allocate memory for dataset */
	/* Read the txt file and learn about number of rows and columns */

	char buffer[256];
	FILE *f = fopen("house_price_data.txt", "r");
	if (f == NULL)
	{
		fprintf(stderr, "%s: %s\n", strerror(errno), "cannot open input file!");
    	exit(1);
	}

	/* Get number of lines and columns */
	int row_count = 0;
	int columns_count = 0;
	char *temp;
    while (fgets(buffer, sizeof(buffer), f)!= NULL){
    	columns_count = 0;
    	// printf("%s", buffer);
    	++row_count;

    	temp = strtok(buffer, ",");
		printf("%f ", atof(temp));
		++columns_count;
		while((temp = strtok(NULL, ",")) && temp != NULL){
			printf("%f ", atof(temp));
			++columns_count;
		}
		printf("\n");
    }
    printf(" | %d columns | %d rows\n", columns_count, row_count);

    fclose(f);

    f = fopen("house_price_data.txt", "r");
	if (f == NULL)
	{
		fprintf(stderr, "%s: %s\n", strerror(errno), "cannot open input file!");
    	exit(1);
	}

    dataset house_prices = memory_allocate(row_count, columns_count);
    /* Parse each line and assign to the house_price dataset */
    row_count=0;
    while (fgets(buffer, sizeof(buffer), f)!= NULL){
    	house_prices.data[row_count][0] = atof(strtok(buffer, ","));
    	for (int col = 1; col < columns_count; ++col)
    	{
    		house_prices.data[row_count][col] = atof(strtok(NULL, ","));
    	}
    	++row_count;
    }

	/* Read the txt file and load into a dataset struct */
	print_dataset(house_prices);

	/* Normalize the input data */
	/* Step 1: Find the average value of each column */
	/* Step 2: Subtract this average value from each corresponded data point */
	/* Step 3: Calculate standard deviation for each data column point */
	/* Step 4: Divide standard deviation from each corresponded data point */
	/* Step 5: Implement gradient descent and iterate over number of epoch times */
	/* Step 6: Implement cost function and calculate cost function */
	/* Step 7: Visualize each steps to support the algorithm run visually */
	/* Step 8: Inference each data point from the trained model */
	/* Step 9: Plot the results in a new plot and show the how well the model is trained*/





	fclose(f);

	return 0;
}



























































































