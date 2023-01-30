//				Introduction to Progarmming - Semester #1
//			    *** Find 1,2 or more max elements in anarchy array-without any kind of sorting ***
// Coding by Gkouziotis Nikolaos

#include<stdio.h>

#define N 10

int main() {
	int  A[2][N] = {10, 50, 2, 6, 33, 567, 875, 875, 106, 104}; 
	int M;                                                    
	int i, j;  
	int max = 100000, cur_max = 0, pos = -1;  
	
	printf("\nHow many max numbers do you want to find? (1 - 10) : ");
	scanf("%d", &M);	
	
//	find N max numbers
	for(i = 0; i < M; i++) {
		for(j = i; j < N; j++) {
			if(A[0][j] <= max && A[0][j] > cur_max && A[1][j] != 1) {
				cur_max = A[0][j];
				pos = j;
			}
		}
		A[1][pos] = 1;
		max = cur_max;
		cur_max = 0;
	}

//	Print the N max numbers
	printf("\nThe N max numbers in matrix are : ");
	for(i = 0; i < N; i++) 
		if(A[1][i] == 1)
			printf("%d, ", A[0][i]);

	return 0;
}
