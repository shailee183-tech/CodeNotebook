class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_candies = *max_element(candies.begin(), candies.end());
        vector<bool> ans;

        for (int candy: candies){
            ans.push_back(candy + extraCandies >= max_candies);
        }
        return ans;
    }
};