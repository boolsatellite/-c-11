//
// Created by satellite on 2023-04-23.
//

//用户自定义字面量

//#define code_3_44
//#define code_3_45
#define code_3_46

#ifdef code_3_44

#include <iostream>

using namespace std;
typedef unsigned char uint8;

struct RGBA {
    uint8 r;
    uint8 g;
    uint8 b;
    uint8 a;

    RGBA(uint8 R, uint8 G, uint8 B, uint8 A = 0) :
            r(R), g(G), b(B), a(A) {}
};

std::ostream &operator<<(std::ostream &out, RGBA &col) {
    return out << "r:" << (int) col.r
               << ",g:" << (int) col.g
               << ",b:" << (int) col.b
               << ",a:" << (int) col.a << endl;
}

void blend(RGBA &col1, RGBA &col2) {
    cout << "blend" << endl << col1 << col2 << endl;
}

int main() {
    RGBA col1(255, 240, 155);
    RGBA col2({15, 255, 10, 7});//C++11风格的列表初始化
    blend(col1, col2);
}

/*程序员在
编写测试用例的时候，常会遇到需要声明较多值确定的RGBA变量。
那么这样的声明变量-传值运算的方式是件非常麻烦的。如果自定义类
型可以像内置类型一样向函数传递字面常量，比如向函数func传递字
面常量func(2,5.0f)，无疑这样的测试代码会简化很多*/

#endif


/*C++11标准允许了这种想象，即我们可以通过定一个后缀标识的操作
符，将声明了该后缀标识的字面量转化为需要的类型。*/


#ifdef code_3_45

#include <cstdlib>
#include <iostream>

using namespace std;
typedef unsigned char uint8;

struct RGBA {
    uint8 r;
    uint8 g;
    uint8 b;
    uint8 a;

    RGBA(uint8 R, uint8 G, uint8 B, uint8 A = 0) :
            r(R), g(G), b(B), a(A) {}
};

RGBA operator ""_C(const char *col, size_t n) {//一个长度为n的字符串col
    const char *p = col;
    const char *end = col + n;
    const char *r, *g, *b, *a;
    r = g = b = a = nullptr;
    for (; p != end; ++p) {
        if (*p == 'r')r = p;
        else if (*p == 'g')g = p;
        else if (*p == 'b')b = p;
        else if (*p == 'a')a = p;
    }
    if ((r == nullptr) || (g == nullptr) || (b == nullptr))
        throw;
    else if (a == nullptr)
        return RGBA(atoi(r + 1), atoi(g + 1), atoi(b + 1));
    else
        return RGBA(atoi(r + 1), atoi(g + 1), atoi(b + 1), atoi(a + 1));
}

std::ostream &operator<<(std::ostream &out, RGBA &col) {
    return out << "r:" << (int) col.r
               << ",g:" << (int) col.g
               << ",b:" << (int) col.b
               << ",a:" << (int) col.a << endl;
}

void blend(RGBA &&col1, RGBA &&col2) {
//Some color blending action
    cout << "blend" << endl << col1 << col2 << endl;
}

int main() {
    blend("r255 g240 b155"_C, "r15 g255 b10 a7"_C);
}


/*声明了一个字面量操作符函数 RGBA operator""_C(const char* col,size_t n) 函数
 * 这个函数会解析以 _C 结尾的字符串并返回一个RGBA的临时变量。有了这样一个用户字面常
 * 量的定义
 * */

#endif

#ifdef code_3_46
/*除去字符串外，后缀声明也可以作用于数值，比如，用户可能使用
60W、120W的表示方式来标识功率，用50kg来表示质量，用1200N来
表示力等*/


struct Watt {
    unsigned int v;
};

Watt operator""_w(unsigned long long v) {
    return {(unsigned int) v};
}

int main() {
    Watt capacity = 1024_w;
}

/*这里我们用_w后缀来标识瓦特。除了整型数，用户自定义字面量还可
以用于浮点型数等的字面量*/

#endif


/*c++11中标准要求声明字面量操作符有一定的规则该规则跟字面量的“类型”密切关系

?如果字面量为整型数，那么字面量操作符函数只可接受unsigned long
long或者constchar*为其参数。当unsigned long long无法容纳该字面量
的时候，编译器会自动将该字面量转化为以\0为结束符的字符串，并
调用以const char*为参数的版本进行处理。

?如果字面量为浮点型数，则字面量操作符函数只可接受long double
或者const char*为参数。const char*版本的调用规则同整型的一样（过
长则使用const char*版本）。

?如果字面量为字符串，则字面量操作符函数函数只可接受const
char*,size_t为参数（已知长度的字符串）。

?如果字面量为字符，则字面量操作符函数只可接受一个char为参
数。

总体上来说，用户自定义字面量为代码书写带来了极大的便利。此
外，在使用这个特性的时候，应该注意以下几点：


?后缀建议以下划线开始。不宜使用非下划线后缀的用户自定义字符
串常量，否则会被编译器警告。当然，这也很好理解，因为如果重用
形如201203L这样的字面量，后缀“L”无疑会引起一些混乱的状况。为
了避免混乱，程序员最好只使用下划线开始的后缀名

 * */