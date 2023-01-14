//																    Analysis and Design of Algorithms - Semester #4
//													         					*** Local Maxima***
// Coding by Gkouziotis Nikolaos

#include<stdio.h>
#include<stdlib.h>


   int main () {
   	
	int **A, **B, **C;// B is local Maxima, C is local Minima   						       
	int M, N;
	int i, j, k, m;
	int w, counter;
	int flag = 0;
   
	printf("\nGive me the lines of Matrix, N  : ");
	scanf("%d", &N );
	printf("\nGive me the rows  of Matrix,  M : ");
	scanf("%d", &M);
	printf("\nGive me the Window, W : ");
	scanf("%d", &w);
	
	A = (int **) malloc(N *sizeof(int *));
	for(i = 0; i < N; i++) 
		A[i] = (int *) malloc(M * sizeof(int));
		
	B = (int **) malloc(N *sizeof(int *));
 	  	 for(i = 0; i < N; i++) 
		     B[i] = (int *) malloc(M * sizeof(int));
	C = (int **) malloc(N *sizeof(int *));
 	  	 for(i = 0; i < N; i++) 
		     C[i] = (int *) malloc(M * sizeof(int));
		
	for(i = 0; i < N; i++) {
		for(j = 0; j < M; j++) {
			A[i][j] = rand() % 10;
			B[i][j] = 0;
			C[i][j] = 0;
		}
	}
	
		
//	Print  matrix A
    printf("\nA Matrix :\n==  ==  ==  == ==  ==  ==  ==");
	for(i = 0; i < N; i++) {
		printf("\n");
		for(j = 0; j < M; j++) {
	    	printf("%d  ", A[i][j]);
		}
	}
	printf("\n==  ==  ==  == ==  ==  ==  ==\n");

//	Print the data inside the window
    printf("\n\n\nWindow Matrix :\n==  ==  ==  == ==  ==  ==  ==");
    for(i = w; i < N - w; i++) {
   		printf("\n");
	    for(j = w; j < M - w; j++) {
  			printf("%d  ", A[i][j]);
		  	}
	    }
	printf("\n==  ==  ==  == ==  ==  ==  ==\n"); 
	    

//  find the local maxima
	for(i = w; i < N - w; i++) {								
		for(j = w; j < M - w; j++) {
			flag  = 0;											
			for(k = j - w; k <= j + w; k++) {
				if(A[i][j] <= A[i][k] && j != k) {// left - right
					flag = 1;
				}
			}
			if(flag == 0) {
				for(k = i - w; k <= i + w; k++) {
					if(A[i][j] <= A[k][j] && k != i) { // up - down
						flag = 1;
					}
				}
			}
			if(flag == 0) {
				counter = w;
				for(k = i - w; k <= i + w; k++) {
					m = j-counter;
					if(A[i][j] <= A[k][m] && j != m) {// cross line left to right
						flag = 1;
					}
					counter--;
				}
			}
			if(flag == 0) {
				counter = w;
				for(k = i - w; k <= i + w; k++) {
					m = j+counter;
					if(A[i][j] <= A[k][m] && j != m) {// cross line right to left
						flag = 1;
					}
					counter--;
				}
			}
			if(flag == 0) {
				B[i][j] = A[i][j];
			}
		}
	}

//	Find the local minima 
	for(i = w; i < N - w; i++) {								
		for(j = w; j < M - w; j++) {
			flag  = 0;											
			for(k = j - w; k <= j + w; k++) {
				if(A[i][j] >= A[i][k] && j != k) {
					flag = 1;
				}
			}
			if(flag == 0) {
				for(k = i - w; k <= i + w; k++) {
					if(A[i][j] >= A[k][j] && k != i) {
						flag = 1;
					}
				}
			}
			if(flag == 0) {
				counter = w;
				for(k = i - w; k <= i + w; k++) {
					m = j-counter;
					if(A[i][j] >= A[k][m] && j != m) {
						flag = 1;
					}
					counter--;
				}
			}
			if(flag == 0) {
				counter = w;
				for(k = i - w; k <= i + w; k++) {
					m = j+counter;
					if(A[i][j] >= A[k][m] && j != m) {
						flag = 1;
					}
					counter--;
				}
			}
			if(flag == 0) {
				C[i][j] = A[i][j];
			}
		}
	}		
					
	    			
//  print the local maxima and minima
	printf("\n\nLocal Maxima Matrix :\t\t\t\tLocal Minima :\n==  ==  ==  == ==  ==  ==  ==\t\t\t==  ==  ==  == ==  ==  ==  ==");
	for(i = 0; i < N ; i++) {
   		printf("\n");
	   for(j = 0; j < M ; j++) {
  			printf("%d  ", B[i][j]);
		}
		printf("\t\t\t");
		for(j = 0; j < M ; j++) {
  			printf("%d  ", C[i][j]);
		}	
   	}
	printf("\n==  ==  ==  == ==  ==  ==  ==\t\t\t==  ==  ==  == ==  ==  ==  ==\n"); 

    free(A);
    free(B);
    return 0;
}
   	
