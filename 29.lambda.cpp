//
// Created by satellite on 2023-05-21.
//

//lambda
//#define code_7_17
//#define code_7_22
//#define code_7_23
//#define code_7_24
//#define code_7_25
//#define code_7_26
//#define code_7_27
//#define code_7_29
//#define code_7_30
//#define code_7_31
//#define code_7_32
//#define code_7_33
//#define code_7_34
#define code_7_35


#ifdef code_7_17
int main(){
    int girls=3,boys=4;
    auto totalChild=[](int x,int y)->int{return x+y;};
    return totalChild(girls,boys);
}
#endif

//[capture](parameters)mutable->return_type{statement}
/*mutable��mutable���η���Ĭ������£�lambda��������һ��const��
����mutable����ȡ���䳣���ԡ���ʹ�ø����η�ʱ�������б���ʡ
�ԣ���ʹ����Ϊ�գ���

���ڿ��������е�lambda�������ܲ�׽������
���е��Զ���������׽�κηǴ�����������Ƿ��Զ��������羲̬��
���ȣ����ᵼ�±���������

 */

#ifdef code_7_22
class AirportPrice {
private:
    float dutyfreerate;
public:
    AirportPrice(float rate) : dutyfreerate(rate) {}

    float operator()(float price) {
        return price * (1 - dutyfreerate / 100);
    }
};

int main() {
    float tax_rate = 5.5f;
    AirportPrice Changi(tax_rate);
    auto Changi2 =
            [tax_rate](float price) -> float
            { return price * (1 - tax_rate / 100); };
    float purchased = Changi(3699);
    float purchased2 = Changi2(2899);
}
#endif

#ifdef code_7_23
extern int z;
extern float c;
void Calc(int&,int,float&,float);
void TestCalc(){
    int x,y=3;
    float a,b=4.0;
    int success=0;
    auto validate=[&]()->bool
    {
        if((x==y+z)&&(a==b+c))
        return 1;
        else
        return 0;
    };
    Calc(x,y,a,b);
    success+=validate();
    y=1024;
    b=1e13;
    Calc(x,y,a,b);
    success+=validate();
}
#endif

#ifdef code_7_24

int Prioritize(int);

int AllWorks(int times) {
    int i;
    int x;
    try {
        for (i = 0; i < times; i++)
            x += Prioritize(i);
    }
    catch (...) {
        x = 0;
    }
    const int y = [=] {
        int i, val;
        try {
            for (i = 0; i < times; i++)
                val += Prioritize(i);
        }
        catch (...) {
            val = 0;
        }
        return val;
    }();
}

#endif

#ifdef code_7_25
#include <iostream>
using namespace std;
int main(){
    int j=12;
    auto by_val_lambda=[=]{return j+1;};
    auto by_ref_lambda=[&]{return j+1;};
    cout<<"by_val_lambda:"<<by_val_lambda()<<endl;
    cout<<"by_ref_lambda:"<<by_ref_lambda()<<endl;
    j++;
    cout<<"by_val_lambda:"<<by_val_lambda()<<endl;
    cout<<"by_ref_lambda:"<<by_ref_lambda()<<endl;
}
#endif

/*ÿ��lambda���ʽ������һ���հ����͵�
��ʱ������ֵ������ˣ��ϸ�ؽ���lambda�������Ǻ���ָ�롣��
��C++11��׼ȴ����lambda���������ָ���ת������ǰ����
lambda����û�в�׽�κα������Һ���ָ����ʾ�ĺ���ԭ�ͣ������
lambda����������ͬ�ĵ��÷�ʽ��*/

#ifdef code_7_26

int main() {
    int girls = 3, boys = 4;
    auto totalChild = [](int x, int y) -> int { return x + y; };
    typedef int(*allChild)(int x, int y);
    typedef int(*oneChild)(int x);
    allChild p;
    p = totalChild;
    oneChild q;
    //q = totalChild;//����ʧ�ܣ���������һ��
    decltype(totalChild) allPeople = totalChild;//��ͨ��decltype���lambda������
    decltype(totalChild) totalPeople = p;//����ʧ�ܣ�ָ���޷�ת��Ϊlambda
    return 0;
}
#endif

#ifdef code_7_27
int main() {
    int val;
//����ʧ��,��const��lambda���޸ĳ���
    auto const_val_lambda = [=]() { val = 3; };
//��const��lambda,�����޸ĳ�������
    auto mutable_val_lambda = [=]()mutable { val = 3; };
//��Ȼ��const��lambda������û�иĶ����ñ���
    auto const_ref_lambda = [&] { val = 3; };
//��Ȼ��const��lambda��ͨ����������val
    auto const_param_lambda = [&](int v) { v = 3; };
    const_param_lambda(val);
    return 0;
}
//c++11��lambda����Ĭ����һ��const����
#endif

