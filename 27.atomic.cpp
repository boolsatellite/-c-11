//
// Created by satellite on 20/05/2023.
//

//#define code_6_18
//#define code_6_19
//#define code_6_20


#ifdef code_6_18
#include <pthread.h>
#include <iostream>
using namespace std;
static long long total=0;
pthread_mutex_t m=PTHREAD_MUTEX_INITIALIZER;
void*func(void*){
    long long i;
    for(i=0;i<100000000LL;i++){
        pthread_mutex_lock(&m);
        total+=i;
        pthread_mutex_unlock(&m);
    }
}
int main(){
    pthread_t thread1,thread2;
    if(pthread_create(&thread1,NULL,&func,NULL)){
        throw;
    }
    if(pthread_create(&thread2,NULL,&func,NULL)){
        throw;
    }
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    cout<<total<<endl;//9999999900000000
    return 0;
}
#endif

#ifdef code_6_19
#include <atomic>
#include <thread>
#include <iostream>
using namespace std;

atomic_llong total{0};//原子数据类型
void func(int){
    for(long long i=0;i<100000000LL;++i){
        total+=i;
    }
}

int main(){
    thread t1(func,0);
    thread t2(func,0);
    t1.join();
    t2.join();
    cout<<total<<endl;//9999999900000000
    return 0;
}
#endif

#ifdef code_6_20
#include <thread>
#include <atomic>
#include <iostream>
#include <unistd.h>
using namespace std;
std::atomic_flag lock=ATOMIC_FLAG_INIT;
void f(int n){
    while(lock.test_and_set(std::memory_order_acquire))//尝试获得锁
        cout<<"Waiting from thread"<<n<<endl;//自旋
    cout<<"Thread"<<n<<"starts working"<<endl;
}
void g(int n){
    cout<<"Thread"<<n<<"is going to start."<<endl;
    lock.clear();
    cout<<"Thread"<<n<<"starts working"<<endl;
}
int main(){
    lock.test_and_set();
    thread t1(f,1);
    thread t2(g,2);
    t1.join();
    usleep(100);
    t2.join();
}

#endif



#include "vector"

int main()
{
    std::vector<int> vi;
}





