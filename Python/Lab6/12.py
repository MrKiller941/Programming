n = input().split()
n.sort(key=lambda x: x.lower())
print(*n)