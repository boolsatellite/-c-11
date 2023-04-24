//
// Created by satellite on 2023-04-24.
//

//内联命名空间

//#define code_3_47
//#define code_3_48
//#define code_3_49
//#define code_3_50

#ifdef code_3_47

#include <iostream>
using namespace std;
//这是Jim编写的库，用了Jim这个名字空间
namespace Jim{
    namespace Basic{
        struct Knife{Knife(){cout<<"Knife in Basic."<<endl;}};
        class CorkScrew{};
    }
    namespace Toolkit{
        template<typename T>class SwissArmyKnife{};
    }
//...
    namespace Other{
        Knife b;//无法通过编译
        struct Knife{Knife(){cout<<"Knife in Other"<<endl;}};
        Knife c;//Knife in Other
        Basic::Knife k;//Knife in Basic
    }
}
//这是LiLei在使用Jim的库
using namespace Jim;
int main(){
    Toolkit::SwissArmyKnife<Basic::Knife>sknife;
}

#endif

/*库的使用者在使用Jim名字空间的时
候，需要知道太多的子名字空间的名字。使用者显然不希望声明一个
sknife变量时，需要Toolkit::SwissArm yKnife<Basic::Knife>这么长的
类型声明*/



#ifdef code_3_48

#include <iostream>
using namespace std;
namespace Jim{
    namespace Basic{
        struct Knife{Knife(){cout<<"Knife in Basic."<<endl;}};
        class CorkScrew{};
    }
    namespace Toolkit{
        template<typename T>class SwissArmyKnife{};
    }
//...
    namespace Other{
//...
    }
//打开一些内部名字空间
    using namespace Basic;
    using namespace Toolkit;
}
//LiLei决定对该class进行特化
/*namespace Jim{
    namespace Toolkit {
        template<>
        class SwissArmyKnife<Knife> {
        };//编译成功
    }
}*/
namespace Jim
{
    template<> class SwissArmyKnife<Knife>{}; //编译失败
    //‘template<class T> class Jim::Toolkit::SwissArmyKnife’ 在其名称空间之外的显式特化必须使用嵌套名称说明符
}
using namespace Jim;
int main(){
    SwissArmyKnife<Knife>sknife;
}
//c++98标准规定，不允许在不同命名空间中对模板特例化
//这样我们在Jim命名空间中打开子命名空间反而让使用者特例化变得困难了

#endif

/*在C++11中，标准引入了一个新特性，叫做“内联的名字空间”。通过
关键字“inline namespace”就可以声明一个内联的名字空间。内联的名
字空间允许程序员在父名字空间定义或特化子名字空间的模板。*/



#ifdef code_3_49

#include <iostream>
using namespace std;

namespace Jim{
    inline namespace Basic{
        struct Knife{Knife(){cout<<"Knife in Basic."<<endl;}};
        class CorkScrew{};
    }
    inline namespace Toolkit{
        template<typename T>class SwissArmyKnife{};
    }
//...
    namespace Other{
        Knife b;//Knife in Basic
        struct Knife{Knife(){cout<<"Knife in Other"<<endl;}};
        Knife c;//Knife in Other
        Basic::Knife k;//Knife in Basic
    }
}
//这是LiLei在使用Jim的库
namespace Jim{
    template<>class SwissArmyKnife<Knife>{};//编译通过
}
using namespace Jim;
int main(){
    SwissArmyKnife<Knife>sknife;
}

/*
输出：
Knife in Basic.
Knife in Other
Knife in Basic.

 */
#endif


#ifdef code_3_50


#include <iostream>
using namespace std;
namespace Jim{
#if __cplusplus==201103L
    inline
#endif
    namespace cpp11{
        struct Knife{Knife(){cout<<"Knife in c++11."<<endl;}};
//...
    }
#if __cplusplus<201103L
    inline
#endif
    namespace oldcpp{
        struct Knife{Knife(){cout<<"Knife in old c++."<<endl;}};
//...
    }
}
using namespace Jim;
int main(){
    Knife a;//Knife in c++11.(默认版本)
    cpp11::Knife b;//Knife in c++11.(强制使用cpp11版本)
    oldcpp::Knife c;//Knife in old c++.(强制使用oldcpp11版本)
}

/*这样一来，编译器就可以根据当前编
译器对C++支持的状况，选择合适的实现版本。而如果需要的话，我
们依然可以通过名字空间的方式（如cpp11::Knife）来访问相应名字空
间中的类型、数据、函数等。这对程序库的发布很有好处，因为需要
长期维护的程序库，可能版本间的接口和实现等都随着程序库的发展
而发生了变化。那么根据需要将合适的名字空间导入到父名字空间
中，无疑会方便库的使用。*/

#endif



/*还有一点需要指出的是，匿名的名字空间同样可以把其包含的名字导
入父名字空间。匿名名字空间无法允许在父名字空间的模板
特化。这也是C++11中为什么要引入新的内联名字空间的一个根本原
因。
名字空间的内联会破坏该名字空间本身具有的封装性，
所以程序员不应该在需要隔离名字
的时候使用inline namespace关键字。*/


/*些C++的语言特性迷惑，比
较典型的是所谓“参数关联名称查找”，即ADL（Argument-Dependent
name Lookup）。这个特性允许编译器在名字空间内找不到函数名称的
时候，在参数的名字空间内查找函数名字。*/



namespace ns_adl{
    struct A{};
    void ADLFunc(A a){}//ADLFunc定义在namespace ns_adl中
}
int main(){
    ns_adl::A a;
    ADLFunc(a);//ADLFunc无需声明名字空间
}

/*函数ADLFunc就无需在使用时声明其所在的名字空间，因为编译器可
以在其参数a的名字空间ns_adl中找到ADLFunc，编译也就不会报错
了。
 这破坏了分装性，因此，比较好的使用方式，还是在使用任何名字前打开名字空间，或
者使用“::”列出变量、函数完整的名字空间。
 */

