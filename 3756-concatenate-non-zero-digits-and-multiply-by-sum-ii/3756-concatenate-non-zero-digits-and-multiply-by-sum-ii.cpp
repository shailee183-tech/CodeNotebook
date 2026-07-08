class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        // Prefix sum of digits
        vector<long long> prefSum(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefSum[i + 1] = prefSum[i] + (s[i] - '0');

        // Store non-zero positions and digits
        vector<int> pos;
        vector<int> digit;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int m = digit.size();

        // Powers of 10
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        // Prefix hash of non-zero digits
        vector<long long> prefHash(m + 1, 0);
        for (int i = 1; i <= m; i++)
            prefHash[i] = (prefHash[i - 1] * 10 + digit[i - 1]) % MOD;

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long sum = prefSum[r + 1] - prefSum[l];

            auto it1 = lower_bound(pos.begin(), pos.end(), l);
            auto it2 = upper_bound(pos.begin(), pos.end(), r);

            if (it1 == it2) {
                ans.push_back(0);
                continue;
            }

            int L = it1 - pos.begin() + 1;
            int R = it2 - pos.begin();

            int len = R - L + 1;

            long long x = (prefHash[R] -
                          prefHash[L - 1] * pow10[len]) % MOD;

            if (x < 0) x += MOD;

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};