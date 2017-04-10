
// Please put your name here
// Yiming Zhang

#include <iostream>
#include <cctype>
#include <fstream>
#include <ostream>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

// vector declaration
vector<string>copy1;
vector<string>copy2;
// function will output encrypt and decrypt file
void readfile(string source_file,string outfile1,string outfile2){
    // file I/O
    ifstream inputFile;
    ofstream  outputFile1;
    ofstream  outputFile2;
    inputFile.open(source_file.c_str());
    outputFile1.open(outfile1);
    outputFile2.open(outfile2);
    string inputString;

    if(!inputFile) return;
    while(getline(inputFile, inputString)) {
        //decrypted copy
        copy2.push_back(inputString);
        // for loop encrypt file content
        for(unsigned i = 0; i < inputString.size() ;i++){
            if(isupper(inputString[i])){
                inputString[i] = inputString[i]+13;
                if(inputString[i] > 90){
                    inputString[i] = inputString[i]-90 +64;
                }
            }
            else if(islower(inputString[i])){
                inputString[i] = toupper(inputString[i]);
                inputString[i] = inputString[i]+ 13;
                if(inputString[i] > 90){
                    inputString[i] = inputString[i]-90 +64;
                }
                inputString[i] = tolower(inputString[i]);
            }
        }
        cout<<inputString<<endl;
        //encrypted copy
        copy1.push_back(inputString);
    }
    // write to external file
    for(unsigned i =0;i< copy1.size();i++){
        outputFile1<<copy1[i]<<endl;
        outputFile2<<copy2[i]<<endl;
    }
    inputFile.close();
    outputFile1.close();
    outputFile2.close();
}




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
    // call on function
    readfile(input_file,encrypted_file,decrypted_file);

    return 0;
}
