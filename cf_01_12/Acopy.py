import math


def f(a1, a2, b1=0, b2=0):
    val = math.log10(a1/a2)
    if val > b2-b1:
        return ">"
    elif val < b2-b1:
        return "<"
    else:
        return "="


print(f(int(1e6), int(1e6)-1))
