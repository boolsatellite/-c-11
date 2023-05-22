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
/*mutable：mutable修饰符。默认情况下，lambda函数总是一个const函
数，mutable可以取消其常量性。在使用该修饰符时，参数列表不可省
略（即使参数为空）。

而在块作用域中的lambda函数仅能捕捉父作用
域中的自动变量，捕捉任何非此作用域或者是非自动变量（如静态变
量等）都会导致编译器报错。

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

/*每个lambda表达式则会产生一个闭包类型的
临时对象（右值）。因此，严格地讲，lambda函数并非函数指针。不
过C++11标准却允许lambda表达是向函数指针的转换，但前提是
lambda函数没有捕捉任何变量，且函数指针所示的函数原型，必须跟
lambda函数有着相同的调用方式。*/

#ifdef code_7_26

int main() {
    int girls = 3, boys = 4;
    auto totalChild = [](int x, int y) -> int { return x + y; };
    typedef int(*allChild)(int x, int y);
    typedef int(*oneChild)(int x);
    allChild p;
    p = totalChild;
    oneChild q;
    //q = totalChild;//编译失败，参数必须一致
    decltype(totalChild) allPeople = totalChild;//需通过decltype获得lambda的类型
    decltype(totalChild) totalPeople = p;//编译失败，指针无法转换为lambda
    return 0;
}
#endif

#ifdef code_7_27
int main() {
    int val;
//编译失败,在const的lambda中修改常量
    auto const_val_lambda = [=]() { val = 3; };
//非const的lambda,可以修改常量数据
    auto mutable_val_lambda = [=]()mutable { val = 3; };
//依然是const的lambda，不过没有改动引用本身
    auto const_ref_lambda = [&] { val = 3; };
//依然是const的lambda，通过参数传递val
    auto const_param_lambda = [&](int v) { v = 3; };
    const_param_lambda(val);
    return 0;
}
//c++11中lambda函数默认是一个const函数
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
//传统的for循环
    for (auto itr = nums.begin(); itr != nums.end(); ++itr) {
        if (*itr >= ubound)
            largeNums.push_back(*itr);
    }
//使用函数指针
    for_each(nums.begin(), nums.end(), LargeNumsFunc);
//使用lambda函数和算法for_each
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
//传统的for循环
    for (auto itr = nums.begin(); itr != nums.end(); ++itr) {
        if (*itr >= ubound)
            largeNums.push_back(*itr);
    }
//使用仿函数
    for_each(nums.begin(), nums.end(), LNums(ubound));
//使用lambda函数和算法for_each
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
//传统的for循环
    for (auto i = nums.begin(); i != nums.end(); i++)
        if (*i == val)break;
//内置的仿函数(template)equal_to,通过bind2nd使其成为单参数调用的仿函数
    find_if(nums.begin(), nums.end(), bind2nd(equal_to<int>(), val));
//使用lambda函数
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
//传统的for循环
    for(auto i=nums.begin();i!=nums.end();i++)
        if(*i>=low&&*i<high)break;
//利用了3个内置的仿函数，以及非标准的compose2
    find_if(nums.begin(),nums.end(),
            compose2(logical_and<bool>(),
            bind2nd(less<int>(),high),
    bind2nd(greater_equal<int>(),low)));
//使用lambda函数
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
//传统的for循环方式
    for (auto i = nums.begin(); i != nums.end(); ++i) {
        *i = *i + val;
    }
    print();
//试一试for_each及内置仿函数
    for_each(nums.begin(), nums.end(), bind2nd(plus<int>(), val));
    print();
//实际这里需要使用STL的一个变动性算法：transform
    transform(nums.begin(), nums.end(), nums.begin(),
              bind2nd(plus<int>(), val));
    print();
//不过在lambda的支持下，我们还是可以只使用for_each
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
//使用accumulate算法，需要两次循环
    errors = accumulate(v.begin(), v.end(), 0);
    score = accumulate(v.begin(), v.end(), 100, minus<int>());
    print();
    errors = 0;
    score = 100;
//使用lambda则只需要一次循环
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
    auto ill_lambda=[d]{};   //超出捕获列表超出父作用域
}
#endif



