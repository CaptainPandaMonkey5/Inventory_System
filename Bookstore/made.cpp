#include <iostream>

using namespace std;

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

int main()
{
    string name, gender, email, phoneNum;
    int age, studentNum, yearLevel, arrSize;
    char answer;

    while(true) {
        cout << "--------------------------------------------------" << endl;
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
        cout << "--------------------------------------------------" << endl;
        cout << " Name: " << name << endl;
        cout << " Gender: " << gender << endl;
        cout << " Age: " << age << endl;
        cout << " Phone number: " << phoneNum << endl;
        cout << " Email address: " << email << endl;
        cout << " Student number: " << studentNum << endl;

        cout << "\n Do you want to make changes [Y/N]: ";
        cin >> answer;

        if(answer == 'y' || answer == 'Y')
            true;
        else
            break;
    }

    cout << "--------------------------------------------------" << endl;
    cout << " Enter your year level [1/2/3/4]: ";
    cin >> yearLevel;
    cout << "--------------------------------------------------" << endl;

    if(yearLevel == 1) {
        cout << "               ====BOOK TITLES====" << endl;
        cout << "\n FIRST YEAR" << endl;
        cout << " 1. Fundamentals of Information Technology" << endl;
        cout << " 2. Integrated Computer Applications" << endl;
        cout << " 3. Learning Guide in C Programming" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << " How many books would you like to purchase?: ";
        cin >> arrSize;
    } else if(yearLevel == 2) {
        cout << "               ====BOOK TITLES====" << endl;
        cout << "\n SECOND YEAR" << endl;
        cout << " 1. Database Management System" << endl;
        cout << " 2. Networking" << endl;
        cout << " 3. Object Oriented Programming" << endl;
        cout << " 4. Assembly Language" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << " How many books would you like to purchase?: ";
        cin >> arrSize;
    } else if(yearLevel == 3) {
        cout << "               ====BOOK TITLES====" << endl;
        cout << "\n THIRD YEAR" << endl;
        cout << " 1. Software Engineering" << endl;
        cout << " 2. SQL" << endl;
        cout << " 3. Python" << endl;
        cout << " 4. Web Development" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << " How many books would you like to purchase?: ";
        cin >> arrSize;
    } else if(yearLevel == 4) {
        cout << "               ====BOOK TITLES====" << endl;
        cout << "\n FOURTH YEAR" << endl;
        cout << " 1. Embedded Systems" << endl;
        cout << " 2. Wireless Technology" << endl;
        cout << " 3. Android Programming" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << " How many books would you like to purchase?: ";
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

    return 0;
}
