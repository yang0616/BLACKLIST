#include <iostream>
using namespace std;
#include "model.h"

class Control
{
private:
    Model _model;
public:
    void process();
    
};
void Control::process()
{
    while(1)
    {
        cout <<"please enter the letter correponding to the operation!" << endl;
        cout << "I:insert" << endl;
        cout << "D:delete" << endl;
        cout << "U:updata" << endl;
        cout << "S:select" << endl;
        cout << "E:end" <<endl;

        char c[6] = {0};
        fgets(c, 5, stdin);

        if(strncmp(c, "E", 1) == 0)
        {
            break;
        }

        Fun fun = _model.search(c[0]);
        if(fun == NULL)
        {
            cout << "sorry,the parament is error!" << endl;
            sleep(1);
        }
        else
        {
            View view;
            (view.*fun)();
        }
    }
    return;
}
