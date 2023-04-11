//
// Created by satellite on 2023-04-11.
//

//模板函数的默认模板参数

//回顾函数模板的定义

#include "iostream"
using  namespace std;

template<typename T> void TempFunc(T a){
    cout << a <<endl;
}

int main1()
{
    TempFunc(1);    //实例化为 TempFun<const int>(1)
    TempFunc("1");  //实例化为 TempFun<const char *>("1")
}

//模板在c++98 与 c++11 中的支持：

void DefParm(int m=3){}//c++98编译通过，c++11编译通过

template <typename T=int>
class DefClass{};//c++98编译通过，c++11编译通过

template<typename T=int>
void DefTempParm(){};//c++98编译失败，c++11编译通过

//c++11中支持了模板函数的模板参数的默认值
//不过在语法上，与类模板有些不同的是，在为多个
//默认模板参数声明指定默认值的时候，程序员必须遵照“从右往左”的
//规则进行指定。而这个条件对函数模板来说并不是必须的


/*template<typename T1,typename T2=int>class DefClass1;
template<typename T1=int,typename T2>class DefClass2;//无法通过编译,默认参数从右到左
template<typename T,int i=0>class DefClass3;
template<int i=0,typename T>class DefClass4;//无法通过编译，默认参数从右到左

template<typename T1=int,typename T2>void DefFunc1(T1 a,T2 b);
template<int i=0,typename T>void DefFunc2(T a); //对于函数模板来说，默认参数没有位置要求*/



//如果能从函数实参中推导出类型的话，那么默认模板参数就不会被使用

template<class T,class U=double>
void f(T t=0,U u=0);
void g(){
    f(1,'c');//f<int,char>(1,'c')
    f(1);//f<int,double>(1,0),使用了默认模板参数double
    f();//错误:T无法被推导出来
    f<int>();//f<int,double>(0,0),使用了默认模板参数double
    f<int,char>();//f<int,char>(0,0)
}









