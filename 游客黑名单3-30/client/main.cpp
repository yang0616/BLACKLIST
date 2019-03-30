#include <iostream>
#include <sys.h>
using namespace std;

enum TYPE
{
    Login,
    Regist,
    Inster,
    Select,
    Update,
    Delete,
    Exit;
}

int main()
{
    Sys sys;
    sys.run();
    return 0;
}

