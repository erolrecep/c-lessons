#include <stdio.h>
#include <stdlib.h>


void update(int *a,int *b) {
    // Complete this function    
    *a = *a + *b;
    *b = abs(*a - *b * 2);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d\n", a, b);

    return 0;
}
