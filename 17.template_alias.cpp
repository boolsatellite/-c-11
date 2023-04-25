//
// Created by satellite on 2023-04-25.
//

//模板的别名

#define code_3_51

/*在C++11中，定义
别名已经不再是typedef的专属能力，使用using同样也可以定义类型的
别名，而且从语言能力上看，using丝毫不比typedef逊色*/


#ifdef code_3_51

#include <iostream>
#include <type_traits>

using namespace std;
using uint = unsigned int;
typedef unsigned int UINT;
using sint = int;

int main() {
    cout << is_same<uint, UINT>::value << endl;//1
}

/*使用了C++11标准库中的is_same模板类来帮助我们判断两
个类型是否一致。is_same模板类接受两个类型作为模板实例化时的参
数，而其成员类型value则表示两个参数类型是否一样*/


#endif



/*在使用模板编程的时候，using的语法甚至比typedef更加灵活*/

#include "map"
template <typename T> using MapString = std::map<T,char*>;
MapString<int> numberedString;

/*我们“模板式”地使用了using关键字，将std::map<T,char*>定
义为了一个MapString类型，之后我们还可以使用类型参数对
MapString进行类型的实例化，而使用typedef将无法达到这样的效果。
*/

