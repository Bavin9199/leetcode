/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
using namespace std;
#include <climits>
#include <iostream>
#include <vector>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        int sum = 0;
        //sum表示当前选中的子数组之和，result表示之前计算得到的子数组最大和
        for (int i=0;i<nums.size();i++){
            sum += nums[i];
            //全局最优：当目前的子数组之和大于之前的子数组之和
            if (sum>result) {result = sum;}
            //局部最优：子数组若不大于0，则说明目前已经选中的子数组加上后面的数值都不会成为子数组最大值
            //则将选中的子数组清零，然后重新计算子数组之和。
            if (sum<=0) {sum = 0;}
        }
        return result;
    }
};
// @lc code=end

