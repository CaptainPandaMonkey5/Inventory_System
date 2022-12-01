#pragma once

int password() 
{
	system("cls");
	Users users;
	unsigned opt {};
	std::string usermain;
    std::string devPassword;
    int login_Attempt = 0;

	if (!readUsers(users))
		cout << "Problem reading users\n";

	do {
		cout << "\n\t[1] LOGIN" << endl;
		cout << "\n\t[2] CHANGE PASSWORD" << endl;
		cout << "\n\t[3] SIGN UP" << endl;
		cout << "\n\t[4] DELETE USER" << endl;
		cout << "\n\t[5] DISPLAY ALL USERS" << endl;
		cout << "\n\t[6] ATTEMPTED DEV ADD ON" << endl;
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

			case 6:
			// working and tested
    while (login_Attempt < 3)
    {
        std::cout << "username: ";
        std::cin >> usermain;
        std::cout << std::endl;
        std::cout << "password: ";
        std::cin >> devPassword;

        if (usermain == "group0" && devPassword == "group01")
        {
            // log dev in
            break;
        }
        else
        {
            std::cout << "INVALID LOGIN ATTEMPT... PLEASE TRY AGAIN!!" << std::endl;
            login_Attempt++;
        }
    }
    if (login_Attempt == 3)
    {
        std::cout << "\n\tTOO MANY LOG IN ATTEMPTS!" << std::endl;
        std::cout << "\n\tGOING BACK TO MAIN MENU" << std::endl;
    }
				break;

			case 0:
				if (!writeUsers(users))
					cout << "Problem writing users\n";

				break;

			default:
				cout << "Invalid option\n";
		}
	} while (opt);
	return 0;
};
