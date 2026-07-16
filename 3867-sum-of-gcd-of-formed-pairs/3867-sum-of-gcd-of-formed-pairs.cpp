class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx =0 ;
        vector<int> g(nums.size());
        for(int i =0; i<nums.size(); i++){
            mx = max(mx, nums[i]);
            g[i] = gcd(nums[i], mx);
        }

        sort(g.begin(), g.end());
        long long sum = 0;
        for(int i=0, j=nums.size()-1;i<nums.size()/2; i++, j--){
            sum += gcd(g[i], g[j]);
        }
        return sum;
    }
};