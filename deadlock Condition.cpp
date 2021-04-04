#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

std::mutex process1Mutex;
std::mutex process2Mutex;

void incrementP1andP2()
{  
       
       process1Mutex.lock();
    process2Mutex.lock();
     cout<<"Critical Section of thread1"<<endl;
}
void unlockingP1andP2()
{
       process1Mutex.unlock();
       process2Mutex.unlock();
}
void incrementP2andP1()
{    process2Mutex.lock();
    process1Mutex.lock();
     cout<<"Critical Section of thread2"<<endl;
}
void unlockingP2andP1()
{
       process2Mutex.unlock();
       process1Mutex.unlock();
}
int main()
{   thread t1(incrementP1andP2);
    thread t2(incrementP2andP1);
    t1.join();
    t2.join();
    unlockingP1andP2();
    unlockingP2andP1();
    
	
	return 0;
}

