#include <iostream>

using namespace std;

enum TYPE
{
    Login,
    Regist,
    Insert,
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
