/***
    Title : ASCII Range sum
    Link  : https://www.geeksforgeeks.org/problems/ascii-range-sum/1
***/

class Solution {
  public:
    vector<int> asciirange(string& s) {
        //map to store the first and last occurence of each character
        unordered_map<char,pair<int,int>> occurences;
        
        for(int i = 0 ; i < s.size() ; i++){
            char c = s[i];
            
            if(occurences.count(c) == 0){
                //first occurence -> start and end positions are the same
                occurences[c] = {i,i}; 
            }else{
                //update the last position
                occurences[c].second = i;
            }
        }
        
        vector<int> rangeSum;
        
        for(auto &[ch,pos] : occurences){
            if(pos.first != pos.second){
                int sum = 0;
                for(int i = pos.first + 1 ; i < pos.second ; i++){
                    sum += s[i];
                }
                if(sum != 0)rangeSum.push_back(sum);
            }
        }
        
        return rangeSum;
    }
};