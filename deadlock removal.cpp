#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

std::mutex process1Mutex;
std::mutex process2Mutex;

void unlockingP2andP1()            #here deadlock is removed by unlocking the mutex before other thread comes to action
{
       process2Mutex.unlock();
       process1Mutex.unlock();
}
void unlockingP1andP2()
{
       process1Mutex.unlock();
       process2Mutex.unlock();
}
void incrementP1andP2()
{  
       
       process1Mutex.lock();
    process2Mutex.lock();
     cout<<"Critical Section of thread1"<<endl;
     unlockingP1andP2();                               # unlocking before another thread
}

void incrementP2andP1()
{    process2Mutex.lock();
    process1Mutex.lock();
     cout<<"Critical Section of thread2"<<endl;
     unlockingP2andP1();                               # unlocking before another thread
}

int main()
{   thread t1(incrementP1andP2);
    thread t2(incrementP2andP1);
    t1.join();
    t2.join();
   
    
	
	return 0;
}

