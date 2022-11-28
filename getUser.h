#pragma once

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