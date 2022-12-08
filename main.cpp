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
#include "UI/getInt.h"

#include "UI/student_interface/readUser.h"
#include "UI/student_interface/writeUser.h"
#include "UI/student_interface/checkPass.h"
#include "UI/student_interface/getUser.h"
#include "UI/student_interface/getPass.h"
#include "UI/student_interface/addUser.h"
#include "UI/student_interface/changePass.h"

#include "UI/dev_interface/displayUsers.h" // list of users - dev TODO: change password output to ****** <- 
#include "UI/dev_interface/deleteUsers.h"
#include "UI/dev_interface/password.h" // UI - student && dev TODO: separate the ones for the dev and student
// create password_student and password_dev ??
#include "UI/dev_interface/devInfo.h"

int main()
{
  int choice;

  while(1)
  {
    cout << "Project in Data Structures and Algorithm (MCS 201)" << endl;
    cout << "\n\tMAIN MENU:" << endl;
    cout << "\n\t[1] LOG IN" << endl;
    cout << "\n\t[2] ABOUT THE DEVELOPERS" << endl;
    cout << "\n\t[3] EXIT" << endl;
    cout << "\n\tChoice: ";
    cin >> choice;

    switch(choice)
    {
      case 1:
        password();
        break;
      case 2:
        devInfo();
        break;
      case 3:
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