#pragma once

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