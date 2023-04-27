//
// Created by satellite on 2023-04-27.
//

//decltype 类型推导

#include <iostream>
#include <typeinfo>

using namespace std;


//#define code_4_16
//#define code_4_17
//#define code_4_18
//#define code_4_19
//#define code_4_20
//#define code_4_22
//#define code_4_23
//#define code_4_25
//#define code_4_27
#define code_4_28

class White {
};

#ifdef code_4_16
class Black {
};

int main() {
    White a;
    Black b;
    cout << typeid(a).name() << endl;//5White
    cout << typeid(b).name() << endl;//5Black
    White c;
    bool a_b_sametype =
            (typeid(a).hash_code() == typeid(b).hash_code());
    bool a_c_sametype =
            (typeid(a).hash_code() == typeid(c).hash_code());
    cout << "Same type?" << endl;
    cout << "A and B?" << (int) a_b_sametype << endl;//0
    cout << "A and C?" << (int) a_c_sametype << endl;//1

}
#endif

#ifdef code_4_17
#include <typeinfo>
#include <iostream>

using namespace std;

int main() {
    int i;
    decltype(i) j = 0;
    cout << typeid(j).name() << endl;//打印出"i",g++表示int
    float a;
    double b;
    decltype(a + b) c;
    cout << typeid(c).name() << endl;//打印出"d",g++表示double
}
/* j的类型由decltype(i)进行声明表示j的类型跟i这个表达式返回的类型相同
 * 而c的类型相则跟(a+b)这个表达式返回的类型相同
 * */
#endif


#ifdef code_4_18
using size_t=decltype(sizeof(0));
using ptrdiff_t=decltype((int*)0-(int*)0);
using nullptr_t=decltype(nullptr);
#endif


#ifdef code_4_19
enum {K1, K2, K3} anon_e;//匿名的强类型枚举

union {
    decltype(anon_e) key;
    char *name;
} anon_u;//匿名的union联合体

struct {
    int d;
    decltype(anon_u) id;
} anon_s[100];//匿名的struct数组

int main() {
    decltype(anon_s) as;
    as[0].id.key = decltype(anon_e)::K1;//引用匿名强类型枚举中的值
}
#endif


#ifdef code_4_20
template<typename T1, typename T2>
void Sum(T1 &t1, T2 &t2, decltype(t1 + t2) &s) {
    s = t1 + t2;
}

int main() {
    int a = 3;
    long b = 5;
    float c = 1.0f, d = 2.3f;
    long e;
    float f;
    Sum(a, b, e);   //s的类型被推导为long
    Sum(c, d, f);   //s的类型被推导为float
}
#endif

#ifdef code_4_22
#include <map>
#include "vector"
using namespace std;
int hash(char *){return 0;}
int main() {
    decltype(::hash(nullptr)) a;
    //std::map<char*,decltype(::hash)>dict_key;//无法通过编译,无法使用函数类型作容器参数
    std::map<char*,decltype(::hash(nullptr))>dict_key1;

}
#endif

#ifdef code_4_23
#include <type_traits>
using namespace std;
typedef double(*func)();
int main(){
    result_of<func()>::type f;//由func()推导其结果类型
}
#endif

#ifdef code_4_25
int i=4;
int arr[5]={0};
int*ptr=arr;
struct S{double d;}s;
void Overloaded(int);
void Overloaded(char);//重载的函数
int&& RvalRef();
const bool Func(int);
int func(int);
//规则1:单个标记符表达式以及访问类成员，推导为本类型

decltype(arr)var1;//int[5],标记符表达式
decltype(ptr)var2;//int*,标记符表达式
decltype(s.d)var4;//double,成员访问表达式
decltype(Overloaded)var5;//无法通过编译，是个重载的函数

//规则2:将亡值，推导为类型的右值引用
decltype(RvalRef())var6=1;//int&&

//规则3:左值，推导为类型的引用
decltype(true?i:i)var7=i; //int&,三元运算符，这里返回一个i的左值
decltype((i))var8=i;      //int&,带圆括号的左值
decltype(++i)var9=i;      //int&,++i返回i的左值
decltype(arr[3])var10=i;  //int&[]操作返回左值
decltype(*ptr)var11=i;    //int&*操作返回左值
decltype("lval")var12="lval";//const char(&)[9],字符串字面常量为左值
//规则4：以上都不是，推导为本类型
decltype(1)var13;//int,除字符串外字面常量为右值
decltype(i++)var14;//int,i++返回右值
decltype((Func(1)))var15;//const bool,圆括号可以忽略
#endif


#ifdef code_4_27

#include <type_traits>
#include <iostream>

using namespace std;
const int ic = 0;
volatile int iv;
struct S {
    int i;
};
const S a = {0};
volatile S b;
volatile S *p = &b;

int main() {
    cout << is_const<decltype(ic)>::value << endl;//1
    cout << is_volatile<decltype(iv)>::value << endl;//1
    cout << is_const<decltype(a)>::value << endl;//1
    cout << is_volatile<decltype(b)>::value << endl;//1
    cout << is_const<decltype(a.i)>::value << endl;//0,成员不是const
    cout << is_volatile<decltype(p->i)>::value << endl;//0,成员不是volatile
}

#endif

#ifdef code_4_28

#include <type_traits>
#include <iostream>

using namespace std;
int i = 1;
int &j = i;
int *p = &i;
const int k = 1;

int main() {
    decltype(i) &var1 = i;
    decltype(j) &var2 = i;//冗余的&,被忽略
    cout << is_lvalue_reference<decltype(var1)>::value << endl;//1,是左值引用
    cout << is_rvalue_reference<decltype(var2)>::value << endl;//0,不是右值引用
    cout << is_lvalue_reference<decltype(var2)>::value << endl;//1,是左值引用
    //decltype(p) *var3 = &i;//无法通过编译
    decltype(p) *var3 = &p;//var3的类型是int**
    auto *v3 = p;//v3的类型是int*
    v3 = &i;
    const decltype(k) var4 = 1;//冗余的const，被忽略
}

#endif