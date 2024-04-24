from math import *

def factor(n, k):
    for b in range(2, 1000000):
        res = sqrt(k * n + b ** 2)
        if res - int(res) == 0.0:
            return int(res)
    
def main():
    n = 143041

    b = factor(n, 247)
    a = int(sqrt(n + b ** 2))

    p = abs(a - b)
    q = a + b

    # p = gcd(p, n)
    # q = gcd(q, n)

    print(p, q, p * q)

main()