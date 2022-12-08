#pragma once

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