//
// Created by satellite on 5/4/2023.
//

//����ָ������������

//#define code_5_8
#define code_5_9

#ifdef code_5_8
#include <memory>
#include <iostream>
using namespace std;
int main() {
    unique_ptr<int> up1(new int(11));//�޷����Ƶ�unique_ptr
    unique_ptr<int> up2 = up1;//����ͨ������
    cout << *up1 << endl;//11
    unique_ptr<int> up3 = move(up1);
    //����p3������Ψһ��unique_ptr����ָ��,�޷��������쵫�ǿ����ƶ������Լ��ƶ���ֵ
    cout << *up3 << endl;//11
    cout << *up1 << endl;//����ʱ����
    up3.reset();//��ʽ�ͷ��ڴ�
    up1.reset();//���ᵼ������ʱ����
    cout << *up3 << endl;//����ʱ����

    shared_ptr<int> sp1(new int(22));
    shared_ptr<int> sp2 = sp1;
    cout << *sp1 << endl;//22
    cout << *sp2 << endl;//22
    sp1.reset();
    cout << *sp2 << endl;//22
}
#endif


#ifdef code_5_9

#include <memory>
#include <iostream>

using namespace std;

void Check(weak_ptr<int> &wp) {
    shared_ptr<int> sp = wp.lock();//ת��Ϊshared_ptr<int>
    if (sp != nullptr)
        cout << "still" << *sp << endl;
    else
        cout << "pointer is invalid." << endl;
}

int main() {
    shared_ptr<int> sp1(new int(22));
    shared_ptr<int> sp2 = sp1;
    weak_ptr<int> wp = sp1;//ָ��shared_ptr<int>��ָ����
    cout << *sp1 << endl;//22
    cout << *sp2 << endl;//22
    Check(wp);//still 22

    sp1.reset();
    cout << *sp2 << endl;//22
    Check(wp);//still 22

    sp2.reset();
    Check(wp);//pointer is invalid
}

#endif




