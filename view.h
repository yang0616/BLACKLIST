#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "database.h"

class View
{
private:
public:
    void insert();
    void delet();
    void updata();
    void select();

};

void View::insert()
{
    char name[51] = {0};
    char id[21] = {0};
    char string[101] = {0};
    char data[51] = {0};
    char limit[51] = {0};

    cout << "please enter name!" << endl;
    fgets(name,50, stdin );

    cout << "please enter id!" << endl;
    fgets(id, 20, stdin);

    cout << "please enter string!" << endl;
    fgets(string, 100, stdin);

    cout << "please enter data!" << endl;
    fgets(data, 50, stdin);

    cout << "please enter limit!" << endl;
    fgets(limit, 50, stdin);

    Database::Get_Base()->insert(name, id, string, data, limit);
    return;

}

void View::delet()
{
    char id[21];
    cout << "please enter id!"<< endl;
    fgets(id, 20, stdin);
    Database::Get_Base()->delet(id);
    return;
}

void View::updata()
{
    char id[21];
    cout << "please enter id!"<< endl;
    fgets(id, 20, stdin);
    Database::Get_Base()->updata(id);
    return;
}

void View::select()
{
    char id[21];
    cout << "please enter id!"<< endl;
    fgets(id, 20, stdin);
    Database::Get_Base()->select(id);
    return;
}


