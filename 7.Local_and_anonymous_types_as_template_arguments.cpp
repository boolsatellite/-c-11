//
// Created by satellite on 2023-04-11.
//

//局部和匿名类型做模板实参

/**c++98中，局部的类型和匿名的类型不能做模板的实参*/

template<typename T>class X{};
template<typename T>void TempFun(T t){};
struct A{}a;          //普通的全局结构体
struct{int i;}b;      //匿名的全局结构体  b是匿名类型变量
typedef struct{int i;}B;//B是匿名类型
void Fun()
{
    struct C{}c;//C是局部类型  局部的结构体

    X<A>x1;//C++98通过，C++11通过
    X<B>x2;//C++98错误，C++11通过
    X<C>x3;//C++98错误，C++11通过
    TempFun(a);//C++98通过，C++11通过
    TempFun(b);//C++98错误，C++11通过
    TempFun(c);//C++98错误，C++11通过
}

//在C++11中标准允许 普通的全局结构体、匿名的全局结构体，以及
//局部的结构体作为参数传给模板做模板参数的做法



//虽然匿名类型可以呗模板参数接受但是，并不意味这以下这是正确的
template<typename T>struct MyTemplate{};
int main(){
    MyTemplate<struct{int a;}>t;//无法编译通过,匿名类型的声明不能在模板实参位置
    return 0;
}





