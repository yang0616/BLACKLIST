#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

class Client
{
public:
    static Client* getClient()
    {
        if( NULL == _client)
        {
            //lock();
            if(NULL == _client)
            {
                _client = new Client();
            }
            //unlock();
        }
        return _client;
    }

    int Send(const string& str)
    {
        int return_send = _tcpClient->sendToServer(str);
        if(return_send == 1)
        {
            return 1;
        }
        return 0;
    }
    
    int  Recv(string& str)
    {
        int return_recv = _tcpClient->recvFromServer(str);
        if(return_recv == 1)
        {
            return 1;
        }
        return 0;
    }

    void close()
    {
        return _tcpClient->close();
    }

    int getFd()
    {
        reutrn _tcpClient->getFd();
    }

private:
    static Client* _client;
    TcpClient* _tcpClient;

    Client()
    {
        string ip;
        unsigned int port;

        cin >> ip;
        cin >> port;

        _tcpClient = new TcpClient(ip, port);
    }
};
Client* Client::_client = NULL;
