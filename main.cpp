#include <stdio.h>
#include <iostream>
#include <string.h>
#include "sys.h"
using namespace std;

int main()
{
    Sys sys;
    while(1)
    {
        cout << "please enter the letter correponding to the operation!" << endl;
        cout << "L:login" << endl;
        cout << "O:logout" << endl;
        cout << "N:enroll" << endl;
        cout << "E:exit" << endl;
     
        char reply_buff[6] = {0};
        fgets(reply_buff, 5, stdin);


        if(strncmp(reply_buff, "N", 1) == 0)
        {
            sys.enroll();
        }
        else if(strncmp(reply_buff, "L", 1) == 0)
        {
            sys.login();
        }
        else if(strncmp(reply_buff, "O", 1) == 0)
        {
            sys.logout();
        }
        else if(strncmp(reply_buff, "E", 1) == 0)
        {
            cout << "system exiting......"<< endl;
            break;
        }
        else
        {
            cout << "sorry,parament input error, please select again" << endl;
        }
    }
        exit(0);
}
