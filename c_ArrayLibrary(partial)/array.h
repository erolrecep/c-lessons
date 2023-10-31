#ifndef ARRAY_H_
#define ARRAY_H_

#include <inttypes.h>

// Define an array (This library only supports INT16 data type)

// This function provides placeholder for the new array with the size
// on parameter
int16_t make_array(size_t size);
int16_t make_randon_array(size_t size);
int16_t fill_array(size_t size, int16_t value);
void print_array(int16_t myArray[], size_t size);

#endif