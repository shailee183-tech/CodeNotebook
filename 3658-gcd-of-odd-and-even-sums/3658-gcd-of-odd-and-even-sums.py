class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        sumOdd = n*(2*1 + (n-1)*2)//2
        sumEven= n*(2*2 +(n-1)*2)//2

        return gcd(sumOdd, sumEven)