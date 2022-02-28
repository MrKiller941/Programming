a = input().split()
for i in range(len(a)-1):
    n = int(a[i])
    i += 1
    m = int(a[i])
    if (n * m) > 0:
        print(n, m, end=' ')
        break
