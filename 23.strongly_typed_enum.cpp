//
// Created by satellite on 2023-04-30.
//��һ�����ˣ�����40���Ӣ�����ˣ�ϲ����Ů���ء���������Щ��֡��G~~�������


//ǿ����ö��

//#define code_5_1
//#define code_5_2
//#define code_5_3
//#define code_5_4
//#define code_5_5
//#define code_5_6
#define code_5_7

/*C/C++��enum�и��ܡ���֡����趨�����Ǿ����������֣���enum����
�����֣��Լ�enum�ĳ�Ա�����ֶ���ȫ�ֿɼ��ġ�����C++�о�����
namespace��class/struct��union����ͨ��������::��Ա�����ķ�ʽ������
���Ǹ�����*/

//���´��뽫����
/*
enum Type{General , Light , medium , Heavy};
enum Categoty{Type,General , Pistol , MachineGun , Cannon};
*/
//Category�е�General��Type�е�General����ȫ�ֵ����֣���˱���ᱨ��

#ifdef code_5_1
#include <iostream>
using namespace std;
namespace T{
    enum Type{General,Light,Medium,Heavy};
}
namespace{   //���������ռ䣬�����ݽ��ڱ��ļ���Ч
    enum Category{General=1,Pistol,MachineGun,Cannon};
}
int main(){
    T::Type t=T::Light;
    if(t==General)//����ʹ��namespace T ����T::General
        cout<<"General Weapon"<<endl;
    return 0;
}
/*Category��һ������namespace�У���������ö�ٳ�Ա����
Ĭ�Ͻ���ȫ�����ֿռ䡣һ������Ա�ڼ��t��ֵ��ʱ������ʹ����
namespace T���ͻᵼ�´���Ľ��*/
#endif

/*C������ö�ٱ����Ϊ������ֵ�ġ��������ı��ԣ�����ö�ٵ�
��Ա���ǿ��Ա���ʽ��ת��Ϊ���͡��ܶ�ʱ����Ҳ�ǲ���ȫ�ġ�*/


#ifdef code_5_2
#include <iostream>
using namespace std;
enum Type{General,Light,Medium,Heavy};
//enum Category{General,Pistol,MachineGun,Cannon};//�޷�����ͨ�����ظ�������General
enum Category{Pistol,MachineGun,Cannon};
struct Killer{
    Killer(Type t,Category c):type(t),category(c){}
    Type type;
    Category category;
};
int main(){
    Killer cool(General,MachineGun);
//...�����ܶ����...
    if(cool.type>=Pistol)  //cool.type��Typeö�٣�Pistol��Pategoryö���еĳ�Ա
    cout<<"It is not a pistol"<<endl;
//...
    cout<<is_pod<Type>::value<<endl;//1
    cout<<is_pod<Category>::value<<endl;//1
    return 0;
}

/*��������ö��������ֵ�ڽ�����ֵ�Ƚ�����
ʱ�����ȱ���ʽ������Ϊint�������ݣ�Ȼ�����ɵؽ��бȽ�����*/
#endif

//Ϊ�˽����һ���⣬Ŀǰ����Աһ����ö�����ͽ��з�װ

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
    //��̬��Ա���������࣬�������ڶ��������ݶο����ڴ�
    //���ǣ������������������������̬���ݳ�Ա��ԭ��
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
//ʹ�����Ͱ�װ���enum
    Killer notCool(Type::General,Category::MachineGun);
//...
//...�����ܶ����...
//...
    if(notCool.type>=Type::General)//����ͨ������
    cout<<"It is not general"<<endl;
    if(notCool.type>=Category::Pistol)//�þ��޷�����ͨ��,�Ľ��˲�ͬ���ͱȽϿ���ͨ������
    cout<<"It is not a pistol"<<endl;
//...
    cout<<is_pod<Type>::value<<endl;//0
    cout<<is_pod<Category>::value<<endl;//0
    return 0;
}
/*
 * һ�����Ա����Ϊ�˼򵥵�enum��������ô���ӵķ�װ��
 * �ƻ���POD����
 * �����ϵͳ��ABI�涨�����ݲ�����ʱ����������Ǹ��ṹ�壬��
����ʹ�üĴ��������Σ�ֻ�ܷ��ڶ�ջ�ϣ�������Եأ����Ϳ���ͨ
���Ĵ����д��ݡ�����һ����class��װ�汾��ö����Ϊ����������
�ݣ��Ϳ��ܴ���һ����������ʧ*/
#endif


