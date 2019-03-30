#include <iostream>
#include <string.h>
#include "client.h"
#include "server.h"
using namespace std;

class recverPthread
{
public:
    recvPthread()
    {
        pthread_t id;
        pthread_creat(&id, NULL, work_thread, NULL);
    }

    static void* work_thread(void* arg)
    {
        while(1)
        {
            string str;
            Client::getClient()->Recv(str);

            Json::Value value;
            Json::Reader reader;

            if(-1 == reader.parse(str,value))
            {
                cout << "Json error!" << endl;
                return NULL;
            }
            
            char type[10] = value["TYPE"];
            char fd[5] = value["FD"];
            char reason[101] = value["REASON"];
            if((strcpy(type, "SELECT\0") == 0) && (strcpy(fd, "-1\0") != 0))
            {
                int new_fd = fd[0] - '0';
                for(int i = 1; fd[i] != '/0'; i++)
                {
                    new_fd = new_fd * 10 + (fd[i] - '0');
                }

                Server::getServer()->Send(new_fd, reason);
            }
            else
            {
                cout << reason << endl;
            }
        }
    }
};
