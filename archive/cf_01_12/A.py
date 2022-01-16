from math import log
t = int(input())
while t > 0:
    t -= 1
    a, p = input().split()
    b, q = input().split()
    a, b, p, q = int(a), int(b), int(p), int(q)

    f = log(a / b) / log(10) + p - q
    res = '='
    if f < -1e-15:
        res = '<'
    elif f > 1e-15:
        res = '>'
    print(res)
