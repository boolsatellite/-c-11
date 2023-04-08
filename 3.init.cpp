//
// Created by satellite on 2023-04-07.
//


/**在C++98中，支持了在类声明中使用等号“=”加初始值的方式，来初始
化类中静态成员常量，也称为就地声明，
如果静态成员不满足常量性，则不可以就地声明，而且即使常
量的静态成员也只能是整型或者枚举型才能就地初始化,
 而非静态成员变量的初始化则必须在构造函数中进行
 */


/*   c++98
class Init{
public:
    Init():a(0){}
    Init(int d):a(d){}
private:
    int a;
    const static int b=0;
    int c=1;             //成员，无法通过编译
    static int d=0;       //成员，无法通过编译
    static const double e=1.3;    //非整型或者枚举，无法通过编译
    static const char*const f="e";//非整型或者枚举，无法通过编译
};*/


/**在C++11中，标准允许
非静态成员变量的初始化有多种形式。具体而言，除了初始化列表
外，在C++11中，标准还允许使用等号=或者花括号{}进行就地的非静
态成员变量初始化*/

/*
struct INIT
{
private:
    int a = 20;  //c++11对非静态成员变量提供了 = {} 的初始化方式
    double b{1.3};
};
*/



/*

//对于非静态成员类对象的初始化必须使用 = 或 {}
// 若使用 () 有可能被认为是函数定义 (个人猜想，报错中未明确说明)
#include <string>
using namespace std;
struct C{
    C(int i):c(i){};
    int c;
};
struct init{
    int a=1;
    //string b("hello");//无法通过编译,
    string b{"hello"}; //必须使用 {} 初始化
    //C c(1);//无法通过编译
    C c{1};
};
*/



/*
#include <iostream>
using namespace std;
struct Mem{
    Mem(){cout<<"Mem default,num:"<<num<<endl;}
    Mem(int i):num(i){cout<<"Mem,num:"<<num<<endl;}
    int num=2;//使用=初始化非静态成员
};

class Group{
public:
    Group(){cout<<"Group default.val:"<<val<<endl;}
    Group(int i):val('G'),a(i){cout<<"Group.val:"<<val<<endl;}
    void NumOfA(){cout<<"number of A:"<<a.num<<endl;}
    void NumOfB(){cout<<"number of B:"<<b.num<<endl;}
private:
    char val{'g'};//使用{}初始化非静态成员
    Mem a;
    Mem b{19};//使用{}初始化非静态成员
};
int main(){
    Mem member;//Mem default,num:2
    Group group;//Mem default,num:2
//Mem,num:19
//Group default.val:g
    group.NumOfA();//number of A:2
    group.NumOfB();//number of B:19
    Group group2(7);//Mem,num:7
//Mem,num:19
//Group.val:G
    group2.NumOfA();//number of A:7
    group2.NumOfB();//number of B:19
}
*/




//默认值初始化的好处：
#include <string>

using namespace std;

class Mem {
public:
    Mem(int i) : m(i) {}

private:
    int m;
};

class Group {
public:
    Group() {}//这里就不需要初始化data、mem、name成员了
    Group(int a) : data(a) {}//这里就不需要初始化mem、name成员了
    Group(Mem m) : mem(m) {}//这里就不需要初始化data、name成员了
    Group(int a, Mem m, string n) : data(a), mem(m), name(n) {}

private:
    int data = 1;
    Mem mem{0};
    string name{"Group"};
};
