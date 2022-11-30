#pragma once

// true OK, false bad
bool addUser(Users& users)
{
	system("cls");
	
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
