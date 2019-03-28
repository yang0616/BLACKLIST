#include <iostream>
#include <Client.h>
using namespace std;

class Sys
{
public:
    rootSys* _rootSys;

    Sys()
    {
        _rootSys = new rootSys();
    }

    void put()
    {
         cout << "please enter you want: " << endl;
         cout << "L -> login" << endl;
         cout << "R -> regist" << endl;
         cout << "E -> exit" << endl;
    }

    void run()
    {
        while(1)
        {
            put();
            char tmp;
            cin << tmp;
            if(tmp == 'E')
            {
                cout << "exit system....." << endl;
                break;
            }
            switch(tmp)
            {
                case L:
                    login();break;
                case R:
                    regist();break;
                default:
                    cout << "please choice again: "; break;
            }
        }
    }

    void login()
    {
        char username[19] = "0";
        char password[19] = "0";

        cout << "username: ";
        cin >> username;

        cout << "password: ";
        cin >> password;

        Json::Value val;
        val["TYPE"] = "Login";
        val["NAME"] = username;
        val["PW"] =password;
        Client::getClient()->Send(val.toStyledString().c_str());

        string answer;
        Client::getClient()->Recv(str);
        Json::Value value;
        Josn::Reader reader;
        if(reader.parse(answer, value))
        {
            if(value["ANSWER"] == "ok")
            {
                _rootSys->run();
            }
            else
            {
                cout << "sorry: answer error"<< endl;
            }
        }
        else
        {
            cout << "sorry: recv json error" << endl;
        }
    }

    void regist()
    {
        
        char username[19] = "0";
        char password[19] = "0";
        char confirm_password[19] = "0";

        cout << "set username: ";
        cin >> username;

        cout << "set password: ";
        cin >> password;

        cout << "enter password again: ";
        cin >> confirm_password;

        if(strcmp(password, confirm_password) != 0)
        {
            cout << "sorry: password error!"<< endl;
            return;
        }

        Json::Value val;
        val["TYPE"] = "Regist";
        val["NAME"] = username;
        val["PW"] =password;
        Client::getClient()->Send(val.toStyledString().c_str());

        string answer;
        Client::getClient()->Recv(str);
        Json::Value value;
        Josn::Reader reader;
        if(reader.parse(answer, value))
        {
            if(value["ANSWER"] == "ok")
            {
                cout << "successful: regist ok!" << endl;
            }
            else
            {
                cout << "sorry: answer error"<< endl;
            }
        }
        else
        {
            cout << "sorry: recv json error" << endl;
        }
    }
};
