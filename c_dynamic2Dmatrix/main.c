#include <stdio.h>
#include <stdlib.h>



typedef struct {
	int rows;
	int columns;
	float **data;
}dataset;


dataset init_dataset(int rows, int columns) {
	dataset myDataset;
	myDataset.rows = rows;
	myDataset.columns = columns;
	myDataset.*data = malloc(myDataset.rows * sizeof(float));
	for(int row=0; row < myDataset.rows; ++row)
		myDataset.data[row] = malloc(myDataset.columns * sizeof(float));
	return myDataset;
}


/* TODO: re-organize matrixlibrary project and 
add single star and double star implementation of matrix library 
so that I can use this implementation again and again on multiple projects*/


int main(int argc, char const *argv[])
{
	
	return 0;
}