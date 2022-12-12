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
        // admin/developer 
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

	void inputDatas(int size, string Q[]) {
    cout << "\n Books to purchase: " << endl;
    for (int ctr = 0; ctr < size; ctr++)
    {
        cout << " ";
        getline(cin >> ws, Q[ctr]);
    }
}

void displays(int size, string Q[]) {
    double order, discount, total;

    if(size >= 3){
        order = 200 * size;
        discount = 200 * 0.05;
        total = order - discount;
    } else {
        total = 200 * size;
    }

    cout << " These are the books you purchased: " << endl;
    for (int ctr = 0; ctr < size; ctr++)
        cout << " " << Q[ctr] << "\tPhp 200.00" << endl;
    cout << "\n Total:\t\t\t\t\tPhp " << total << ".00" << endl;
};

void inputData(int size, string Q[]) {
    cout << "\n Books to purchase: " << endl;
    for (int ctr = 0; ctr < size; ctr++)
    {
        cout << " ";
        getline(cin >> ws, Q[ctr]);
    }
}

void display(int size, string Q[]) {
    double order, discount, total;

    if(size >= 3){
        order = 200 * size;
        discount = 200 * 0.05;
        total = order - discount;
    } else {
        total = 200 * size;
    }

    cout << " These are the books you purchased: " << endl;
    for (int ctr = 0; ctr < size; ctr++)
        cout << " " << Q[ctr] << "\tPhp 200.00" << endl;
    cout << "\n Total:\t\t\t\t\tPhp " << total << ".00" << endl;
}

int password() {
	system("cls");
	Users users;
	unsigned opt {};
	int attemptCount = 0;
    string name, gender, email, phoneNum;
    int age, studentNum, yearLevel, arrSize;
    char answer;

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
				{
                    system("cls");
    while(true) {
        cout << " Enter your full name: ";
        getline(cin >> ws, name);
        cout << " Enter your gender: ";
        cin >> gender;
        cout << " Enter your age: ";
        cin >> age;
        cout << " Enter your phone number: ";
        cin >> phoneNum;
        cout << " Enter your email address: ";
        cin >> email;
        cout << " Enter your student number: ";
        cin >> studentNum;
        system("cls");
        cout << "--------------------------------------------------" << endl;
        cout << " Name: " << name << endl;
        cout << " Gender: " << gender << endl;
        cout << " Age: " << age << endl;
        cout << " Phone number: " << phoneNum << endl;
        cout << " Email address: " << email << endl;
        cout << " Student number: " << studentNum << endl;
        system("cls");
        cout << "\n Do you want to make changes [Y/N]: ";
        cin >> answer;

        if(answer == 'y' || answer == 'Y')
            true;
        else
            break;
    }
    system("cls");
    cout << "--------------------------------------------------" << endl;
    cout << " Enter your year level [1/2/3/4]: ";
    cin >> yearLevel;
    cout << "--------------------------------------------------" << endl;

    if(yearLevel == 1) {
        system("cls");
        cout << "               ====BOOK TITLES====" << endl;
        cout << "\n FIRST YEAR" << endl;
        cout << " 1. Fundamentals of Information Technology" << endl;
        cout << " 2. Integrated Computer Applications" << endl;
        cout << " 3. Learning Guide in C Programming" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << " How many books would you like to purchase? ";
        cin >> arrSize;
    } else if(yearLevel == 2) {
        system("cls");
        cout << "               ====BOOK TITLES====" << endl;
        cout << "\n SECOND YEAR" << endl;
        cout << " 1. Database Management System" << endl;
        cout << " 2. Networking" << endl;
        cout << " 3. Object Oriented Programming" << endl;
        cout << " 4. Assembly Language" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << " How many books would you like to purchase? ";
        cin >> arrSize;
    } else if(yearLevel == 3) {
        system("cls");
        cout << "               ====BOOK TITLES====" << endl;
        cout << "\n THIRD YEAR" << endl;
        cout << " 1. Software Engineering" << endl;
        cout << " 2. SQL" << endl;
        cout << " 3. Python" << endl;
        cout << " 4. Web Development" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << " How many books would you like to purchase? ";
        cin >> arrSize;
    } else if(yearLevel == 4) {
        system("cls");
        cout << "               ====BOOK TITLES====" << endl;
        cout << "\n FOURTH YEAR" << endl;
        cout << " 1. Embedded Systems" << endl;
        cout << " 2. Wireless Technology" << endl;
        cout << " 3. Android Programming" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << " How many books would you like to purchase? ";
        cin >> arrSize;
    } else {
        cout << " Invalid Input" << endl;
        cout << "--------------------------------------------------" << endl;
    }

    string *num = new string[arrSize];

    inputData(arrSize, num);
    cout << "------------------------------------------------------" << endl;
    display(arrSize, num);
    cout << "------------------------------------------------------" << endl;
    break;
				}
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