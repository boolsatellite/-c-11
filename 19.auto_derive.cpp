// Created by satellite on 2023-04-26.
//
//auto�����Ƶ�

//#define code_4_3
//#define code_4_4
//#define code_4_5
//#define code_4_7
//#define code_4_8
//#define code_4_9
//#define code_4_10
//#define code_4_11
//#define code_4_12
//#define code_4_13
//#define code_4_14
#define code_4_15

#ifdef code_4_3

#include <iostream>
using namespace std;

void f(int i, int j , float k);

int main(){
    auto name="world.\n";

    cout<<"hello,"<<name;
}

#endif


#ifdef code_4_4

int main(){
    double foo();
    auto x=1;//x������Ϊint
    auto y=foo();//y������Ϊdouble
    struct m{int i;}str;
    auto str1=str;//str1��������struct m
    auto z;//�޷��Ƶ����޷�ͨ������
    z=x;
}

#endif


#ifdef code_4_5

#include <string>
#include <vector>

void loopover(std::vector<std::string> &vs) {
    std::vector<std::string>::iterator i = vs.begin();//��Ҫʹ��iterator��������Ҫ��д��������
    for (; i < vs.end(); i++) {
        //һЩ����
    }
}

#endif

#ifdef code_4_7

class PI{
public:
    double operator*(float v){
        return(double)val*v;//���ﾫ�ȱ���չ��
    }
    const float val=3.1415927f;
};
int main(){
    float radius=1.7e10;
    PI pi;
    auto circumference=2*(pi*radius);
}

#endif


#ifdef code_4_8

#include <iostream>
using namespace std;
int main(){
    unsigned int a=4294967295;//����unsigned intֵ
    unsigned int b=1;
    auto c=a+b;//c��������Ȼ��unsigned int
    cout<<"a="<<a<<endl;//a=4294967295
    cout<<"b="<<b<<endl;//b=1
    cout<<"a+b="<<c<<endl;//a+b=0
    return 0;
}

#endif

#ifdef code_4_9

template<typename T1,typename T2>
double Sum(T1& t1,T2& t2){
auto s=t1+t2;//s�����ͻ���ģ��ʵ����ʱ���Ƶ�����
return s;
}
int main(){
    int a=3;
    long b=5;
    float c=1.0f,d=2.3f;
    auto e=Sum<int,long>(a,b);//s�����ͱ��Ƶ�Ϊlong
    auto f=Sum<float,float>(c,d);//s�����ͱ��Ƶ�Ϊfloat
}


#endif


#ifdef code_4_10

#define Max1(a,b)((a)>(b))?(a):(b)
#define Max2(a,b)({\
auto _a=(a);\
auto _b=(b);\
(_a>_b)?_a:_b;})
int main(){
    int m1=Max1(1*2*3*4,5+6+7+8);
    int m2=Max2(1*2*3*4,5+6+7+8);
}

#endif


#ifdef code_4_11

int x;
int *y = &x;

double foo();

int &bar();

auto *a = &x;//int*
auto &b = x;//int&
auto c = y;//int*
auto *d = y;//int*
auto *e = &foo();//����ʧ��,ָ�벻��ָ��һ����ʱ����
auto &f = foo();//����ʧ��,nonconst����ֵ���ò��ܺ�һ����ʱ������
auto g = bar();//int
auto &h = bar();//int&

#endif


#ifdef code_4_12

double foo();
float *bar();

const auto a = foo();//a:const double
const auto &b = foo();//b:const double&
volatile auto *c = bar();//c:volatile float*
auto d = a;//d:double
auto &e = a;//e:const double&
auto f = c;//f:float*
volatile auto &g = c;//g:volatile float*&

#endif


#ifdef code_4_13

auto x = 1, y = 2;//x��y�����;�Ϊint
//m��һ��ָ��const int���ͱ�����ָ��,n��һ��int���͵ı���
const auto *m = &x, n = 1;
auto i = 1, j = 3.14f;//����ʧ��

auto o = 1,&p = o, *q =&p;//���������Ƶ�

#endif

#ifdef code_4_14

#include <initializer_list>
auto x=1;
auto x1(1);
auto y{1};//ʹ�ó�ʼ���б��auto
auto z=new auto(1);//��������new


#endif


#ifdef code_4_15

#include <vector>
#include <iostream>

using namespace std;

void fun(auto x = 1) {}//1:auto�����������޷�ͨ������
struct str {
    auto var = 10;//2:auto�Ǿ�̬��Ա�������޷�ͨ������
};

int main() {
    char x[3];
    auto y = x;
    auto z[3] = x;//3:auto���飬�޷�ͨ������
    //4:autoģ�������ʵ����ʱ�����޷�ͨ������
    vector<auto> v = {1};
}

#endif