a = [int(num) for num in input().split()]

for i in range(len(a)):
    x = a[i]
    y = a[:i]
    if x in y:
        print('Yes')
    else:
        print('No')