#include <iostream>
#include <string.h>
#include <unistd.h>
using namespace std;

class Serive
{
public:
    static Serive* getSerive()
    {
        if(NULL  == _serive)
        {
            //lock()
            if(NULL == _serive)
            {
                _serive = new Serive();
            }
            //unlock()
        }
        return _serive;
    }

    int Send(const string* str)
    {
        int return_send = _tcpSreive->sendToClient(str);
        if(return_send == -1)
        {
            return -1;
        }
        reutrn return_send;
    }

    int Recv(string& str)
    {
        int return_recv = _tcpserive->recvFromClient(str);
        if(return_recv == -1)
        {
            return -1;
        }
        return return_recv;
    }

    void close(int fd)
    {
        return _tcpSerive->closeClient(fd);
    }

    int getListenFd()
    {
        return _tcpSerive->getListenFd();
    }

private:
    static Serive* _serive;
    TcpSerive* _tcpSerive;

    Serive()
    {
        string ip;
        unsigned int port;

        cin << ip;
        cin << port;

        _tcpSerive = new TcpSerive(ip, port);
    }
};
Serive* Serive::_serive = NULL;
