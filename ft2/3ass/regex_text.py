text = input()
M = int(input())
import re
for _ in range(M):
    pat = input()
    print(pat, end=" ")
    m = re.search(pat , text)
    if m:
        print(m)
    else:
        print(0)
