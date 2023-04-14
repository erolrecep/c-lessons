#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    void (*move)(void* self, int dx, int dy);
} Point;

void movePoint(void* self, int dx, int dy) {
    Point* point = self;
    point->x += dx;
    point->y += dy;
}

Point* createPoint(int x, int y) {
    Point* point = malloc(sizeof(Point));
    point->x = x;
    point->y = y;
    point->move = &movePoint;
    return point;
}

int main() {
    Point* point = createPoint(0, 0);
    printf("Initial position: (%d, %d)\n", point->x, point->y);
    point->move(point, 5, 5);
    printf("New position: (%d, %d)\n", point->x, point->y);
    free(point);
    return 0;
}
