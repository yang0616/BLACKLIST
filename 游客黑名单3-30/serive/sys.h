#include <iostream>
#include "runPthread.h"
#include "shareQueue.h"
#include "contral.h"
using namespace std;

class Sys
{
public:
    struct event_base* _base;
    Control* _control;

    void cli_cb(int cli_fd, short event, void* arg)
    {
        struct event_base* base = (struct event_base*)arg;

        string recv_str;
        Server::getServer()->Recv(recv_str);
        
        ShareQueue::getShareQueue()->push(make_pair(clifd, recv_str));
    }

    void listen_cb(int listen_fd, short event, void* arg)
    {
        struct event_base* base = (struct event_base*)arg
        ;
        int cli_fd = Server::getServer()->acceptClient();
        struct event* cli_event = 
               event_new(base, cli_fd, EV_READ, cli_cb, base);
        if(NULL == cli_event)
        {
            cerr << "event error(Sys): " << errno << endl;
            return ;
        }

        event_add(cli_event, NULL);
    }

    Sys()
    {
        _control = new Control();
        _base = event_base_new();

        int server_fd = Server::getServer()->getListenFd();
        struct event* listen_event = 
               event_new(_base, server_fd, EV_READ|EV_PERSIST, listen_cb, _base);
       if(NULL == listen_event)
       {
           cerr << "event error(Sys): " << errno << endl;
           return;
       }

       event_add(listen_event, NULL);
       event_base_dispatch(_base);
    }

    void run()
    {
        for(int i = 0; i < 3; i++)
        {
            RunPthread* _runPthread = new RunPthread();
        }
    }
};
