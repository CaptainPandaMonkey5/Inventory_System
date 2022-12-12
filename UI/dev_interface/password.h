#pragma once

string username, bookCode;
    int bookQuantity;
    int firstA = 34;
    int firstB = 26;
    int firstC = 74;
    int secondA = 17;
    int secondB = 82;
    int secondC = 34;
    int secondD = 78;
    int thirdA = 76;
    int thirdB = 16;
    int thirdC = 45;
    int thirdD = 80;
    int fourthA = 36;
    int fourthB = 25;
    int fourthC = 38;

void displayBooks() {
    cout << "--------------------------------------------------" << endl;
    cout << "              Welcome to Books R Us!" << endl << endl;
    cout << " Hello " << username << "!" << endl << endl;
    cout << "======================================================" << endl;
    cout << " CODE\tBOOKS TITLE\t\t\t\tSTOCKS" << endl;
    cout << " 1A\tFundamentals of Information Technology\t" << firstA << endl;
    cout << " 1B\tIntegrated Computer Application\t\t" << firstB << endl;
    cout << " 1C\tLearning Guide in C Programming\t\t" << firstC << endl;
    cout << " 2A\tDatabase Management System\t\t" << secondA << endl;
    cout << " 2B\tNetworking\t\t\t\t" << secondB << endl;
    cout << " 2C\tObject Oriented Programming\t\t" << secondC << endl;
    cout << " 2D\tAssembly Language\t\t\t" << secondD << endl;
    cout << " 3A\tSoftware Engineering\t\t\t" << thirdA << endl;
    cout << " 3B\tSQL\t\t\t\t\t" << thirdB << endl;
    cout << " 3C\tPython\t\t\t\t\t" << thirdC << endl;
    cout << " 3D\tWeb Development\t\t\t\t" << thirdD << endl;
    cout << " 4A\tEmbedded Systems\t\t\t" << fourthA << endl;
    cout << " 4B\tWireless Technology\t\t\t" << fourthB << endl;
    cout << " 4C\tAndroid Programming\t\t\t" << fourthC << endl;
    cout << "======================================================" << endl;
    cout << " *Number in code are the year levels*" << endl << endl;
}

void purchaseBooks(string bookCode, int bookQuantity) {
    if (bookCode == "1A") {
        firstA = firstA - bookQuantity;
    } else if (bookCode == "1B") {
        firstB = firstB - bookQuantity;
    } else if (bookCode == "1C") {
        firstC = firstC - bookQuantity;
    } else if (bookCode == "2A") {
        secondA = secondA - bookQuantity;
    } else if (bookCode == "2B") {
        secondB = secondB - bookQuantity;
    } else if (bookCode == "2C") {
        secondC = secondC - bookQuantity;
    } else if (bookCode == "2D") {
        secondD = secondD - bookQuantity;
    } else if (bookCode == "3A") {
        thirdA = thirdA - bookQuantity;
    } else if (bookCode == "3B") {
        thirdB = thirdB - bookQuantity;
    } else if (bookCode == "3C") {
        thirdC = thirdC - bookQuantity;
    } else if (bookCode == "3D") {
        thirdD = thirdD - bookQuantity;
    } else if (bookCode == "4A") {
        fourthA = fourthA - bookQuantity;
    } else if (bookCode == "4B") {
        fourthB = fourthB - bookQuantity;
    } else if (bookCode == "4C") {
        fourthC = fourthC - bookQuantity;
    }
}

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

