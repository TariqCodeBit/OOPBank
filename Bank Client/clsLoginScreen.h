#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:
    

    static  bool _Login()
    {
        bool LoginFaild = false;
         short _counter = 3;
        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!";
                cout << "\nYou have " <<( --_counter )<< " Trial(s) to login.\n\n";
               
                    
                

        } if (_counter == 0) {
            cout << "\nYour are Locked After 3 Faild Trails \n";
            return false;
        }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);
        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
       return  _Login();

    }

};
