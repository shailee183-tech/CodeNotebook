from typing import List

class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        size = 2 * n + 3
        bit = [0] * size

        def update(i):
            while i < size:
                bit[i] += 1
                i += i & -i

        def query(i):
            s = 0
            while i > 0:
                s += bit[i]
                i -= i & -i
            return s

        offset = n + 1
        prefix = 0
        ans = 0

        update(offset)

        for x in nums:
            if x == target:
                prefix += 1
            else:
                prefix -= 1

            idx = prefix + offset
            ans += query(idx - 1)
            update(idx)

        return ans