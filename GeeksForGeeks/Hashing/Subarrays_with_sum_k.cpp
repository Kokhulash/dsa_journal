class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // map to store the prefixSum -> stores how many times x - k appears before
        unordered_map<int,int> preSum;
        //this is important
        preSum[0] = 1;
        int cnt = 0;
        int sum = 0;
        
        for(int i = 0 ; i < arr.size() ; i++){
            sum += arr[i];
            int remove = sum - k;
            cnt += preSum[remove]; //no of subarray till arr[i] is the no. of sum - k before it
            preSum[sum] += 1;
        }
        
        return cnt;
    }
};