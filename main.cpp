#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void login();
void registration();
void forgotPassword();

int main()
{
    int c;

    cout << "\t\t\t______________________________________________________\n\n";
    cout << "\t\t\t                  Welcome to login                     \n\n";
    cout << "\t\t\t                        MENU                            \n\n";
    cout << "                                                               \n";
    cout << "\t\t\t\t | Press 1 to Login                  |" << endl;
    cout << "\t\t\t\t | Press 2 for registration          |" << endl;
    cout << "\t\t\t\t | Press 3 if forgot password        |" << endl;
    cout << "\t\t\t\t | Press 4 to exit                   |" << endl;
    cout << "\n\t\t\t\t Please enter your choice: " << endl;

    cin >> c;

    cout << endl;

    switch (c)
    {
    case 1:
        login();
        break;

    case 2:
        registration();
        break;

    case 3:
        forgotPassword();
        break;

    case 4:
        cout << "\t\t\t Thank you \n\n";
        break;

    default:
        system("cls");
        cout << "\t\t\t Invalid choice \n"
             << endl;
        main();
    }
}

void login()
{
    int count;
    string userId, password, id, pass;

    system("cls");

    cout << "\t\t\t Please enter the username and password : " << endl;

    cout << "\t\t\t Username ";
    cin >> userId;

    cout << "\t\t\t Password ";
    cin >> password;

    ifstream input("records.txt");

    while (input >> id >> pass)
        ;
    {
        if (id == userId && pass == password)
        {
            count = 1;
            system("cls");
        }
    }

    input.close();

    if (count == 1)
    {
        cout << "\t\t\t Welcome " << userId << endl;
        main();
    }
    else
    {
        cout << "\t\t\t Login error! Do you have an account? \n"
             << endl;
        main();
    }
}

void registration()
{
    string ruserId, rpassword, rid, rpass;

    system("cls");

    cout << "\t\t\t Enter a username : ";
    cin >> ruserId;

    cout << "\t\t\t Enter a password : ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserId << ' ' << rpassword << endl;

    system("cls");

    cout << "\t\t\t Registration successful \n"
         << endl;
    main();
}

void forgotPassword()
{
    int option;
    system("cls");

    cout << "\t\t\t Forgot the password? \n"
         << endl;
    cout << "\t\t\t Press 1 to search for username " << endl;
    cout << "\t\t\t Press 2 to go back to menu " << endl;
    cout << "\t\t\t Enter your option : ";
    cin >> option;

    switch (option)
    {

    case 1:
    {
        int count = 0;
        string suserId, sId, spass;

        cout << "\t\t\t Enter your username : ";
        cin >> suserId;

        ifstream f2("records.txt");

        while (f2 >> sId >> spass)
        {
            if (sId == suserId)
            {
                count = 1;
                break;
            }
        }
        f2.close();

        if (count == 1)
        {
            cout << "\n\n Your account is found \n";
            cout << "\n\n Your password is : " << spass;
            main();
        }
        else
        {
            cout << "\n\n Account not found \n";
            main();
        }
        break;
    }

    case 2:
    {
        main();
    }

    default:
        cout << "\n\n Invalid choice \n";
    }
}