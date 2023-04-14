//
// Created by satellite on 2023-04-14.
//

//委托构造函数

/*
 * 委派构造函数也是C++11中对C++的构造函
 * 数的一项改进，其目的也是为了减少程序员书写构造函数的时间。通
 * 过委派其他构造函数，多构造函数的类编写将更加容易
 * */

/*class Info{
public:
    Info():type(1),name('a'){InitRest();}
    Info(int i):type(i),name('a'){InitRest();}
    Info(char e):type(1),name(e){InitRest();}
private:
    void InitRest(){*//*其他初始化*//*}
    int type;
    char name;
//...
};*/

/*这里的3个构造函数都声明了初始化列表
来初始化成员type和name，并且都调用了相同的函数InitRest。可以看
到，除了初始化列表有的不同，而其他的部分，3个构造函数基本上是
相似的，因此其代码存在着很多重复。*/

//可以使用c++11提供的成语初始化来简化：


/*class Info{
public:
    Info(){InitRest();}
    Info(int i):type(i),name('a'){InitRest();}
    Info(char e):type(1),name(e){InitRest();}
private:
    void InitRest(){*//*其他初始化*//*}
    int type = 1;
    char name = 'a';
//...
};*/

//这样确实使构造函数变得简单了，但是每个构造函数都需要调用InitRest函数


/*
class Info{
public:
    Info(){InitRest();}   			//基准版本的构造函数
    Info(int i):Info(){type=i;}  	 //在初始化列表中委托构造函数完成一部分初始化工作
    Info(char e):Info(){name = 'a';}

private:
    void InitRest(){*/
/*其他初始化*//*
}
    int type{1};
    char name{'a'};
//...
};
*/





/*
 * 委派构造函数只能在函数体中**为type、 name等成员赋初值，这是由于委派构造函数不能有初始化列表
 * 造成的。在C++中，构造函数不能同时“委派”和使用初始化列表**，
 * 所以如 果委派构造函数要给变量赋初值，初始化代码必须放在函数体中*/

/*class Info{
public:
    Info(){InitRest();}
    Info(int i):Info(){type=i;}
    Info(char e):Info(),name('a'){}  //无法即使用委托构造又使用初始化列表
private:
    void InitRest(){*//*其他初始化*//*}
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
    }            //基准版本的构造函数
    Info(int i) : Info() {
        cout << "Inof(int) type =" << type << endl;
        type = i;
        cout << "Inof(int) type =" << type << endl;
    }     //在初始化列表中委托构造函数完成一部分初始化工作
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
    Info(int i):Info(i,'a'){cout<<"目标构造"<<endl;}
    Info(char e):Info(1,e){}
private:
    Info(int i,char e):type(i),name(e)
    {
        cout<<"委托构造"<<endl;
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
