//
// Created by satellite on 2023-04-06.
//
#include "assert.h"   //断言assert所在头文件
#include "iostream"
#include "cstring"

//assert断言
int* ArrAlloc(int n)
{
    assert(n > 0);
    return new int[n];
}

int main()
{
    ArrAlloc(0);
}




/*
//枚举编译器对各种特性的支持,每个枚举值占一位
enum FeatureSupports{
    C99=0x0001,
    ExtInt=0x0002,
    SAssert=0x0004,
    NoExcept=0x0008,
    SMAX=0x0010,
};
//一个编译器类型，包括名称、特性支持等
struct Compiler{
    const char*name;
    int spp;//使用FeatureSupports枚举
};
int main(){
//检查枚举值是否完备
    assert((SMAX-1)==(C99|ExtInt|SAssert|NoExcept));
    //assert为运行时断言
    Compiler a={"abc",(C99|SAssert)};
//...
    if(a.spp & C99){
//一些代码...
    }
}
 */


//静态断言： static_assert(返回bool类型的表达式，用于说明断言错误的字符串)
/*
template<typename t,typename u>
int bit_copy(t&a,u&b)
{
    static_assert(sizeof(b)==sizeof(a),"the parameters of bit_copymust havesame width.");
};

int main(){
    int a=0x2468;
    double b;
    bit_copy(a,b);
}
*/

int positive(const int n)
{
    const int m = 20;
    static_assert(m>0,"value must＞0");
}
