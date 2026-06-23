class Solution:
    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        MOD = 10**9 + 7
        m = r - l + 1

        if n == 1:
            return m

        # length = 2
        up = [i for i in range(m)]                 # values smaller than i
        down = [m - 1 - i for i in range(m)]      # values greater than i

        for _ in range(3, n + 1):
            new_up = [0] * m
            pref = 0

            for i in range(m):
                new_up[i] = pref
                pref = (pref + down[i]) % MOD

            new_down = [0] * m
            suf = 0

            for i in range(m - 1, -1, -1):
                new_down[i] = suf
                suf = (suf + up[i]) % MOD

            up, down = new_up, new_down

        return (sum(up) + sum(down)) % MOD