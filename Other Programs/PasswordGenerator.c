#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define num 10
#define ch 70
#define N 18 // length of password

int numbers[num]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
char characters[ch] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', ',',
                           'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                           'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                           'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                           'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
                           

int main(int argc, char **argv) {
	int i;
	char password[N];
	
	srand(time(NULL));
	
	for(i = 0; i < N; i++) {
		if((rand() % (N+ch+num)) % 2 == 0) 
			password[i] = numbers[rand() % num] + '0';
		else 
			password[i] = characters[rand() % ch];
	}
	
	printf("\nGenerated Password : ");
	for(i = 0; i < N; i++) {
		printf("%c", password[i]);
	}
	
	return 0;
}
