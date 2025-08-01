/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int bis = 0;
        int child = 0;
        //贪心算法：优先以最少资源满足需求最少的，若满足不了，更换较大资源重试。
        while (bis<s.size() && child<g.size()){
            if(g[child]<=s[bis]){
                child++;
            }
            bis++;
        }
        return child;
    }
};
// @lc code=end

