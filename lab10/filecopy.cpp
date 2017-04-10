
// Please put your name here


#include <iostream>
#include <cctype>
#include <fstream>
#include <ostream>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
int a = 0;

// Please add your function or class here to implement your filecopy
void filecopy(string in_file,string out_file) {
    //file I/O and vector declaration
    ifstream inputFile;
    inputFile.open(in_file.c_str());
    ofstream outputFile;
    outputFile.open(out_file);
    vector <string>copystring;
    string inputString;

    if(!inputFile) return;

    while(getline(inputFile, inputString)) {
        //store in vector
        copystring.push_back(inputString);
    }
    for(unsigned i = 0;i < copystring.size() ;i++){
        outputFile<<copystring[i]<<endl;
    }
    inputFile.close();
    outputFile.close();
}





int main(int argc, char *argv[]) {
    string source_file;	// source file to copy data from
    string dest_file;	// dest file the recipent of the data

    // This section prompts for or uses command line arguments to get
    // the filenames
#ifdef TESTING	// includes Mimir so do not modify

    if(argc != 3) {
        cout << "Not correct Usage: " << argv[0] << " source_file dest_file\n";
        exit(-1);
    }
    source_file = argv[1];
    dest_file = argv[2];

#else
    cout << "Enter Source File: ";
    cin >> source_file;

    cout << "Enter Dest File: ";
    cin >> dest_file;

#endif
    cout << "Going to Copy into: " << dest_file << " From " << source_file << endl;


    // Please place your function code or calls to function here.
    // call on function
    filecopy(source_file,dest_file);
    return 0;
}
