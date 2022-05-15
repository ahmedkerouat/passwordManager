#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <cstdlib>
using namespace std;
int main()
{
    std::string listOfNumbers = { "123456789" };
    std::string listOfChracters = { "!?_&" };
    std::string alphabet = {"abcdefghijklmnopqrstuvwxyz"};
    std::string alphabetWithMaj = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    

    string finalList = "";
    finalList = alphabet;

    cout << "Are you here to create a password (1) ? \n Or to simply check your passwords (2) ? \n";
    int createOrRead = 0;
    cin >> createOrRead;
    cin.ignore();


     if (createOrRead == 1) {

         ofstream MyFile;
         MyFile.open("science_project_text.txt", ios::app);
         if (MyFile) {
             ifstream File("science_project_text.txt", ios::binary);
             ofstream File_copy("class_notes.txt", ios::binary);
             File_copy << File.rdbuf();
         }
         else {
             ofstream MyFile("science_project_text.txt");
         }

         cout << "Type the number of characters in your password\n";
         int numberOfChar(0);
         cin >> numberOfChar;
         cin.ignore();

         cout << "Let's choose the options in your password =) !\n";

         cout << "Do you want capital letters in your password ?\n";
         string ifCapital("");
         getline(cin, ifCapital);
         if (ifCapital == "yes") {
             finalList = finalList + alphabetWithMaj;

         }

         cout << "Do you want numbers in your password ? \n";
         string ifNumbers("");
         getline(cin, ifNumbers);
         if (ifNumbers == "yes") {
             finalList = finalList + listOfNumbers;

         }


         cout << "Do you want random characters in you password ? (example: `` ? or & or ! or ; `` ...)\n";
         string ifCharacters("");
         getline(cin, ifCharacters);
         if (ifCharacters == "yes") {
             finalList = finalList + listOfChracters;

         }
         int i(0);
         string result("");
         srand(clock());
         for (i = 0; i < numberOfChar; i++) {
             int index = std::rand() % finalList.size();
             result += finalList[index];
         }
         cout << "Your password is " << result << endl;

         cout << " For what are you going to use this password ? \n";
         string application("");
         getline(cin, application);

         cout << " What's the username or the email that u are going to use for here ? \n";
         string emailOrUsername("");
         getline(cin, emailOrUsername);

         
         MyFile << endl << application <<" "<<  emailOrUsername << " " << result << endl;
         MyFile.close();

     }

     if (createOrRead == 2) {

         ifstream MyFile;
         MyFile.open("science_project_text.txt");
    

         cout << "Application Email/Username Password \n";
         string myLine("");
         
             while (getline(MyFile, myLine))
             {
                 cout << myLine << endl;
             }
             MyFile.close();
         
     }
 


    return 0;
    
}


