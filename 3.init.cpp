//
// Created by satellite on 2023-04-07.
//


/**��C++98�У�֧��������������ʹ�õȺš�=���ӳ�ʼֵ�ķ�ʽ������ʼ
�����о�̬��Ա������Ҳ��Ϊ�͵�������
�����̬��Ա�����㳣���ԣ��򲻿��Ծ͵����������Ҽ�ʹ��
���ľ�̬��ԱҲֻ�������ͻ���ö���Ͳ��ܾ͵س�ʼ��,
 ���Ǿ�̬��Ա�����ĳ�ʼ��������ڹ��캯���н���
 */


/*   c++98
class Init{
public:
    Init():a(0){}
    Init(int d):a(d){}
private:
    int a;
    const static int b=0;
    int c=1;             //��Ա���޷�ͨ������
    static int d=0;       //��Ա���޷�ͨ������
    static const double e=1.3;    //�����ͻ���ö�٣��޷�ͨ������
    static const char*const f="e";//�����ͻ���ö�٣��޷�ͨ������
};*/


/**��C++11�У���׼����
�Ǿ�̬��Ա�����ĳ�ʼ���ж�����ʽ��������ԣ����˳�ʼ���б�
�⣬��C++11�У���׼������ʹ�õȺ�=���߻�����{}���о͵صķǾ�
̬��Ա������ʼ��*/

/*
struct INIT
{
private:
    int a = 20;  //c++11�ԷǾ�̬��Ա�����ṩ�� = {} �ĳ�ʼ����ʽ
    double b{1.3};
};
*/



/*

//���ڷǾ�̬��Ա�����ĳ�ʼ������ʹ�� = �� {}
// ��ʹ�� () �п��ܱ���Ϊ�Ǻ������� (���˲��룬������δ��ȷ˵��)
#include <string>
using namespace std;
struct C{
    C(int i):c(i){};
    int c;
};
struct init{
    int a=1;
    //string b("hello");//�޷�ͨ������,
    string b{"hello"}; //����ʹ�� {} ��ʼ��
    //C c(1);//�޷�ͨ������
    C c{1};
};
*/



/*
#include <iostream>
using namespace std;
struct Mem{
    Mem(){cout<<"Mem default,num:"<<num<<endl;}
    Mem(int i):num(i){cout<<"Mem,num:"<<num<<endl;}
    int num=2;//ʹ��=��ʼ���Ǿ�̬��Ա
};

class Group{
public:
    Group(){cout<<"Group default.val:"<<val<<endl;}
    Group(int i):val('G'),a(i){cout<<"Group.val:"<<val<<endl;}
    void NumOfA(){cout<<"number of A:"<<a.num<<endl;}
    void NumOfB(){cout<<"number of B:"<<b.num<<endl;}
private:
    char val{'g'};//ʹ��{}��ʼ���Ǿ�̬��Ա
    Mem a;
    Mem b{19};//ʹ��{}��ʼ���Ǿ�̬��Ա
};
int main(){
    Mem member;//Mem default,num:2
    Group group;//Mem default,num:2
//Mem,num:19
//Group default.val:g
    group.NumOfA();//number of A:2
    group.NumOfB();//number of B:19
    Group group2(7);//Mem,num:7
//Mem,num:19
//Group.val:G
    group2.NumOfA();//number of A:7
    group2.NumOfB();//number of B:19
}
*/




//Ĭ��ֵ��ʼ���ĺô���
#include <string>

using namespace std;

class Mem {
public:
    Mem(int i) : m(i) {}

private:
    int m;
};

class Group {
public:
    Group() {}//����Ͳ���Ҫ��ʼ��data��mem��name��Ա��
    Group(int a) : data(a) {}//����Ͳ���Ҫ��ʼ��mem��name��Ա��
    Group(Mem m) : mem(m) {}//����Ͳ���Ҫ��ʼ��data��name��Ա��
    Group(int a, Mem m, string n) : data(a), mem(m), name(n) {}

private:
    int data = 1;
    Mem mem{0};
    string name{"Group"};
};
