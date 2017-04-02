
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
   string encrypted_file;	// dest file the recipent of the encrypted data
   string decrypted_file;	// dest file the recipent of the decrypted data

// This section prompts for or uses command line arguments to get 
// the filenames
#ifdef TESTING	// includes Mimir so do not modify

	if(argc != 4) {
		cout << "Not correct Usage: " << argv[0] << " input_file encrypted_file decrypted_file\n";
		exit(-1);
	}
	input_file = argv[1];
	encrypted_file = argv[2];
	decrypted_file = argv[3];

#else
	cout << "Enter Source File: ";
	cin >> input_file;

	cout << "Enter Encrypted File: ";
	cin >> encrypted_file;

	cout << "Enter Decrypted File: ";
	cin >> decrypted_file;

#endif
	cout << "Going to Encrypt into: " << encrypted_file << " From " << input_file << endl;
	cout << "Going to Decrypt into: " << decrypted_file << " From " << encrypted_file << endl;
		

// Please place your function code or calls to function here.

	
	return 0;
}
