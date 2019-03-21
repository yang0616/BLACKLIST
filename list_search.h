#include <iostream>
using namespace std;
#include "view.h"
typedef void(View::*Fun)();

class Node_search
{
private:
public:
    char _c;
    Fun _fun;
    Node_search* _next;
};

class List_search
{
private:
    View _view;
public:
    Node_search* _head;

    void Init(Node_search* node, char c, Fun fun, Node_search* _next);
    
    List_search()
    {
        Node_search* s = new Node_search();
        Fun p_s = &View::select;
        Init(s, 'S',p_s, NULL);

        Node_search* u = new Node_search();
        Fun p_u = &View::updata;
        Init(u, 'U', p_u, s);

        Node_search* d = new Node_search();
        Fun p_d = &View::delet;
        Init(d, 'D', p_d, u);

        Node_search* i = new Node_search();
        Fun p_i = &View::insert;
        Init(i, 'I', p_i, d);

        _head = i;
    }

    ~List_search()
    {
        while(1)
        {
            Node_search* p = _head;
            if(p == NULL)
            {
                break;
            }
            _head = _head->_next;
            delete p;
        }
    }
};

void List_search::Init(Node_search* node, char c, Fun fun, Node_search* next)
{
    node->_c = c;
    node->_fun = fun;
    node->_next = next;
}



