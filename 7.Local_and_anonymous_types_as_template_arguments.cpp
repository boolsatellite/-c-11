//
// Created by satellite on 2023-04-11.
//

//�ֲ�������������ģ��ʵ��

/**c++98�У��ֲ������ͺ����������Ͳ�����ģ���ʵ��*/

template<typename T>class X{};
template<typename T>void TempFun(T t){};
struct A{}a;          //��ͨ��ȫ�ֽṹ��
struct{int i;}b;      //������ȫ�ֽṹ��  b���������ͱ���
typedef struct{int i;}B;//B����������
void Fun()
{
    struct C{}c;//C�Ǿֲ�����  �ֲ��Ľṹ��

    X<A>x1;//C++98ͨ����C++11ͨ��
    X<B>x2;//C++98����C++11ͨ��
    X<C>x3;//C++98����C++11ͨ��
    TempFun(a);//C++98ͨ����C++11ͨ��
    TempFun(b);//C++98����C++11ͨ��
    TempFun(c);//C++98����C++11ͨ��
}

//��C++11�б�׼���� ��ͨ��ȫ�ֽṹ�塢������ȫ�ֽṹ�壬�Լ�
//�ֲ��Ľṹ����Ϊ��������ģ����ģ�����������



//��Ȼ�������Ϳ�����ģ��������ܵ��ǣ�������ζ������������ȷ��
template<typename T>struct MyTemplate{};
int main(){
    MyTemplate<struct{int a;}>t;//�޷�����ͨ��,�������͵�����������ģ��ʵ��λ��
    return 0;
}





