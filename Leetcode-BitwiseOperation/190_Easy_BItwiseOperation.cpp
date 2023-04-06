#include <iostream>
using namespace std;

// 熟悉位运算
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev = 0;
        for (int i = 0; i < 32 && n > 0; ++i) {
            rev |= (n & 1) << (31 - i);  
            // 位运算优先级高于逻辑运算高于赋值运算
            // 先取n的最右边的最后一位，然后左移，然后按位或等于
            n >>= 1; // 右移一位后赋值
        }
        return rev;
    }

// 分治
// private:
//     const uint32_t M1 = 0x55555555; // 01010101010101010101010101010101
//     const uint32_t M2 = 0x33333333; // 00110011001100110011001100110011
//     const uint32_t M4 = 0x0f0f0f0f; // 00001111000011110000111100001111
//     const uint32_t M8 = 0x00ff00ff; // 00000000111111110000000011111111

// public:
//     uint32_t reverseBits(uint32_t n) {
//         n = n >> 1 & M1 | (n & M1) << 1;
//         n = n >> 2 & M2 | (n & M2) << 2;
//         n = n >> 4 & M4 | (n & M4) << 4;
//         n = n >> 8 & M8 | (n & M8) << 8;
//         return n >> 16 | n << 16;
//     }

};