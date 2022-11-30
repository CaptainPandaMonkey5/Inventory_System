#pragma once

string getPass(const UserData& data)
{
	string pass;
	Passerr passerr;

	do {
		cout << "Enter password (CR to terminate): ";
		getline(cin, pass);
	} while (!pass.empty() && ((passerr = checkPass(data, pass)) != OK) && (cout << "Invalid password - " << PassErrs[passerr] << '\n'));

	return pass;
}