class Solution {
public:
    vector<int> generateRow(int row){
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(ans);

        for(int col = 1 ; col < row ; col++){
            ans = ans * (row - col);
            ans = ans / col;

            ansRow.push_back(ans);
        }
        return ansRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int row = 1 ; row <= numRows ; row++){
            ans.push_back(generateRow(row));
        }
        return ans;
    }
};