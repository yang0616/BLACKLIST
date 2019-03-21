#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

#include "list_data.h"

class Database
{
private:
    static Database* _base;
    List_data _list;
public:
    static Database* Get_Base()
    {
        if(_base == NULL)
        {
            _base = new Database();
        }
        return _base;
    }

    ~Database()
    {
        delete _base;
        _base = NULL;
    }

    void insert(char* name, char* id, char* string, char* data, char* limit);
    void delet(char* id);
    void updata(char* id);
    void select(char* id);
};
Database* Database::_base = NULL;

void Database::insert(char* name, char* id, char* string, char* data, char* limit)
{
    int n =  _list.add_Node(name, id, string, data, limit);
    if(n)
    {
        cout << "successful insert!" << endl;
    }
    else
    {
        cout << "insert error!" << endl;
    }
    return;
}

void Database::delet(char* id)
{
    int n = _list.delet(id);
    if(n)
    {
        cout << "successful delete!" << endl;
    }
    else
    {
        cout << "sorry,delete error!" << endl;
    }
    return;
}

void Database::updata(char* id)
{
    int n = _list.updata(id);
    if(n)
    {
        cout << "successful amend!" << endl;
    }
    else
    {
        cout << "sorry,updata error!" << endl;
    }
    return;
}

void Database::select(char* id)
{
    int n = _list.show(id);
    if(n)
    {
        cout << "successful select!" << endl;
    }
    else
    {
        cout << "sorry, select error!" << endl;
    }
    return;
}

