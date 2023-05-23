//
// Created by satellite on 2023-05-22.
//

//���뷽ʽ

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
/*�����ǵ�ƽ̨�����ϣ�C/C++��int��������Ҫ��
���뵽4�ֽڣ���Ҫ��int�������ݱ������һ���ܹ�����4�ĵ�ַ�ϣ�
��charҪ����뵽1�ֽڡ�*/
#endif


#ifdef code_8_2
#include <iostream>

using namespace std;
//�Զ����ColorVector��ӵ��32�ֽڵ�����
struct ColorVector {
    double r;
    double g;
    double b;
    double a;
};

int main() {
//ʹ��C++11�е�alignof����ѯColorVector�Ķ��뷽ʽ
    cout << "alignof(ColorVector):" << alignof(ColorVector) << endl;
    return 1;
}
#endif


#ifdef code_8_3
#include <iostream>
using namespace std;
//�Զ����ColorVector�����뵽32�ֽڵı߽�
struct alignas(32)ColorVector{
    double r;
    double g;
    double b;
    double a;
};
int main(){
//ʹ��C++11�е�alignof����ѯColorVector�Ķ��뷽ʽ
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
//���������ͺ���������ʹ��alignof
    cout << alignof(int) << endl//4
         << alignof(Completed) << endl;//1
//�Ա��������û�������ʹ��alignof
    cout << alignof(a) << endl//4
         << alignof(b) << endl//8
         << alignof(c) << endl//8����b��ͬ
         << alignof(d) << endl;//1,��Ԫ��Ҫ����ͬ
    //cout<<alignof(Incomplete)<<endl;  �����޷�ͨ�����룬Incomplete���Ͳ�����

}
#endif


#ifdef code_8_5
alignas(double)void f();//����alignas�������κ���
alignas(double)unsigned char c[sizeof(double)];//��ȷ
//extern unsigned char c[sizeof(double)];
//alignas(float) extern unsigned char c[sizeof(double)];//���󣺲�ͬ���뷽ʽ�ı�������
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

//�̶�������ģ������
template<typename T>
class FixedCapacityArray {
public:
    void push_back(T t) {/*��data�м���t����*/}

//...
//һЩ������Ա��������Ա������
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
//һ������ֵΪ4�Ķ���
struct IntAligned {
    int a;
    char b;
};

//ʹ��aligned_storageʹ�����Ҫ������ϸ�
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
