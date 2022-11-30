#pragma once

int password() 
{
	system("cls");
	Users users;
	unsigned opt {};

	if (!readUsers(users))
		cout << "Problem reading users\n";

	do {
		cout << "\n\t[1] LOGIN" << endl;
		cout << "\n\t[2] CHANGE PASSWORD" << endl;
		cout << "\n\t[3] SIGN UP" << endl;
		cout << "\n\t[4] DELETE USER" << endl;
		cout << "\n\t[5] DISPLAY ALL USERS" << endl;
		cout << "\n\t[0] EXIT" << endl;

		switch (opt = getInt("\nEnter options: ")) {
			case 3:
				addUser(users);
				break;

			case 4:
				deleteUser(users);
				break;

			case 2:
				changePass(users);
				break;

			case 1:
				if (login(users))
					cout << "OK\n";
				else
					cout << "Invalid\n";
				break;

			case 5:
				displayUsers(users);
				break;

			case 0:
				if (!writeUsers(users))
					cout << "Problem writing users\n";

				break;

			default:
				cout << "Invalid option\n";
		}
	} while (opt);
};
