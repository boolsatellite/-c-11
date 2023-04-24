//
// Created by satellite on 2023-04-24.
//

//���������ռ�

//#define code_3_47
//#define code_3_48
//#define code_3_49
//#define code_3_50

#ifdef code_3_47

#include <iostream>
using namespace std;
//����Jim��д�Ŀ⣬����Jim������ֿռ�
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
        Knife b;//�޷�ͨ������
        struct Knife{Knife(){cout<<"Knife in Other"<<endl;}};
        Knife c;//Knife in Other
        Basic::Knife k;//Knife in Basic
    }
}
//����LiLei��ʹ��Jim�Ŀ�
using namespace Jim;
int main(){
    Toolkit::SwissArmyKnife<Basic::Knife>sknife;
}

#endif

/*���ʹ������ʹ��Jim���ֿռ��ʱ
����Ҫ֪��̫��������ֿռ�����֡�ʹ������Ȼ��ϣ������һ��
sknife����ʱ����ҪToolkit::SwissArm yKnife<Basic::Knife>��ô����
��������*/



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
//��һЩ�ڲ����ֿռ�
    using namespace Basic;
    using namespace Toolkit;
}
//LiLei�����Ը�class�����ػ�
/*namespace Jim{
    namespace Toolkit {
        template<>
        class SwissArmyKnife<Knife> {
        };//����ɹ�
    }
}*/
namespace Jim
{
    template<> class SwissArmyKnife<Knife>{}; //����ʧ��
    //��template<class T> class Jim::Toolkit::SwissArmyKnife�� �������ƿռ�֮�����ʽ�ػ�����ʹ��Ƕ������˵����
}
using namespace Jim;
int main(){
    SwissArmyKnife<Knife>sknife;
}
//c++98��׼�涨���������ڲ�ͬ�����ռ��ж�ģ��������
//����������Jim�����ռ��д��������ռ䷴����ʹ�������������������

#endif

/*��C++11�У���׼������һ�������ԣ����������������ֿռ䡱��ͨ��
�ؼ��֡�inline namespace���Ϳ�������һ�����������ֿռ䡣��������
�ֿռ��������Ա�ڸ����ֿռ䶨����ػ������ֿռ��ģ�塣*/



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
//����LiLei��ʹ��Jim�Ŀ�
namespace Jim{
    template<>class SwissArmyKnife<Knife>{};//����ͨ��
}
using namespace Jim;
int main(){
    SwissArmyKnife<Knife>sknife;
}

/*
�����
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
    Knife a;//Knife in c++11.(Ĭ�ϰ汾)
    cpp11::Knife b;//Knife in c++11.(ǿ��ʹ��cpp11�汾)
    oldcpp::Knife c;//Knife in old c++.(ǿ��ʹ��oldcpp11�汾)
}

/*����һ�����������Ϳ��Ը��ݵ�ǰ��
������C++֧�ֵ�״����ѡ����ʵ�ʵ�ְ汾���������Ҫ�Ļ�����
����Ȼ����ͨ�����ֿռ�ķ�ʽ����cpp11::Knife����������Ӧ���ֿ�
���е����͡����ݡ������ȡ���Գ����ķ������кô�����Ϊ��Ҫ
����ά���ĳ���⣬���ܰ汾��Ľӿں�ʵ�ֵȶ����ų����ķ�չ
�������˱仯����ô������Ҫ�����ʵ����ֿռ䵼�뵽�����ֿռ�
�У����ɻ᷽����ʹ�á�*/

#endif



/*����һ����Ҫָ�����ǣ����������ֿռ�ͬ�����԰�����������ֵ�
�븸���ֿռ䡣�������ֿռ��޷������ڸ����ֿռ��ģ��
�ػ�����Ҳ��C++11��ΪʲôҪ�����µ��������ֿռ��һ������ԭ
��
���ֿռ���������ƻ������ֿռ䱾����еķ�װ�ԣ�
���Գ���Ա��Ӧ������Ҫ��������
��ʱ��ʹ��inline namespace�ؼ��֡�*/


/*ЩC++�����������Ի󣬱�
�ϵ��͵�����ν�������������Ʋ��ҡ�����ADL��Argument-Dependent
name Lookup�������������������������ֿռ����Ҳ����������Ƶ�
ʱ���ڲ��������ֿռ��ڲ��Һ������֡�*/



namespace ns_adl{
    struct A{};
    void ADLFunc(A a){}//ADLFunc������namespace ns_adl��
}
int main(){
    ns_adl::A a;
    ADLFunc(a);//ADLFunc�����������ֿռ�
}

/*����ADLFunc��������ʹ��ʱ���������ڵ����ֿռ䣬��Ϊ��������
���������a�����ֿռ�ns_adl���ҵ�ADLFunc������Ҳ�Ͳ��ᱨ��
�ˡ�
 ���ƻ��˷�װ�ԣ���ˣ��ȽϺõ�ʹ�÷�ʽ��������ʹ���κ�����ǰ�����ֿռ䣬��
��ʹ�á�::���г��������������������ֿռ䡣
 */

