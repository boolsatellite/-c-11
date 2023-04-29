//
// Created by satellite on 2023-04-28.
//

//跟踪返回类型

//#define code_4_29
//#define code_4_30
//#define code_4_31
//#define code_4_32

#ifdef code_4_29
class OuterType{
    struct InnerType{int i;};
    InnerType GetInner();
    InnerType it;
};
//可以不写OuterType::InnerType
auto OuterType::GetInner()->InnerType{//使用最终返回类型的时候，InnerType不必写明其作用域
return it;
}

/*OuterType::InnerType OuterType::GetInner() {
    return it;
}*/
#endif

#ifdef code_4_30
#include <iostream>
using namespace std;
template<typename T1,typename T2>
auto Sum(const T1&t1,const T2&t2)->decltype(t1+t2){
return t1+t2;
}
template<typename T1,typename T2>
auto Mul(const T1&t1,const T2&t2)->decltype(t1*t2){
return t1*t2;
}
int main(){
    auto a=3;
    auto b=4L;
    auto pi=3.14;
    auto c=Mul(Sum(a,b),pi);
    cout<<c<<endl;//21.98
}
#endif

#ifdef code_4_31

#include <type_traits>
#include <iostream>

using namespace std;
//有的时候，你会发现这是面试题

int(* (*pf())()   )()
{
    return nullptr;
}


//auto(*)()->int(*)()一个返回函数指针的函数(假设为a函数)
//auto pf1()->auto(*)()->int(*)()一个返回a函数的指针的函数

auto pf1() -> auto (*)()->int (*)() {
    return nullptr;
}

int main() {
    cout << is_same<decltype(pf), decltype(pf1)>::value << endl;//1
}

#endif

#ifdef code_4_32

#include <iostream>
using namespace std;

double foo(int a) {
    return (double) a + 0.1;
}

int foo(double b) {
    return (int) b;
}

template<class T>
auto Forward(T t) -> decltype(foo(t)) {
    return foo(t);
}

int main() {
    cout << Forward(2) << endl;//2.1
   // cout << Forward(0.5) << endl;//0

}

#endif


auto (*pf)() -> int ;  //等价于：int(*pf)()
auto (&fr)() -> int = *pf;   //等价于：int(&fr)()

