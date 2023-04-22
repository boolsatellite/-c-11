//
// Created by satellite on 2023-04-22.
//

//������������

//#define code_3_38
//#define code_3_39
//#define code_3_41
//#define code_3_42
#define code_3_43


//��c++98�в��������е��������Ͷ��ܳ�Ϊ����������ݳ�Ա�������´��룺

#ifdef code_3_38
struct Student{   //�ṩ�˹��캯��������ƽ�����ͣ���Ȼ����POD����
    Student(bool g,int a):gender(g),age(a){}
    bool gender;
    int age;
};
union T{
    Student s;//����ʧ�ܣ�����һ��POD����
    int id;
    char name[10];
};
//��ʵ��c++98��׼���˲������POD�������⣬��������������ӵ�о�̬���������͵ĳ�Ա
#endif


/*C++11��׼�У�ȡ����������������ݳ�Ա���͵�
���ơ���׼�涨���κη��������Ͷ����Գ�Ϊ����������ݳ�Ա����
���������弴��ν�ķ����������壨Unrestricted Union����*/




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



/*c++11��׼��Ĭ��ɾ��һЩ��������
�����Ĭ�Ϻ��������磬��������������һ����POD�ĳ�Ա�����÷�
POD��Ա����ӵ���з�ƽ���Ĺ��캯������ô�������������Ա��Ĭ
�Ϲ��캯������������ɾ���������������Ա����������Ĭ�Ͽ�����
�캯����������ֵ�������Լ����������ȣ�Ҳ����Ӵ˹���*/


#ifdef code_3_41

#include <string>
using namespace std;
union T{
    string s;//string�з�ƽ���Ĺ��캯��
    int n;
};
int main(){
    T t;//����ʧ�ܣ���ΪT�Ĺ��캯����ɾ����
}
/*������Tӵ��һ����POD�ĳ�Աs����string�з�ƽ
���Ĺ��캯�������T�Ĺ��캯����ɾ���������͵ı���tҲ���޷���
���ɹ�*/

/*
���������
 �Լ�Ϊ�����������嶨�幹�캯��,ͨ��palcement new�ᷢ�Ӻܺõ�����
 */

#endif



#ifdef code_3_42

#include <string>
using namespace std;

union T{
    string s;
    int n;
public:
//�Զ��幹�캯������������
    T(){new(&s)string;}  //ʹ��placement new ����string�Ĺ��캯��
    ~T(){s.~string();}   //����ʱunion TҲ������һ��string���󣬷������������
};
int main(){
    T t;//���������ɹ�
}

#endif


#ifdef code_3_43
/*���������������������������������У���������Ҳ����Ϊ��ö��ʽ
���ࡱ��union-like class��*/

#include <cstring>
using namespace std;
struct Student{
    Student(bool g,int a):gender(g),age(a){}
    bool gender;
    int age;
};

class Singer{
public:
    enum Type{STUDENT,NATIVE,FOREIGNER};  //ö������
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
    union{//�����ķ�����������
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


//���������������е�Ӧ��ûѧ��

