/***
    Title : 2411. Smallest Subarrays With Maximum Bitwise OR
    Link  : https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/
***/

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n);
        //setBitIndex[j] = i means that jth bit can be set using element at index i in nums
        vector<int> setBitIndex(32,-1); 

        //traverse from back so that we already know to set jth bit we need which element
        for(int i = n - 1 ; i >= 0 ; i--){
            int endIndex = i;
            
            for(int j = 0 ; j < 32 ; j++){
                //check if the jth bit is set in nums[i]
                if(!(nums[i] & (1 << j))){
                    if(setBitIndex[j] != -1){
                        //store the maxIndex to need to set the index to get max XOR
                        endIndex = max(endIndex,setBitIndex[j]);
                    }
                }else{
                    //store the index to set the jth bit
                    setBitIndex[j] = i;
                }
            }
            //calculate the subarray length
            result[i] = endIndex - i + 1;
        }
        return result;
    }
};