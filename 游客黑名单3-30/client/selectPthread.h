#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <event.h>
#include <errno.h>
#include "client.h"
#include "server.h"
using namespace std;

class selecterpthread
{
public:
    struct event_base* _base;

    static void cli_cb(int cli_fd, short event, void* arg)
    {
        struct event_base* cli_base = (struct event_base*)arg;
        char fd[5] = "0";
        itoa(cli_fd, fd, 10);

        string id;
        Server::getServer()->Recv(cli_fd, id);

        Json::Value value;
        value["TYPE"] = "Select";
        value["ID"] = id;
        value["FD"] = fd;

        Client::getClient()->Send(val.toStyledString);
    }

    static void listen_cb(int fd, short event, void* arg)
    {
        struct event_base* base = (struct event_base*)arg;

        struct sockaddr_in caddr;
        int cli_fd = accept(fd, (struct sockaddr*)&caddr, &sizeof(caddr));
        if(-1 == cli_fd)
        {
            cerr << "accept error(selectPthread): "<< errno<<  endl;
            return;
        }

        struct event* cli_event = event_new(base, cli_fd, EV_READ, cli_cb, base);
        if(NULL == cli_event)
        {
            cerr << "cli event creat error(selectPthread): " << errno << endl;
            return;
        }

        event_add(cli_event, NULL);
    }

    selectPthread()
    {
        _base =  event_base_new();
        pthread_t id;
        pthread_creat(&id, NULL, work_thread, _base);
    }

    static void* work_thread(void* arg)
    {
        struct event_base* base = (struct event_base*)arg;
        struct enent* listen_event = event_new(base, Server::getServer()->getListenFd(), EV_READ|EV_PERSIST, listen_cb, base);
        event_add(listen_event, NULL);
        event_base_dispatch(base);
    }
};
