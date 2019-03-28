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
    }
    return _client;
private:
    Client()
    {
        cin >> ip;
        cin >> port;
        _tcpClient = new TcpClient(ip, port);
    }
    static Client* _client;
    TcpClient* _tcpClient;
};
Client* Client::_client = NULL;
