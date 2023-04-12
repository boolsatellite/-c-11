//
// Created by satellite on 2023-04-12.
//

#include "iostream"
using namespace std;

/*
struct A
{
    A(int i){}
};

struct B : A
{
    B(int i): A(i) {}   //B�ڹ��캯���е���A�Ĺ��캯������ɹ��캯���Ĵ���
};
*/


/*
 * ���ǵĻ������ӵ�������ڶ�Ĳ�ͬ�汾�Ĺ��캯��
 * �����������д����Ĺ��캯������������ֻ��һЩ��Ա����ʱ
 * ��ô������������ԣ��乹��͵�ͬ�ڹ�����࣬�������ĵ�
 * �������ӣ�
 * */
/*struct A{
    A(int i){}
    A(double d,int i){}
    A(float f,int i,const char*c){}
//...
};
struct B:A{
    B(int i):A(i){}
    B(double d,int i):A(d,i){}
    B(float f,int i,const char*c):A(f,i,c){}
//...
    virtual void ExtraInterface(){}
};*/


//��C++���Ѿ�����һ�����õĹ��򣬾������������Ҫʹ��
//����ĳ�Ա�����Ļ�������ͨ�� using ������using-declaration�������

/*struct Base{
    void f(double i){cout<<"Base:"<<i<<endl;}   //�����������ӵ��ͬ���ĺ��������ǲ�����ͬ
};
struct Derived:Base{
    using Base::f;
    //����������Ҳʹ�û���汾��f
    //�����������ӵ���������汾��f����
    void f(int i){cout<<"Derived:"<<i<<endl;}
    //����ʹ��using��������f�������������f�������Ḳ�ǻ����f��������ôʹ�����������f������Զֻ�ܵ���������汾
};
int main()
{
    Base b;
    b.f(4.5);//Base:4.5
    Derived d;
    d.f(4.5);//Base:4.5
    d.f(1);  //Derived:1
}*/



/*��C++11�У�����뷨����չ���˹��캯���ϡ��������ͨ��ʹ��
using�����������̳л���Ĺ��캯����*/


/*struct A{
    A(int i){}
    A(double d,int i){}
    A(float f,int i,const char*c){}
//...
};
struct B:A{
    using A::A;//�̳й��캯��
//...
    virtual void ExtraInterface(){}
};*/

/*
 * using A::A ������Ĺ��캯��ȫ���̳е�������B�У������Ͳ���Ҫ��͸���캯����
 * c++11��׼���̳й��캯�����Ϊ���������и���Ĭ�Ϻ���(Ĭ�Ϲ��죬����������)һ��������ʽ������
 * ����ζ�����һ���̳й��캯��������ش���ʹ�ã�����������Ϊ����������ĺ�������
 * �����̳й��캯��ֻ���ʼ�������г�Ա�����������������еĳ�Ա������������Ϊ��
 * */


struct A{
    A(int i){}
    A(double d,int i){}
    A(float f,int i,const char*c){}
//...
};
struct B:A{
    using A::A;
    int d{0};
};
int main(){
    B b(356.1,33);//b.d����ʼ��Ϊ0
}



//�ģ���������