class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        
        // Step 1: Transform the array
        // Map each element to +1 if it's > k, otherwise -1
        // This lets us track the difference between count(>k) and count(<=k)
        vector<int> prefixArray(n);
        for(int i = 0 ; i < n ; i++){
            if(arr[i] > k) 
                prefixArray[i] = 1;
            else 
                prefixArray[i] = -1;
        }
        
        // Step 2: Use a hash map to store the first occurrence of each prefix sum
        unordered_map<int, int> mpp;

        int maxLen = 0;       // Stores the maximum length of valid subarray
        int prefixSum = 0;    // Running sum of the transformed array

        for(int i = 0 ; i < n ; i++){
            prefixSum += prefixArray[i];

            // Case 1: If prefixSum > 0, then the entire subarray from index 0 to i is valid
            if(prefixSum > 0){
                maxLen = max(maxLen, i + 1);
            }

            // Case 2: We want to find the longest subarray with sum > 0
            // So we check if prefixSum - 1 has been seen before
            // If yes, the subarray from that index + 1 to i has sum > 0
            int toFind = prefixSum - 1;
            if(mpp.find(toFind) != mpp.end()){
                maxLen = max(maxLen, i - mpp[toFind]);
            }

            // Store the earliest index where prefixSum was seen
            // Only insert if not already present (to keep the earliest one)
            if(mpp.find(prefixSum) == mpp.end()){
                mpp[prefixSum] = i;
            }
        }

        return maxLen;
    }
};
