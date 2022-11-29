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