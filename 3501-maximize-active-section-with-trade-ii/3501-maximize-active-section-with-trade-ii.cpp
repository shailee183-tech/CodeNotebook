#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {

        int n = s.size();
        int ones = count(s.begin(), s.end(), '1');

        vector<int> zeroStart, zeroEnd;

        for (int i = 0; i < n;) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0') j++;
                zeroStart.push_back(i);
                zeroEnd.push_back(j - 1);
                i = j;
            } else {
                i++;
            }
        }

        int blocks = zeroStart.size();

        vector<int> valley;

        for (int i = 0; i + 1 < blocks; i++) {
            int len1 = zeroEnd[i] - zeroStart[i] + 1;
            int len2 = zeroEnd[i + 1] - zeroStart[i + 1] + 1;
            valley.push_back(len1 + len2);
        }

        int m = valley.size();

        vector<vector<int>> sparse;
        sparse.push_back(valley);

        for (int k = 1; (1 << k) <= m; k++) {

            vector<int> cur(m - (1 << k) + 1);

            for (int i = 0; i + (1 << k) <= m; i++) {
                cur[i] = max(
                    sparse[k - 1][i],
                    sparse[k - 1][i + (1 << (k - 1))]
                );
            }

            sparse.push_back(cur);
        }

        auto rmq = [&](int l, int r) {

            if (l > r) return 0;

            int k = __lg(r - l + 1);

            return max(
                sparse[k][l],
                sparse[k][r - (1 << k) + 1]
            );
        };

        auto clip = [&](int idx, int l, int r) {

            return valley[idx]
                - max(0, l - zeroStart[idx])
                - max(0, zeroEnd[idx + 1] - r);
        };
                auto gain = [&](int l, int r) {

            if (blocks < 2) return 0;

            int left =
                lower_bound(zeroEnd.begin(), zeroEnd.end(), l)
                - zeroEnd.begin();

            int right =
                upper_bound(zeroStart.begin(), zeroStart.end(), r)
                - zeroStart.begin() - 1;

            if (left >= right) return 0;

            int ans = 0;

            ans = max(ans, clip(left, l, r));

            ans = max(ans, clip(right - 1, l, r));

            if (right - left >= 2) {
                ans = max(ans, rmq(left + 1, right - 2));
            }

            return ans;
        };

        vector<int> answer;
        answer.reserve(queries.size());

        for (auto &q : queries) {
            answer.push_back(ones + gain(q[0], q[1]));
        }

        return answer;
    }
};