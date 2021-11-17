import re
# n = int(input())


# for _ in range(n):
#     s = input()
#     tokens = re.split(' \t",()', s)
#     print(tokens)

s = 'catch ( BE, "BE in line 3")'
tokens = re.split('"|,|(|)', s)

print(tokens)
