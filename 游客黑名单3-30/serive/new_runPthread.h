#include <iostream>
#include <fcntl.h>
#include "shareQueue.h"
#include "control.h"
using namespace std;

clacc RunPthread
{
public:
    RunPthread()
    {
        pthread_t id;
        pthread_creat(&id, NULL, work_pthread, NULL);
    }

    static void* work_pthread(void* arg)
    {
        while(1)
        {
            pair<int, string> data = ShareQueue::getShaerQueue()->top();
            Contral::getContral()->process(data.first, data.second);
        }
    }
};
