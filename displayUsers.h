#pragma once

void displayUsers(const Users& users)
{
	cout << '\n' << right << setw(24) << "USER" << setw(16) << "PASS\n";
	cout << left << setw(20) << "NAME" << setw(15) << "NAME" << setw(10) << "WORD" << " PREVIOUS PASSWORDS\n";
	cout << setw(75) << setfill('-') << '-' << setfill(' ') << '\n';

	for (const auto& user : users) {
		cout << setw(20) << user.second.name << setw(15) << user.first << setw(10) << user.second.curpass;
		for (const auto& old : user.second.prevpass)
			cout << " " << old;

		cout << '\n';
	}

	cout << '\n';
}