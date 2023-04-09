//
// Created by satellite on 2023-04-09.
//

//非静态成员的 sizeof

/**c++98中对非静态成员·sizeof是不可以通过编译的*/

#include <iostream>
using namespace std;
struct People{
public:
    int hand;
    static People*all;
};
int main(){
    People p;
    cout<<sizeof(p.hand)<<endl;//C++98中通过,C++11中通过
    cout<<sizeof(People::all)<<endl;//C++98中通过,C++11中通过
    cout<<sizeof(People::hand)<<endl;//C++98中错误,C++11中通过
    //在c++11中对非静态成员变量使用sizeof操作是合法的
    //在c++98中只有静态变量，或对象的实例才能对其成员进行sizeof操作
    //c++11中的sizeof可以作用的表达式包括了类成员表达式 sizeof(People::hand),即使hand是一个非静态成员变量

}
