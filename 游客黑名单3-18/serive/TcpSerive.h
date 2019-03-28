#include <iostream>
#include <unistd.h>
#include <assert.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <string>

#define LIST_MAX 5
using namespace std;

class TcpServer
{
private:
    string _ip;
    unsigned short _port;
    int _listenFd;
public:
    TcpServer(string ip, unsigned short port)
    {
        listenFd = socket(AF_INET, SOCK_STREAM, 0);
        assert(sockfd != -1);

        struct sockaddr_in saddr;
        memset(&saddr, 0, sizeof(saddr));
        saddr.sin_family = AF_INET;
        saddr.sin_port = port;
        saddr.sin_addr.s_addr = inet_addr(ip);

        int res = bind(sockfd, (struct sockaddr*)&saddr, sizeof(saddr), 0);
        assert(res != -1);

        listen(listenFd, LIST_MAX);
    }

    int acceptClient()
    {
        struct sockaddr_in caddr;
        int len = sizeof(caddr);
        int c = accept(_listenFd, (struct sockaddr*)&caddr, &len);
        return c;
    }

    int sendToClient(int cliFd, string& str)
    {
        char tmp[1024] = "0";
        strcpy_s(tmp, str.c_str());
        int retur = send(cliFd, tmp, sizeof(tmp), 0);
        if(!retur)
        {
            return 0;
        }
        return 1;
    }

    int recvFrom(int cliFd, string& str)
    {
        char tmp[1024] = "0";
        int retur = recv(cliFd, tmp, 1023, 0);
        if(!retur)
        {
            return 0;
        }
        str = tmp;
        show(str);
        return 1;
    }

    void closeClient(int cliFd)
    {
        cout << "one client over!" << endl;
        close(cliFd);
    }

    void show(const string str)
    {
        string :: iterator it = str.begin();
        cout << "RECV:(cliFd = " << cliFd <<") "; 
        for(itl it != str.end(); it++)
        {
            cout << *it;
        }
        cout << endl;
    }
};
