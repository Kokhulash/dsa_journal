/***
    Title : 2419. Longest Subarray With Maximum Bitwise AND
    Link  : https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/
***/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //the maximum bitwise AND of an aray / subarray is the max element in it.
        int maxAnd = *max_element(nums.begin(), nums.end());

        int cur_streak = 0;
        int max_streak = 0;

        //the problem boils down to the question -> longest subarray having maxValue 
        for(int num : nums){
            if(num == maxAnd){
                cur_streak++;
            }else{
                max_streak = max(max_streak,cur_streak);
                cur_streak = 0;
            }
        }

        //for edge case : when the last value is maxAnd and is part of the longest streak;
        max_streak = max(max_streak,cur_streak);

        return max_streak;
    }
};