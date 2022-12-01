#pragma once

bool devLogin(const Users& users)
{
    system("cls");
	std::string usermain;
    std::string devPassword;
    int login_Attempt = 0;
	
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
    return false;
};
