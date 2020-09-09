#include <iostream>
#include <unordered_map>
#include <map>
#include "my_dictionary.h"

using namespace std;

struct A{
    int val;

    explicit A(int v)
    : val(v)
    {}

    friend bool operator==(const A& a1, const A& a2);
    //friend bool operator<(const A& a1, const A& a2);
};

bool operator==(const A& a1, const A& a2){
    return a1.val == a2.val;
}
/*bool operator<(const A& a1, const A& a2){
    return a1.val < a2.val;
}*/

int main() {


    MyDictionary<int, int> Int_dic;

    Int_dic.Set(1, 10);
    Int_dic.Set(2, 20);
    std::cout<<Int_dic.Get(2)<<' '<< (Int_dic.IsSet(3) ? Int_dic.Get(3) : Int_dic.Get(1))<<'\n';

    MyDictionary<A, A> A_dic;
    A a1(20);
    a1.val = 20;
    A a2(10);
    a2.val = 10;
    A_dic.Set(a1, a2);
    A_dic.Set(a2, a1);
    A a3(30);
    a3.val = 20;
    std::cout<<A_dic.Get(a2).val<<' '<<(A_dic.IsSet(a3) ? "Yes" : "No")<<'\n';

    MyDictionary<std::string, std::string> Str_dic;

    Str_dic.Set("1", "2");
    Str_dic.Set("2", "1");
    std::cout<<Str_dic.Get("2")<<Str_dic.Get("1")<<'\n';



    return 0;
}
