//
// Created by satellite on 2023-04-22.
//

//非受限联合体

//#define code_3_38
//#define code_3_39
//#define code_3_41
//#define code_3_42
#define code_3_43


//在c++98中并不是所有的数据类型都能成为联合体的数据成员。看如下代码：

#ifdef code_3_38
struct Student{   //提供了构造函数，不是平凡类型，自然不是POD类型
    Student(bool g,int a):gender(g),age(a){}
    bool gender;
    int age;
};
union T{
    Student s;//编译失败，不是一个POD类型
    int id;
    char name[10];
};
//事实上c++98标准除了不允许非POD类型以外，还不允许联合体拥有静态或引用类型的成员
#endif


/*C++11标准中，取消了联合体对于数据成员类型的
限制。标准规定，任何非引用类型都可以成为联合体的数据成员，这
样的联合体即所谓的非受限联合体（Unrestricted Union）。*/




#ifdef code_3_39

#include <iostream>
using namespace std;
union T{
    static long Get(){return 32;}
};
int main(){
    cout<<::T::Get()<<endl;
}

#endif



/*c++11标准会默认删除一些非受限联
合体的默认函数。比如，非受限联合体有一个非POD的成员，而该非
POD成员类型拥有有非平凡的构造函数，那么非受限联合体成员的默
认构造函数将被编译器删除。其他的特殊成员函数，例如默认拷贝构
造函数、拷贝赋值操作符以及析构函数等，也将遵从此规则。*/


#ifdef code_3_41

#include <string>
using namespace std;
union T{
    string s;//string有非平凡的构造函数
    int n;
};
int main(){
    T t;//构造失败，因为T的构造函数被删除了
}
/*联合体T拥有一个非POD的成员s。而string有非平
凡的构造函数，因此T的构造函数被删除，其类型的变量t也就无法声
明成功*/

/*
解决方法：
 自己为非受限联合体定义构造函数,通常palcement new会发挥很好的作用
 */

#endif



#ifdef code_3_42

#include <string>
using namespace std;

union T{
    string s;
    int n;
public:
//自定义构造函数和析构函数
    T(){new(&s)string;}  //使用placement new 调用string的构造函数
    ~T(){s.~string();}   //析构时union T也必须是一个string对象，否则会析构错误
};
int main(){
    T t;//构造析构成功
}

#endif


#ifdef code_3_43
/*匿名非受限联合体可以运用于类的声明中，这样的类也被称为“枚举式
的类”（union-like class）*/

#include <cstring>
using namespace std;
struct Student{
    Student(bool g,int a):gender(g),age(a){}
    bool gender;
    int age;
};

class Singer{
public:
    enum Type{STUDENT,NATIVE,FOREIGNER};  //枚举类型
    Singer(bool g,int a):s(g,a){t=STUDENT;}
    Singer(int i):id(i){t=NATIVE;}
    Singer(const char*n,int s){
        int size=(s>9)?9:s;
        memcpy(name,n,size);
        name[s]='\0';
        t=FOREIGNER;
    }
    ~Singer(){}
private:
    Type t;
    union{//匿名的非受限联合体
        Student s;
        int id;
        char name[10];
    };
};
int main(){
    Singer(true,13);
    Singer(310217);
    Singer("J Michael",9);
}

#endif


//匿名联合体在类中的应用没学会

