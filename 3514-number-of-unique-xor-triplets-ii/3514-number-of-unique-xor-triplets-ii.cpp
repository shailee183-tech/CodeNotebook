class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        int mx = *max_element(nums.begin(), nums.end());
        int u = 1 << bit_width((size_t)mx);

        vector<bool> s(u, false);

        // All XORs of two elements
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                s[nums[i] ^ nums[j]] = true;
            }
        }

        vector<bool> t(u, false);

        // XOR with third element
        for (int i = 0; i < u; i++) {
            if (!s[i]) continue;

            for (int x : nums)
                t[x ^ i] = true;
        }

        int ans = 0;
        for (bool x : t)
            ans += x;

        return ans;
    }
};