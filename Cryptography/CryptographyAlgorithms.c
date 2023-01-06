//															  SECURITY OF DIGITAL SYSTEMS - EXAM #6
//													            *** CRYPTOGRAPHY ALGORITHMS ***			
// Coding by Gkouziotis Nikolaos

//  LIBRARIES
#include<stdio.h>
#include<string.h>
#include <ctype.h> 
#include<time.h>

#define letters 26//	English Alphabet a, b, .. ,z
#define Sal 97// 	STATHERA A = 97 STON PINAKA ASCII ALPHAVITO

//  Functions
void main_menu();
void caesar_cipher();
void vigenere_cipher();
void hill_cipher();
void otp_cipher();
void affine_cipher();
void permutation();
int divisor(int, int);
void dec_to_binary(int, int);
int reverse_mod(int);


//  MAIN PROGRAM
int main(int argc, char**argv) {
	int select, stop;// CHOOSE ALGORITHM, STOP THE PROGRAMM

	do {
		main_menu();// PRINT THE MENU OF ALGORITHMS
		printf("\nSelect the algorithm to execute(1-6) : ");
		printf("\n==>  ");
		scanf("%d", &select);
		while(select < 0 || select >= 7) {// IF USER GIVE NOT ACCEPTABLE VALUE
			printf("\n**Error : the input can take values from 0 to 6... Try again!");
			printf("\nSelect the algorithm to execute(1-6) : ");
			printf("\n==>  ");
			scanf("%d", &select);
		}
		switch(select) {// CALL THE ALGORITHM
			case 1 : caesar_cipher();
				break;
			case 2 : vigenere_cipher();
				break;
			case 3 : hill_cipher();
				break;
			case 4 : otp_cipher();
				break;
			case 5 : affine_cipher();
				break;
			case 6 :  permutation();
				break;
			case 0 : return 1; // STOP THE PROGRAMM
		}
		printf("--Continue or End programm (1=continue, 0=end) :");
		printf("\n==>  ");
		scanf("%d", &stop);
	} while(stop != 0);// IF STOP == 0, STOP THE PROGRAMM
	
	return 0;
}

//  SUNARTHSEIS
void main_menu(void) {// MENU OF ALGORITHMS
    printf("\n------------------------------\n\tALGORITHM MENU\n------------------------------\n");
	printf("1. Caesar Cipher.\n");
	printf("2. Vigenere Cipher.\n");
	printf("3. Hill Cipher.\n");
	printf("4. OTP Cipher.\n");
	printf("5. Affine Cipher.\n");
	printf("6. Permutation Cipher.\n");
	printf("0. GIA TERMATISMO TU PROGRAMMATOS.\n");
}

