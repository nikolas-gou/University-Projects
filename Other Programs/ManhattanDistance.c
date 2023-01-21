#include <stdio.h>

#define P 4

int main(int argc, char *argv[]) {
    float distance;
    float point[P], i;
    int stop = 1;

    while (stop != 0) {
        printf("\nGive me the first point: ");
        printf("\n--x = "); scanf("%f", &point[0]);
        printf("\n--y = "); scanf("%f", &point[1]);

        printf("\n\nGive me the second point: ");
        printf("\n--x = "); scanf("%f", &point[2]);
        printf("\n--y = "); scanf("%f", &point[3]);

        distance = abs(point[0] - point[2]) + abs(point[1] - point[3]);

        printf("\n\nThe Manhattan distance is: %f", distance);

        printf("\n\nContinue?(1=Yes, 0=Stop)\n=============\n=> ");
        scanf("%d", &stop);
    }

    return 0;
}

