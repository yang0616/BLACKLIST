#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

class Node_data
{
private:
public:
    char _name[51];
    char _id[21];
    char _string[101];
    char _data[51];
    char _limit[51];
    Node_data* _next;
};

class List_data
{
private:
public:
    Node_data* _head;
    Node_data* _last;

    void Show();

    List_data()
    {
        _head = new Node_data();
        _last = _head;
    }

    ~List_data()
    {
        while(1)
        {
            Node_data*p = _head;
            if(p == _last)
            {
                break;
            }
            _head = _head->_next;
            delete p;
        }
    }
    
    int add_Node(char* name, char* id, char* string, char* data, char* limit);
    int delet(char* id);
    int updata(char* id);
    int show(char*);

};
int List_data::add_Node(char* name, char* id, char* string, char* data, char* limit)
{
    strcpy(_last->_name, name);
    strcpy(_last->_id, id);
    strcpy(_last->_string, string);
    strcpy(_last->_data, data);
    strcpy(_last->_limit, limit);

    Node_data* tmp = new Node_data();
    _last->_next = tmp;
    _last = _last->_next;

    return 1;
}

int List_data::delet(char* id)
{
     Node_data* p =  _head;
     if(strcmp(p->_id, id) == 0)
     {
         Node_data* tmp = _head;
         delete tmp;
         _head = _head->_next;
         return 1;
     }
     else
     {
        while(p->_next != _last)
        {
            if(strncmp(p->_next->_id, id, 18) == 0)
            {
                break;
            }
            else
            {
                p = p->_next;
            }
        }
     }
     if( p == _last)
     {
         return 0;
     }
     else
     {
        Node_data* s = p->_next;
        p->_next = s->_next;
        delete s;
        return 1;
     }
}

int List_data::updata(char* id)
{
     Node_data* p = _head;
     while( p != _last)
     {
         if(strncmp(p->_id, id ,18) == 0)
         {
             break;
         }
         else
         {
            p = p->_next;
         }
     } 
     if( p == _last)
     {
         return 0;
     }
     else
     {
        cout << "please choice that which you want to change!" << endl;
        cout << "n:name"<< endl;
        cout << "i:id" << endl;
        cout << "s:string" << endl;
        cout << "d:data" << endl;
        cout << "l:limit" << endl;
        char symbol[4];
        fgets(symbol, 3, stdin);
        
        cout << "please enter the modified content!"<< endl;
    
        char change[101];
        fgets(change, 100, stdin);

        int len = strlen(change);

        if( strncmp(symbol, "n" , 1) == 0)
        {
            memset(p->_name, 0, sizeof(p->_name));
            strncpy(p->_name, change, len);
        }
        else if(strncmp(symbol, "i", 1) == 0)
        {
            memset(p->_id, 0, sizeof(p->_id));
            strncpy(p->_id, change, len);
        }
        else if(strncmp(symbol, "s", 1) == 0)
        {
            memset(p->_string, 0, sizeof(p->_string));
            strncpy(p->_string, change, len);
        }
        else if(strncmp(symbol, "d", 1) == 0)
        {
            memset(p->_data, 0, sizeof(p->_data));
            strncpy(p->_data, change, len);
        }
        else if(strncmp(symbol, "l", 1) == 0)
        {
            memset(p->_limit, 0, sizeof(p->_limit));
            strncpy(p->_limit, change, len-1);
        }
        else
        {
            return 0;
        }
        return 1;
    }
}

int List_data::show(char* id)
{
    Node_data* p = _head;
    while(p != _last)
    {
        if(strncmp(p->_id, id, 18) == 0)
        {
            break;
        }
        else
        {
            p = p->_next;
        }
    }
    if(p == _last)
    {
        return 0;
    }
    else
    {
        cout << "name   :" << p->_name << endl;
        cout << "id     :" << p->_id << endl;
        cout << "string :" << p->_string << endl;
        cout << "data   :" << p->_data << endl;
        cout << "limit  :" << p->_limit << endl;
        return 1;
    }
}


