#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <limits>
#include <stdlib.h>

using namespace std;

struct UserData {
	string name;
	string curpass;
	set<string> prevpass;
};

using Users = map<string, UserData>;

enum Passerr {OK, UPPER, LOWER, LENGTH, DUPLICATE, LAST};

const string PassErrs[LAST] {"", "Insufficient upper case chars", "Insufficient lower case chars", "Not enough chars", "Duplicate"};
const string userfile {"users.txt"};

// Format of file is
#include "getInt.h"
#include "readUser.h"
#include "writeUser.h"
#include "checkPass.h"
#include "getUser.h"
#include "getPass.h"
#include "addUser.h"
#include "changePass.h"
#include "login.h"
#include "displayUsers.h"
#include "deleteUsers.h"
#include "password.h"

int main()
{
  int choice;

  while(1)
  {
    cout << "Project in Data Structures and Algorithm (MCS 201)" << endl;
    cout << "\n\tMAIN MENU:" << endl;
    cout << "\n\t[1] LOG IN FOR STUDENTS" << endl;
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
        exit(0);
    }
  }
  return 0;
};