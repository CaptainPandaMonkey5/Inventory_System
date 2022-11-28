#pragma once

int password() {
	Users users;
	unsigned opt {};

	if (!readUsers(users))
		std::cout << "Problem reading users\n";

	do {
		std::cout << "\n1. Login\n";
		std::cout << "2. Change password\n";
		std::cout << "\n3. Add user\n";
		std::cout << "4. Delete user\n";
		std::cout << "5. Display all users\n";
		std::cout << "0. Exit\n";

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
					std::cout << "OK\n";
				else
					std::cout << "Invalid\n";

				break;

			case 5:
				displayUsers(users);
				break;

			case 0:
				if (!writeUsers(users))
					std::cout << "Problem writing users\n";

				break;

			default:
				std::cout << "Invalid option\n";
		}
	} while (opt);
};
