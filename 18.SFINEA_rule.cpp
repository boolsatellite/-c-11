//
// Created by satellite on 2023-04-26.
//

/*-Substitution failure is not an error��
����ֱ�뼴�ǡ�ƥ��ʧ�ܲ��Ǵ��󡱡���Ϊȷ�е�˵����
�������ʾ���Ƕ����ص�ģ��Ĳ�������չ����ʱ�����չ������
��һЩ���Ͳ�ƥ�䣬�����������ᱨ��*/

//#define code_3_52
#define code_3_53

#ifdef code_3_52

struct Test {
    typedef int foo;
};

template<typename T>
void f(typename T::foo) {}//��һ��ģ�嶨��-#1

template<typename T>
void f(T) {}//�ڶ���ģ�嶨��-#2

int main() {
    f<Test>(10);//����#1.
    f<int>(10);//����#2.����SFINEA����Ȼ����������int::foo��Ҳ���ᷢ���������
}

#endif

#ifdef code_3_53

template<int I>
struct A {
};

char xxx(int);

char xxx(float);

template<class T>
A<sizeof(xxx((T) 0))> f(T) {}

int main() {
    f(1);
}


#endif


//����ѽ��û����
