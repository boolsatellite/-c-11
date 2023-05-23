//
// Created by satellite on 2023-05-22.
//

//对齐方式

//#define code_8_1
//#define code_8_2
//#define code_8_3
//#define code_8_4
//#define code_8_5
//#define code_8_6
//#define code_8_7
#define code_8_8

#ifdef code_8_1
#include <iostream>
#include "algorithm"
#include "cstddef"
using namespace std;
struct HowManyBytes{
    char a;
    int b;
};
int main(){
    cout<<"sizeof(char):"<<sizeof(char)<<endl;
    cout<<"sizeof(int):"<<sizeof(int)<<endl;
    cout<<"sizeof(HowManyBytes):"<<sizeof(HowManyBytes)<<endl;
    cout<<endl;
    cout<<"offset of char a:"<<offsetof(HowManyBytes,a)<<endl;
    cout<<"offset of int b:"<<offsetof(HowManyBytes,b)<<endl;
    return 0;
}
/*在我们的平台定义上，C/C++的int类型数据要求
对齐到4字节，即要求int类型数据必须放在一个能够整除4的地址上；
而char要求对齐到1字节。*/
#endif


#ifdef code_8_2
#include <iostream>

using namespace std;
//自定义的ColorVector，拥有32字节的数据
struct ColorVector {
    double r;
    double g;
    double b;
    double a;
};

int main() {
//使用C++11中的alignof来查询ColorVector的对齐方式
    cout << "alignof(ColorVector):" << alignof(ColorVector) << endl;
    return 1;
}
#endif


#ifdef code_8_3
#include <iostream>
using namespace std;
//自定义的ColorVector，对齐到32字节的边界
struct alignas(32)ColorVector{
    double r;
    double g;
    double b;
    double a;
};
int main(){
//使用C++11中的alignof来查询ColorVector的对齐方式
    cout<<"alignof(ColorVector):"<<alignof(ColorVector)<<endl;
    return 1;
}
#endif


#ifdef code_8_4
#include <iostream>

using namespace std;

class InComplete;

struct Completed {
};

int main() {
    int a;
    long long b;
    auto &c = b;
    char d[1024];
//对内置类型和完整类型使用alignof
    cout << alignof(int) << endl//4
         << alignof(Completed) << endl;//1
//对变量、引用或者数组使用alignof
    cout << alignof(a) << endl//4
         << alignof(b) << endl//8
         << alignof(c) << endl//8，与b相同
         << alignof(d) << endl;//1,与元素要求相同
    //cout<<alignof(Incomplete)<<endl;  本句无法通过编译，Incomplete类型不完整

}
#endif


#ifdef code_8_5
alignas(double)void f();//错误：alignas不能修饰函数
alignas(double)unsigned char c[sizeof(double)];//正确
//extern unsigned char c[sizeof(double)];
//alignas(float) extern unsigned char c[sizeof(double)];//错误：不同对齐方式的变量定义
#endif

#ifdef code_8_6
#include <iostream>

using namespace std;
struct alignas(alignof(double) * 4)ColorVector {
    double r;
    double g;
    double b;
    double a;
};

//固定容量的模板数组
template<typename T>
class FixedCapacityArray {
public:
    void push_back(T t) {/*在data中加入t变量*/}

//...
//一些其他成员函数、成员变量等
//...
    char alignas(T) data[1024] = {0};
//int length=1024/sizeof(T);
};

int main() {
    FixedCapacityArray<char> arrCh;
    cout << "alignof(char):" << alignof(char) << endl;
    cout << "alignof(arrCh.data):" << alignof(arrCh.data) << endl;
    FixedCapacityArray<ColorVector> arrCV;
    cout << "alignof(ColorVector):" << alignof(ColorVector) << endl;
    cout << "alignof(arrCV.data):" << alignof(arrCV.data) << endl;
    return 1;
#endif

#ifdef code_8_7
#include <iostream>
#include <memory>

using namespace std;
struct ColorVector {
    double r;
    double g;
    double b;
    double a;
};

int main() {
    size_t const size = 400;
    ColorVector *const vec = new ColorVector[size];
    void *p = vec;
    size_t sz = size;
    void *aligned = align(alignof(double) * 4, size, p, sz);
    if (aligned != nullptr)
        cout << alignof(p) << endl;
}
#endif


#ifdef code_8_8

#include <iostream>
#include <type_traits>
#include "stddef.h"
#include "stdalign.h"
using namespace std;
//一个对齐值为4的对象
struct IntAligned {
    int a;
    char b;
};

//使用aligned_storage使其对齐要求更加严格
typedef aligned_storage<sizeof(IntAligned)
        ,alignof(long double)>::type StrictAligned;

int main() {
    StrictAligned sa;
    IntAligned *pia = new(&sa)IntAligned;
    cout << alignof(IntAligned) << endl;//4
    cout << alignof(StrictAligned) << endl;//16
    cout << alignof(*pia) << endl;//4
    cout << alignof(sa) << endl;//16
    alignas(8) int c;
    c = 20;
    return 0;
}

#endif
