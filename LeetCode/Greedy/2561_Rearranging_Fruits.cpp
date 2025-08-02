class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mpp;
        int min_element = INT_MAX;

        // count freq of numbers in basket1
        for (const int& num : basket1) {
            mpp[num]++;
            min_element = min(min_element, num);
        }

        // subtract the freq of numbers in basket2
        for (const int& num : basket2) {
            mpp[num]--;
            min_element = min(min_element, num);
        }

        /*
            Three possible cases in mpp :
                -> mpp[x] > 0 -> x is present more in basket1
                -> mpp[x] < 0 -> x is present more in basket2
                -> mpp[x] = 0 -> x is present equally
        */

        vector<int> finalList;
        for (auto it : mpp) {
            int num = it.first;
            int count = it.second;

            if (count == 0)
                continue;
            if (count % 2 != 0)
                return -1;

            /*
                if {2,2} and {1,1} are the extra elements to make
                them equal you swap only one pair {1,2}
                so abs(count) / 2;
            */
            for (int i = 1; i <= abs(count) / 2; i++) {
                finalList.push_back(num);
            }
        }

        // sort(finalList.begin(),finalList.end());

        // sort the first half of finalList to get the minimum cost of swapping
        nth_element(finalList.begin(), finalList.begin() + finalList.size() / 2,
                    finalList.end());

        long long result = 0;
        // we can use the min_element to make indirect swapping, if so the
        // min_element would be swapped twice so min_element * 2
        for (int i = 0; i < finalList.size() / 2; i++) {
            result += min(finalList[i], min_element * 2);
        }

        return result;
    }
};