int password() 
{
	system("cls");
	Users users;
	unsigned opt {};
	int attemptCount = 0;
    string name, gender, email, phoneNum;
    char answer;
    string usermain;
    string devPassword;
    int login_Attempt = 0;
    int choiceDo, age, studentNum, choiceEdit, choiceRet, yearLevel, arrSize;
    string nameHOLDER, genderHOLDER, phoneHOLDER, emailHOLDER, usernameHOLDER, passHolder;
    int ageHOLDER, studentHOLDER;
    int main, secondary;
    string pass, username1, pass1;
    bool run = 1;
    int attempts = 3;


	if (!readUsers(users))
		cout << "Problem reading users\n";

	do 
    {
		cout << "\n\t[1] LOGIN" << endl;
		cout << "\n\t[2] SIGN UP" << endl;
		cout << "\n\t[3] CHANGE PASSWORD" << endl;
		cout << "\n\t[4] LOG IN FOR DEVELOPERS" << endl;
		cout << "\n\t[0] EXIT" << endl;

		switch(opt = getInt("\nEnter options: ")) 
        {
			case 1:
            system("cls");
                cout << "--------------------------------------------------" << endl;
                cout << "              Welcome to Books R Us!" << endl << endl;
                cout << " SIGN IN" << endl << endl;
                cout << " Username: ";
                cin >> username;
                cout << " Password: ";
                cin >> pass;
                cout << endl;

                if (username1 == username && pass1 == pass) 
                {
                    system("cls");
                    cout << " Login successfully!" << endl << endl;
                    system("cls");
                    cout << "--------------------------------------------------" << endl;
                    cout << "              Welcome to Books R Us!" << endl << endl;
                    cout << " Hello " << username << "!" << endl << endl;
                    displayBooks();
                    cout << " What do you want to do?" << endl << endl;
                    cout << " [1] Purchase" << endl;
                    cout << " [2] Change Username" << endl;
                    cout << " [3] Change Password" << endl;
                    cout << " [4] Back to Main Menu" << endl << endl;
                    cout << " Enter choice [1-4]: ";
                    cin >> secondary;
                    cin.ignore();

                    if (secondary == 1) 
                    {
                        system("cls");
                        displayBooks();
                        string confirm = "END";

                        while(bookCode != "END") 
                        {
                            cout << " PURCHASE" << endl << endl;
                            cout << " Enter book code: ";
                            cin >> bookCode;

                            if(bookCode == "END")
                                break;

                            cout << " Enter quantity: ";
                            cin >> bookQuantity;
                            purchaseBooks(bookCode, bookQuantity);
                            system("cls");
                            displayBooks();
                        }
                        system("pause");
                        system("cls");
                            string *num = new string[arrSize];

    inputData(arrSize, num);
    cout << "------------------------------------------------------" << endl;
    display(arrSize, num);
    cout << "------------------------------------------------------" << endl;
                    }
                    }
			break;
			case 2:
            system("cls");
        cout << "--------------------------------------------------" << endl;
        cout << "               Customer Information" << endl;
        cout << "\n [1] Create" << endl;
        cout << " [2] Edit" << endl;
        cout << " [3] Delete" << endl;
        cout << " [4] Retrieve" << endl;
        cout << " [5] Exit" << endl;
        cout << "\n What would you like to do? : ";
        cin >> choiceDo;

        switch(choiceDo)
        {
            case 1:
            system("cls");
            cout << "--------------------------------------------------" << endl;
            cout << "               Customer Information" << endl;
            cout << "                      Create" << endl;
            cout << "\n Name : ";
            getline(cin >> ws, name);
            cout << " Gender : ";
            cin >> gender;
            cout << " Age : ";
            cin >> age;
            cout << " Phone No. : ";
            cin >> phoneNum;
            cout << " Email Address : ";
            cin >> email;
            cout << " Student No. : ";
            cin >> studentNum;
            cout << " Username: ";
            cin >> username;
            cout << " Password: ";
            cin >> pass;

            cout << "--------------------------------------------------" << endl;
            cout << " Name : " << name << endl;
            cout << " Gender : " << gender << endl;
            cout << " Age : " << age << endl;
            cout << " Phone No. : " << phoneNum << endl;
            cout << " Email Address : " << email << endl;
            cout << " Student No. : " << studentNum << endl;
            cout << " Username:" << username << endl;
            cout << " Password:" << pass << endl; 
            break;
            case 2:
            nameHOLDER = name;
            genderHOLDER = gender;
            phoneHOLDER = phoneNum;
            emailHOLDER = email;
            ageHOLDER = age;
            studentHOLDER = studentNum;
            usernameHOLDER = username;
            passHolder = pass;
            system("cls");
            cout << "--------------------------------------------------" << endl;
            cout << "               Customer Information" << endl;
            cout << "                       Edit" << endl;
            cout << "\n [1] Name" << endl;
            cout << " [2] Gender" << endl;
            cout << " [3] Age" << endl;
            cout << " [4] Phone No." << endl;
            cout << " [5] Email Address" << endl;
            cout << " [6] Student No." << endl;
            cout << " [7] Username" << endl;
            cout << " [8] Password" << endl;
            cout << "\n What would you like to edit? : ";
            cin >> choiceEdit;

            if (choiceEdit == 1) {
                system("cls");
                cout << "\n Name : ";
                getline(cin >> ws, name);

                cout << "--------------------------------------------------" << endl;
                cout << " Name : " << name << endl;
                cout << " Gender : " << gender << endl;
                cout << " Age : " << age << endl;
                cout << " Phone No. : " << phoneNum << endl;
                cout << " Email Address : " << email << endl;
                cout << " Student No. : " << studentNum << endl;
            } else if (choiceEdit == 2) {
                system("cls");
                cout << "\n Gender : ";
                cin >> gender;

                cout << "--------------------------------------------------" << endl;
                cout << " Name : " << name << endl;
                cout << " Gender : " << gender << endl;
                cout << " Age : " << age << endl;
                cout << " Phone No. : " << phoneNum << endl;
                cout << " Email Address : " << email << endl;
                cout << " Student No. : " << studentNum << endl;
            } else if (choiceEdit == 3) {
                system("cls");
                cout << "\n Age : ";
                cin >> age;

                cout << "--------------------------------------------------" << endl;
                cout << " Name : " << name << endl;
                cout << " Gender : " << gender << endl;
                cout << " Age : " << age << endl;
                cout << " Phone No. : " << phoneNum << endl;
                cout << " Email Address : " << email << endl;
                cout << " Student No. : " << studentNum << endl;
            } else if (choiceEdit == 4) {
                system("cls");
                cout << "\n Phone No. : ";
                cin >> phoneNum;

                cout << "--------------------------------------------------" << endl;
                cout << " Name : " << name << endl;
                cout << " Gender : " << gender << endl;
                cout << " Age : " << age << endl;
                cout << " Phone No. : " << phoneNum << endl;
                cout << " Email Address : " << email << endl;
                cout << " Student No. : " << studentNum << endl;
            } else if (choiceEdit == 5) {
                system("cls");
                cout << "\n Email Address : ";
                cin >> email;

                cout << "--------------------------------------------------" << endl;
                cout << " Name : " << name << endl;
                cout << " Gender : " << gender << endl;
                cout << " Age : " << age << endl;
                cout << " Phone No. : " << phoneNum << endl;
                cout << " Email Address : " << email << endl;
                cout << " Student No. : " << studentNum << endl;
            } else if (choiceEdit == 6) {
                system("cls");
                cout << "\n Student No. : ";
                cin >> studentNum;

                cout << "--------------------------------------------------" << endl;
                cout << " Name : " << name << endl;
                cout << " Gender : " << gender << endl;
                cout << " Age : " << age << endl;
                cout << " Phone No. : " << phoneNum << endl;
                cout << " Email Address : " << email << endl;
                cout << " Student No. : " << studentNum << endl;
            }
            else if (choiceEdit == 7) {
             system("cls");
                cout << "\n Student No. : ";
                cin >> username;

                cout << "--------------------------------------------------" << endl;
                cout << " Name : " << name << endl;
                cout << " Gender : " << gender << endl;
                cout << " Age : " << age << endl;
                cout << " Phone No. : " << phoneNum << endl;
                cout << " Email Address : " << email << endl;
                cout << " Student No. : " << studentNum << endl;
                cout << " Username: " << username << endl;
                cout << " Password: " << pass << endl;
            } 
            else if (choiceEdit == 8) {
                system("cls");
                cout << "\n Student No. : ";
                cin >> pass;

                cout << "--------------------------------------------------" << endl;
                cout << " Name : " << name << endl;
                cout << " Gender : " << gender << endl;
                cout << " Age : " << age << endl;
                cout << " Phone No. : " << phoneNum << endl;
                cout << " Email Address : " << email << endl;
                cout << " Student No. : " << studentNum << endl;
                cout << " Username: " << username << endl;
                cout << " Password: " << pass << endl;
            }
            else {
                cout << "\n Invalid input!" << endl;
            }
            break;
            case 3:
            nameHOLDER = name;
            genderHOLDER = gender;
            phoneHOLDER = phoneNum;
            emailHOLDER = email;
            ageHOLDER = age;
            studentHOLDER = studentNum;
            usernameHOLDER = username;
            passHolder = pass;
            name.clear();
            gender.clear();
            age = -1;
            phoneNum.clear();
            email.clear();
            studentNum = -1;
            username.clear();
            pass.clear();
            cout << "\n Data cleared successfully! " << endl;
            break;
            case 4:
            name = nameHOLDER;
            gender = genderHOLDER;
            phoneNum = phoneHOLDER;
            email = emailHOLDER;
            age = ageHOLDER;
            studentNum = studentHOLDER;
            cout << "\n Data successfully restored from previous point." << endl;
            cout << "--------------------------------------------------" << endl;
            cout << " Name : " << name << endl;
            cout << " Gender : " << gender << endl;
            cout << " Age : " << age << endl;
            cout << " Phone No. : " << phoneNum << endl;
            cout << " Email Address : " << email << endl;
            cout << " Student No. : " << studentNum << endl;
            case 5:
            password();
            default:
            cout << " Invalid input!" << endl;
        }
				break;
			case 3:
				changePass(users);
				break;
      		case 4:
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
			do
			{
                cout << "\n\tWelcome Developer" << endl;
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
                        password();
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