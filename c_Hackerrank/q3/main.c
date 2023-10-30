#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int add(int num1, int num2){
    return num1 + num2;
}

int sub(int num1, int num2){
    // return abs(num1 - num2);
    return (num1 - num2);
}

float fadd(float num1, float num2){
    return num1 + num2;
}

float fsub(float num1, float num2){
    // return fabs(num1 - num2);
    return num1 - num2;
}

int main()
{
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    float fnum1, fnum2;
    scanf("%f %f", &fnum1, &fnum2);
    
    printf("%d %d\n", add(num1, num2), sub(num1, num2));
    printf("%.1f %.1f\n", fadd(fnum1, fnum2), fsub(fnum1, fnum2));
    
    return 0;
}
