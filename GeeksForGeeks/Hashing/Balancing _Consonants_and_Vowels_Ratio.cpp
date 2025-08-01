class Solution {
  public:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }
        return false;
    }
    int countBalanced(vector<string>& arr) {
        //we need no.of.vowels = no.of.consonants -> v = c -> v - c = 0
        //this boils down to the problem of finding the no.of.subarrays with sum k .Here k is 0
        vector<int> diff; 
        
        for(auto& s : arr){
            int vowels = 0;
            int consonants = 0;
            for(char& c : s){
                if(isVowel(c)){
                    vowels++;
                }else{
                    consonants++;
                }
            }
            diff.push_back(vowels - consonants);
        }
        
        //classic : find no.of subarrays with sum 0
        unordered_map<int,int> mpp;
        int preSum = 0;
        int cnt = 0;
        mpp[0] = 1;
        
        for(int i = 0 ; i < diff.size() ; i++){
            preSum += diff[i];
            if(mpp.find(preSum) != mpp.end()){
                cnt += mpp[preSum];
            }
            mpp[preSum]++;
        }

        return cnt;
    }
};