#include<stdio.h>
#include<math.h>
#define P 4

int main(int argc, char *argv[]) {
	float distance;
	int point[P], i;
	int stop = 1;
	
	while(stop != 0) {
		printf("\nGive me the first point: ");
		printf("\n--x = ");	scanf("%d", &point[0]);
		printf("\n--y = ");	scanf("%d", &point[1]);
		
		printf("\n\nGive me the second point: ");
		printf("\n--x = ");	scanf("%d", &point[2]);
		printf("\n--y = ");	scanf("%d", &point[3]);
		
		distance = sqrt(((point[0]-point[2])*(point[0]-point[2])) + ((point[1]-point[3])*(point[1]-point[3])));
		
		printf("\n\n The Eukleidian distance is: %f", distance);	
		
		printf("\n\nContinue?(1=Yes, 0=Stop)\n=============\n=> "); scanf("%d", &stop);
	}
	
	return 0;
}
