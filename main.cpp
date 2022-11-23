#include <iostream>
#include <stdlib.h>

using namespace std;

void devInfo();
// not done still figuring out
int password()
{
  char pass[15] = {0}, check[15] = {0}, ch;


};

int main()
{
  int choice;
  cout << "Project in Data Structures and Algorithm (MCS 201)" << endl;

  while(1)
  {
    cout << "\n\tMAIN MENU:" << endl;
    cout << "\n\t[1] LOG IN" << endl;
    cout << "\n\t[2] SIGN UP" << endl;
    cout << "\n\t[3] ABOUT THE DEVELOPERS" << endl;
    cout << "\n\t[4] EXIT" << endl;
    // cin var; or getline(cin, var);

    switch(choice)
    {
      case 1:
        break;
      case 2:
        break;
      case 3:
        devInfo();
        break;
    }
  }

  void devInfo()
  {
    // not checked if everything is aligned
    cout << "Presented by:" << endl;
    cout << "\n\tBaguiso, Jericho John" << endl;
    cout << "\n\t\tBSM CS 2A" /* name of the group */ << endl;
    cout << "\n\tBasario, Jomari" << endl;
    cout << "\n\t\tBSM CS 2A" /* name of the group */ << endl;
    cout << "\n\tBelardo, Jefferson" << endl;
    cout << "\n\t\tBSM CS 2A" /* name of the group */ << endl;
    cout << "\n\tBello, Saimon" << endl;
    cout << "\n\t\tBSM CS 2A" /* name of the group */ << endl;
    cout << "\n\tCagalingan, Joshua" << endl;
    cout << "\n\t\tBSM CS 2A" /* name of the group */ << endl;
    cout << "\n\tCunanan, Lovely" << endl;
    cout << "\n\t\tBSM CS 2A" /* name of the group */ << endl;
    cout << "\n\tEnfectana, Vincent" << endl;
    cout << "\n\t\tBSM CS 2A" /* name of the group */ << endl;
    cout << "\n\tSabado, Lars" << endl;
    cout << "\n\t\tBSM CS 2A" /* name of the group */ << endl;
    cout << "\n\tSandiego, Neil" << endl;
    cout << "\n\t\tBSM CS 2A" /* name of the group */ << endl;
    cout << "\n\tShinohara, Yuya" << endl;
    cout << "\n\t\tBSM CS 2A" /* name of the group */ << endl;

    cout << "Presented to:\t Engr. Evelyn C. Samson" << endl;
    cout << "\t\t Instructor" << endl;
  };
}
