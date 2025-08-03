// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem135.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 * n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。

 * 你需要按照以下要求，给这些孩子分发糖果：

 * 每个孩子至少分配到 1 个糖果。
 * 相邻两个孩子中，评分更高的那个会获得更多的糖果。
 * 请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
 */

// @lc code=start
using namespace std;
#include <iostream>
#include <vector>
#include <numeric>
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        //首先保证每个孩子1个糖果
        vector<int> candies(n,1);
        //先从左到右检查，若右侧数值比左侧大，给左侧数量+1个糖果
        for(int i=0;i<n-1;i++){
            if(ratings[i+1]>ratings[i]){
                candies[i+1]=candies[i]+1;
            }
        }
        //从右到左检查，若左侧数值比右侧大，给右侧数量+1个糖果;
        //同时，在第一轮检查结束后，当左侧数值大时，如果左侧糖果数量已经比右侧高，则不需要操作。
        for(int i=n-1;i>0;i--){
            if(ratings[i-1]>ratings[i] && candies[i-1]<=candies[i]){
                candies[i-1] = candies[i]+1;
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
// @lc code=end

