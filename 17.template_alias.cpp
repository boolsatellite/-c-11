//
// Created by satellite on 2023-04-25.
//

//ģ��ı���

#define code_3_51

/*��C++11�У�����
�����Ѿ�������typedef��ר��������ʹ��usingͬ��Ҳ���Զ������͵�
���������Ҵ����������Ͽ���using˿������typedefѷɫ*/


#ifdef code_3_51

#include <iostream>
#include <type_traits>

using namespace std;
using uint = unsigned int;
typedef unsigned int UINT;
using sint = int;

int main() {
    cout << is_same<uint, UINT>::value << endl;//1
}

/*ʹ����C++11��׼���е�is_sameģ���������������ж���
�������Ƿ�һ�¡�is_sameģ�����������������Ϊģ��ʵ����ʱ�Ĳ�
���������Ա����value���ʾ�������������Ƿ�һ��*/


#endif



/*��ʹ��ģ���̵�ʱ��using���﷨������typedef�������*/

#include "map"
template <typename T> using MapString = std::map<T,char*>;
MapString<int> numberedString;

/*���ǡ�ģ��ʽ����ʹ����using�ؼ��֣���std::map<T,char*>��
��Ϊ��һ��MapString���ͣ�֮�����ǻ�����ʹ�����Ͳ�����
MapString�������͵�ʵ��������ʹ��typedef���޷��ﵽ������Ч����
*/