void caesar_cipher() {// CASESAR ALGORITHM
	int i, key, N = 20;//	Pointers, key, max length of message
	char msg[N], InMsg[N], EnMsg[N];// given msg, initial message, encrypted/dercrypted message
	
	printf("\n===========================");
	printf("\n\tCAESAR CIPHER");
	printf("\n===========================");
	
	// INPUT DATA 
	printf("\n\nGive me the message(char : 0 - 20) : ");
	scanf("%s", msg);
	
	// FIND THE LENGTH OF MESSAGE
	int len = strlen(msg);
	
	// CHECK IF THE INPUT DATA IS ACCEPTABLE
	if(len > N)
		do {//	 IF USER GIVES BIGGER MESSAGE THAN N
			printf("\n**Error : the message must contain only 20 characters and not empty... Try again!");
			printf("\n\nGive me the message(char : 0 - 20) : ");
			scanf("%s", msg);
			len = strlen(msg); // Length of string
		} while(len > N);
	
	// INPUT DATA
	printf("\nGive me the key(int : 1 - 26) : ");
	scanf("%d", &key);
	
	// CHECK IF THE INPUT DATA IS ACCEPTABLE
	if(key > letters)
		do {	// IF USER GIVES BIGGER KEY THAN 26
			printf("\n**Error : the key can take values from 1 to 26... Try again!");
			printf("\nGive me the key(int : 1 - 26) : ");
			scanf("%d", &key);
		} while(key > letters);
	
	// ENCRYPT DATA
	for(i = 0; i < len; i++)  {
		InMsg[i] = msg[i];// SAVE THE INITIAL MESSAGE
		msg[i] = tolower(msg[i]);// CONVERT ALL CHARS TO LOWWER FOR 26 ALPHABET 
		EnMsg[i] = (((msg[i] - Sal) + key) % letters) + Sal;// (am+k)modn
	}
	
	// PRINT THE MSG, KEY AND ENCRYPT DATA 
	printf("\nEncryption");
	printf("\n--Initial message : ");
	for(i = 0; i < len; i++)
		printf("%c", InMsg[i]);
	printf("\n--Key : %d", key);
	printf("\n--Encrypted message : ");
	for(i = 0; i < len; i++)
		printf("%c", EnMsg[i]);
	
	// DECRYPTION DATA 
	for(i = 0; i < len; i++) {
		if((EnMsg[i]-Sal)-key >= 0)//IF c-k > 0
			EnMsg[i] = (((EnMsg[i] - Sal) - key) % letters) + Sal;// m = (c-k) mod n
		else// IF c-k < 0
			EnMsg[i] = letters + (((EnMsg[i] - Sal) - key)%letters) + Sal;
	}
	
	// PRINT THE DECRYPT DATA
	printf("\n\nDecryption");
	printf("\n--Decrypted message : ");
	for(i = 0; i < len; i++)
		printf("%c", EnMsg[i]);
	printf("\n===========================\n\n");
}

void vigenere_cipher() {// VIGINERE ALGORITHM
	int i, N = 20;//	Pointers,  max length of message
	char msg[N], InMsg[N], EnMsg[N];//	Pointers, key, max length of message
	char key[N], InKey[N];// KEY INITIAL KEY
	
	printf("\n===========================");
	printf("\n\tVigenere Cipher");
	printf("\n===========================");
	
	// INPUT DATA 
	printf("\n\nGive me the plaintext(char : 1 - 20)  : ");
	scanf("%s", msg);
	
	// FIND THE LENGTH OF MESSAGE
	int len = strlen(msg);
	
	// CHECK IF THE INPUT DATA IS ACCEPTABLE
	if(len > N)
		do {//	 IF USER GIVES BIGGER MESSAGE THAN N
			printf("\n**Error : the message must contain only 20 characters and not empty... Try again!");
			printf("\n\nGive me the message(char : 0 - 20) : ");
			scanf("%s", msg);
			len = strlen(msg); // Length of string
		} while(len > N);
	
	// INPUT DATA
	printf("\nGive me the key(char : 1 - length of plaintext)  : ");
	scanf("%s", key);
	
	//FIND THE LENGTH OF KEY
	int len2 = strlen(key);
	
	// CHECK IF THE INPUT DATA IS ACCEPTABLE
	if(len2 > len)
		do {//	 IF USER GIVES BIGGER KEY THAN LENGTH OF MESSAGE
			printf("\n**Error : the key must contain only length of message characters and not empty... Try again!");
			printf("\n\nGive me the key(char : 0 - length of message) : ");
			scanf("%s", key);
			len2 = strlen(key); // Length of string
		} while(len < len2);

	
	// ENCRYPT DATA
	for(i = 0; i < len; i++) {
		InMsg[i] = msg[i];// SAVE THE INITIAL MESSAGE
		msg[i] = tolower(msg[i]);// CONVERT ALL CHARS TO LOWWER FOR 26 ALPHABET
		InKey[i] = key[i];// SAVE THE INITIAL KEY
		key[i] = tolower(key[i]);// CONVERT ALL CHARS TO LOWWER FOR 26 ALPHABET
		EnMsg[i] = (((msg[i] - Sal) + (key[i % len2] - Sal)) % letters) + Sal;// c = message[i] + key[i] mod n, IF THE KEY IS SMALLER THAN MESSAGE, THEN RESTART FROM ZERO 
	}
	
	// PRINT THE MSG, KEY AND ENCRYPT DATA
	printf("\nEncryption");
	printf("\n--Initial message : ");
	for(i = 0; i < len; i++)
		printf("%c", InMsg[i]);
	printf("\n--Key : %s", InKey);
	printf("\n--Encrypted message : ");
	for(i = 0; i < len; i++)
		printf("%c", EnMsg[i]);
		
	// DECRYPT DATA
	for(i = 0; i < len; i++) {
		if(EnMsg[i] - Sal < key[i % len2] - Sal)//IF c-k > 0
			EnMsg[i] = (letters + ((EnMsg[i] - Sal) - (key[i % len2] - Sal))) + Sal;//m = (cipher[i] - key[i]) mod n
		else////IF c-k <= 0	
			EnMsg[i] = (((EnMsg[i] - Sal) - (key[i % len2] - Sal)) % letters) + Sal;
	}
	
	// PRINT THE DECRYPTED DATA
	printf("\n\nDecryption");
	printf("\n--Decrypted message : ");
	for(i = 0; i < len; i++)
		printf("%c", EnMsg[i]);
	printf("\n===========================\n\n");
}

