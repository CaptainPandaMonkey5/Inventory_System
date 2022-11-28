#pragma once


//userid,name,curpass,oldpass,...
int getInt(const std::string& prm)
{
	int i {};

	while ((std::cout << prm) && (!(std::cin >> i) || std::cin.peek() != '\n')) {
		std::cout << "Not an integer\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return i;
}
