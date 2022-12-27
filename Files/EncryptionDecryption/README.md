# Encryption and Decryption data using files with C

### What does this program do? 
The scope of code is the encryption and the decryption of data with the help of files
### What Encryption/Decryption Algorithm we use? 
The algorithm is not known.. it's mine for practicing with C, files/data structures and encryption/decryption.
### How works this algorithm?
   #### Steps : 
   * Convert char to binary
   * Add one or more '0' left of each word to make them equal to 8 bits
   * check each pair of bits and if the first bit of pair is '1' change the second bit in inverse from initial state. If the first bit of pair is '0', don't do anything and check the next pair.

### For Example :
	 1st step(input file) :
		 S-string = 'h'
	 2st step(encryption data) :
		 S-decimal = 104
		 S-binary = 1101000(7-bit) = 'h'
		 add '0'
		 S-algorithm = 01111100(8-bit) = '|'
	 3st step(decryption data) :
		 S-binary = 01111100(8-bit) = '|'
		 remove '0'
		 S-algorithm = 01101000(7-bit) = 'h'

### Output :
![alt text](https://github.com/nikolas-gou/University-Projects/blob/main/Files/EncryptionDecryption/images/1.png)

![alt text](https://github.com/nikolas-gou/University-Projects/blob/main/Files/EncryptionDecryption/images/2.png)

![alt text](https://github.com/nikolas-gou/University-Projects/blob/main/Files/EncryptionDecryption/images/3.png)
