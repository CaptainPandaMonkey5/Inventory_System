#pragma once


//userid,name,curpass,oldpass,...
int getInt(const string& prm)
{
	int i {};

	while ((cout << prm) && (!(cin >> i) || cin.peek() != '\n')) {
		cout << "Not an integer\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return i;
}
