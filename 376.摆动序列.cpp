// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem376.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int length = 2;
        //当数组只有一个数值的时候，长度返回1
        //若数组数值都相等，待改进。。。
        if(n==1 || (n==2&&nums[0]==nums[1]) || (n==3&&nums[0]==nums[1])){
            length = 1;
            return length;
        }
        //利用两两差值乘积应为负数来判断是否为摆动序列
        //如果和前一组数的差值乘积为负，则摆动数列长度+1，否则erase函数删除对应位置的数值并让长度-1，进入下一轮循环但选中数值的位置不变
        for(int i=1; i<n-1; i++){
            int res = nums[i]-nums[i-1];
            if (((nums[i+1]-nums[i])*res) < 0){
                length++;
            }
            else {
                nums.erase(nums.begin()+i);
                i--;
                n--;
                continue;
            }

        }
        return length;
    }
};
// @lc code=end

