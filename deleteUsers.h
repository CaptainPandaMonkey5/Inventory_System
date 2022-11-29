#pragma once


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