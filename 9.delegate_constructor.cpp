//
// Created by satellite on 2023-04-14.
//

//ί�й��캯��

/*
 * ί�ɹ��캯��Ҳ��C++11�ж�C++�Ĺ��캯
 * ����һ��Ľ�����Ŀ��Ҳ��Ϊ�˼��ٳ���Ա��д���캯����ʱ�䡣ͨ
 * ��ί���������캯�����๹�캯�������д����������
 * */

/*class Info{
public:
    Info():type(1),name('a'){InitRest();}
    Info(int i):type(i),name('a'){InitRest();}
    Info(char e):type(1),name(e){InitRest();}
private:
    void InitRest(){*//*������ʼ��*//*}
    int type;
    char name;
//...
};*/

/*�����3�����캯���������˳�ʼ���б�
����ʼ����Աtype��name�����Ҷ���������ͬ�ĺ���InitRest�����Կ�
�������˳�ʼ���б��еĲ�ͬ���������Ĳ��֣�3�����캯����������
���Ƶģ�������������źܶ��ظ���*/

//����ʹ��c++11�ṩ�ĳ����ʼ�����򻯣�


/*class Info{
public:
    Info(){InitRest();}
    Info(int i):type(i),name('a'){InitRest();}
    Info(char e):type(1),name(e){InitRest();}
private:
    void InitRest(){*//*������ʼ��*//*}
    int type = 1;
    char name = 'a';
//...
};*/

//����ȷʵʹ���캯����ü��ˣ�����ÿ�����캯������Ҫ����InitRest����


/*
class Info{
public:
    Info(){InitRest();}   			//��׼�汾�Ĺ��캯��
    Info(int i):Info(){type=i;}  	 //�ڳ�ʼ���б���ί�й��캯�����һ���ֳ�ʼ������
    Info(char e):Info(){name = 'a';}

private:
    void InitRest(){*/
/*������ʼ��*//*
}
    int type{1};
    char name{'a'};
//...
};
*/





/*
 * ί�ɹ��캯��ֻ���ں�������**Ϊtype�� name�ȳ�Ա����ֵ����������ί�ɹ��캯�������г�ʼ���б�
 * ��ɵġ���C++�У����캯������ͬʱ��ί�ɡ���ʹ�ó�ʼ���б�**��
 * ������ ��ί�ɹ��캯��Ҫ����������ֵ����ʼ�����������ں�������*/

/*class Info{
public:
    Info(){InitRest();}
    Info(int i):Info(){type=i;}
    Info(char e):Info(),name('a'){}  //�޷���ʹ��ί�й�����ʹ�ó�ʼ���б�
private:
    void InitRest(){*//*������ʼ��*//*}
    int type{1};
    char name{'a'};
//...
};*/



#include "iostream"

using namespace std;

class Info {
public:
    Info() {
        InitRest();
        cout << "info() type = " << type << endl;
    }            //��׼�汾�Ĺ��캯��
    Info(int i) : Info() {
        cout << "Inof(int) type =" << type << endl;
        type = i;
        cout << "Inof(int) type =" << type << endl;
    }     //�ڳ�ʼ���б���ί�й��캯�����һ���ֳ�ʼ������
    Info(char e) : Info() { name = 'a'; }


    void InitRest() {
        type++;
    }

    int type{1};
    char name{'a'};
//...
};




/*class Info{
public:
    Info():Info(1,'a'){}
    Info(int i):Info(i,'a'){cout<<"Ŀ�깹��"<<endl;}
    Info(char e):Info(1,e){}
private:
    Info(int i,char e):type(i),name(e)
    {
        cout<<"ί�й���"<<endl;
        type++;
    }
    int type;
    char name;
//...
};

int main()
{
    Info f(3);
    //cout<<f.type<<endl;
}*/


#include <list>
#include <vector>
#include <deque>
using namespace std;
class TDConstructed{
    template<class T> TDConstructed(T first,T last):l(first,last){}

    list<short> l;
public:
    TDConstructed(vector<short> &v) : TDConstructed(v.begin(),v.end()){}
    TDConstructed(deque<int> &d) : TDConstructed(d.begin(),d.end()){}

    void show()
    {
        for(auto & i : l)
        {
            cout<<i<<" ";
        }
    }

};

int main()
{
    vector<short>vi = {12,13,35};
    TDConstructed t(vi);
    t.show();
}
