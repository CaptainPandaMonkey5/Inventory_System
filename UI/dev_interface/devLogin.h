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