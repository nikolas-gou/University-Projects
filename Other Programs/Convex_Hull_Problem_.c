#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 20

struct point {
	int x;
	int y;
};
typedef struct point point;

struct stack_point {
	int *St;         
	int top;
};
typedef struct stack_point St_point;

int euresi_gonias(point p, point q, point r);
void epilogi_point(point P[], int n_points);

int main() {
    int size, i;
    point *P;
	srand(time(NULL));
	
	printf("Give me the size of array : ");
	scanf("%d", &size);
	P = (point*)malloc(size * sizeof(point));
	printf("\n\nRandom points : ");
	for(i = 0; i < size; i++) {
		P[i].x = rand() % 10;
		P[i].y = rand() % 10;
		if(i % 7 == 0)
			printf("\n\t");
		printf("[ %d, %d ], ", P[i].x, P[i].y);
	}
	epilogi_point(P, size);
   
    return 0;
}

int euresi_gonias(point p, point q, point r) {
	int sum;

	sum = (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
  
	if(sum == 0) 
        return 0;
    else if(sum > 0)
	    return 1;
	else if(sum < 0)
        return 2;
}

void epilogi_point(point P[], int n_points) {
	point *Stack_points;
	int i, j = 0;
	int leftmost = 0, head_point;
	int start = 3;
	int q = 0;
	
	Stack_points = (int *)malloc(start * sizeof(point));
	
	if(n_points < 3 ) {
	    printf("\nThese points are not able to built a convex hull...");
        return -1; 
	}
														                            
	for(i = 0; i < n_points; i++) 
		if(P[i].x < P[leftmost].x) 
		    leftmost = i;           								
		
    head_point = leftmost;
 
    do {
    	if(j == start){ 
    	   start++;
		   Stack_points = realloc(Stack_points, start * sizeof(point));
	    }
		Stack_points[j] = P[head_point];
		
        do { 
        	q = rand() % n_points;
        } while(q == head_point);
         
        for (i = 0; i < n_points; i++) 
           if (euresi_gonias(P[head_point], P[q], P[i]) == 1)   
               q = i;
        head_point = q;
        j++;
    } while (head_point != leftmost);
	
	printf("\n\nThese points form the convex hull");
    for (i = 0; i < start; i++)
        printf("\n[ %d, %d ]", Stack_points[i].x, Stack_points[i].y);
}
	