void hill_cipher() {// HILL ALGORITHM
		
	int i, j, k, len;//	POINTERS FOR ARRAY, LENGTH MESSAGE
	int N = 3;// DIMMENSIONS ARRAY NXN
	float x, p, q;
	int EnMsg[N];//	ENCRYPTED MESSAGE
	char msg[N];// INITIAL MESSAGE
	float CipherKey[3][3] = { {6, 24, 1},//	KEY 
					 	    {13, 16, 10},
						    {20, 17, 15}
			               };
	float c[3][3], b[3][3], encrypt[3][1], mes[3][1], decrypt[3][1];

 	
 	printf("\n===========================");
	printf("\n\tHILL CIPHER");
	printf("\n===========================");
	
	printf("\n\nGive me the plaintext(3 letter string)  : ");
	scanf("%s", msg);
	
	len = strlen(msg);
	
	// CHECK IF THE INPUT IS ACCEPTABLE
	if(len > N)
		do {
			printf("\n**Error : the message must contain only 3 characters... Try again!");
			printf("\nGive me the plaintext(3 letter string)  : ");
			scanf("%s", msg);
		} while(len > N);

	//	TEMPORARY USE OF ARRAY	
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++) 
			c[i][j] = CipherKey[i][j];

	//	ENCRYPTION
	for(i = 0; i < 3; i++) {
		x = 0;
		for(k = 0; k < 3; k++) {
			x += CipherKey[i][k] * (msg[k]-97);// c = m[i] * k[i][k]
		}
		EnMsg[i] = (int)x;// THE RESULT OF MULTIPLICATION ARRAY IS THE ENCRYPTED CHAR
		EnMsg[i] = (EnMsg[i]%letters)+97;
		encrypt[i][0] = x;
	}
	
	// PRINT DATA
	printf("\nEncryption");
	printf("\n--Initial message : ");
	for(i = 0; i < len; i++)
		printf("%c", msg[i]);
	printf("\n--Key 3X3 matrix : ");
	for(i = 0; i < N; i++) {
		if(i == 0)
			printf("{");
		for(j = 0; j < N; j++) {
			if(j == 0)
				printf("{%d,  ", (int)CipherKey[i][j]);
			else if(j == N-1 && i != N-1)
				printf("%d }, ", (int)CipherKey[i][j]);
			else if(j == N-1 && i == N-1)
				printf("%d }", (int)CipherKey[i][j]);
			else
				printf("%d,  ", (int)CipherKey[i][j]);
		}
		if(i == N-1)
		 printf("}");	
	}
	printf("\n--Encrypted message : ");
	for(i = 0; i < len; i++)
		printf("%c", EnMsg[i]);
		
	//	DECRYPTION
	for(i = 0; i < 3; i++)// CREATE THE ARRAY I, IDENTITY MATRIX
		for(j = 0; j < 3; j++) {
			if(i == j)
				b[i][j]=1;
			else
				b[i][j]=0;
		}
	//	INVERSE MATRIX
	for(k = 0; k < 3; k++) {
		for(i = 0; i < 3; i++) {
			p = c[i][k];
			q = c[k][k];
			for(j = 0; j < 3; j++) {
				if(i != k) {
				c[i][j] = c[i][j]*q - p*c[k][j];
				b[i][j] = b[i][j]*q - p*b[k][j];
				}
			}	
		}
	}
	
	 
	printf("\n\nDecryption");
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			b[i][j] = b[i][j] / c[i][i];
			
	// PRINT DATA 
	printf("\n--Inverse Matrix is: ");
	for(i = 0; i < N; i++) {
		if(i == 0)
			printf("{");
		for(j = 0; j < N; j++) {
			if(j == 0)
				printf("{%.2f,  ", b[i][j]);
			else if(j == N-1 && i != N-1)
				printf("%.2f }, ", b[i][j]);
			else if(j == N-1 && i == N-1)
				printf("%.2f }", b[i][j]);
			else
				printf("%.2f,  ", b[i][j]);
		}
		if(i == N-1)
		 printf("}");	
	}


	for(i = 0; i < 3; i++) {
		for(j = 0; j < 1; j++) {
			decrypt[i][j] = 0;
			for(k = 0; k < 3; k++) {
				decrypt[i][j] += b[i][k] * encrypt[k][j];
					
			}
			EnMsg[i] = (int)decrypt[i][j];
			EnMsg[i] = (EnMsg[i]%letters)+97;
	}	
	}
	printf("\n--Decrypted message : ");
	for(i = 0; i < len; i++)
		printf("%c", EnMsg[i]);
	printf("\n===========================\n\n");
}

