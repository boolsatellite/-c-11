//
// Created by satellite on 2023-04-11.
//

//ģ�庯����Ĭ��ģ�����

//�ع˺���ģ��Ķ���

#include "iostream"
using  namespace std;

template<typename T> void TempFunc(T a){
    cout << a <<endl;
}

int main1()
{
    TempFunc(1);    //ʵ����Ϊ TempFun<const int>(1)
    TempFunc("1");  //ʵ����Ϊ TempFun<const char *>("1")
}

//ģ����c++98 �� c++11 �е�֧�֣�

void DefParm(int m=3){}//c++98����ͨ����c++11����ͨ��

template <typename T=int>
class DefClass{};//c++98����ͨ����c++11����ͨ��

template<typename T=int>
void DefTempParm(){};//c++98����ʧ�ܣ�c++11����ͨ��

//c++11��֧����ģ�庯����ģ�������Ĭ��ֵ
//�������﷨�ϣ�����ģ����Щ��ͬ���ǣ���Ϊ���
//Ĭ��ģ���������ָ��Ĭ��ֵ��ʱ�򣬳���Ա�������ա��������󡱵�
//�������ָ��������������Ժ���ģ����˵�����Ǳ����


/*template<typename T1,typename T2=int>class DefClass1;
template<typename T1=int,typename T2>class DefClass2;//�޷�ͨ������,Ĭ�ϲ������ҵ���
template<typename T,int i=0>class DefClass3;
template<int i=0,typename T>class DefClass4;//�޷�ͨ�����룬Ĭ�ϲ������ҵ���

template<typename T1=int,typename T2>void DefFunc1(T1 a,T2 b);
template<int i=0,typename T>void DefFunc2(T a); //���ں���ģ����˵��Ĭ�ϲ���û��λ��Ҫ��*/



//����ܴӺ���ʵ�����Ƶ������͵Ļ�����ôĬ��ģ������Ͳ��ᱻʹ��

template<class T,class U=double>
void f(T t=0,U u=0);
void g(){
    f(1,'c');//f<int,char>(1,'c')
    f(1);//f<int,double>(1,0),ʹ����Ĭ��ģ�����double
    f();//����:T�޷����Ƶ�����
    f<int>();//f<int,double>(0,0),ʹ����Ĭ��ģ�����double
    f<int,char>();//f<int,char>(0,0)
}









