//								University of Thessaly 
//								   Digital Systems


//	LIBRARIES
#include<stdio.h>
#include<string.h>

#define BITE 8

// FUNCTIONS
FILE *fopen_read(char *);
FILE *fopen_write(char *); 
int ascii_to_binary(int);
void binary_to_ascii(char *, FILE *);
int encryption(int, char *, FILE *);
int decryption(int, char*, FILE *);

// MAIN PROGRAMM
int main() {
	FILE *fp, *fo; 
	int i = 0, j = 0, length, binary, counter = 0, cont, byte = 7;
	char c, nameFile[100], nameFile2[100], cc[100], cbin[BITE + 1];  
	
	// OPEN THE INITIAL FILE
	printf("\nGive me the path of file to open : ");
	gets(nameFile);

    fp = fopen_read(nameFile);
	
	// READ THE INITIAL DATA
	printf("\n--Data of file : ");
    i = 0;
	while(!feof(fp)) {
		c = fgetc(fp);
		if(!feof(fp)) {
	    	printf("%c", c);
	    	cc[i] = c;
	      	i++;
	  	}
	}
	length = strlen(cc);
	printf("\n--The size of file : %dbyte\n", length-1);
	fclose(fp);
	
	// OPEN/CREATE THE FILE TO WRITE
	printf("\nGive me the path of file to write : ");
	gets(nameFile2);
	
    fo = fopen_write(nameFile2);
	
	//	CONVERT DEC TO BIN. SOME WORDS ARE 6-7BIT, SO WE ADD 0 TO FORMAT 8BIT EACH WORD
	for (i = 0; i < length; i++) {
	  binary = ascii_to_binary(cc[i]);
		if((cc[i] >= 'A' && cc[i] <= 'z')){
	  		fprintf(fo, "0%d", binary);
		} else {
	  		fprintf(fo, "00%d", binary);
	  }
	}
	fclose(fo);

	fo = fopen(nameFile2, "r");

	i = 0;
	while(!feof(fo)) {
	  c = fgetc(fo);
	 if(!feof(fo)) {
	      cc[i] = c;
	      i++;
	  }
	}
	fclose(fo);
	
    length = strlen(cc);
	
	// OPEN CONVERTED FILE TO WRITE
	fo = fopen(nameFile2, "w");
	
	// ENCRYPTION DATA
    length = encryption(length, cc, fp);
	printf("\n--The size of file : %dbyte\n", length);
	fclose(fo);
	
	printf("\nDo you want continue to decrypt(1=yes, 0=no)?\n==> ");
	scanf("%d", &cont);
	if(!cont)
		return -3;
	
	// DECRYPTION
	// OPEN/CREATE THE FILE TO WRITE
	printf("\nGive me the path of file to write : ");
	scanf("%s", nameFile2);
	
	fo = fopen_write(nameFile2);
	
	//printf("\n--Data of file : ");
	decryption(length, cc, fo);
	
	fclose(fo); 
	  
	fo = fopen(nameFile2, "r");
	i = 0;
	while(!feof(fp)) {
    	c = fgetc(fp);
    	if(!feof(fp)) {
        	cc[i] = c;
        	i++;  
    	}
  	}
  	length = i;
  	//printf("\n--The size of file : %dbyte\n", length);
  	fclose(fo);
  
  	fo = fopen(nameFile2, "w");  
    if(!(fp != NULL) || (fp == NULL)) {
    	printf("\n--The file : '%s' not found..\n", nameFile2);
        return -5;
    }
    
    printf("\n--Data of file : ");
    for(i = 0; i < length-1; i++){
   	    cbin[j] = cc[i];
   	    if (i == byte){
   		    binary_to_ascii(cbin, fo);
   	 	    j = -1;
   			byte +=8;
	    }
		j++;
   }
   printf("\n--The size of file : %dbyte\n", byte/8);
   
   return 0;
}
 
// FUNCTIONS 
FILE *fopen_read(char *nameFile) {
    FILE *fp;
    fp = fopen(nameFile, "r"); 
	if(fp == NULL) {
	  printf("\n--The file '%s' is empty..\n\n", nameFile);
	  return ;
	}
	printf("\n--The file '%s' opened to read successfully!", nameFile);
    return fp;
}

FILE *fopen_write(char *nameFile) {
    FILE *fo;
    fo = fopen(nameFile, "w");
	if((fo != NULL) || (fo == NULL)) { 
	  printf("\n--The file : '%s' opened to write successfully!", nameFile); 
      return fo;
    }
	else{
	  printf("\n--The file : '%s' not found..\n\n", nameFile);
	  return ;
	}
}

int ascii_to_binary(int a) {
    int sum = 0, remainder;
    int i = 1, j = 0;
    
    while (a > 0) {
        remainder = a % 2;
        sum = sum + (i * remainder);
        a = a / 2;
        i = i * 10;
    }
    return sum;
}

void binary_to_ascii(char *byte, FILE *name) {
    int c = 0;
    int i;
    for (i = 0; i < BITE; i++) 
        c |= (byte[i] == '1') << ((BITE - 1) - i);
    fprintf(name, "%c", c);
    printf("%c", c);
}

int encryption(int length, char *buffer, FILE *name) {
    int i, counter = 0;

	printf("\n--Data of file : ");
    for(i = 0; i < length - 1; i++){
    	if(i % 2 == 0) 
  			counter = 1;
		else 
		    counter = 0;
		if (counter == 1) {
			if((buffer[i] == '1') && (buffer[i] == buffer[i+1])) 
				buffer[i+1] = '0';
			else if((buffer[i] == '1') && (buffer[i] != buffer[i+1]))
				buffer[i+1] = buffer[i];
		}      
		 fprintf (name, "%c", buffer[i]);
		 printf("%c", buffer[i]);
	}			
	length = strlen(buffer);
    return length;
}

int decryption(int length, char *buffer, FILE *name) {
	int i, counter;

	for(i = 0; i < length - 1; i++){
    	if (i % 2 == 0) {
  			counter = 1;
		   } else 
		      counter = 0;
		if (counter == 1) {
			if ((buffer[i] == '1') && (buffer[i] == buffer[i+1])) {
				buffer[i+1] = '0';
			} else if((buffer[i] == '1') && (buffer[i] != buffer[i+1])){
				buffer[i+1] = buffer[i];
			}
		}      
		 fprintf(name, "%c", buffer[i]);
		 //printf("%c", buffer[i]);
	  }	
}
