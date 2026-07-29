class Solution {
public:
    using ll = long long;

    // Compute nCr, capped at limit to avoid overflow
    ll comb(int n, int r, ll limit) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);

        ll ans = 1;
        for (int i = 1; i <= r; i++) {
            if (ans > limit) return limit;
            ans = ans * (n - r + i) / i;
            if (ans > limit) ans = limit;
        }
        return ans;
    }

    // Count distinct permutations of multiset
    ll countPerm(vector<int>& cnt, ll limit) {
        int total = 0;
        for (int x : cnt) total += x;

        ll ans = 1;
        int rem = total;

        for (int x : cnt) {
            if (x == 0) continue;
            ans *= comb(rem, x, limit);
            if (ans >= limit) return limit;
            rem -= x;
        }
        return ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> halfCnt(26, 0);
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            halfCnt[i] = freq[i] / 2;
            if (freq[i] % 2)
                mid = char('a' + i);
        }

        // Check whether kth palindrome exists
        if (countPerm(halfCnt, (ll)k) < k)
            return "";

        int halfLen = s.size() / 2;
        string half;

        for (int pos = 0; pos < halfLen; pos++) {
            for (int c = 0; c < 26; c++) {
                if (halfCnt[c] == 0) continue;

                halfCnt[c]--;

                ll ways = countPerm(halfCnt, (ll)k);

                if (ways < k) {
                    k -= ways;
                    halfCnt[c]++;
                } else {
                    half.push_back(char('a' + c));
                    break;
                }
            }
        }

        string rev = half;
        reverse(rev.begin(), rev.end());

        if (mid)
            return half + string(1, mid) + rev;

        return half + rev;
    }
};