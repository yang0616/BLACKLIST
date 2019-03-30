#include <iostream>
#include "selectPthread.h"
#include "recvPthread.h"
using namespace std;

class rootSys
{
public:
    void put()
    {
        cout << "please choice you want: ";
        cout << "I: insert" << endl;
        cout << "D: delete" << endl;
        cout << "S: select" << endl;
        cout << "U: update" << endl;
    }

    void run()
    {
        selectPthread* selectpthread = new selectPthread();
        recvPthread* recvpthread  = new recvPthread();
        while(1)
        {
            put();
            char tmp;
            cin << tmp;
            
            switch(tmp)
            {
                case I:
                    Insert();break;
                case D:
                    Delete();break;
                case U:
                    Update();break;
                case S:
                    Select();break;
                default:
                    cout << "enter error!" << endl;break;
            }
        }
    }

    void Insert()
    {
        char age[2] = "0";
        char sex[2] = "0";
/*      char id[19] = "0";
        char name[21] = "0";
        char limit[21] = "0";
        char event[101] = "0";
        cout << "enter name: ";  cin << name; 
*/      cout << "enter age: ";   cin << age;
        cout << "enter sex: ";   cin << sex;
/*      cout << "enter id: ";    cin << id;
        cout << "enter limit: "; cin << limit;
        cout << "enter event: "; cin << event;
*/
        Json::Value val;
        val["TYPE"] = "Insert";
        val["AGE"] = age;
        val["SEX"] = sex;
        Client::getClient()->Send(val.tostyleString.c_str());
    }

    void Delete()
    {
        char id[19] = "0";
        cout << "enter id: ";    cin << id;
        
        Json::Value val;
        val["TYPE"] = "Delete";
        val["ID"] = id;
        Client::getClient()->Send(val.tostyleString.c_str());
    }

    void Update()
    {
        char id[19] = "0";
        cout << "enter id" << endl;
        cin >> id;

        cout << "please choice you want" << endl;
        cout << "N: name";   
        cout << "A: age";   
        cout << "S: sex";   
        cout << "I: id";    
        cout << "L: limit"; 
        cout << "E: event"; 
        //cout << "X: exit";

        char tmp;  
        cin >> tmp;

        Json::Value val;
        val["TYPE"] = "Update";
        val["ID"] = id;

        int flag = 0;
        cout << "enter change: ";
        switch(tmp)
        {
            case N:
                char name[21] = "0"; cin >> name;
                val["NAME"] = name;
                break;
            case A:
                char age[2] = "0"; cin >> age;
                val["AGE"] = age;
                break;
            case S:
                char sex[2] = "0"; cin >> sex;
                val["SEX"] = sex;
                break;
            case I:
                char new_id[19] = "0"; cin >> new_id;
                val["NEW_ID"] = new_id;
                break;
            case L:
                char limit[21] = "0"; cin >> limit;
                val["LIMIT"] = limit;
                break;
            case E:
                char event[101] = "0"; cin >> event;
                val["EVENT"] = event;
                break;
            default:
                flag = 1;
                break;
        }

        if(flag == 1)
        {
            cout << "enter error !" << endl;
            return;
        }

        Client::getClient()->Send(val.tostyleString.c_str());
    }

    void Select()
    {
        char id[19] = "0";
        cout << "enter id" << endl;
        cin >> id;

        Json::Value val;
        val["TYPE"] = "Select";
        val["ID"] = id;
        val["FD"] = "-1";

        Client::getClient()->Send(val.tostyleString.c_str());
    }
};