void otp_cipher() {
	int i, j, N = 20, epil; // Pointers,  max length of message
	char msg[N], InMsg[N], EnMsg[N];// INITIAL MESSAGE, GIVEN MESSAGE, ENCRYPTED/DECRYPTED MESSAGE 
	char key[N], InKey[N];// GIVEN KEY, INITIAL KEY
	
	printf("\n===========================");
	printf("\n\tOTP Cipher");
	printf("\n===========================");
	
	printf("\n\n1. Vernam\n2. Xor ");
	printf("\n==>  ");
	scanf("%d", &epil);
	if(epil != 1 && epil != 2) 
		do {
			printf("\n**Error : the acceptable value is 1 or 2... Try again!");
			scanf("%d", &epil);
		} while(epil != 1 && epil != 2);
	
	//INPUT THE DATA 
	printf("\n\nGive me the plaintext(char)  : ");
	scanf("%s", msg);
	
	// FIND THE LENGTH OF MESSAGE
	int len = strlen(msg);
	
	// CHECK IF THE INPUT IS ACCEPTABLE
	if(len > N)
		do {
			printf("\n**Error : the message must contain only 3 characters... Try again!");
			printf("\nGive me the plaintext(3 letter string)  : ");
			scanf("%s", msg);
		} while(len > N);
	
	printf("\nGive me the key(char) : ");
	scanf("%s", key);
	
	//FIND THE LENGTH OF KEY
	int len2 = strlen(key);
	
	// CHECK IF THE INPUT DATA IS ACCEPTABLE
	if(len2 > len)
		do {//	 IF USER GIVES BIGGER KEY THAN LENGTH OF MESSAGE
			printf("\n**Error : the key must contain only length of message characters and not empty... Try again!");
			printf("\n\nGive me the key(char : 0 - length of message) : ");
			scanf("%s", key);
			len2 = strlen(key); // Length of string
		} while(len < len2);
	
	// ENCRYPT THE DATA
	for(i = 0; i < len; i++) {
		InMsg[i] = msg[i];
		msg[i] = tolower(msg[i]);
		InKey[i] = key[i];
		key[i] = tolower(key[i]);
		if(epil == 2)// xor
			EnMsg[i] = msg[i] ^ key[i]; 
		else// vernam
			EnMsg[i] = (((msg[i] - Sal) + (key[i] - Sal)) % letters) + Sal;
	}
	
	int x;// USE FOR CONVERT DEC TO BINARY
	
	// PRINT THE DATA  
	printf("\nEncryption");
	printf("\n--Initial message : ");
	for(i = 0; i < len; i++)
		printf("%c", InMsg[i]);
	printf(" = ");
	for(i = 0; i < len; i++) {
		x = (int)InMsg[i];
		dec_to_binary(x, len);
	}
	printf("\n--Key : ");
	for(i = 0; i < len2; i++)
		printf("%c", InKey[i]);
	printf("\t\t  = ");
	for(i = 0; i < len; i++) {
		x = (int)InKey[i];
		dec_to_binary(x, len);
	}
	printf("\n--Encrypted message : ");
	for(i = 0; i < len; i++)
		printf("%c", EnMsg[i]);
	printf("\n--Encrypted message binary : ");
	
	// CONVERT DEC TO BINARY
	for(i = 0; i < len; i++) {
		x = (int)EnMsg[i];
		dec_to_binary(x, len);//	PRINT THE BINARY 
	}
	
	// DECRYPT THE DATA 
	for(i = 0; i < len; i++) {
		if(epil == 2)
			EnMsg[i] = EnMsg[i] ^ key[i];
		else {
			if(EnMsg[i] >= key[i])
				EnMsg[i] = (((EnMsg[i] - Sal) - (key[i] - Sal)) % letters) + Sal;
			else
				EnMsg[i] = (((EnMsg[i] - Sal) - (key[i] - Sal)) + letters) + Sal;
		}
		
	}
	
	//PRINT THE DATA 
	printf("\n\nDecryption");
	printf("\n--Decrypted message : ");
	for(i = 0; i < len; i++)
		printf("%c", EnMsg[i]);
	printf("\n===========================\n\n");
	
}

