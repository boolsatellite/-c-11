//
// Created by satellite on 2023-04-18.
//

//�б��ʼ��

//#define initializer list test
//#define use initializer list
//#define use_initializer_list_inFuncLisat
#define initializer_list_ret

#ifdef initializer list test
#include <vector>
#include <map>
using namespace std;
int a[]={1,3,5};//C++98ͨ����C++11ͨ��
int b[]{2,4,6};//C++98ʧ�ܣ�C++11ͨ��
vector<int> c{1,3,5};//C++98ʧ�ܣ�C++11ͨ��
map<int,float>d=
        {{1,1.0f},{2,2.0f},{5,3.2f}};//C++98ʧ�ܣ�C++11ͨ��
#endif


/*
 �Զ�������ȫ�ֱ����ĳ�ʼ����c++11�б��ḻ�ˣ�
 �Ⱥš�=�����ϸ�ֵ���ʽ��assignment-expression)������int a=3+4��
 �Ⱥš�=�����ϻ�����ʽ�ĳ�ʼ���б�����int a={3+4}��
 Բ����ʽ�ı��ʽ�б�expression-list��������int a(3+4)��
 ������ʽ�ĳ�ʼ���б�����int a{3+4}��

 �������Ҳ�������ڻ�ȡ���ڴ�new�������У�
 int *i = new int(1);
 double *d = new double(1.2f);
 */


/*
��׼ģ����������Գ�ʼ���б�
��֧��Դ��<initializer_list>���ͷ�ļ���initialize_list��ģ���֧
�֡�����ԱֻҪ#include��<initializer_list>ͷ�ļ�����������һ����
initialize_list<T>ģ����Ϊ�����Ĺ��캯����ͬ������ʹ���Զ����
��ʹ���б��ʼ����
 */


#ifdef use_initializer_list_inConstructor

#include <vector>
#include <string>
using namespace std;

//�Զ�����ʹ�ó�ʼ���б��ʼ��
enum Gender{boy,girl};
class People{
public:
    People(initializer_list<pair<string,Gender>>l) //�ṩ����initialize_listΪ�����Ĺ����캯��
    {
        auto i=l.begin();
        for(;i!=l.end();++i)
            data.push_back(*i);
    }
private:
    vector<pair<string,Gender>>data;
};
People ship2012={{"Garfield",boy},{"HelloKitty",girl}};

#endif


#ifdef use_initializer_list_inFuncLisat
//���������б���ʹ�ó�ʼ���б�
#include <initializer_list>
#include "vector"
#include "iostream"
using namespace std;

void Fun(initializer_list<int> iv) {
    for(auto i = iv.begin();i!=iv.end();++i)
    {
        cout<<*i<<' ';
    }
}

int main1() {
    Fun({1, 2});
    Fun({});//���б�
}




class Mydata{
public:
    Mydata& operator[](initializer_list<int> l)
    {
        for(auto i=l.begin();i!=l.end();++i)
            idx.push_back(*i);
        return*this;
    }
    Mydata& operator=(int v)
    {
        if(idx.empty()!=true){
            for(auto i=idx.begin();i!=idx.end();++i){
                d.resize((*i>d.size())?*i:d.size());
                d[*i-1]=v;
            }
            idx.clear();
        }
        return*this;
    }
    void Print(){
        for(auto i=d.begin();i!=d.end();++i)
            cout<<*i<<"";
        cout<<endl;
    }
private:
    vector<int> idx;//�������飬���ڼ�¼index
    vector<int> d;
};
int main(){
    Mydata d;
    d[{2,3,5}]=7;
    d[{1,4,5,8}]=4;
    d.Print();//4 7 7 4 4 0 0 4
}

#endif

#ifdef initializer_list_ret
#include "vector"
#include "deque"
using namespace std;
//��ʼ���б�����������

//����һ����ʼ���б�ͨ���ᵼ�¹���һ����ʱ����

vector<int> Func() {return {1,2}; }
//ʹ�ó�ʼ���б���һ��vector<int>����ʱ���󲢷���

//�������ֵ��һ���������ͣ���᷵��һ����ʱ��������ã�ע���const��ʹ����ֵ����
const vector<int>& Func1() {return {1,2};}

vector<int>&& Func2() {return {1,2};}

auto ini = {1,2,3,5};

#endif




