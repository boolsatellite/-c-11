//
// Created by satellite on 2023-04-10.
//
#include <iostream>
using namespace std;
class MathObject{
public:
    virtual double Arith()=0;
    virtual void Print()=0;
};
class Printable:public MathObject{
public:
    double Arith()=0;
    void Print()//在C++98中我们无法阻止该接口被重写
    {
        cout<<"Output is:"<<Arith()<<endl;
    }
};
class Add2:public Printable{
public:
    Add2(double a,double b):x(a),y(b){}
    double Arith(){return x+y;}
private:
    double x,y;
};
class Mul3:public Printable{
public:
    Mul3(double a,double b,double c):x(a),y(b),z(c){}
    double Arith(){return x*y*z;}
private:
    double x,y,z;
};


/**我们的基础类MathObject定义了两个接口：Arith
和Print。类Printable则继承于MathObject并实现了Print接口。接下来，
Add2和Mul3为了使用MathObject的接口和Printable的Print的实现，于
是都继承了Printable。这样的类派生结构，在面向对象的编程中非常
典型。不过倘若这里的Printable和Add2是由两个程序员完成的，
Printable的编写者不禁会有一些忧虑，如果Add2的编写者重载了Print
函数，那么他所期望的统一风格的打印方式将不复存在。*/

//final关键字的作用是使派生类不可覆盖它所修饰的虚函数

/*struct Object{
    virtual void fun()=0;
};
struct Base:public Object{
    void fun()final;//声明为final
};
struct Derived:public Base{
    void fun();//无法通过编译，即无法覆盖基类指定final的虚函数
};*/


/**override,如果基类在虚函数声明时，使用了override描述符，那么该函数必须重载其基类中的
同名函数，否则无法通过编译*/

struct Base{
    virtual void Turing()=0;
    virtual void Dijkstra()=0;
    virtual void VNeumann(int g)=0;
    virtual void DKnuth()const;
    void Print();
};
struct DerivedMid:public Base{
//virtual void VNeumann(double g);
//接口被隔离了，曾想多一个版本的VNeumann函数
};
struct DerivedTop:public DerivedMid{
    void Turing()override;
    void Dikjstra()override;//无法通过编译，拼写错误，并非重载
    void VNeumann(double g)override;//无法通过编译，参数不一致，并非重载
    void DKnuth()  override;//无法通过编译，常量性不一致，并非重载
    //void DKnuth() const override;  保证常量性
    void Print()override;//无法通过编译，非虚函数重载
};
