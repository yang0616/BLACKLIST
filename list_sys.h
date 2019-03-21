#include <iostream>
#include <string.h>
using namespace std;

class Node_Sys
{
private:
public:
    char _name[11];
    char _pw[11];
    Node_Sys* _next;
};


class List_Sys
{
private:
public:
    Node_Sys* _head;
    Node_Sys* _last;

    List_Sys()
    {
        _head = new Node_Sys();
        _last = _head;
    }

    ~List_Sys()
    {
        while(_head != _last)
        {
            Node_Sys* p = _head;
            _head = _head->_next;
            delete p;
        }
    }

    int Add_Node(char* name, char*pw);
    int Judge(char* name);
    int Delet_Node(char* name, char* pw);
};
int List_Sys::Judge(char* name)
{
    Node_Sys* new_head = _head;
    while(new_head != _last)
    {
        if(strcmp(new_head->_name, name) == 0)
        {
            break;
        }
        else
        {
            new_head = new_head->_next;
        }
    }
    if(new_head == _last)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int List_Sys::Delet_Node(char* name, char* pw)
{
    Node_Sys* new_head = _head;
    if( strcmp(new_head->_name, name) == 0)
    {
        delete new_head;
        _head = _head->_next;
        return 1;
    }
    else
    {
        while(new_head->_next != _last)
        {
            if(strcmp(new_head->_next->_name, name)  == 0)
            {
                break;
            }
            else
            {
                new_head = new_head->_next;
            }
        }
        if(new_head->_next == _last)
        {
            return 0;
        }
        else
        {
            Node_Sys* new_next = new_head->_next;
            new_head->_next = new_next->_next;
            delete new_next;
            return 1;
        }
    }
}

int List_Sys::Add_Node(char* name, char*pw)
{
    if(Judge(name))
    {
        strcpy(_last->_name ,name);
        strcpy(_last->_pw, pw);
        Node_Sys* tmp = new Node_Sys();
        _last->_next = tmp;
        _last = _last->_next;
        return 1;
    }
    else
    {
        return 0;
    }
}
