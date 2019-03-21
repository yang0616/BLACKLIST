#include <iostream>
using namespace std;

#include "list_search.h"

class Model
{
private:
    List_search _list;    
public:
    Fun search(char c);
};
Fun Model::search(char c)
{
    Node_search* p = _list._head;
    while( p != NULL)
    {
        if( p->_c == c)
        {
            break;
        }
        else
        {
            p = p->_next;
        }
    }
    if(p == NULL)
    {
        return NULL;
    }
    else
    {
        return p->_fun;
    }
}
