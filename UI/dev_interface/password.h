#pragma once

void devLogin(const Users& users)
{
	string usermain;
    string devPassword;
    int login_Attempt = 0;
	
    while (login_Attempt < 3)
    {
        cout << "username: ";
        cin >> usermain;
        cout << endl;
        cout << "password: ";
        cin >> devPassword;

        if (usermain == "group0" && devPassword == "group01")
        {
			system("cls");
			Users users;
			unsigned opt {};

			if (!readUsers(users))
				cout << "PROBLEM READING USERS\n";

			cout << "\n\tWelcome Developer" << endl;
			do
			{
				cout << "\n\t[1] DELETE USER" << endl;
				cout << "\n\t[2] DISPLAY ALL USERS" << endl;
				cout << "\n\t[3] EXIT PROGRAM" << endl;
				
				switch(opt = getInt("\nENTER CHOICE: "))
				{
					case 1:
						deleteUser(users);
						break;
					case 2:
						displayUsers(users);
						break;
					case 3:
						getch();
						exit(0);
						break;
					default:
						cout << "Invalid Option" << endl;
				}
			}while (opt);
        }
        else
        {
            cout << "INVALID LOGIN ATTEMPT... PLEASE TRY AGAIN!!" << endl;
            login_Attempt++;
        }
    }
    if (login_Attempt == 3)
    {
        cout << "\n\tTOO MANY LOG IN ATTEMPTS!" << endl;
        cout << "\n\tGOING BACK TO MAIN MENU" << endl;
    }
};

int password() {
	system("cls");
	Users users;
	unsigned opt {};
	int attemptCount = 0;

	if (!readUsers(users))
		cout << "Problem reading users\n";

	do {
		cout << "\n\t[1] LOGIN" << endl;
		cout << "\n\t[2] SIGN UP" << endl;
		cout << "\n\t[3] CHANGE PASSWORD" << endl;
		cout << "\n\t[4] LOG IN FOR DEVELOPERS" << endl;
		cout << "\n\t[0] EXIT" << endl;

		switch (opt = getInt("\nEnter options: ")) {
			case 1:
			while (attemptCount < 3)
			{
				if (login(users))
					cout << "OK\n";
				else if (attemptCount == 0)
				{
					cout << "Incorrect username/password combination. Please try again." << endl;
					cout << "ONE OUT OF THREE TRIES." << endl;
				}
				else if (attemptCount == 1)
				{
					cout << "Incorrect username/password combination. Please try again." << endl;
					cout << "TWO OUT OF THREE TRIES." << endl;
				}
				else if (attemptCount == 2)
				{
					cout << endl;
					cout << "TERMINATING PROGRAM" << endl;
					cout << "PRESS ANY KEY TO EXIT" << endl;
					getch();
					exit(0);
				}

				attemptCount++;
			}
			break;
			case 2:
				addUser(users);
				break;
			case 3:
				changePass(users);
				break;
      		case 4:
        		devLogin(users);
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
