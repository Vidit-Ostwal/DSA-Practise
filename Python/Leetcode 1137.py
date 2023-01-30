class Solution:
    def tribonacci(self, n: int) -> int:
        tribonacii = list()

        tribonacii.append(0)
        tribonacii.append(1)
        tribonacii.append(1)

        if n < 3:
            return tribonacii[n]

        for num in range(2,n):
            tribonacii.append(tribonacii[num] + tribonacii[num-1] + tribonacii[num-2])

        return tribonacii[n]