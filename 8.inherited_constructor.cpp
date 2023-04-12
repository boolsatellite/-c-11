//
// Created by satellite on 2023-04-12.
//

#include "iostream"
using namespace std;

/*
struct A
{
    A(int i){}
};

struct B : A
{
    B(int i): A(i) {}   //B在构造函数中调用A的构造函数，完成构造函数的传递
};
*/


/*
 * 我们的基类可能拥有数量众多的不同版本的构造函数
 * 倘若基类中有大量的构造函数，而派生类只有一些成员函数时
 * 那么对于派生类而言，其构造就等同于构造基类，这是无聊的
 * 如下例子：
 * */
/*struct A{
    A(int i){}
    A(double d,int i){}
    A(float f,int i,const char*c){}
//...
};
struct B:A{
    B(int i):A(i){}
    B(double d,int i):A(d,i){}
    B(float f,int i,const char*c):A(f,i,c){}
//...
    virtual void ExtraInterface(){}
};*/


//在C++中已经有了一个好用的规则，就是如果派生类要使用
//基类的成员函数的话，可以通过 using 声明（using-declaration）来完成

/*struct Base{
    void f(double i){cout<<"Base:"<<i<<endl;}   //基类和派生类拥有同名的函数，但是参数不同
};
struct Derived:Base{
    using Base::f;
    //声明派生类也使用基类版本的f
    //这样派生类就拥有了两个版本的f函数
    void f(int i){cout<<"Derived:"<<i<<endl;}
    //若不使用using引入基类的f函数则派生类的f函数将会覆盖基类的f函数，那么使用派生类调用f函数永远只能调用派生类版本
};
int main()
{
    Base b;
    b.f(4.5);//Base:4.5
    Derived d;
    d.f(4.5);//Base:4.5
    d.f(1);  //Derived:1
}*/



/*在C++11中，这个想法被扩展到了构造函数上。子类可以通过使用
using声明来声明继承基类的构造函数。*/


/*struct A{
    A(int i){}
    A(double d,int i){}
    A(float f,int i,const char*c){}
//...
};
struct B:A{
    using A::A;//继承构造函数
//...
    virtual void ExtraInterface(){}
};*/

/*
 * using A::A 将基类的构造函数全部继承到派生类B中，这样就不需要穿透构造函数了
 * c++11标准将继承构造函数设计为与派生类中各种默认函数(默认构造，析构，拷贝)一样，是隐式声明的
 * 这意味着如果一个继承构造函数不被相关代码使用，编译器不会为其产生真正的函数代码
 * 不过继承构造函数只会初始化基类中成员变量，对于派生类中的成员变量，则无能为力
 * */


struct A{
    A(int i){}
    A(double d,int i){}
    A(float f,int i,const char*c){}
//...
};
struct B:A{
    using A::A;
    int d{0};
};
int main(){
    B b(356.1,33);//b.d被初始化为0
}



//寄：看不懂了