//
// Created by satellite on 2023-04-18.
//


//显式转换操作符

//#define explicit_construct
//#define operator_overload
//#define explicit_operator_overload

#include <iostream>

using namespace std;

#ifdef explicit_construct
struct Rational1{
    Rational1(int n=0,int d=1):num(n),den(d){  //没有使用explicit修饰可以被隐式构造
        cout<<__func__<<"("<<num<<"/"<<den<<")"<<endl;
    }
    int num;//Numerator（被除数）
    int den;//Denominator（除数）
};

struct Rational2{
    explicit Rational2(int n=0,int d=1):num(n),den(d){  //使用explicit修饰，隐式转换被禁止
        cout<<__func__<<"("<<num<<"/"<<den<<")"<<endl;
    }
    int num;
    int den;
};
void Display1(Rational1 ra){
    cout<<"Numerator:"<<ra.num<<"Denominator:"<<ra.den<<endl;
}
void Display2(Rational2 ra){
    cout<<"Numerator:"<<ra.num<<"Denominator:"<<ra.den<<endl;
}
int main(){
    Rational1 r1_1=11;//Rational1(11/1)
    Rational1 r1_2(12);//Rational1(12/1)
    Rational2 r2_1=21;//无法通过编译
    Rational2 r2_2(22);//Rational2(22/1)
    Display1(1);//Rational1(1/1)
//Numerator:1 Denominator:1
    Display2(2);//无法通过编译
    Display2(Rational2(2));//Rational2(2/1)
//Numerator:2 Denominator:1
    return 0;
}
#endif

#ifdef operator_overload

//不过同样的机制并没有出现在自定义的类型转换符上。这就允许了一
//个逆向的过程，从自定义类型转向一个已知类型。
//这样虽然出现问题
//的几率远小于从已知类型构造自定义类型，不过有的时候，我们确实
//应该阻止会产生歧义的隐式转换。

template<typename T>
class Ptr{
public:
    Ptr(T*p):_p(p){}

    operator bool()const{
        //此为用户自定义的转化为bool类型的函数，提供了隐式转化方法
        //此函数的作用是判断指针是否有效即使if(p)成立
        //但是这样的转换使 Ptr<int> + Ptr<double> 在语法上被允许，但语义上是毫无作用的
        if(_p!=0)
            return true;
        else
            return false;
    }

private:
    T* _p;
};
int main(){
    int a;
    Ptr<int> p(&a);
    if(p)//自动转换为bool型，没有问题
        cout<<"valid pointer."<<endl;//valid pointer.
    else
    cout<<"invalid pointer."<<endl;
    Ptr<double> pd(0);
    cout<<p+pd<<endl;//1，相加，语义上没有意义
}

#endif

#ifdef explicit_operator_overload

/**在C++11中，标准将explicit的使用范围扩展到了自定义的类型转换操
作符上，以支持所谓的“显式类型转换”。explicit关键字作用于类型转
换操作符上，意味着只有在直接构造目标类型或显式类型转换的时候
可以使用该类型。
 * */


class ConvertTo {
};

class Convertable {
public:
    explicit operator ConvertTo() const //不允许隐式转换
    {
        return ConvertTo();
    }
};

void Func(ConvertTo ct) {}

void test() {
    Convertable c;
    ConvertTo ct(c);//直接初始化，通过
//ConvertTo ct2=c;//拷贝构造初始化，编译失败
    ConvertTo ct3 = static_cast<ConvertTo>(c);//强制转化，通过
//Func(c);//拷贝构造初始化，编译失败
}

#endif



template<typename T>
class Ptr{
public:
    Ptr(T*p):_p(p){}

    explicit operator bool()const{
        if(_p!=0)
            return true;
        else
            return false;
    }

private:
    T* _p;
};
int main(){
    int a;
    Ptr<int> p(&a);
    if(p)//可以通过编译
        cout<<"valid pointer."<<endl;//valid pointer.
    else
        cout<<"invalid pointer."<<endl;
    Ptr<double> pd(0);
    //cout<<p+pd<<endl;  无法通过编译
    cout<<(p && pd)<<endl;
}
/*if(p)可以通过编译，因为可以通过p直接构造出bool类型的变量。
 * p && pd 可以通过编译，因为p 和 pd可以直接构造出bool类型
 * 而p+pd这样的语句就无法通过编译了，这是由于全局的
 * operator+并不接受bool类型变量为参数
 * */

