#pragma once

int password() {
	Users users;
	unsigned opt {};

	if (!readUsers(users))
		cout << "Problem reading users\n";

	do {
		cout << "\n1. Login\n";
		cout << "2. Change password\n";
		cout << "\n3. Add user\n";
		cout << "4. Delete user\n";
		cout << "5. Display all users\n";
		cout << "0. Exit\n";

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
