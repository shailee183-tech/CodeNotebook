from collections import Counter
from typing import List

class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        mx = max(nums)

        # Special case for 1
        ans = cnt[1] - (1 if cnt[1] % 2 == 0 else 0)

        for num in cnt:
            if num == 1:
                continue

            x = num
            length = 0

            while x <= mx and cnt.get(x, 0) >= 2:
                length += 2
                x *= x

            if x <= mx and cnt.get(x, 0):
                length += 1
            else:
                length -= 1

            ans = max(ans, length)

        return ans