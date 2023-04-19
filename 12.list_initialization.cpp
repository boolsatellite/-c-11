//
// Created by satellite on 2023-04-18.
//

//列表初始化

//#define initializer list test
//#define use initializer list
//#define use_initializer_list_inFuncLisat
#define initializer_list_ret

#ifdef initializer list test
#include <vector>
#include <map>
using namespace std;
int a[]={1,3,5};//C++98通过，C++11通过
int b[]{2,4,6};//C++98失败，C++11通过
vector<int> c{1,3,5};//C++98失败，C++11通过
map<int,float>d=
        {{1,1.0f},{2,2.0f},{5,3.2f}};//C++98失败，C++11通过
#endif


/*
 自动变量和全局变量的初始化在c++11中背丰富了：
 等号“=”加上赋值表达式（assignment-expression)，比如int a=3+4。
 等号“=”加上花括号式的初始化列表，比如int a={3+4}。
 圆括号式的表达式列表（expression-list），比如int a(3+4)。
 花括号式的初始化列表，比如int a{3+4}。

 最后两种也可以用于获取都内存new操作符中：
 int *i = new int(1);
 double *d = new double(1.2f);
 */


/*
标准模板库中容器对初始化列表
的支持源自<initializer_list>这个头文件中initialize_list类模板的支
持。程序员只要#include了<initializer_list>头文件，并且声明一个以
initialize_list<T>模板类为参数的构造函数，同样可以使得自定义的
类使用列表初始化。
 */


#ifdef use_initializer_list_inConstructor

#include <vector>
#include <string>
using namespace std;

//自定义类使用初始化列表初始化
enum Gender{boy,girl};
class People{
public:
    People(initializer_list<pair<string,Gender>>l) //提供了以initialize_list为参数的购构造函数
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
//函数参数列表中使用初始化列表
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
    Fun({});//空列表
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
    vector<int> idx;//辅助数组，用于记录index
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
//初始化列表做函数返回

//返回一个初始化列表，通常会导致构造一个临时变量

vector<int> Func() {return {1,2}; }
//使用初始化列表构造一个vector<int>的临时对象并返回

//如果返回值是一个引用类型，则会返回一个临时对象的引用，注意加const或使用右值引用
const vector<int>& Func1() {return {1,2};}

vector<int>&& Func2() {return {1,2};}

auto ini = {1,2,3,5};

#endif