//���⣬ö��������ռ�õĿռ��СҲ��һ������ȷ����������׼�涨��
//C++ö�������ڵġ��������͡����ɱ�����������ָ��ʵ�ֵģ���ᵼ
//��ö�����ͳ�Ա�Ļ������͵Ĳ�ȷ�������⣨�����Ƿ����ԣ���
#ifdef code_5_4
#include <iostream>
using namespace std;
enum C{C1=1,C2=2};
enum D{D1=1,D2=2,Dbig=0xFFFFFFF0U};
enum E{E1=1,E2=2,Ebig=0xFFFFFFFFFLL};
int main(){
    cout<<sizeof(C1)<<endl;//4
    cout<<Dbig<<endl;//�����������ͬ,g++��4294967280
    cout<<sizeof(D1)<<endl;//4
    cout<<sizeof(Dbig)<<endl;//4
    cout<<Ebig<<endl;//68719476735
    cout<<sizeof(E1)<<endl;//8
    return 0;
}
/*���ǿ��Կ����������������������
�͵Ĳ�ͬ��enumӦ�ò�ͬ�����ݳ��ȡ������Ƕ�g++�Ĳ����У���ͨ
��ö��ʹ����4�ֽڵ��ڴ棬������Ҫ��ʱ�򣬻���չΪ8�ֽڡ���
�⣬���ڲ�ͬ�ı�������������Dbig�����������᲻ͬ��ʹ��
Visual C++��������������Ϊ-16����ʹ��g++���������Ϊ
4294967280����������Visual C++����ʹ���޷���������Ϊö�ٵĵ�
��ʵ�֣���g++�����ö�ٵ����ͽ��б䶯��ɵġ�
*/
#endif

/*��ǿ����������������ʽת��Ϊ���ͣ�ռ�ô洢�ռ估�����Բ�ȷ
��������ö�����ȱ�㡣�����Щȱ�㣬�±�׼C++11������һ����
��ö�����ͣ�����ö���ࡱ���ֳơ�ǿ����ö�١�(strong-typed enum)��

����Ϊ��enum class Type{General , Light , Medium , Heavy};
����ָ���ײ����͡�ǿ����ö��Ĭ�ϵĵײ�����Ϊint,��Ҳ������ʽ
��ָ���ײ����ͣ����巽��Ϊ��ö�����ƺ�����ϡ���type��������type
�����ǳ�wchar_t������κ����͡�
 enum class Type:char{General,Light,Medium,Heavy};  ָ���˵ײ�ʹ��char���洢
 */

#ifdef code_5_5
#include <iostream>
using namespace std;
enum class Type{General,Light,Medium,Heavy};
enum class Category{General=1,Pistol,MachineGun,Cannon};
int main(){
    Type t=Type::Light;
    t=General;//����ʧ�ܣ�����ʹ��ǿ��������
    if(t==Category::General)//����ʧ�ܣ�����ʹ��Type�е�General
        cout<<"General Weapon"<<endl;
    if(t>Type::General)//ͨ������
    cout<<"Not General Weapon"<<endl;
    if(t>0)//����ʧ�ܣ��޷�ת��Ϊint����
    cout<<"Not General Weapon"<<endl;
    if((int)t>0)//ͨ������
    cout<<"Not General Weapon"<<endl;
    cout<<is_pod<Type>::value<<endl;//1
    cout<<is_pod<Category>::value<<endl;//1
    return 0;
}

#endif


#ifdef code_5_6
/*���ڿ���ָ���ײ���ڵĻ������ͣ����ǿ��Ա����������ͬ
�������Ĳ�����ֲ�ԡ����⣬���ý�С�Ļ�������Ҳ���Խ�ʡ�ڴ��
��*/

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
    cout << (unsigned int) D::Dbig << endl;//���������һ��,4294967280
    cout << sizeof(D::D1) << endl;//4
    cout << sizeof(D::Dbig) << endl;//4
    return 0;
}

/*����������ǿ����ö�ٵ�ʱ��Ҳ����ʹ�ùؼ���enum
struct����ʵ��enum struct��enum class���﷨��û���κ�����enum
class�ĳ�Աû�й���˽��֮�֣�Ҳ����ʹ��ģ����֧�ַ�������
������
*/
#endif

#ifdef code_5_7
enum class{General,Light,Medium,Heavy}weapon;
int main(){
    weapon=General;//�޷�����ͨ��
    bool b=(weapon==weapon::General);//�޷�����ͨ��
    return 0;
}
//ʹ��emum class ʱ��һ������Ϊenum class �ṩһ������

#endif
