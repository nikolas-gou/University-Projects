//																    Introduction to Programming - Semester #1
//													         		   	     *** Matrix Product ***
// Coding by Gkouziotis Nikolaos

#include<stdio.h>

#define M 2
#define N 3
#define L 4

int main(int argc, char **argv) {
	int A [M][N] = {{2, 1, 2}, {1, 3, 1}};
  	int B [N][L] = {{1, 1, 2, 0}, {0, 2, 1, 1}, {2, 2, 3, 0}};
  	int C [M][L];  	
  	int i, j, k;
  	int sum = 0, cur_sum = 0;

  	
//	Print the first matrix
  	printf("\nA Matrix :");
	for (i = 0; i < M; i++) {
		printf("\n");
		for (j=0; j<N; j++)
			printf("%d  ", A[i][j]);
	}
	printf("\n\n");

//	Print the second matrix
	printf("\n\nB Matrix :");
	for (i = 0; i < N; i++) {
		printf("\n");
		for (j=0; j < L; j++)
			printf("%d  ", B[i][j]);
	}
	printf("\n\n");

	for(k = 0; k < M; k++) {
		for(i = 0; i < L; i++){ 
			for(j = 0; j < N; j++){
				  sum = A[k][j] * B[j][i];
				  cur_sum += sum;
	  		    }
	  		    C[k][i] = cur_sum;
	  		    cur_sum = 0;
			}	
		}
	
//	Print the result
	printf("\nC Matrix :");
	for(i = 0; i < M; i++) {
		printf("\n");
		for(j = 0; j < L; j++) 
			  printf("%d  ", C[i][j]);
	}

	return 0;
}
