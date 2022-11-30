#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <limits>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct UserData {
	string name;
	string curpass;
	set<string> prevpass;
};

using Users = map<string, UserData>;

enum Passerr {OK, UPPER, LOWER, LENGTH, DUPLICATE, LAST};

const string PassErrs[LAST] {"", "Insufficient upper case chars", "Insufficient lower case chars", "Not enough characters", "Duplicate"};
const string userfile {"users.txt"};

// Format of file is
#include "getInt.h" // user input of choice - dev
#include "readUser.h" // password - dev
#include "writeUser.h" // password - dev
#include "checkPass.h" // password checking - dev
#include "getUser.h" // username - student
#include "getPass.h" // password storing - dev
#include "addUser.h" // sign up - student
#include "changePass.h" // password changer algo? - dev
#include "login.h" // password input - student
#include "displayUsers.h" // list of users - dev TODO: change password output to ****** <- 
#include "deleteUsers.h" // algorithm - dev
#include "password.h" // UI - student && dev TODO: separate the ones for the dev and student

int main()
{
  int choice;

  while(1)
  {
    cout << "Project in Data Structures and Algorithm (MCS 201)" << endl;
    cout << "\n\tMAIN MENU:" << endl;
    cout << "\n\t[1] LOG IN FOR STUDENTS" << endl;
    // move password info and backend stuff to LOG IN FOR DEVELOPERS must have password and user log in too
    cout << "\n\t[2] LOG IN FOR DEVELOPERS" << endl;
    cout << "\n\t[3] ABOUT THE DEVELOPERS" << endl;
    cout << "\n\t[4] EXIT" << endl;
    cout << "\n\tChoice: ";
    cin >> choice;

    switch(choice)
    {
      case 1:
        password();
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        cout << endl;
        cout << "THANK YOU FOR USING OUR SOFTWARE" << endl;
        cout << endl;
        exit(0);
        break;
      default:
        cout << "\n\t YOU ENTERED THE WRONG CHOICE..." << endl;
        cout << "\n\t PRESS ANY KEY TO TRY AGAIN" << endl;
        cout << "-----------------------------------------------" << endl;
        getch();
        break;
    }
    system("cls");
  }
  return 0;
};