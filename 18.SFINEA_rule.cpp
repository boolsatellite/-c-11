//
// Created by satellite on 2023-04-26.
//

/*-Substitution failure is not an error，
中文直译即是“匹配失败不是错误”。更为确切地说，这
条规则表示的是对重载的模板的参数进行展开的时候，如果展开导致
了一些类型不匹配，编译器并不会报错。*/

//#define code_3_52
#define code_3_53

#ifdef code_3_52

struct Test {
    typedef int foo;
};

template<typename T>
void f(typename T::foo) {}//第一个模板定义-#1

template<typename T>
void f(T) {}//第二个模板定义-#2

int main() {
    f<Test>(10);//调用#1.
    f<int>(10);//调用#2.由于SFINEA，虽然不存在类型int::foo，也不会发生编译错误
}

#endif

#ifdef code_3_53

template<int I>
struct A {
};

char xxx(int);

char xxx(float);

template<class T>
A<sizeof(xxx((T) 0))> f(T) {}

int main() {
    f(1);
}


#endif


//好难呀，没看懂
