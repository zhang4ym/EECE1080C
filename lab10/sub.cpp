
// Please put your name here


#include <iostream>
#include <cctype>
#include <fstream>
#include <ostream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Please add your function or class here to implement your filecopy

int main(int argc, char *argv[]) {
   string input_file;	// input file to encrypt
   string encrypted_file;	// dest file for the recipent of the encrypted data
   string decrypted_file;	// dest file for the decrypted data
   string cipher_key;	// cipher_key

// This section prompts for or uses command line arguments to get 
// the filenames
#ifdef TESTING	// includes Mimir so do not modify

cout << argc << endl;
	if(argc != 5) {
		cout << "Not correct Usage: " << argv[0] << " input_file encrypted_file decrypted_file cipher_key\n";
		exit(-1);
	}
	input_file = argv[1];
	encrypted_file = argv[2];
	decrypted_file = argv[3];
	cipher_key = argv[4];

#else
	cout << "Enter Source File: ";
	cin >> input_file;

	cout << "Enter Encrypted File: ";
	cin >> encrypted_file;

	cout << "Enter Decrypted File: ";
	cin >> decrypted_file;

	cout << "Enter Cipher Key: ";
	cin >> cipher_key;

#endif
	cout << "Going to Encrypt File:  " << input_file 
	     << " using the encryption key " << cipher_key 
	     << " the encrypted file going to " << encrypted_file
	     << "  decrypting back to" << decrypted_file
	     << endl;

// Please place your class variable declaration here.

	
	return 0;
}
