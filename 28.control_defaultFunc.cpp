//
// Created by satellite on 2023-05-21.
//

//默认函数控制

//#define code_7_7
//#define code_7_8
//#define code_7_12
//#define code_7_13
#define code_7_14

#ifdef code_7_7
#include <type_traits>
#include <iostream>
using namespace std;
class TwoCstor{
public:
//提供了带参数版本的构造函数，则必须自行提供
//不带参数版本，且TwoCstor不再是POD类型
    TwoCstor(){};
    TwoCstor(int i):data(i){}
private:
    int data;
};
int main(){
    cout<<is_pod<TwoCstor>::value<<endl;//0
}
#endif


#ifdef code_7_8
#include <type_traits>
#include <iostream>
using namespace std;
class TwoCstor{
public:
//提供了带参数版本的构造函数，再指示编译器
//提供默认版本，则本自定义类型依然是POD类型
    TwoCstor()=default;
    TwoCstor(int i):data(i){}
private:
    int data;
};
int main(){
    cout<<is_pod<TwoCstor>::value<<endl;//1
}
#endif


#ifdef code_7_12
class ConvType{
public:
    ConvType(int i){};
    ConvType(char c)=delete;//删除char版本
};
void Func(ConvType ct){}
int main(){
    Func(3);
    Func('a');//无法通过编译
    ConvType ci(3);
    ConvType cc('a');//无法通过编译
}
#endif


#ifdef code_7_13
class ConvType{
public:
    ConvType(int i){};
    explicit ConvType(char c)=delete;//删除explicit的char构造函数
};
void Func(ConvType ct){}
int main(){
    Func(3);
    Func('a');//可以通过编译
    ConvType ci(3);
    ConvType cc('a');//无法通过编译
}
#endif

#ifdef  code_7_14
#include <cstddef>
#include <new>
extern void*p;
class NoStackAlloc{
public:
    ~NoStackAlloc()=delete;
};
int main(){
    NoStackAlloc nsa;//无法通过编译
    new(p)NoStackAlloc();//placement new,假设p无需调用析构函数
    return 1;
}

#endif

