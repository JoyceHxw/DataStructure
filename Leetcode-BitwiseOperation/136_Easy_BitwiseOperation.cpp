#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        // 使用了 auto 关键字以后，编译器会在编译期间自动推导出变量的类型
        // 遍历容器
        // 任何数和 0 做异或运算，结果仍然是原来的数，即aa⊕0=a。
        // 任何数和其自身做异或运算，结果是 0，即 a⊕a=0。
        // 异或运算满足交换律和结合律，即 a⊕b⊕a=b⊕a⊕a=b⊕(a⊕a)=b⊕0=b。

        for (auto e: nums) ret ^= e;
        return ret;
    }
};