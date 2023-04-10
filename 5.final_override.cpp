//
// Created by satellite on 2023-04-10.
//
#include <iostream>
using namespace std;
class MathObject{
public:
    virtual double Arith()=0;
    virtual void Print()=0;
};
class Printable:public MathObject{
public:
    double Arith()=0;
    void Print()//��C++98�������޷���ֹ�ýӿڱ���д
    {
        cout<<"Output is:"<<Arith()<<endl;
    }
};
class Add2:public Printable{
public:
    Add2(double a,double b):x(a),y(b){}
    double Arith(){return x+y;}
private:
    double x,y;
};
class Mul3:public Printable{
public:
    Mul3(double a,double b,double c):x(a),y(b),z(c){}
    double Arith(){return x*y*z;}
private:
    double x,y,z;
};


/**���ǵĻ�����MathObject�����������ӿڣ�Arith
��Print����Printable��̳���MathObject��ʵ����Print�ӿڡ���������
Add2��Mul3Ϊ��ʹ��MathObject�Ľӿں�Printable��Print��ʵ�֣���
�Ƕ��̳���Printable���������������ṹ�����������ı���зǳ�
���͡��������������Printable��Add2������������Ա��ɵģ�
Printable�ı�д�߲�������һЩ���ǣ����Add2�ı�д��������Print
��������ô����������ͳһ���Ĵ�ӡ��ʽ���������ڡ�*/

//final�ؼ��ֵ�������ʹ�����಻�ɸ����������ε��麯��

/*struct Object{
    virtual void fun()=0;
};
struct Base:public Object{
    void fun()final;//����Ϊfinal
};
struct Derived:public Base{
    void fun();//�޷�ͨ�����룬���޷����ǻ���ָ��final���麯��
};*/


/**override,����������麯������ʱ��ʹ����override����������ô�ú�����������������е�
ͬ�������������޷�ͨ������*/

struct Base{
    virtual void Turing()=0;
    virtual void Dijkstra()=0;
    virtual void VNeumann(int g)=0;
    virtual void DKnuth()const;
    void Print();
};
struct DerivedMid:public Base{
//virtual void VNeumann(double g);
//�ӿڱ������ˣ������һ���汾��VNeumann����
};
struct DerivedTop:public DerivedMid{
    void Turing()override;
    void Dikjstra()override;//�޷�ͨ�����룬ƴд���󣬲�������
    void VNeumann(double g)override;//�޷�ͨ�����룬������һ�£���������
    void DKnuth()  override;//�޷�ͨ�����룬�����Բ�һ�£���������
    //void DKnuth() const override;  ��֤������
    void Print()override;//�޷�ͨ�����룬���麯������
};
