k = [int(s) for s in input().split()]
for i in range(len(k)):
    for j in range(len(k)):
        if i != j and k[i] == k[j]:
            break
    else:
        print(k[i], end=' ')