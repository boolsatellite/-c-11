//
// Created by satellite on 2023-05-21.
//

//Ĭ�Ϻ�������

//#define code_7_7
//#define code_7_8
//#define code_7_12
//#define code_7_13
#define code_7_14

#ifdef code_7_7
#include <type_traits>
#include <iostream>
using namespace std;
class TwoCstor{
public:
//�ṩ�˴������汾�Ĺ��캯��������������ṩ
//���������汾����TwoCstor������POD����
    TwoCstor(){};
    TwoCstor(int i):data(i){}
private:
    int data;
};
int main(){
    cout<<is_pod<TwoCstor>::value<<endl;//0
}
#endif


#ifdef code_7_8
#include <type_traits>
#include <iostream>
using namespace std;
class TwoCstor{
public:
//�ṩ�˴������汾�Ĺ��캯������ָʾ������
//�ṩĬ�ϰ汾�����Զ���������Ȼ��POD����
    TwoCstor()=default;
    TwoCstor(int i):data(i){}
private:
    int data;
};
int main(){
    cout<<is_pod<TwoCstor>::value<<endl;//1
}
#endif


#ifdef code_7_12
class ConvType{
public:
    ConvType(int i){};
    ConvType(char c)=delete;//ɾ��char�汾
};
void Func(ConvType ct){}
int main(){
    Func(3);
    Func('a');//�޷�ͨ������
    ConvType ci(3);
    ConvType cc('a');//�޷�ͨ������
}
#endif


#ifdef code_7_13
class ConvType{
public:
    ConvType(int i){};
    explicit ConvType(char c)=delete;//ɾ��explicit��char���캯��
};
void Func(ConvType ct){}
int main(){
    Func(3);
    Func('a');//����ͨ������
    ConvType ci(3);
    ConvType cc('a');//�޷�ͨ������
}
#endif

#ifdef  code_7_14
#include <cstddef>
#include <new>
extern void*p;
class NoStackAlloc{
public:
    ~NoStackAlloc()=delete;
};
int main(){
    NoStackAlloc nsa;//�޷�ͨ������
    new(p)NoStackAlloc();//placement new,����p���������������
    return 1;
}

#endif

