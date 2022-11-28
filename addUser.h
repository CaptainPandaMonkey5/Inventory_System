#pragma once

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
