//																    Quantum Computing - Semester #4
//													         		   *** Kronecker Product ***
// Coding by Gkouziotis Nikolaos

#include<stdio.h>

#define N 2

int main(int argc, char **argv) {  	
	float A[N][N] = {{0.2, 0.7}, {0.8, 0.3}};
	float B[N][N] = {{1, 0}, {0, 1}};
  	float C[N * N][N * N];
  	int i, j, k, m, lines = 0, rows = 0;
    float temp;
  		  				
//	Print the first matrix
	printf("\n1st Matrix :");
    for (i = 0; i < N; i++) {
		printf("\n");
		for (j=0; j < N; j++)
			printf("%.2f\t", A[i][j]);
	}
	printf("\n\n");

//	Print the second matrix
	printf("\n2nd Matrix :");			
	for(i = 0; i < N; i++) {
		printf("\n");
		for(j = 0; j < N; j++)
			 printf("%.2f\t", B[i][j]);
	}
	 	 
	for(m = 0; m < N; m++) {
		for(i = 0; i < N; i++) {
		 	for(j = 0; j < N; j++) {
		 		for(k = 0; k < N; k++) {
			 		temp = A[m][j] * B[i][k];
			 		C[lines][rows] = temp;
			 		rows++;
				 }
			 }
			 rows = 0;
			 lines++;
		 }
	 }
	 
//	print the result 		 
	printf("\n\n\n3rd Matrix :");			
	for(i = 0; i < N * N; i++) {
		printf("\n");
		for( j = 0; j < N * N; j++)
			 printf("%.2f\t", C[i][j]);
	}

	return 0;
}
  
