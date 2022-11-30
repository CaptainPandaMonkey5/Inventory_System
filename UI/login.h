#pragma once

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