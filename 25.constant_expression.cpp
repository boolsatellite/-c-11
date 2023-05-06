//
// Created by satellite on 5/6/2023.
//

//#define code_6_1
//#define code_6_2
//#define code_6_3
//#define code_6_4
//#define code_6_5
//#define code_6_6
//#define code_6_7
#define code_6_8

#ifdef code_6_1
const int GetConst() { return 1; }

void Constless(int cond) {
    int arr[GetConst()] = {0};//无法通过编译
    enum {
        e1 = GetConst(), e2
    };//无法通过编译
    switch (cond) {
        case GetConst()://无法通过编译
            break;
        default:
            break;
    }
}
#endif

#ifdef code_6_2
#include "typeinfo"
#include "iostream"
enum BitSet{
    V0=1<<0,
    V1=1<<1,
    V2=1<<2,
    VMAX=1<<3
};
//重定义操作符"|",以保证返回的BitSet值不超过枚举的最大值
const BitSet operator|(BitSet x,BitSet y){
    return static_cast<BitSet>(((int)x|y)&(VMAX-1));
}
template<int i=V0|V1>//无法通过编译
void LikeConst(){}
#endif

#ifdef code_6_3
constexpr int f();   //只声明不定义
int a=f();
const int b=f();
constexpr int c=f();//无法通过编译
constexpr int f(){return 1;}  //定义
constexpr int d=f(); //可以通过编译
#endif

#ifdef code_6_4
struct MyType{
    constexpr MyType(int x):i(x){}
    int i;
};
constexpr MyType mt={0};
#endif


#ifdef code_6_5
#include <iostream>

using namespace std;

struct Date {
    constexpr Date(int y, int m, int d) :
            year(y), month(m), day(d) {}

    constexpr int GetYear() { return year; }

    constexpr int GetMonth() { return month; }

    constexpr int GetDay() { return day; }

private:
    int year;
    int month;
    int day;
};

constexpr Date PRCfound{1949, 10, 1};
constexpr int foundmonth = PRCfound.GetMonth();

int main() { cout << foundmonth << endl; }//10
#endif


#ifdef code_6_6
struct NotLiteral {
    NotLiteral() { i = 5; }
    int i;
};

NotLiteral nl;

template<typename T>
constexpr T ConstExp(T t) {
    return t;
}

void g() {
    NotLiteral nl;
    NotLiteral nl1 = ConstExp(nl);
    constexpr NotLiteral nl2 = ConstExp(nl);//无法通过编译
    constexpr int a = ConstExp(1);
}
#endif


#ifdef code_6_7

#include <iostream>
using namespace std;

constexpr int Fibonacci(int n) {
    return (n == 1) ? 1 : ((n == 2) ? 1 : Fibonacci(n - 1) + Fibonacci(n - 2));
}

int main() {
    int fib[] = {
            Fibonacci(11), Fibonacci(12),
            Fibonacci(13), Fibonacci(14),
            Fibonacci(15), Fibonacci(16)
    };
    for (int i: fib)cout << i << endl;
}

#endif


#ifdef code_6_8

#include <iostream>

using namespace std;
template<long num>
struct Fibonacci {
    static const long val = Fibonacci<num - 1>::val + Fibonacci<num - 2>::val;
};

template<>
struct Fibonacci<2> {
    static const long val = 1;
};
template<>
struct Fibonacci<1> {
    static const long val = 1;
};
template<>
struct Fibonacci<0> {
    static const long val = 0;
};

int main() {
    int fib[] = {
            Fibonacci<11>::val, Fibonacci<12>::val,
            Fibonacci<13>::val, Fibonacci<14>::val,
            Fibonacci<15>::val, Fibonacci<16>::val,
    };
    for (int i: fib)cout << i << endl;
}

#endif








