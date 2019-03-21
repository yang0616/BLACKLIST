#include <iostream>
using namespace std;

#include "list_sys.h"
#include "control.h"

class Sys
{
private:
    List_Sys _list;
public:
    int Add_person(char* name, char* pw);
    void enroll();
    void login();
    void logout();

    char _name[11];
    char _pw[11];

    Sys()
    {
        memset(_name, 0, sizeof(_name));
        memset(_pw, 0, sizeof(_pw));
    }
};

void Sys::logout()
{
    cout << "please enter name that you wang to logout!" << endl;
    fgets( _name, 10, stdin);

    cout << "please enter password!" << endl;
    fgets( _pw, 10, stdin);

    int n = _list.Delet_Node(_name, _pw);
    if(n)
    {
        cout << "successful logout!" << endl;
    }
    else
    {
        cout << "sorry, please ensure name and password!" << endl;
    }
    return;
}

int  Sys::Add_person(char* name, char* pw)
{
    int n = _list.Add_Node(name, pw);
    if(n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Sys::enroll()
{
    char verify[11];
    
    cout << "please set your login name!" << endl;
    fgets( _name, 10, stdin);

    cout << "please set password!" << endl;
    fgets( _pw, 10, stdin);

    cout << "please confirm the password!" << endl;
    fgets(verify, 10, stdin);
  
    if(strcmp( _pw, verify) != 0)
    {
        cout << "sorry, please register again!" << endl;
        sleep(1);
        return;
    }
    else
    {
        int n = Add_person(_name, _pw);
        if(n)
        {
            cout << "successful,enroll!" << endl;
        }
        else
        {
            cout << "sorry,repeat name!" << endl;
        }
        sleep(1);
        return;
    }
}

void Sys::login()
{
    cout << "please enter a login name!" << endl;
    memset(_name, 0, sizeof(_name));
    fgets(_name, 10, stdin);

    cout <<"please enter your login password!" << endl;
    memset(_pw, 0, sizeof(_pw));
    fgets(_pw, 10, stdin);

    Node_Sys* head = _list._head;
    Node_Sys* last = _list._last;

    while(head != last )
    {
        if(( strcmp(head->_name,_name) == 0 ) && ( strcmp(head->_pw, _pw) == 0))
        {
            break;
        }
        else
        {
            head = head->_next;
        }
    }
    if( head == last)
    {
        cout << "sorry,worong name or password!" << endl;
        sleep(1);
        return;
    }
    else
    {
        Control _control;
        cout << "successful,login!" << endl;
        _control.process();
        return;
    }
}
