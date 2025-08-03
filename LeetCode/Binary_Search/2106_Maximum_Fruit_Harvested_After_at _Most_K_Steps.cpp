class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();

        vector<int> positions(n);
        vector<int> prefixSum(n); //calculate the prefix sum

        for(int i = 0; i < n; i++){
            positions[i] = fruits[i][0];
            prefixSum[i] = fruits[i][1] + (i > 0 ? prefixSum[i - 1] : 0);
        }

        int max_fruits = 0;
        /* 
            k - 2 * d >= 0 -> d <= k / 2
            case 1 : move left and then right
                you move d steps left from startPos => k - d steps
                you return to the startPos again => k - d - d = k - 2d steps (remaining to go to right)

            case 2 : similar
        */
        for(int d = 0; d <= k/2; d++){ 
            //case-1 : move left and then right
            int remaining = k - 2 * d;
            int i = startPos - d;
            int j = startPos + remaining;

            int left = lower_bound(positions.begin(),positions.end(),i) - positions.begin();
            int right = upper_bound(positions.begin(),positions.end(),j) - positions.begin() - 1;

            if(left <= right){
                int result = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                max_fruits = max(max_fruits,result);
            }
            

            //case-2 : move right and then left
            i = startPos - remaining;
            j = startPos + d;

            left = lower_bound(positions.begin(),positions.end(),i) - positions.begin();
            right = upper_bound(positions.begin(),positions.end(),j) - positions.begin() - 1;

            
            if(left <= right){
                int result = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                max_fruits = max(max_fruits,result);
            }
            
        }
        return max_fruits;
    }
};