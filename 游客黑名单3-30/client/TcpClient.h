#include <iostream>
#include <unistd.h>
#include <assert.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <string.h>

using namespace std;

class TcpClient
{
private:
    string _ip;
    unsigned short _port;
    int _fd;
public:
    TcpClient(string ip, unsigned short port)
    {
        _ip = ip;
        _port = port;
        _fd = socket(AF_INET, SOCK_STREAM, 0);
        assert(_fd != -1);

        struct sockaddr_in saddr;
        memset(&saddr, 0, sizeof(saddr));
        saddr.sin_family = AF_INET;
        saddr.sin_port = _port;
        saddr.sin_addr.s_addr = inet_addr(_ip);

        int res = connect(_fd, (struct sockaddr*)&saddr, sizeof(saddr));
        assert(res != -1);
    }

    int sendToServer(string& str)
    {
        char tmp[1024] = "0";
        strcpy_s(tmp, str);
        int return_send = send(_fd, tmp, strlen(tmp), 0);
        if(return_send == -1)
        {
            return 0;
        }
        return 1;
    }

    int recvFromServer(string& str)
    {
        char tmp[1024] = "0";
        int return_recv = recv(_fd, tmp, 1024, 0);
        if(return_recv == -1)
        {
            return 0;
        }
        str = tmp;
        show(str);
        return 1;
    }

    void close()
    {
        close(_fd);
    }

    void show(const string str)
    {
        string :: iterator it = str.begin();
        cout << "RECV: ";
        for(it; it != str.end(); it++)
        {
            cout << *it;
        }
        cout << endl;
    }

    int getFd()
    {
        return _fd;
    }
};
