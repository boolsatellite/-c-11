//
// Created by satellite on 2023-04-29.
//


//���ڷ�Χ��forѭ��


//#define code_4_33
//#define code_4_34
//#define code_4_35
//#define code_4_36
#define code_4_37

#ifdef code_4_33

#include <iostream>
using namespace std;
int main(){
    int arr[5]={1,2,3,4,5};
    int*p;
    for(p=arr;p<arr+sizeof(arr)/sizeof(arr[0]);++p){
        *p*=2;
    }
    for(p=arr;p<arr+sizeof(arr)/sizeof(arr[0]);++p){
        cout<<*p<<'\t';
    }
}

#endif

//��c++ģ����У������ҵ�for_each��ģ�庯��

#ifdef code_4_34

#include <algorithm>
#include <iostream>
using namespace std;
int action1(int&e){e*=2;}
int action2(int&e){cout<<e<<'\t';}
int main(){
    int arr[5]={1,2,3,4,5};
    for_each(arr,arr+sizeof(arr)/sizeof(arr[0]),action1);
    for_each(arr,arr+sizeof(arr)/sizeof(arr[0]),action2);
}
/*for_eachʹ���˵������ĸ�������������ָ�롣���ڵ������ں���
���������ĸ������������嵥4-33�е�++p��������Բ�д��
for_eachѭ������*/
#endif

/*����һ���з�
Χ�ļ��϶��ԣ��ɳ���Ա��˵��ѭ���ķ�Χ�Ƕ���ģ�Ҳ�����׷���
��ġ���C++11Ҳ�����˻��ڷ�Χ��forѭ�����Ϳ��Ժܺõؽ������
�����⡣*/


#ifdef code_4_35
#include "iostream"
using namespace std;
int main(){
    int arr[5]={1,2,3,4,5};
    for(int&e:arr)
    e*=2;
    for(int&e:arr)
    cout<<e<<'\t';
}
#endif


/*�Ƿ��ܹ�ʹ�û��ڷ�Χ��forѭ��������������һЩ��
�������ȣ�����forѭ�������ķ�Χ�ǿ�ȷ���ġ���������˵�������
����begin��end��������ôbegin��end֮�����forѭ�������ķ�Χ��
��������ԣ���������ĵ�һ�������һ��Ԫ�ؼ�ķ�Χ������
�ڷ�Χ��forѭ����Ҫ������Ķ���ʵ��++��==�Ȳ�����*/



/*�෴��������������С����ȷ���Ļ����ǲ��ܹ�ʹ�û��ڷ�Χ��forѭ����*/

#ifdef code_4_36
#include <iostream>
using namespace std;
int func(int a[]){
    for(auto e:a)   //�޷�ʹ�÷�Χ��ȷ�����������ڻ��ڷ�Χ��forѭ��
        cout<<e;
}
int main(){
    int arr[]={1,2,3,4,5};
    func(arr);
}
#endif


#ifdef code_4_37
#include <vector>
#include <iostream>
using namespace std;
int main(){
    vector<int> v={1,2,3,4,5};
    for(auto i=v.begin();i!=v.end();++i)
        cout<<*i<<endl;//i�ǵ���������
    for(auto e:v)
        cout<<e<<endl;//e�ǽ����ú�Ķ���
}
//ע�⣺ e��*i������

#endif
