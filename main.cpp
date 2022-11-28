#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <limits>
#include <stdlib.h>

struct UserData {
	std::string name;
	std::string curpass;
	std::set<std::string> prevpass;
};

using Users = std::map<std::string, UserData>;

enum Passerr {OK, UPPER, LOWER, LENGTH, DUPLICATE, LAST};

const std::string PassErrs[LAST] {"", "Insufficient upper case chars", "Insufficient lower case chars", "Not enough chars", "Duplicate"};
const std::string userfile {"users.txt"};

// Format of file is
//userid,name,curpass,oldpass,...

int getInt(const std::string& prm)
{
	int i {};

	while ((std::cout << prm) && (!(std::cin >> i) || std::cin.peek() != '\n')) {
		std::cout << "Not an integer\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return i;
}

// true OK, false bad
bool readUsers(Users& users)
{
	std::ifstream ifs(userfile);

	if (!ifs)
		return false;

	for (std::string line; std::getline(ifs, line); ) {
		UserData user;
		std::string id;
		std::istringstream iss(line);

		std::getline(iss, id, ',');
		std::getline(iss, user.name, ',');
		std::getline(iss, user.curpass, ',');

		const bool ok {iss};

		for (std::string pass; std::getline(iss, pass, ','); user.prevpass.insert(pass));

		// Assume data on file is correct - no duplicates etc
		if (ok)
			users[id] = user;
	}

	return true;
}

// true OK, false bad
bool writeUsers(const Users& users)
{
	std::ofstream ofs(userfile);

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
Passerr checkPass(const UserData& user, const std::string& pass)
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

auto getUser(Users& users, std::string& id)
{
	std::cout << "\nEnter userid: ";
	std::getline(std::cin, id);

	return users.find(id);
}

auto getUser(Users& users)
{
	std::string id;

	return getUser(users, id);
}

std::string getPass(const UserData& data)
{
	std::string pass;
	Passerr passerr;

	do {
		std::cout << "Enter password (CR to terminate): ";
		std::getline(std::cin, pass);
	} while (!pass.empty() && ((passerr = checkPass(data, pass)) != OK) && (std::cout << "Invalid password - " << PassErrs[passerr] << '\n'));

	return pass;
}

// true OK, false bad
bool addUser(Users& users)
{
	std::string id;

	if (const auto itr {getUser(users, id)}; itr != users.end()) {
		std::cout << "Id already exists.\n";
	} else {
		UserData data;

		std::cout << "Enter name: ";
		std::getline(std::cin, data.name);

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
		std::cout << "Id does not exist\n";
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
	std::string pass;

	std::cout << "Password: ";
	std::getline(std::cin, pass);

	if (itr != users.end())
		if (itr->second.curpass == pass)
			return true;

	return false;
}

void displayUsers(const Users& users)
{
	std::cout << '\n' << std::right << std::setw(24) << "USER" << std::setw(16) << "PASS\n";
	std::cout << std::left << std::setw(20) << "NAME" << std::setw(15) << "NAME" << std::setw(10) << "WORD" << " PREVIOUS PASSWORDS\n";
	std::cout << std::setw(75) << std::setfill('-') << '-' << std::setfill(' ') << '\n';

	for (const auto& user : users) {
		std::cout << std::setw(20) << user.second.name << std::setw(15) << user.first << std::setw(10) << user.second.curpass;
		for (const auto& old : user.second.prevpass)
			std::cout << " " << old;

		std::cout << '\n';
	}

	std::cout << '\n';
}

// true OK, false bad
bool deleteUser(Users& users)
{
	if (const auto iditr {getUser(users)}; iditr == users.end()) {
		std::cout << "Id does not exist\n";
		return false;
	} else
		users.erase(iditr);

	return true;
}

int password() {
	Users users;
	unsigned opt {};

	if (!readUsers(users))
		std::cout << "Problem reading users\n";

	do {
		std::cout << "\n1. Login\n";
		std::cout << "2. Change password\n";
		std::cout << "\n3. Add user\n";
		std::cout << "4. Delete user\n";
		std::cout << "5. Display all users\n";
		std::cout << "0. Exit\n";

		switch (opt = getInt("\nEnter options: ")) {
			case 3:
				addUser(users);
				break;

			case 4:
				deleteUser(users);
				break;

			case 2:
				changePass(users);
				break;

			case 1:
				if (login(users))
					std::cout << "OK\n";
				else
					std::cout << "Invalid\n";

				break;

			case 5:
				displayUsers(users);
				break;

			case 0:
				if (!writeUsers(users))
					std::cout << "Problem writing users\n";

				break;

			default:
				std::cout << "Invalid option\n";
		}
	} while (opt);
};

int main()
{
  int choice;

  while(1)
  {
    std::cout << "Project in Data Structures and Algorithm (MCS 201)" << std::endl;
    std::cout << "\n\tMAIN MENU:" << std::endl;
    std::cout << "\n\t[1] LOG IN FOR STUDENTS" << std::endl;
    std::cout << "\n\t[2] LOG IN FOR DEVELOPERS" << std::endl;
    std::cout << "\n\t[3] ABOUT THE DEVELOPERS" << std::endl;
    std::cout << "\n\t[4] EXIT" << std::endl;
    std::cout << "\n\tChoice: ";
    std::cin >> choice;

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