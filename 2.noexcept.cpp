//
// Created by satellite on 2023-04-07.
//
#include <iostream>
using namespace std;

/**noexcept  ��ʶ�ĺ������׳��쳣�����̵��õ��� terminate ��ֹ��ǰ����
noexcept�����ʽ�� ���ʽ�ᱻǿתΪ bool ���ͣ�Ϊ true ���ʾ�������׳��쳣�������ʾ�����׳��쳣*/


/*
void Throw(){throw 1;}
void NoBlockThrow(){Throw();}
void BlockThrow()noexcept{Throw();}
int main(){
    try{
        Throw();
    }
    catch(...){
        cout<<"Found throw."<<endl;//Found throw.
    }
    try{
        NoBlockThrow();
    }
    catch(...){
        cout<<"Throw is not blocked."<<endl;//Throw is not blocked.
    }
    try{
        BlockThrow();//terminate called after throwing an instance of'int'
    }
    catch(...){
        cout<<"Found throw 1."<<endl;
    }
}*/



/**����һ��������
������Ӧ���׳��쳣����ô���ڳ��������������õ�delete������˵��
C++11Ĭ�Ͻ�delete�������ó�noexcept���Ϳ������Ӧ�ó���İ�ȫ
�ԡ�

C++11��׼���������������Ĭ��Ҳ��
noexcept(true)�ġ���Ȼ���������Ա��ʽ��Ϊ��������ָ����
noexcept��������Ļ�����Ա��noexcept(false)������������������
���Ͳ����ٱ���Ĭ��ֵ
*/



struct A{
    ~A(){throw 1;}
};
struct B{
    ~B()noexcept(false){throw 2;}
};
struct C{
    B b;
};
int funA(){A a;}
int funB(){B b;}
int funC(){C c;}
int main(){
    try{
        funB();
    }
    catch(...){
        cout<<"caught funB."<<endl;//caught funB.
    }
    try{
        funC();
    }
    catch(...){
        cout<<"caught funC."<<endl;//caught funC.
    }
    try{
        funA();//terminate called after throwing an instance of'int'
    }
    catch(...){
        cout<<"caught funA."<<endl;
    }
}