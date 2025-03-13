#include <iostream>
#include "clsLoginScreen.h"
//#include "clsMainScreen.h"

int main()

{

    //clsMainScreen::ShowMainMenue();
    while (true) {

       // clsLoginScreen::ShowLoginScreen();
        if (!clsLoginScreen::ShowLoginScreen()) {

            break;
        }

    }

   
    return 0;
}