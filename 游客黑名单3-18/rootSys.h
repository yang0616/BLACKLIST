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

    }

    void Delete()
    {

    }

    void Update()
    {

    }

    void Select()
    {

    }
};
