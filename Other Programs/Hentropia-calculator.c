#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
	double fraction_a, fraction_b;
	double a, b;
	double loga, logb, H;
	int stop = 1;
	
	while(stop != 0) {
		// first fraction
		printf("\nFirst fraction(a, b) : ");
		printf("\n--- a = "); scanf("%lf", &a);
		printf("\n--- b = "); scanf("%lf", &b);
		fraction_a = a / b;
		loga = log(1 / fraction_a) / log(2);// log base 2
		
		
		// Second fraction
		printf("\n\nSecond fraction(a, b) : ");
		printf("\n--- a = "); scanf("%lf", &a);
		printf("\n--- b = "); scanf("%lf", &b);
		fraction_b = a / b;	
		logb = log(1 / fraction_b) / log(2);
		printf("\n=========\n--Result fractions : %lf %lf", fraction_a, fraction_b);
		
		H = (fraction_a * loga) + (fraction_b * logb);
		
		printf("\n--Entropia is      : %lf", H);
		printf("\n\nPress 0 to stop : "); scanf("%d", &stop); 
	}
	
	return 0;
}