#ifdef code_7_29

#include <vector>
#include <algorithm>

using namespace std;
vector<int> nums;
vector<int> largeNums;
const int ubound = 10;

inline void LargeNumsFunc(int i) {
    if (i > ubound)
        largeNums.push_back(i);
}

void Above() {
//��ͳ��forѭ��
    for (auto itr = nums.begin(); itr != nums.end(); ++itr) {
        if (*itr >= ubound)
            largeNums.push_back(*itr);
    }
//ʹ�ú���ָ��
    for_each(nums.begin(), nums.end(), LargeNumsFunc);
//ʹ��lambda�������㷨for_each
    for_each(nums.begin(), nums.end(), [=](int i) {
        if (i > ubound)
            largeNums.push_back(i);
    });
}
#endif

#ifdef code_7_30

#include <vector>
#include <algorithm>

using namespace std;
vector<int> nums;
vector<int> largeNums;

class LNums {
public:
    LNums(int u) : ubound(u) {}

    void operator()(int i) const {
        if (i > ubound)
            largeNums.push_back(i);
    }

private:
    int ubound;
};

void Above(int ubound) {
//��ͳ��forѭ��
    for (auto itr = nums.begin(); itr != nums.end(); ++itr) {
        if (*itr >= ubound)
            largeNums.push_back(*itr);
    }
//ʹ�÷º���
    for_each(nums.begin(), nums.end(), LNums(ubound));
//ʹ��lambda�������㷨for_each
    for_each(nums.begin(), nums.end(), [=](int i) {
        if (i > ubound)
            largeNums.push_back(i);
    });
}

#endif

#ifdef code_7_31

#include <vector>
#include <algorithm>

using namespace std;
extern vector<int> nums;

void OneCond(int val) {
//��ͳ��forѭ��
    for (auto i = nums.begin(); i != nums.end(); i++)
        if (*i == val)break;
//���õķº���(template)equal_to,ͨ��bind2ndʹ���Ϊ���������õķº���
    find_if(nums.begin(), nums.end(), bind2nd(equal_to<int>(), val));
//ʹ��lambda����
    find_if(nums.begin(), nums.end(), [=](int i) {
        return i == val;
    });
}

#endif

#ifdef code_7_32

#include <vector>
#include <algorithm>
using namespace std;
extern vector<int> nums;
void TwoCond(int low,int high){
//��ͳ��forѭ��
    for(auto i=nums.begin();i!=nums.end();i++)
        if(*i>=low&&*i<high)break;
//������3�����õķº������Լ��Ǳ�׼��compose2
    find_if(nums.begin(),nums.end(),
            compose2(logical_and<bool>(),
            bind2nd(less<int>(),high),
    bind2nd(greater_equal<int>(),low)));
//ʹ��lambda����
    find_if(nums.begin(),nums.end(),[=](int i){
        return i>=low&&i<high;
    });
}
#endif

#ifdef code_7_33

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int> nums;

void Add(const int val) {
    auto print =[]{
        for (auto s: nums) { cout << s << '\t'; }
        cout << endl;
    };
//��ͳ��forѭ����ʽ
    for (auto i = nums.begin(); i != nums.end(); ++i) {
        *i = *i + val;
    }
    print();
//��һ��for_each�����÷º���
    for_each(nums.begin(), nums.end(), bind2nd(plus<int>(), val));
    print();
//ʵ��������Ҫʹ��STL��һ���䶯���㷨��transform
    transform(nums.begin(), nums.end(), nums.begin(),
              bind2nd(plus<int>(), val));
    print();
//������lambda��֧���£����ǻ��ǿ���ֻʹ��for_each
    for_each(nums.begin(), nums.end(), [=](int&i){
        i += val;
    });
    print();
}

int main() {
    for (int i = 0; i < 10; i++) {
        nums.push_back(i);
    }
    Add(10);
    return 1;
}

#endif


#ifdef code_7_34

#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

void Stat(vector<int> &v) {
    int errors;
    int score;
    auto print = [&] {
        cout << "Errors:" << errors << endl
             << "Score:" << score << endl;
    };
//ʹ��accumulate�㷨����Ҫ����ѭ��
    errors = accumulate(v.begin(), v.end(), 0);
    score = accumulate(v.begin(), v.end(), 100, minus<int>());
    print();
    errors = 0;
    score = 100;
//ʹ��lambda��ֻ��Ҫһ��ѭ��
    for_each(v.begin(), v.end(), [&](int i) {
        errors += i;
        score -= i;
    });
    print();
}

int main() {
    vector<int> v(10);
    generate(v.begin(), v.end(), [] {
        return rand() % 10;
    });
    Stat(v);
}

#endif

#ifdef code_7_35
int d = 0;
int TryCapture(){
    auto ill_lambda=[d]{};   //���������б�����������
}
#endif



