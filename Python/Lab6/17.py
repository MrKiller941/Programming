n = [[4, 9, 2], [3, 5, 7], [8, 1, 6]]

res = sum(n[0])

if all([sum(x) == res for x in n]) and all([sum(x) == res for x in list(zip(*n))]):
    print('YES')
else:
    print('NO')