void affine_cipher() {
	int i, j, key[2], N = 20;
	char msg[N], InMsg[N], EnMsg[N];
	
	printf("\n===========================");
	printf("\n\tAFFINE CIPHER");
	printf("\n===========================");
	
	// INPUT THE DATA 
	printf("\n\nGive me the message           : ");
	scanf("%s", msg);
	
	// FIND THE LENGTH OF MESSAGE
	int len = strlen(msg);
	
	// CHECK IF THE INPUT IS ACCEPTABLE
	if(len > N)
		do {
			printf("\n**Error : the message must contain only 3 characters... Try again!");
			printf("\nGive me the plaintext(3 letter string)  : ");
			scanf("%s", msg);
		} while(len > N);
		
	// INPUT THE DATA
	printf("\nGive me the key : \n");
	for(i = 0; i < 2; i++) {
		printf("%c : ", 97+i);
		scanf("%d", &key[i]);
	}
	
	// ENCRYPT THE DATA 
	for(i = 0; i < len; i++)  {
		InMsg[i] = msg[i];
		msg[i] = tolower(msg[i]);
		EnMsg[i] = ((((msg[i] - Sal)*key[0]) + key[1]) % letters) + Sal;// (a*m+k)mod n
	}
	
	// PRINT THE DATA
	printf("\nEncryption");
	printf("\n--Initial mesaage : ");
	for(i = 0; i < len; i++)
		printf("%c", InMsg[i]);
	printf("\n--Key : K(%d, %d)", key[0], key[1]);
	printf("\n--Encrypted message : ");
	for(i = 0; i < len; i++)
		printf("%c", EnMsg[i]);
	
	// CHECK IF A IS FIRST WITH N
	if(divisor(key[0], letters) != 1) {
		printf("\n\nThe a is not first with n (a,n) != 1...");
		return;
	}
	
	//FIND THE A^-1 = 1 MOD N
	key[0] = reverse_mod(key[0]);
	
	// DECRYPT THE DATA
	for(i = 0; i < len; i++) {
		if(key[0] * ((EnMsg[i]-Sal)-key[1]) >= 0)
			EnMsg[i] = (key[0]*((EnMsg[i] - Sal) - key[1]) % letters) + Sal;
		else
			EnMsg[i] = letters + (key[0]*((EnMsg[i] - Sal) - key[1])%letters) + Sal;
	}
	
	// PRINT THE DATA 
	printf("\n\nDecryption");
	printf("\n--Decrypted message : ");
	for(i = 0; i < len; i++)
		printf("%c", EnMsg[i]);
	printf("\n===========================\n\n");
}

