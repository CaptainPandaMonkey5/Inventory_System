// pandamonkey test site breaking everything here and fixing

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

const string PassErrs[LAST] {"", "Insufficient upper case chars", "Insufficient lower case chars", "Not enough chars", "Duplicate"};
const string userfile {"users.txt"};

// Format of file is
//userid,name,curpass,oldpass,...

int getInt(const string& prm)
{
	int i {};

	while ((cout << prm) && (!(cin >> i) || cin.peek() != '\n')) {
		cout << "Not an integer\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return i;
}

// true OK, false bad
bool readUsers(Users& users)
{
	ifstream ifs(userfile);

	if (!ifs)
		return false;

	for (string line; getline(ifs, line); ) {
		UserData user;
		string id;
		istringstream iss(line);

		getline(iss, id, ',');
		getline(iss, user.name, ',');
		getline(iss, user.curpass, ',');

		const bool ok {iss};

		for (string pass; getline(iss, pass, ','); user.prevpass.insert(pass));

		// Assume data on file is correct - no duplicates etc
		if (ok)
			users[id] = user;
	}

	return true;
}

// true OK, false bad
bool writeUsers(const Users& users)
{
	ofstream ofs(userfile);

	if (!ofs)
		return false;

	for (const auto& user : users) {
		ofs << user.first << ',' << user.second.name << ',' << user.second.curpass << ',';

		for (size_t pasno = 0; const auto & pass : user.second.prevpass)
			ofs << (pasno++ ? "," : "") << pass;

		ofs << '\n';
	}

	return true;
}

//true OK, false bad
Passerr checkPass(const UserData& user, const string& pass)
{
	// INCLUDE HERE OTHER REQUIRED TESTS FOR VALID PASSWORD

	size_t lowerCount {}, upperCount {};

	for (const auto& ch : pass) {
		upperCount += isupper(static_cast<unsigned char>(ch));
		lowerCount += islower(static_cast<unsigned char>(ch));
	}

	if (pass.size() < 6)
		return LENGTH;

	if (lowerCount == 0)
		return LOWER;

	if (upperCount == 0)
		return UPPER;

	if ((pass == user.curpass) || user.prevpass.count(pass))
		return DUPLICATE;

	return OK;
}

auto getUser(Users& users, string& id)
{
	cout << "\nEnter userid: ";
	getline(cin, id);

	return users.find(id);
}

auto getUser(Users& users)
{
	string id;

	return getUser(users, id);
}

string getPass(const UserData& data)
{
	string pass;
	Passerr passerr;

	do {
		cout << "Enter password (CR to terminate): ";
		getline(cin, pass);
	} while (!pass.empty() && ((passerr = checkPass(data, pass)) != OK) && (cout << "Invalid password - " << PassErrs[passerr] << '\n'));

	return pass;
}

// true OK, false bad
bool addUser(Users& users)
{
	string id;

	if (const auto itr {getUser(users, id)}; itr != users.end()) {
		cout << "Id already exists.\n";
	} else {
		UserData data;

		cout << "Enter name: ";
		getline(cin, data.name);

		if (const auto pass {getPass(data)}; !pass.empty()) {
			data.curpass = pass;
			users[id] = data;
			return true;
		}
	}

	return false;
}

// true OK, false bad
bool changePass(Users& users)
{
	if (const auto iditr {getUser(users)}; iditr == users.end()) {
		cout << "Id does not exist\n";
	} else {
		if (const auto pass {getPass(iditr->second)}; !pass.empty()) {
			iditr->second.prevpass.insert(iditr->second.curpass);
			iditr->second.curpass = pass;
			return true;
		}
	}

	return false;
}

// true OK, false bad
bool login(const Users& users)
{
	const auto itr {getUser(const_cast<Users&>(users))};
	string pass;

	cout << "Password: ";
	getline(cin, pass);

	if (itr != users.end())
		if (itr->second.curpass == pass)
			return true;

	return false;
}

void displayUsers(const Users& users)
{
	cout << '\n' << right << setw(24) << "USER" << setw(16) << "PASS\n";
	cout << left << setw(20) << "NAME" << setw(15) << "NAME" << setw(10) << "WORD" << " PREVIOUS PASSWORDS\n";
	cout << setw(75) << setfill('-') << '-' << setfill(' ') << '\n';

	for (const auto& user : users) {
		cout << setw(20) << user.second.name << setw(15) << user.first << setw(10) << user.second.curpass;
		for (const auto& old : user.second.prevpass)
			cout << " " << old;

		cout << '\n';
	}

	cout << '\n';
}

// true OK, false bad
bool deleteUser(Users& users)
{
	if (const auto iditr {getUser(users)}; iditr == users.end()) {
		cout << "Id does not exist\n";
		return false;
	} else
		users.erase(iditr);

	return true;
}

void devLogin(const Users& users)
{
    system("cls");
	string usermain;
    string devPassword;
    int login_Attempt = 0;
	
    while (login_Attempt < 3)
    {
        cout << "username: ";
        cin >> usermain;
        cout << endl;
        cout << "password: ";
        cin >> devPassword;

        if (usermain == "group0" && devPassword == "group01")
        {
            // log dev in
            break;
        }
        else
        {
            cout << "INVALID LOGIN ATTEMPT... PLEASE TRY AGAIN!!" << endl;
            login_Attempt++;
        }
    }
    if (login_Attempt == 3)
    {
        cout << "\n\tTOO MANY LOG IN ATTEMPTS!" << endl;
        cout << "\n\tGOING BACK TO MAIN MENU" << endl;
    }
};

int password() {
	system("cls");
	Users users;
	unsigned opt {};

	if (!readUsers(users))
		cout << "Problem reading users\n";

	do {
		cout << "\n\t[1] LOGIN" << endl;
		cout << "\n\t[2] CHANGE PASSWORD" << endl;
		cout << "\n\t[3] SIGN UP" << endl;
		cout << "\n\t[4] DELETE USER" << endl;
		cout << "\n\t[5] DISPLAY ALL USERS" << endl;
		cout << "\n\t[6] ATTEMPTED DEV ADD ON" << endl;
		cout << "\n\t[0] EXIT" << endl;


		switch (opt = getInt("\nEnter options: ")) {
			case 3:
				addUser(users);
				break;

			case 4:
				devLogin(users);
				break;

			case 2:
				changePass(users);
				break;

			case 1:
				if (login(users))
					cout << "OK\n";
				else
					cout << "Invalid\n";

				break;

			case 5:
				displayUsers(users);
				break;

      case 6:
        devLogin(users);
        break;

			case 0:
				if (!writeUsers(users))
					cout << "Problem writing users\n";

				break;

			default:
				cout << "Invalid option\n";
		}
	} while (opt);
};

int main()
{
  int choice;

  while(1)
  {
    cout << "Project in Data Structures and Algorithm (MCS 201)" << endl;
    cout << "\n\tMAIN MENU:" << endl;
    cout << "\n\t[1] LOG IN" << endl;
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
