class Solution:
    def fib(self, n: int) -> int:
        f = 0;
        s = 1;
        t=0
        for i in range(n):
            t = f+s
            f= s
            s=t;
        return f;
        