# Encryption and Decryption data using files with C

What does this program do? The scope of code is the encryption and the decryption of data with the help of files
What Encryption/Decryption Algorithm we use? The algorithm is not some known.. is our own for the practice.
How works this algorithm?
   Steps :
   * Convert char to binary
   * Add one or more '0' left of each word to make them equal to 8 bits
   * check each pair of bits and if the first bit of pair is '1' change the second bit in inverse from initial state. the first bit of pair is '0', don't do anything and check the next pair.

For Example :
	1 step(input file) :
   		S-string = 'h'
	2 step(encryption data) :
   		S-decimal = 104
   		S-binary = 1101000(7-bit) = 'h'
		S-algorithm = 01111100(8-bit) = '|'
	4 step(decryption data) :
		S-binary = 01111100(8-bit) = '|'
		S-algorithm = 01101000 = 'h'