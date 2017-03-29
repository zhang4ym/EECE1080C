//Jacob Fike & Yiming Zhang
//Lab 9

#include <string>
#include <vector>
#include <bitset>
#include <fstream>

using namespace std;

void addcontact(string last,string firstname,string email,string mobile);
bool findcontact(string search);
void editcontact(string search);
void deletecontact(string search);
void exportcontacts(string filename);
bool import(string phoneBookFile);

//creates a structure to hold each person's information
struct contact {
    string lname;
    string fname;
    string mobile;
    string emailID;
};

class phoneBook {
private:
    //vector of the contacts. Notice the type of the vector
    vector < contact > myContacts;
    void displayPhoneBook(){
        for (unsigned int i = 0; i < myContacts.size(); i++){
            cout << "last name " << myContacts[i].lname
                 << " first name " << myContacts[i].fname
                 << " mobile " << myContacts[i].mobile
                 << " e-mail " << myContacts[i].emailID << endl;
        }
    }

    //Other functions here.

public:
    // Menu is for sure a public functions. Others may or may not be
    void menu(){
//This makes it so the program enters
        int functionchoice = 8;
//This loop displays the entire list of functions and how to activate them after every
//function use, so the user can always see the list, as well as running whatever funtion the user selects
//until they choose to quit
        while (functionchoice != 0){
            cout << endl;
            cout << "Contact Application:" << endl;
            cout << "1. Import Contacts" << endl;
            cout << "2. Add Contact" << endl;
            cout << "3. Find Contact" << endl;
            cout << "4. Edit Contact" << endl;
            cout << "5. Delete Contact" << endl;
            cout << "6. Export Contacts" << endl;
            cout << "7. Display Contacts" << endl;
            cout << "0. Quit" << endl;
            cout << "Function Choice: "; //asks user for an input which determines the output of the switch function
            cin >> functionchoice;
            switch(functionchoice){      //each outcome of the switch function is connected to one of the phonebook functions
            case 1: // Import Contacts
            {
                string filename;
                cout << "File to Import: ";
                cin >> filename;
                cout << endl;
                import(filename);
                break;
            }
            case 2: // Add Contact
            {
                string last;
                string first;
                string mobile;
                string emailID;
                cout << "First Name: ";
                cin >> first;
                cout << endl;
                cout << "Last Name: ";
                cin >> last;
                cout << endl;
                cout << "Mobile Number: ";
                cin >> mobile;
                cout << endl;
                cout << "Email ID: ";
                cin >> emailID;
                cout << endl;
                addcontact(last, first, mobile, emailID);
                break;
            }
            case 3: //Find Contact
            {
                string search;
                cout << "Search For: " << endl;
                cin >> search;
                cout << endl;
                findcontact(search);
                break;
            }
            case 4: //Edit Contact
            {
                string search;
                cout << "Contact to Edit: " << endl;
                cin >> search;
                cout << endl;
                editcontact(search);
                break;
            }
            case 5: // Delete Contact
            {
                string search;
                cout << "Contact to Delete: " << endl;
                cin >> search;
                cout << endl;
                deletecontact(search);
                break;
            }
            case 6: // Export Contacts
            {
                string filename;
                cout << "File to Export To: ";
                cin >> filename;
                cout << endl;
                exportcontacts(filename);
                break;
            }
            case 7: //Display Contacts
            {
                displayPhoneBook();
                break;
            }
            case 0: break;
            }
        }
    }
//creates a new object of type contact in the vector of contacts, using the last name, first name, mobile number, and email ID inputted by the user
    void addcontact(string last,string firstname,string mobile,string email){
        contact obj1;
        obj1.lname = last;
        obj1.fname = firstname;
        obj1.mobile = mobile;
        obj1.emailID = email;
        myContacts.push_back(obj1);
        cout<<"1 contact added!"<<endl;
    }
//searches through the vector of contacts one by one until it finds one whose first name or last name matches with the inputted search term
    bool findcontact(string search){
        int n = 0;
        cout<< "The following are the contacts that match your search in order (last first mobile email)"<<endl;
        for(unsigned i = 0; i < myContacts.size(); i++){
            if( myContacts[i].lname == search || myContacts[i].fname == search){
                cout<<myContacts[i].lname<<" "<< myContacts[i].fname<<" "<<myContacts[i].mobile<<" "<< myContacts[i].emailID<<" "<<endl;
                n = n +1;
            }
        }
        if(n > 0){
            return true;
        }
        if( n == 0){
            cout << "No matches found.";
            return false;
        }
    }
//searches for a matching contact, the same way the search function does, and then rewrites all the values in that contact object to the ones inputted by the user
    void editcontact(string search){
        int n = 0;
        int found;
        cout<<"The following are the contacts in your phonebook in order (last first mobile email): "<<endl;
        for(unsigned i = 0; i < myContacts.size(); i++){
            if( myContacts[i].lname == search || myContacts[i].fname == search){
                cout<<myContacts[i].lname<<" "<< myContacts[i].fname<<" "<<myContacts[i].mobile<<" "<< myContacts[i].emailID<<" "<<endl;
                n = n+1;
                found = i;
            }

        }
        if(n > 1){
            cout<<"Re-enter to Narrow down or Enter a different name? y/n";
            string a;
            cin >> a;
            if(a == "y"){
                string search;
                cout << "Contact to Edit: " << endl;
                cin >> search;
                cout << endl;
                editcontact(search);
            }

        }
        else if(n == 0){
            cout<<"No contacts found matching that name. Re-enter? y/n";
            string a;
            cin >> a;
            if(a == "y"){
                string search;
                cout << "Enter the name of the person you would like to edit" << endl;
                cin >> search;
                cout << endl;
                editcontact(search);
            }
        }
        else if (n == 1){
            string a;
            cout << "Is this the contact you wish to edit? y/n";
            cin >> a;
            if(a == "y"){
                cout<<"First Name?";
                cin>> myContacts[found].fname;
                cout << "Last Name?";
                cin >> myContacts[found].lname;
                cout<< "Mobile?";
                cin>>myContacts[found].mobile;
                cout<< "emailID?";
                cin>>myContacts[found].emailID;
                cout << "Contact edited" << endl;
            }
            else
            {
                cout<<"Search again? y/n";
                string a;
                cin >> a;
                if(a == "y"){
                    string search;
                    cout << "Contact to Edit: " << endl;
                    cin >> search;
                    cout << endl;
                    editcontact(search);
                }
            }

        }

    }
//searches for a matching contact object in the same way as the search function, checks with the user to make sure they watn to, and then removes that entire contact object form the vector
    void deletecontact(string search){
        int n = 0;
        int found;
        cout<<"The following are the contacts in your phonebook in order (last first mobile email): "<<endl;
        for(unsigned i = 0; i < myContacts.size(); i++){
            if( myContacts[i].lname == search || myContacts[i].fname == search){
                cout<<myContacts[i].lname<<" "<< myContacts[i].fname<<" "<<myContacts[i].mobile<<" "<< myContacts[i].emailID<<" ";
                n = n+1;
                found = i;
            }
        }
        if(n > 1){
            cout<<"Re-enter to Narrow down or Enter a different name? y/n";
            string a;
            cin >> a;
            if(a == "y"){
                string search;
                cout << "Contact to Edit: " << endl;
                cin >> search;
                cout << endl;
                editcontact(search);
            }

        }
        else if(n == 0){
            cout<<"No contacts found matching that name. Re-enter? y/n";
            string a;
            cin >> a;
            if(a == "y"){
                string search;
                cout << "Enter the name of the person you would like to edit ";
                cin >> search;
                cout << endl;
                deletecontact(search);
            }

        }
        else if (n == 1){
            string a;
            cout << "Is this the contact you wish to delete? Remember, all deletions are permanent. y/n";
            cin >> a;
            if(a == "y"){
                myContacts.erase(myContacts.begin() + found);

                cout << "Contact Deleted. RIP Contact" << endl;
            }
            else{
                cout<<"Search again? y/n";
                string a;
                cin >> a;
                if(a == "y"){
                    string search;
                    cout << "Contact to Delete: " << endl;
                    cin >> search;
                    cout << endl;
                    deletecontact(search);
                }
            }
        }
}
//goes through the vector of contact objects one by one and writes the values of all the parts of each contact object into a new text file
    void exportcontacts(string filename){
        ofstream outfile;
        outfile.open(filename);
         for(unsigned i = 0; i < myContacts.size(); i++){
            outfile<<myContacts[i].lname<<" "<<myContacts[i].fname<<" "<<myContacts[i].mobile<<" "<< myContacts[i].emailID<<endl;
        }
        outfile.close();
        cout<<"All Contacts exported to file in order(last first mobile email)";

    }


    // For testing purposes, Please leave intact
#ifdef MIMIR_TEST
    vector < contact > getInternalState(){
        return myContacts;
    }
#endif
    // returns a true if the file is found and is readable
    // returns a false if the file in not found or not readable
    // reads data in a text file and creates a new contact object in the vector of contacts,
    // assigning each word on a line as the value for a part of that line's contact
    bool import(string phoneBookFile){
        ifstream myFile;
        //Link the input file to this object;
        myFile.open(phoneBookFile.c_str());

        if(!myFile) return false;

        contact temp;
        while(!myFile.eof()){

                    myFile >> temp.lname
                            >> temp.fname
                            >> temp.mobile
                            >> temp.emailID;
                    if(!myFile.eof()) // add this
                          myContacts.push_back(temp);
                }


        myFile.close();

        return true;
    }

};








