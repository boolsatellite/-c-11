//
// Created by satellite on 2023-04-15.
//

//右值引用：移动语义和完美转发

#include "iostream"
#include "type_traits"
using namespace std;

//不施使用移动语义，造成了对临时对象拷贝开销过大
/*class HasPtrMem {
public:
    HasPtrMem() : d(new int(0)) {
        cout << "Construct:" << ++n_cstr << endl;
    }

    HasPtrMem(const HasPtrMem &h) : d(new int(*h.d)) {
        cout << "Copy construct:" << ++n_cptr << endl;
    }

    ~HasPtrMem() {
        cout << "Destruct:" << ++n_dstr << endl;
    }

    int *d;
    static int n_cstr;
    static int n_dstr;
    static int n_cptr;
};

int HasPtrMem::n_cstr = 0;
int HasPtrMem::n_dstr = 0;
int HasPtrMem::n_cptr = 0;

HasPtrMem GetTemp() { return HasPtrMem(); }

int main() {
    HasPtrMem a = GetTemp();
}*/

/*class HasPtrMem{
public:
    HasPtrMem():d(new int(3)){
        cout<<"Construct:"<<++n_cstr<<endl;
    }
    HasPtrMem(const HasPtrMem&h):d(new int(*h.d)){
        cout<<"Copy construct:"<<++n_cptr<<endl;
    }
    HasPtrMem(HasPtrMem&&h):d(h.d)   //移动构造函数.在初始化列表中偷走了指针的值
    {
        h.d=nullptr;          //将临时值的指针成员置空
        cout<<"Move construct:"<<++n_mvtr<<endl;
    }
    ~HasPtrMem(){
        delete d;
        cout<<"Destruct:"<<++n_dstr<<endl;
    }
    int*d;
    static int n_cstr;
    static int n_dstr;
    static int n_cptr;
    static int n_mvtr;
};
int HasPtrMem::n_cstr=0;
int HasPtrMem::n_dstr=0;
int HasPtrMem::n_cptr=0;
int HasPtrMem::n_mvtr=0;
HasPtrMem GetTemp(){
    HasPtrMem h;
    cout<<"Resource from "<<__func__<<":"<<hex<<h.d<<endl;
    return h;
}
int main(){
    HasPtrMem a=GetTemp();
    cout<<"Resource from "<<__func__<<":"<<hex<<a.d<<endl;
}*/


/*
#include <iostream>
using namespace std;
struct Copyable{
    Copyable(){}
    Copyable(const Copyable&o){
        cout<<"Copied"<<endl;
    }
    Copyable(Copyable&&o){
        cout<<"copied&&"<<endl;
    }

};
Copyable ReturnRvalue(){return Copyable();}
void AcceptVal(Copyable){}
void AcceptRef(const Copyable&){}
void AcceptRvalueRef(Copyable&&){}

int main(){
*/
/*
    cout<<"Pass by value:"<<endl;
    AcceptVal(ReturnRvalue());//临时值被拷贝传入
    cout<<"Pass by reference:"<<endl;
    AcceptRef(ReturnRvalue());//临时值被作为引用传递
    cout<<"Pass by rvalueReference"<<endl;
    AcceptRvalueRef(ReturnRvalue());
*//*

    int a = 1;
    std::move(a);
}
*/

/*
class Moveable{
public:
    Moveable():i(new int(3)){}
    ~Moveable(){delete i;}
    Moveable(const Moveable&m):i(new int(*m.i)){}
    Moveable(Moveable&&m):i(m.i){
        m.i=nullptr;
    }

    int*i;
};
int main(){
    Moveable a;
    Moveable c(move(a));//会调用移动构造函数
    cout<<*a.i<<endl;//运行时错误
}
*/

/*class HugeMem{
public:
    HugeMem(int size):sz(size>0?size:1){
        c=new int[sz];
    }
    ~HugeMem(){delete[] c;}
    HugeMem(HugeMem&&hm):sz(hm.sz),c(hm.c){
        hm.c=nullptr;
    }
    int*c;
    int sz;
};
class Moveable{
public:
    Moveable():i(new int(3)),h(1024){}
    ~Moveable(){delete i;}
    Moveable(Moveable&&m):
    i(m.i),h(move(m.h)){//强制转为右值，以调用移动构造函数
        m.i=nullptr;
    }
    int*i;
    HugeMem h;
};
Moveable GetTemp(){
    Moveable tmp=Moveable();
    cout<<hex<<"Huge Mem from "<<__func__
    <<"@"<<tmp.h.c<<endl;//Huge Mem from GetTemp@0x603030
    return tmp;
}

template <typename T>
void swap(T& a, T& b)
{
    T tem(move(a));
    a = move(b);
    b = tem;
}

int main(){
    Moveable a(GetTemp());
    cout<<hex<<"Huge Mem from "<<__func__
    <<"@"<<a.h.c<<endl;//Huge Mem from main@0x603030;


}*/

/*
#include <iostream>
#include <utility>
using namespace std;
struct Maythrow{
    Maythrow(){}
    Maythrow(const Maythrow&){
        std::cout<<"Maythorow copy constructor."<<endl;
    }
    Maythrow(Maythrow&&){
        std::cout<<"Maythorow move constructor."<<endl;
    }
};
struct Nothrow{
    Nothrow(){}
    Nothrow(Nothrow&&)noexcept{
        std::cout<<"Nothorow move constructor."<<endl;
    }
    Nothrow(const Nothrow&){
        std::cout<<"Nothorow move constructor."<<endl;
    }
};
int main(){
    Maythrow m;
    Nothrow n;
    Maythrow mt=move_if_noexcept(m);//Maythorow copy constructor.
    Nothrow nt=move_if_noexcept(n);//Nothorow move constructor.
    return 0;
}
*/
#include "iostream"
using namespace std;

/*typedef const int T;
typedef T& TR;
TR& v = 1;             //该声明在C++98中会导致编译错误
int main() {
    std::cout << is_lvalue_reference<TR &>::value;
}*/

/*template<typename T>
void IamForwording(T&&t){
IrunCodeActually(static_cass<T&&>(t));
}*/

/*template<typename T>
void IamForwording(T&&t){
IrunCodeActually(std::forward(t));
}*/


#include <iostream>
using namespace std;
/*
void RunCode(int&&m){cout<<"rvalue ref"<<endl;}
void RunCode(int&m){cout<<"lvalue ref"<<endl;}
void RunCode(const int&&m){cout<<"const rvalue ref"<<endl;}
void RunCode(const int&m){cout<<"const lvalue ref"<<endl;}

template<typename T>
void PerfectForward(T&&t){
    RunCode(std::forward<T>(t));
}

int main(){
    int a;
    int b;
    const int c=1;
    const int d=0;
    PerfectForward(a);//lvalue ref
    PerfectForward(move(b));//rvalue ref
    PerfectForward(c);//const lvalue ref
    PerfectForward(move(d));//const rvalue ref
}
*/


template<typename T,typename U>
void PerfectForward(T&&t,U&Func){
cout<<t<<"\tforwarded..."<<endl;
Func(forward<T>(t));
}
void RunCode(double&&m){}
void RunHome(double&&h){}
void RunComp(double&&c){}
int main(){
    PerfectForward(1.5,RunComp);//1.5 forwarded...
    PerfectForward(8,RunCode);//8 forwarded...
    PerfectForward(1.5,RunHome);//1.5 forwarded...
}