void permutation() {
	int i, j, key[5], N = 20, x, blocks = 5, count = 0;// POINTERS, KEY, LENGTH OF MESSAGE, BLOCKS, COUNTER FOR BLOCKS
	char msg[N], InMsg[N], EnMsg[N], temp, CpEnMsg[N];// INITIAL MESSAGE, GIVEN MESSAGE, ENCRYP/DECRYPT MESSAGE, TEMPORARY VARIABLES/ARRAYS

	printf("\n===========================");
	printf("\n\tPERMUTATION CIPHER");
	printf("\n===========================");
	
	
	// INPUT DATA
	printf("\n\nGive me the message : ");
	scanf("%s", msg);
	
	// KEY 
	key[0] = 3;// 1 -> 4
	key[1] = 1;// 2 -> 2
	key[2] = 4;// 3 -> 5
	key[3] = 2;// 4 => 3
	key[4] = 0;// 5 => 1
	
	//FIND LENGTH OF MESSAGE 
	int len = strlen(msg);
	
	// CHECK IF THE INPUT DATA IS ACCEPTABLE
	if(len > N)
		do {//	 IF USER GIVES BIGGER MESSAGE THAN N
			printf("\n**Error : the message must contain only 20 characters and not empty... Try again!");
			printf("\n\nGive me the message(char : 0 - 20) : ");
			scanf("%s", msg);
			len = strlen(msg); // Length of string
	} while(len > N);
	
	//CONVERT THE CHARS TO LOWER
	for(i = 0; i < len; i++)  {
		InMsg[i] = msg[i];
		msg[i] = tolower(msg[i]);
	}
	
	// ENCRYPT DATA
	for(i = 0; i < (len/blocks)+1; i++) {// FIND THE NUMBER OF BLOCKS THERE ARE IN THE WORD
		for(j = 0; j < blocks; j++) {// GO TO J-BLOCK AND DO PERMUTATION
			x = key[j % blocks];
			if(count+x <= len)
				EnMsg[count+j] = msg[count+x];// GO TO NEXT BLOCK, J+1
		}
		count += blocks;// next block 
	}
	
	// PRINT DATA
	printf("\nEncryption");
	printf("\n--Initial mesaage : ");
	for(i = 0; i < len; i++)
		printf("%c", InMsg[i]);
	printf("\n--Key : ");
	for(i = 0; i < blocks; i++)
		printf("[%d => %d], ", i, key[i]);
	printf("\n--Encrypted message : ");
	for(i = 0; i < len; i++)
		printf("%c", EnMsg[i]);
	for(i = 0; i < len; i++)
		CpEnMsg[i] = EnMsg[i];
		
	// DECRYPT DATA
	count = 0;// first block
	for(i = 0; i < (len / blocks)+1; i++) {// FIND THE NUMBER OF BLOCKS THERE ARE IN THE WORD
		for(j = 0; j < blocks; j++) {// GO TO J-BLOCK AND DO PERMUTATION
			x = key[j % blocks];// The x takes the value of first position
			EnMsg[x+count] = CpEnMsg[j+count];// change the position of values 
		}
		count += 5;// next block
	}
	
	//PRINT DATA 
	printf("\n\nDecryption");
	printf("\n--Decrypted message : ");
	for(i = 0; i < len; i++)
		printf("%c", EnMsg[i]);
	printf("\n===========================\n\n");
}

int divisor(int a, int b){// FIND THE GREATEST COMMON DIVISOR
    if (a * b == 0)
        return a+b;
    return divisor(b % a, a % b);
}

void dec_to_binary(int x, int n) {// CONVERT DECIMAL TO BINARY
	int i, a[n];
	for(i = 0; i < n; i++) {
		a[i] = x % 2;
		x = x / 2;
	}
	for(i = 0; i < n; i++)
		printf("%d", a[i]);
	printf(" | ");
}

int reverse_mod(int a) {
	int i;
	for(i = 0; i < letters; i++) {
		if((a * i) % letters == 1 ) {// if a *x == 1 mod 26 ==> 1
			a = i;
			break;// stop
		}
	}
	return a;// return the a 
}
