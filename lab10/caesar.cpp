
// Please put your name here


#include <iostream>
#include <cctype>
#include <fstream>
#include <ostream>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
// Please add your function or class here to implement your filecopy
vector<string>copy1;   //copy1 stands for encrypted content
vector<string>copy2; //copy2 stands for decrypted content
class Asckey{
public:
    //declare encrypt key, source file, encrypted file,decrypted file and  key;
    string infile1;        //infile1 is original file   /home/student/Programming/zhang4ym-StudentCode/lab10/inputfile.txt
    string OUTFILE1;       // OUTFILE1 is encrypted file /home/student/Programming
    string OUTFILE2;       // OUTFILE2 is decrypted file
    string key;

    // constructor 1
    Asckey(string infile_x,string OUTFILE1_x,string OUTFILE2_x,string key_x){
        key = key_x;
        infile1 = infile_x;
        OUTFILE1 = OUTFILE1_x;
        OUTFILE2 = OUTFILE2_x;
    }

    //This member function calculate the key
    int cipherkey(string key1){
        int asc2sum = 0;
        for(unsigned i = 0;i < key1.size();i++){
            asc2sum = asc2sum + key1[i];
        }
        asc2sum = (asc2sum % 23) + 3;
        cout<<asc2sum<<endl;
        return asc2sum;
    }
    //This member funtion output two seperate file
    void readfile(string source_file,string outfile1,string outfile2,int key3){
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
            //file encryption here
            for(unsigned i = 0; i < inputString.size() ;i++){
                if(isupper(inputString[i])){
                    inputString[i] = inputString[i]+key3;
                    if(inputString[i] > 90){
                        inputString[i] = inputString[i]-90 +64;
                    }
                }
                else if(islower(inputString[i])){
                    inputString[i] = toupper(inputString[i]);
                    inputString[i] = inputString[i]+ key3;
                    if(inputString[i] > 90){
                        inputString[i] = inputString[i]-90 +64;
                    }
                    inputString[i] = tolower(inputString[i]);
                }

            }
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
};

int main(int argc, char *argv[]) {
    string input_file;	// input file to encrypt
    string encrypted_file;	// dest file for the recipent of the encrypted data
    string decrypted_file;	// dest file for the decrypted data
    string cipher_key;	// cipher_key

    // This section prompts for or uses command line arguments to get
    // the filenames
#ifdef TESTING	// includes Mimir so do not modify

    if(argc != 5) {
        cout << "Not correct Usage: " << argv[0] << " input_file encryped_file decryped_file cipher_key\n";
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
         << "  decrypting back to " << decrypted_file
         << endl;

    // Please place your class variable declaration here.
    // create class object
    Asckey obj1(input_file,encrypted_file,decrypted_file,cipher_key);
    // call on member function
    int key_key = obj1.cipherkey(cipher_key);
    // call on member function
    obj1.readfile(input_file,encrypted_file,decrypted_file,key_key);
    return 0;
}
