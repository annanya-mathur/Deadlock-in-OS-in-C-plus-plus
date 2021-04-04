#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

std::mutex process1Mutex;
std::mutex process2Mutex;


void unlockingP1andP2()
{
       process1Mutex.unlock();
       process2Mutex.unlock();
} 
void incrementP1andP2()    //Here deadlock is removed by accessing the mutex in same order by both the threads thereby unlocking the mutexes before another thread
{  
       
       process1Mutex.lock();
    process2Mutex.lock();
     cout<<"Critical Section of thread 1 and 2"<<endl;
     unlockingP1andP2();
}


int main()
{   thread t1(incrementP1andP2);
    thread t2(incrementP1andP2);
    t1.join();
    t2.join();
   
    
	
	return 0;
}

