//
// Created by satellite on 2023-04-21.
//

//POD 类型

#include <iostream>
#include <type_traits>

using namespace std;
//#define POD_type
//#define standard_layout
//#define template_is_standard_layout
#define template_is_pod

#ifdef POD_type
struct Trivial1 {
};

struct Trivial2 :Trivial1
        {
public:
    int a;
private:
    int b;
};

struct Trivial3 {
    Trivial1 a;
    Trivial2 b;
};

struct Trivial4 {
    Trivial2 a[23];
};

struct Trivial5 {
    int x;
    static int y;
};

struct NonTrivial1 {
    NonTrivial1() : z(42) {}

    int z;
};

struct NonTrivial2 {
    NonTrivial2();

    int w;
};

NonTrivial2::NonTrivial2() = default;

struct NonTrivial3 {
    Trivial5 c;

    virtual void f();
};

int main() {
    cout << is_trivial<Trivial1>::value << endl;//1
    cout << is_trivial<Trivial2>::value << endl;//1
    cout << is_trivial<Trivial3>::value << endl;//1
    cout << is_trivial<Trivial4>::value << endl;//1
    cout << is_trivial<Trivial5>::value << endl;//1
    cout << is_trivial<NonTrivial1>::value << endl;//0
    cout << is_trivial<NonTrivial2>::value << endl;//0
    cout << is_trivial<NonTrivial3>::value << endl;//0
    return 0;
}
#endif


#ifdef standard_layout
/*struct B1{static int a;};
struct D1:B1{int d;};

struct B2{int a;};
struct D2:B2{static int d;};

struct D3:B2,B1{static int d;};
struct D4:B2{int d;};
struct D5:B2,D1{};*/


struct B1{};
struct B2{};
struct D1:B1{
    B1 b;//第一个非静态变量跟基类相同
    int i;
};
struct D2:B1{
    B2 b;
    int i;
};
int main(){
    D1 d1;
    D2 d2;
    cout<<hex;
    cout<<reinterpret_cast<long long>(&d1)<<endl;
    cout<<reinterpret_cast<long long>(&(d1.b))<<endl;
    cout<<reinterpret_cast<long long>(&(d1.i))<<endl;
    cout<<reinterpret_cast<long long>(&d2)<<endl;
    cout<<reinterpret_cast<long long>(&(d2.b))<<endl;
    cout<<reinterpret_cast<long long>(&(d2.i))<<endl;

    cout<<is_standard_layout<D1>::value<<endl;
    cout<<is_standard_layout<D2>::value<<endl;
}


#endif


#ifdef template_is_standard_layout

struct SLayout1{};
struct SLayout2{
private:
    int x;
    int y;
};
struct SLayout3:SLayout1{
    int x;
    int y;
    void f();
};
struct SLayout4:SLayout1{
    int x;
    SLayout1 y;
};
struct SLayout5:SLayout1,SLayout3{};
struct SLayout6{static int y;};
struct SLayout7:SLayout6{int x;};
struct NonSLayout1:SLayout1{
    SLayout1 x;
    int i;
};
struct NonSLayout2:SLayout2{int z;};
struct NonSLayout3:NonSLayout2{};
struct NonSLayout4{
public:
    int x;
private:
    int y;
};
int main(){
    cout<<is_standard_layout<SLayout1>::value<<endl;//1
    cout<<is_standard_layout<SLayout2>::value<<endl;//1
    cout<<is_standard_layout<SLayout3>::value<<endl;//1
    cout<<is_standard_layout<SLayout4>::value<<endl;//1
    cout<<is_standard_layout<SLayout5>::value<<endl;//1
    cout<<is_standard_layout<SLayout6>::value<<endl;//1
    cout<<is_standard_layout<SLayout7>::value<<endl;//1
    cout<<is_standard_layout<NonSLayout1>::value<<endl;//0
    cout<<is_standard_layout<NonSLayout2>::value<<endl;//0
    cout<<is_standard_layout<NonSLayout3>::value<<endl;//0
    cout<<is_standard_layout<NonSLayout4>::value<<endl;//0
    return 0;
}

#endif



#ifdef template_is_pod

union U{};
union U1{U1(){}};
enum E{};
typedef double*DA;
typedef void(*PF)(int,double);
int main(){
    cout<<is_pod<U>::value<<endl;//1
    cout<<is_pod<U1>::value<<endl;//0
    cout<<is_pod<E>::value<<endl;//1
    cout<<is_pod<int>::value<<endl;//1
    cout<<is_pod<DA>::value<<endl;//1
    cout<<is_pod<PF>::value<<endl;//1
}

#endif





