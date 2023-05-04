//
// Created by satellite on 2023-04-30.
//五一结束了，玩了40多把英雄联盟，喜欢的女孩呢…………有些奇怪。欸~~再想想吧


//强类型枚举

//#define code_5_1
//#define code_5_2
//#define code_5_3
//#define code_5_4
//#define code_5_5
//#define code_5_6
#define code_5_7

/*C/C++的enum有个很“奇怪”的设定，就是具名（有名字）的enum类型
的名字，以及enum的成员的名字都是全局可见的。这与C++中具名的
namespace、class/struct及union必须通过“名字::成员名”的方式访问相
比是格格不入的*/

//如下代码将报错：
/*
enum Type{General , Light , medium , Heavy};
enum Categoty{Type,General , Pistol , MachineGun , Cannon};
*/
//Category中的General和Type中的General都是全局的名字，因此编译会报错

#ifdef code_5_1
#include <iostream>
using namespace std;
namespace T{
    enum Type{General,Light,Medium,Heavy};
}
namespace{   //匿名命名空间，其内容仅在本文件有效
    enum Category{General=1,Pistol,MachineGun,Cannon};
}
int main(){
    T::Type t=T::Light;
    if(t==General)//忘记使用namespace T 即：T::General
        cout<<"General Weapon"<<endl;
    return 0;
}
/*Category在一个匿名namespace中，所以所有枚举成员名都
默认进入全局名字空间。一旦程序员在检查t的值的时候忘记使用了
namespace T，就会导致错误的结果*/
#endif

/*C语言中枚举被设计为常量数值的“别名”的本性，所以枚举的
成员总是可以被隐式地转换为整型。很多时候，这也是不安全的。*/


#ifdef code_5_2
#include <iostream>
using namespace std;
enum Type{General,Light,Medium,Heavy};
//enum Category{General,Pistol,MachineGun,Cannon};//无法编译通过，重复定义了General
enum Category{Pistol,MachineGun,Cannon};
struct Killer{
    Killer(Type t,Category c):type(t),category(c){}
    Type type;
    Category category;
};
int main(){
    Killer cool(General,MachineGun);
//...其他很多代码...
    if(cool.type>=Pistol)  //cool.type是Type枚举，Pistol是Pategory枚举中的成员
    cout<<"It is not a pistol"<<endl;
//...
    cout<<is_pod<Type>::value<<endl;//1
    cout<<is_pod<Category>::value<<endl;//1
    return 0;
}

/*这是由于枚举类型数值在进行数值比较运算
时，首先被隐式地提升为int类型数据，然后自由地进行比较运算*/
#endif

//为了解决这一问题，目前程序员一般会对枚举类型进行封装

#ifdef code_5_3
#include <iostream>
using namespace std;
class Type{
public:
    enum type{general,light,medium,heavy};
    type val;
public:
    Type(type t):val(t){}
    bool operator>=(const Type&t){return val>=t.val;}
    static const Type General,Light,Medium,Heavy;
    //静态成员变量属于类，而不属于对象，在数据段开辟内存
    //这是，可以在类内中声明本类对象静态数据成员的原因
};
const Type Type::General(Type::general);
const Type Type::Light(Type::light);
const Type Type::Medium(Type::medium);
const Type Type::Heavy(Type::heavy);

class Category{
public:
    enum category{pistol,machineGun,cannon};
    category val;
public:
    Category(category c):val(c){}
    bool operator>=(const Category&c){return val>=c.val;}
    static const Category Pistol,MachineGun,Cannon;
};
const Category Category::Pistol(Category::pistol);
const Category Category::MachineGun(Category::machineGun);
const Category Category::Cannon(Category::cannon);

struct Killer{
    Killer(Type t,Category c):type(t),category(c){}
    Type type;
    Category category;
};
int main(){
//使用类型包装后的enum
    Killer notCool(Type::General,Category::MachineGun);
//...
//...其他很多代码...
//...
    if(notCool.type>=Type::General)//可以通过编译
    cout<<"It is not general"<<endl;
    if(notCool.type>=Category::Pistol)//该句无法编译通过,改进了不同类型比较可以通过编译
    cout<<"It is not a pistol"<<endl;
//...
    cout<<is_pod<Type>::value<<endl;//0
    cout<<is_pod<Category>::value<<endl;//0
    return 0;
}
/*
 * 一般程序员不会为了简单的enum声明做这么复杂的封装。
 * 破坏了POD类型
 * 大多数系统的ABI规定，传递参数的时候如果参数是个结构体，就
不能使用寄存器来传参（只能放在堆栈上），而相对地，整型可以通
过寄存器中传递。所以一旦将class封装版本的枚举作为函数参数传
递，就可能带来一定的性能损失*/
#endif


