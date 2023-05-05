//
// Created by satellite on 5/4/2023.
//

//智能指针与垃圾回收

//#define code_5_8
#define code_5_9

#ifdef code_5_8
#include <memory>
#include <iostream>
using namespace std;
int main() {
    unique_ptr<int> up1(new int(11));//无法复制的unique_ptr
    unique_ptr<int> up2 = up1;//不能通过编译
    cout << *up1 << endl;//11
    unique_ptr<int> up3 = move(up1);
    //现在p3是数据唯一的unique_ptr智能指针,无法拷贝构造但是可以移动构造以及移动赋值
    cout << *up3 << endl;//11
    cout << *up1 << endl;//运行时错误
    up3.reset();//显式释放内存
    up1.reset();//不会导致运行时错误
    cout << *up3 << endl;//运行时错误

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
    shared_ptr<int> sp = wp.lock();//转换为shared_ptr<int>
    if (sp != nullptr)
        cout << "still" << *sp << endl;
    else
        cout << "pointer is invalid." << endl;
}

int main() {
    shared_ptr<int> sp1(new int(22));
    shared_ptr<int> sp2 = sp1;
    weak_ptr<int> wp = sp1;//指向shared_ptr<int>所指对象
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




