//
// Created by satellite on 2023-04-28.
//

//���ٷ�������

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
//���Բ�дOuterType::InnerType
auto OuterType::GetInner()->InnerType{//ʹ�����շ������͵�ʱ��InnerType����д����������
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
//�е�ʱ����ᷢ������������

int(* (*pf())()   )()
{
    return nullptr;
}


//auto(*)()->int(*)()һ�����غ���ָ��ĺ���(����Ϊa����)
//auto pf1()->auto(*)()->int(*)()һ������a������ָ��ĺ���

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


auto (*pf)() -> int ;  //�ȼ��ڣ�int(*pf)()
auto (&fr)() -> int = *pf;   //�ȼ��ڣ�int(&fr)()

