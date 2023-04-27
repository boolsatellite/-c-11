//
// Created by satellite on 2023-04-27.
//

//decltype �����Ƶ�

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
    cout << typeid(j).name() << endl;//��ӡ��"i",g++��ʾint
    float a;
    double b;
    decltype(a + b) c;
    cout << typeid(c).name() << endl;//��ӡ��"d",g++��ʾdouble
}
/* j��������decltype(i)����������ʾj�����͸�i������ʽ���ص�������ͬ
 * ��c�����������(a+b)������ʽ���ص�������ͬ
 * */
#endif


#ifdef code_4_18
using size_t=decltype(sizeof(0));
using ptrdiff_t=decltype((int*)0-(int*)0);
using nullptr_t=decltype(nullptr);
#endif


#ifdef code_4_19
enum {K1, K2, K3} anon_e;//������ǿ����ö��

union {
    decltype(anon_e) key;
    char *name;
} anon_u;//������union������

struct {
    int d;
    decltype(anon_u) id;
} anon_s[100];//������struct����

int main() {
    decltype(anon_s) as;
    as[0].id.key = decltype(anon_e)::K1;//��������ǿ����ö���е�ֵ
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
    Sum(a, b, e);   //s�����ͱ��Ƶ�Ϊlong
    Sum(c, d, f);   //s�����ͱ��Ƶ�Ϊfloat
}
#endif

#ifdef code_4_22
#include <map>
#include "vector"
using namespace std;
int hash(char *){return 0;}
int main() {
    decltype(::hash(nullptr)) a;
    //std::map<char*,decltype(::hash)>dict_key;//�޷�ͨ������,�޷�ʹ�ú�����������������
    std::map<char*,decltype(::hash(nullptr))>dict_key1;

}
#endif

#ifdef code_4_23
#include <type_traits>
using namespace std;
typedef double(*func)();
int main(){
    result_of<func()>::type f;//��func()�Ƶ���������
}
#endif

#ifdef code_4_25
int i=4;
int arr[5]={0};
int*ptr=arr;
struct S{double d;}s;
void Overloaded(int);
void Overloaded(char);//���صĺ���
int&& RvalRef();
const bool Func(int);
int func(int);
//����1:������Ƿ����ʽ�Լ��������Ա���Ƶ�Ϊ������

decltype(arr)var1;//int[5],��Ƿ����ʽ
decltype(ptr)var2;//int*,��Ƿ����ʽ
decltype(s.d)var4;//double,��Ա���ʱ��ʽ
decltype(Overloaded)var5;//�޷�ͨ�����룬�Ǹ����صĺ���

//����2:����ֵ���Ƶ�Ϊ���͵���ֵ����
decltype(RvalRef())var6=1;//int&&

//����3:��ֵ���Ƶ�Ϊ���͵�����
decltype(true?i:i)var7=i; //int&,��Ԫ����������ﷵ��һ��i����ֵ
decltype((i))var8=i;      //int&,��Բ���ŵ���ֵ
decltype(++i)var9=i;      //int&,++i����i����ֵ
decltype(arr[3])var10=i;  //int&[]����������ֵ
decltype(*ptr)var11=i;    //int&*����������ֵ
decltype("lval")var12="lval";//const char(&)[9],�ַ������泣��Ϊ��ֵ
//����4�����϶����ǣ��Ƶ�Ϊ������
decltype(1)var13;//int,���ַ��������泣��Ϊ��ֵ
decltype(i++)var14;//int,i++������ֵ
decltype((Func(1)))var15;//const bool,Բ���ſ��Ժ���
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
    cout << is_const<decltype(a.i)>::value << endl;//0,��Ա����const
    cout << is_volatile<decltype(p->i)>::value << endl;//0,��Ա����volatile
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
    decltype(j) &var2 = i;//�����&,������
    cout << is_lvalue_reference<decltype(var1)>::value << endl;//1,����ֵ����
    cout << is_rvalue_reference<decltype(var2)>::value << endl;//0,������ֵ����
    cout << is_lvalue_reference<decltype(var2)>::value << endl;//1,����ֵ����
    //decltype(p) *var3 = &i;//�޷�ͨ������
    decltype(p) *var3 = &p;//var3��������int**
    auto *v3 = p;//v3��������int*
    v3 = &i;
    const decltype(k) var4 = 1;//�����const��������
}

#endif