//
// Created by satellite on 2023-04-29.
//


//基于范围的for循环


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

//在c++模板库中，可以找到for_each的模板函数

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
/*for_each使用了迭代器的概念，其迭代器就是指针。由于迭代器内含了
自增操作的概念，所以如代码清单4-33中的++p操作则可以不写在
for_each循环中了*/
#endif

/*对于一个有范
围的集合而言，由程序员来说明循环的范围是多余的，也是容易犯错
误的。而C++11也引入了基于范围的for循环，就可以很好地解决了这
个问题。*/


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


/*是否能够使用基于范围的for循环，必须依赖于一些条
件。首先，就是for循环迭代的范围是可确定的。对于类来说，如果该
类有begin和end函数，那么begin和end之间就是for循环迭代的范围对
于数组而言，就是数组的第一个和最后一个元素间的范围。，基
于范围的for循环还要求迭代的对象实现++和==等操作符*/



/*相反，如果我们数组大小不能确定的话，是不能够使用基于范围的for循环的*/

#ifdef code_4_36
#include <iostream>
using namespace std;
int func(int a[]){
    for(auto e:a)   //无法使用范围不确定的数组用于基于范围的for循环
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
        cout<<*i<<endl;//i是迭代器对象
    for(auto e:v)
        cout<<e<<endl;//e是解引用后的对象
}
//注意： e和*i的区别

#endif
