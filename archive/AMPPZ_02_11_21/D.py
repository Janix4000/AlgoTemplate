points = []

n = int(input())
for _ in range(n):
    s = input()
    s = s.split()
    x = int(s[0])
    y = int(s[1])
    points.append((x, y))


while True:
    s = input()
    s = s.split()
    x = int(s[0])
    y = int(s[1])
    best_d = int(2 * 1e12) + 10
    for p in points:
        d = (p[0] - x) ** 2 + (p[1] - y) ** 2
        best_d = min(best_d, d)
        if best_d == 0:
            points.remove(p)
            break
    print(best_d)