//
// Created by satellite on 2023-04-07.
//
#include <iostream>
using namespace std;

/**noexcept  标识的函数若抛出异常则立刻调用调用 terminate 终止当前进程
noexcept（表达式） 表达式会被强转为 bool 类型，为 true 则表示不允许抛出异常，否则表示允许抛出异常*/


/*
void Throw(){throw 1;}
void NoBlockThrow(){Throw();}
void BlockThrow()noexcept{Throw();}
int main(){
    try{
        Throw();
    }
    catch(...){
        cout<<"Found throw."<<endl;//Found throw.
    }
    try{
        NoBlockThrow();
    }
    catch(...){
        cout<<"Throw is not blocked."<<endl;//Throw is not blocked.
    }
    try{
        BlockThrow();//terminate called after throwing an instance of'int'
    }
    catch(...){
        cout<<"Found throw 1."<<endl;
    }
}*/



/**比如一个类析构
函数不应该抛出异常，那么对于常被析构函数调用的delete函数来说，
C++11默认将delete函数设置成noexcept，就可以提高应用程序的安全
性。

C++11标准中让类的析构函数默认也是
noexcept(true)的。当然，如果程序员显式地为析构函数指定了
noexcept，或者类的基类或成员有noexcept(false)的析构函数，析构函
数就不会再保持默认值
*/



struct A{
    ~A(){throw 1;}
};
struct B{
    ~B()noexcept(false){throw 2;}
};
struct C{
    B b;
};
int funA(){A a;}
int funB(){B b;}
int funC(){C c;}
int main(){
    try{
        funB();
    }
    catch(...){
        cout<<"caught funB."<<endl;//caught funB.
    }
    try{
        funC();
    }
    catch(...){
        cout<<"caught funC."<<endl;//caught funC.
    }
    try{
        funA();//terminate called after throwing an instance of'int'
    }
    catch(...){
        cout<<"caught funA."<<endl;
    }
}