//
// Created by satellite on 2023-04-18.
//


//��ʽת��������

//#define explicit_construct
//#define operator_overload
//#define explicit_operator_overload

#include <iostream>

using namespace std;

#ifdef explicit_construct
struct Rational1{
    Rational1(int n=0,int d=1):num(n),den(d){  //û��ʹ��explicit���ο��Ա���ʽ����
        cout<<__func__<<"("<<num<<"/"<<den<<")"<<endl;
    }
    int num;//Numerator����������
    int den;//Denominator��������
};

struct Rational2{
    explicit Rational2(int n=0,int d=1):num(n),den(d){  //ʹ��explicit���Σ���ʽת������ֹ
        cout<<__func__<<"("<<num<<"/"<<den<<")"<<endl;
    }
    int num;
    int den;
};
void Display1(Rational1 ra){
    cout<<"Numerator:"<<ra.num<<"Denominator:"<<ra.den<<endl;
}
void Display2(Rational2 ra){
    cout<<"Numerator:"<<ra.num<<"Denominator:"<<ra.den<<endl;
}
int main(){
    Rational1 r1_1=11;//Rational1(11/1)
    Rational1 r1_2(12);//Rational1(12/1)
    Rational2 r2_1=21;//�޷�ͨ������
    Rational2 r2_2(22);//Rational2(22/1)
    Display1(1);//Rational1(1/1)
//Numerator:1 Denominator:1
    Display2(2);//�޷�ͨ������
    Display2(Rational2(2));//Rational2(2/1)
//Numerator:2 Denominator:1
    return 0;
}
#endif

#ifdef operator_overload

//����ͬ���Ļ��Ʋ�û�г������Զ��������ת�����ϡ����������һ
//������Ĺ��̣����Զ�������ת��һ����֪���͡�
//������Ȼ��������
//�ļ���ԶС�ڴ���֪���͹����Զ������ͣ������е�ʱ������ȷʵ
//Ӧ����ֹ������������ʽת����

template<typename T>
class Ptr{
public:
    Ptr(T*p):_p(p){}

    operator bool()const{
        //��Ϊ�û��Զ����ת��Ϊbool���͵ĺ������ṩ����ʽת������
        //�˺������������ж�ָ���Ƿ���Ч��ʹif(p)����
        //����������ת��ʹ Ptr<int> + Ptr<double> ���﷨�ϱ��������������Ǻ������õ�
        if(_p!=0)
            return true;
        else
            return false;
    }

private:
    T* _p;
};
int main(){
    int a;
    Ptr<int> p(&a);
    if(p)//�Զ�ת��Ϊbool�ͣ�û������
        cout<<"valid pointer."<<endl;//valid pointer.
    else
    cout<<"invalid pointer."<<endl;
    Ptr<double> pd(0);
    cout<<p+pd<<endl;//1����ӣ�������û������
}

#endif

#ifdef explicit_operator_overload

/**��C++11�У���׼��explicit��ʹ�÷�Χ��չ�����Զ��������ת����
�����ϣ���֧����ν�ġ���ʽ����ת������explicit�ؼ�������������ת
���������ϣ���ζ��ֻ����ֱ�ӹ���Ŀ�����ͻ���ʽ����ת����ʱ��
����ʹ�ø����͡�
 * */


class ConvertTo {
};

class Convertable {
public:
    explicit operator ConvertTo() const //��������ʽת��
    {
        return ConvertTo();
    }
};

void Func(ConvertTo ct) {}

void test() {
    Convertable c;
    ConvertTo ct(c);//ֱ�ӳ�ʼ����ͨ��
//ConvertTo ct2=c;//���������ʼ��������ʧ��
    ConvertTo ct3 = static_cast<ConvertTo>(c);//ǿ��ת����ͨ��
//Func(c);//���������ʼ��������ʧ��
}

#endif



template<typename T>
class Ptr{
public:
    Ptr(T*p):_p(p){}

    explicit operator bool()const{
        if(_p!=0)
            return true;
        else
            return false;
    }

private:
    T* _p;
};
int main(){
    int a;
    Ptr<int> p(&a);
    if(p)//����ͨ������
        cout<<"valid pointer."<<endl;//valid pointer.
    else
        cout<<"invalid pointer."<<endl;
    Ptr<double> pd(0);
    //cout<<p+pd<<endl;  �޷�ͨ������
    cout<<(p && pd)<<endl;
}
/*if(p)����ͨ�����룬��Ϊ����ͨ��pֱ�ӹ����bool���͵ı�����
 * p && pd ����ͨ�����룬��Ϊp �� pd����ֱ�ӹ����bool����
 * ��p+pd�����������޷�ͨ�������ˣ���������ȫ�ֵ�
 * operator+��������bool���ͱ���Ϊ����
 * */

