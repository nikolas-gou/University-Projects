#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 2000

int main(int argc, char **argv) {
    int P[N]={11, 17, 5, 8, 6, 4, 7, 12, 3};
    int L[N];
    int i, j;
    int max_chain;
    clock_t t1, t2;
    
    for(i = 0; i < N; i++) {
        L[i] = 1;
        P[i] = rand() % 100;
    }
    t1 = clock();

    for(i = 1; i < N; i++)
        for (j = 0; j < i; j++)
            if (P[i] > P[j] && L[i] <= L[j])
                L[i] = L[j] + 1;
    t2 = clock();  

    for(i = 0; i < N; i++) 
        printf("%3d", P[i]);
    printf("\n");

    max_chain=L[0];
    for(i = 0; i < N; i++) {
        printf("%3d", L[i]);
        if(max_chain < L[i])
            max_chain = L[i];
    }
    printf("\n\n\n--The length of the biggest chain is: %d", max_chain);
    printf("\n\n--Time=%.2f\n", (float)(t2-t1) / CLOCKS_PER_SEC);
    return 0;
}
    
