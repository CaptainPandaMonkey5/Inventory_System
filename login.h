#pragma once

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