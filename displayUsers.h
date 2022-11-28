#pragma once

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