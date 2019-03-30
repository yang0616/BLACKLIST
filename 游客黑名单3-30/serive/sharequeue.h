#include <iostream>
#include <queue>
using namespace std;

class ShareQueue
{
public:
    ShareQueue* getShareQueue()
    {
        if(_shareQueue == NULL)
        {
            //lock
            if(_shareQueue == NULL)
            {
                _shareQueue = new ShareQueue();
            }
            //unlock
        }
        return _shareQueue;
    }

    void push(pair<int, string> data)
    {
        _queue.push(data);
    }

    pair<int, string> top()
    {
        pair<int, string> data;

        lock()
        while(_queue.empty())
        {
            sleep(1);
        }

        data = _queue.top();
        _queue.pop();
        unlock();

        return data;
    }
private:
    static ShareQueue* _shareQueue;
    queue<pair<int, string>> _queue;
};
ShareQueue* ShareQueue:: _shareQueue = NULL;
