//
// Created by satellite on 2023-04-09.
//

//�Ǿ�̬��Ա�� sizeof

/**c++98�жԷǾ�̬��Ա��sizeof�ǲ�����ͨ�������*/

#include <iostream>
using namespace std;
struct People{
public:
    int hand;
    static People*all;
};
int main(){
    People p;
    cout<<sizeof(p.hand)<<endl;//C++98��ͨ��,C++11��ͨ��
    cout<<sizeof(People::all)<<endl;//C++98��ͨ��,C++11��ͨ��
    cout<<sizeof(People::hand)<<endl;//C++98�д���,C++11��ͨ��
    //��c++11�жԷǾ�̬��Ա����ʹ��sizeof�����ǺϷ���
    //��c++98��ֻ�о�̬������������ʵ�����ܶ����Ա����sizeof����
    //c++11�е�sizeof�������õı��ʽ���������Ա���ʽ sizeof(People::hand),��ʹhand��һ���Ǿ�̬��Ա����

}
