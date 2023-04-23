//
// Created by satellite on 2023-04-23.
//

//�û��Զ���������

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
    RGBA col2({15, 255, 10, 7});//C++11�����б��ʼ��
    blend(col1, col2);
}

/*����Ա��
��д����������ʱ�򣬳���������Ҫ�����϶�ֵȷ����RGBA������
��ô��������������-��ֵ����ķ�ʽ�Ǽ��ǳ��鷳�ġ�����Զ�����
�Ϳ�������������һ�������������泣������������func������
�泣��func(2,5.0f)�����������Ĳ��Դ����򻯺ܶ�*/

#endif


/*C++11��׼�������������󣬼����ǿ���ͨ����һ����׺��ʶ�Ĳ���
�����������˸ú�׺��ʶ��������ת��Ϊ��Ҫ�����͡�*/


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

RGBA operator ""_C(const char *col, size_t n) {//һ������Ϊn���ַ���col
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


/*������һ������������������ RGBA operator""_C(const char* col,size_t n) ����
 * �������������� _C ��β���ַ���������һ��RGBA����ʱ��������������һ���û����泣
 * ���Ķ���
 * */

#endif

#ifdef code_3_46
/*��ȥ�ַ����⣬��׺����Ҳ������������ֵ�����磬�û�����ʹ��
60W��120W�ı�ʾ��ʽ����ʶ���ʣ���50kg����ʾ��������1200N��
��ʾ����*/


struct Watt {
    unsigned int v;
};

Watt operator""_w(unsigned long long v) {
    return {(unsigned int) v};
}

int main() {
    Watt capacity = 1024_w;
}

/*����������_w��׺����ʶ���ء��������������û��Զ�������������
�����ڸ��������ȵ�������*/

#endif


/*c++11�б�׼Ҫ��������������������һ���Ĺ���ù�����������ġ����͡����й�ϵ

?���������Ϊ����������ô����������������ֻ�ɽ���unsigned long
long����constchar*Ϊ���������unsigned long long�޷����ɸ�������
��ʱ�򣬱��������Զ�����������ת��Ϊ��\0Ϊ���������ַ�������
������const char*Ϊ�����İ汾���д���

?���������Ϊ����������������������������ֻ�ɽ���long double
����const char*Ϊ������const char*�汾�ĵ��ù���ͬ���͵�һ������
����ʹ��const char*�汾����

?���������Ϊ�ַ���������������������������ֻ�ɽ���const
char*,size_tΪ��������֪���ȵ��ַ�������

?���������Ϊ�ַ���������������������ֻ�ɽ���һ��charΪ��
����

��������˵���û��Զ���������Ϊ������д�����˼���ı�������
�⣬��ʹ��������Ե�ʱ��Ӧ��ע�����¼��㣺


?��׺�������»��߿�ʼ������ʹ�÷��»��ߺ�׺���û��Զ����ַ�
������������ᱻ���������档��Ȼ����Ҳ�ܺ���⣬��Ϊ�������
����201203L����������������׺��L�����ɻ�����һЩ���ҵ�״����Ϊ
�˱�����ң�����Ա���ֻʹ���»��߿�ʼ�ĺ�׺��

 * */