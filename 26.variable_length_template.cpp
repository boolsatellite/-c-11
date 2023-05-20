//
// Created by satellite on 7/05/2023.
//

//变长模板

//#define code_6_9
//#define code_6_10
//#define code_6_11
//#define code_6_12
//#define code_6_13
//#define code_6_14
#define code_6_15

#include <stdio.h>
#include "tuple"
#include "iostream"
#include <stdarg.h>
#include "string"

using namespace std;
#ifdef code_6_9
double SumOfFloat(int count,...){
    va_list ap;
    double sum=0;
    va_start(ap,count);//获得变长列表的句柄ap
    for(int i=0;i<count;i++)
    sum+=va_arg(ap,double);//每次获得一个参数
    va_end(ap);
    return sum;
}
int main(){
    printf("%f\n",SumOfFloat(3,1.2f,3.4,5.6));//10.200000

}
#endif

#ifdef code_6_10
template<typename...Elements>class tuple;//变长模板的声明
template<typename Head,typename...Tail>//递归的偏特化定义
class tuple<Head,Tail...>:private tuple<Tail...>{
Head head;
};
template<>class tuple<>{};//边界条件

int main()
{
    tuple<int, double,float> t;
    //t.head = 20;
    return 0;
}

#endif

#ifdef code_6_11
template<long...nums>struct Multiply;    //接受非类型参数的变长模板类Multiply

template<long first,long...last>
struct Multiply<first,last...>{
static const long val=first*Multiply<last...>::val;
};

template<>
struct Multiply<>{
static const long val=1;
};
int main(){
    cout<<Multiply<2,3,4,5>::val<<endl;//120
    cout<<Multiply<22,44,66,88,9>::val<<endl;//50599296
    return 0;
}
#endif


#ifdef code_6_12
#include <stdexcept>
using namespace std;
void Printf(const char*s){
    while(*s){
        if(*s=='%'&&*++s!='%')
        throw runtime_error("invalid format string:missing arguments");
        cout<<*s++;
    }
}
template<typename T,typename...Args>
void Printf(const char*s,T value,Args...args){
    while(*s){
        if(*s=='%'&&*++s!='%'){
            cout<<value;
            return Printf(++s,args...);
        }
        cout<<*s++;
    }
    throw runtime_error("extra arguments provided to Printf");
}
int main(){
    Printf("hello%s\n",string("world"));//hello world
}
#endif

#ifdef code_6_13
template<typename...T>void DummyWrapper(T...t){}
template<typename T>T pr(T t){
    cout<<t;
    return t;
}
template<typename...A>
void VTPrint(A...a){
    DummyWrapper(pr(a)...);//包扩展解包为pr(1),pr(",")...,pr(",abc\n")
};
int main(){
    VTPrint(1,",",1.2,",abc\n");
}
#endif

#ifdef code_6_14

#include <cassert>
#include <iostream>

using namespace std;

template<class...A>
void Print(A...arg) {
    assert(false);//非6参数偏特化版本都会默认assert(false)
}

//特化6参数的版本
void Print(int a1, int a2, int a3, int a4, int a5, int a6) {
    cout << a1 << "," << a2 << "," << a3 << ","
         << a4 << "," << a5 << "," << a6 << endl;
}

template<class...A>
int Vaargs(A...args) {
    int size = sizeof...(A);//计算变长包的长度
    switch (size) {
        case 0:
            Print(99, 99, 99, 99, 99, 99);
            break;
        case 1:
            Print(99, 99, args..., 99, 99, 99);
            break;
        case 2:
            Print(99, 99, args..., 99, 99);
            break;
        case 3:
            Print(args..., 99, 99, 99);
            break;
        case 4:
            Print(99, args..., 99);
            break;
        case 5:
            Print(99, args...);
            break;
        case 6:
            Print(args...);
            break;
        default:
            Print(0, 0, 0, 0, 0, 0);
    }
    return size;
}

int main(void) {
    Vaargs();//99,99,99,99,99,99
    Vaargs(1);//99,99,1,99,99,99
    Vaargs(1, 2);//99,99,1,2,99,99
    Vaargs(1, 2, 3);//1,2,3,99,99,99
    Vaargs(1, 2, 3, 4);//99,1,2,3,4,99
    Vaargs(1, 2, 3, 4, 5);//99,1,2,3,4,5
    Vaargs(1, 2, 3, 4, 5, 6);//1,2,3,4,5,6
    Vaargs(1, 2, 3, 4, 5, 6, 7);//0,0,0,0,0,0
    return 0;
}

#endif

#ifdef code_6_15
template<typename I, template<typename> class...B>
struct Container {
};

template<typename I, template<typename> class A,template<typename> class...B>
struct Container<I, A, B...> {
    A<I> a;
    Container<I, B...> b;   //递归调用
};
template<typename I>
struct Container<I> {
};
#endif