//此外，枚举类型所占用的空间大小也是一个“不确定量”。标准规定，
//C++枚举所基于的“基础类型”是由编译器来具体指定实现的，这会导
//致枚举类型成员的基本类型的不确定性问题（尤其是符号性）。
#ifdef code_5_4
#include <iostream>
using namespace std;
enum C{C1=1,C2=2};
enum D{D1=1,D2=2,Dbig=0xFFFFFFF0U};
enum E{E1=1,E2=2,Ebig=0xFFFFFFFFFLL};
int main(){
    cout<<sizeof(C1)<<endl;//4
    cout<<Dbig<<endl;//编译器输出不同,g++：4294967280
    cout<<sizeof(D1)<<endl;//4
    cout<<sizeof(Dbig)<<endl;//4
    cout<<Ebig<<endl;//68719476735
    cout<<sizeof(E1)<<endl;//8
    return 0;
}
/*我们可以看到，编译器会根据数据类
型的不同对enum应用不同的数据长度。在我们对g++的测试中，普通
的枚举使用了4字节的内存，而当需要的时候，会拓展为8字节。此
外，对于不同的编译器，上例中Dbig的输出结果将会不同：使用
Visual C++编译程序的输出结果为-16，而使用g++来编译输出为
4294967280。这是由于Visual C++总是使用无符号类型作为枚举的底
层实现，而g++会根据枚举的类型进行变动造成的。
*/
#endif

/*非强类型作用域，允许隐式转换为整型，占用存储空间及符号性不确
定，都是枚举类的缺点。针对这些缺点，新标准C++11引入了一种新
的枚举类型，即“枚举类”，又称“强类型枚举”(strong-typed enum)。

声明为：enum class Type{General , Light , Medium , Heavy};
可以指定底层类型。强类型枚举默认的底层类型为int,但也可以显式
地指定底层类型，具体方法为在枚举名称后面加上“：type”，其中type
可以是除wchar_t以外的任何整型。
 enum class Type:char{General,Light,Medium,Heavy};  指定了底层使用char来存储
 */

#ifdef code_5_5
#include <iostream>
using namespace std;
enum class Type{General,Light,Medium,Heavy};
enum class Category{General=1,Pistol,MachineGun,Cannon};
int main(){
    Type t=Type::Light;
    t=General;//编译失败，必须使用强类型名称
    if(t==Category::General)//编译失败，必须使用Type中的General
        cout<<"General Weapon"<<endl;
    if(t>Type::General)//通过编译
    cout<<"Not General Weapon"<<endl;
    if(t>0)//编译失败，无法转换为int类型
    cout<<"Not General Weapon"<<endl;
    if((int)t>0)//通过编译
    cout<<"Not General Weapon"<<endl;
    cout<<is_pod<Type>::value<<endl;//1
    cout<<is_pod<Category>::value<<endl;//1
    return 0;
}

#endif


#ifdef code_5_6
/*由于可以指定底层基于的基本类型，我们可以避免编译器不同
而带来的不可移植性。此外，设置较小的基本类型也可以节省内存空
间*/

#include "iostream"

using namespace std;
enum class C : char {
    C1 = 1, C2 = 2
};
enum class D : unsigned int {
    D1 = 1, D2 = 2, Dbig = 0xFFFFFFF0U
};

int main() {
    cout << sizeof(C::C1) << endl;//1
    cout << (unsigned int) D::Dbig << endl;//编译器输出一致,4294967280
    cout << sizeof(D::D1) << endl;//4
    cout << sizeof(D::Dbig) << endl;//4
    return 0;
}

/*我们在声明强类型枚举的时候，也可以使用关键字enum
struct。事实上enum struct和enum class在语法上没有任何区别（enum
class的成员没有公有私有之分，也不会使用模板来支持泛化的声
明）。
*/
#endif

#ifdef code_5_7
enum class{General,Light,Medium,Heavy}weapon;
int main(){
    weapon=General;//无法编译通过
    bool b=(weapon==weapon::General);//无法编译通过
    return 0;
}
//使用emum class 时，一个总是为enum class 提供一个名字

#endif
