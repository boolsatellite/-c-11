//
// Created by satellite on 2023-05-23.
//





/*
void DoSomething1();
void DoSomething2();
[[noreturn]]void ThrowAway(){
    throw "expection";
}
void Func(){
    DoSomething1();
    ThrowAway();
    DoSomething2();
}
*/

//#define code_8_14
//#define code_8_15
//#define code_8_16
//#define code_8_17
//#define code_8_18
#define code_8_20

#ifdef code_8_14
#include <iostream>
using namespace std;
int main(){
    char utf8[]=u8"\u4F60\u597D\u554A";
    char utf88[]=u8"你好啊";
    char16_t utf16[]=u"hello";
    char32_t utf32[]=U"hello equals\u4F60\u597D\u554A";
    cout<<utf8<<endl;

    cout<<utf16<<endl;
    cout<<utf32<<endl;
/*
    char32_t u2[]=u "hello";//Error
    char u3[]=U "hello";//Error
    char16_t u4=u8 "hello";//Error
*/
}
#endif

#ifdef code_8_15
#include <iostream>
using namespace std;
int main() {
    char utf8[] = u8"\u4F60\u597D\u554A";
    char16_t utf16[] = u"\u4F60\u597D\u554A";
    cout << sizeof(utf8) << endl;//10字节
    cout << sizeof(utf16) << endl;//8字节
    cout << utf8[1] << endl;//输出不可见字符
    cout << utf16[1] << endl;//输出22909(0x597D)
}
#endif

/*c++11中提供了编码转换函数，来完成Unicode编码间的转换
 *
 *mb  multi_byte多字节       rt  convert转换
size_t mbrtoc16(char16_t*pc16,const char*s,size_t n,mbstate_t*ps);
size_t c16rtomb(char*s,char16_t c16,mbstate_t*ps);
size_t mbrtoc32(char32_t*pc32,const char*s,size_t n,mbstate_t*ps);
size_t c32rtomb(char*s,char32_t c32,mbstate_t*ps);

类型 mbstate 用于返回转换中的状态信息
 */


#ifdef code_8_16
#include <iostream>
#include <cuchar>
using namespace std;
int main(){
    char16_t utf16[]=u"\u4F60\u597D\u554A";
    char mbr[sizeof(utf16)*2]={0};//这里我们假设buffer这么大就够了
    mbstate_t s;
    c16rtomb(mbr,utf16[1],&s);
    cout<<mbr<<endl;
}

#endif


#ifdef code_8_17
#include <iostream>
#include <locale>
using namespace std;

int main() {
//定义一个locale并查询该locale是否支持一些facet
    locale lc("en_US.UTF-8");
    bool can_cvt = has_facet<codecvt<wchar_t, char, mbstate_t>>(lc);
    if (!can_cvt)
        cout << "Do not support char-wchar_t facet!" << endl;
    can_cvt = has_facet<codecvt<char16_t, char, mbstate_t>>(lc);
    if (!can_cvt)
        cout << "Do not support char-char16 facet!" << endl;
    can_cvt = has_facet<codecvt<char32_t, char, mbstate_t>>(lc);
    if (!can_cvt)
        cout << "Do not support char-char32 facet!" << endl;
    can_cvt = has_facet<codecvt<char, char, mbstate_t>>(lc);
    if (!can_cvt)
        cout << "Do not support char-char facet!" << endl;
    return 0;
}
#endif


#ifdef code_8_18

#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <iomanip>
using namespace std;
int main() {
//UTF-8字符串,"\x7a\xc3\x9f\xe6\xb0\xb4\xf0\x9d\x84\x8b";
    ofstream("text.txt") << u8"z\u00df\u6c34\U0001d10b";
    wifstream fin("text.txt");
//该locale的facet-codecvt<wchar_t,char,mbstate_t>
//可以将UTF-8转化为UTF-32
    fin.imbue(locale("en_US.UTF-8"));
    cout << "The UTF-8 file contains the following widecharacters:\n";
    for (wchar_t c; fin >> c;)
        cout << "U+" << hex << setw(4) << setfill('0') << c << '\n';
}
#endif

#ifdef code_8_20
#include <iostream>
using namespace std;
int main(){
    cout<<u8R"(\u4F60,\n
\u597D)"<<endl;
    cout<<u8R"(你好)"<<endl;
    cout<<sizeof(u8R"(hello)")<<"\t"<<u8R"(hello)"<<endl;
    cout<<sizeof(uR"(hello)")<<"\t"<<uR"(hello)"<<endl;
    cout<<sizeof(UR"(hello)")<<"\t"<<UR"(hello)"<<endl;
    return 0;
}
#endif
