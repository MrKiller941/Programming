n = 8
a = []
b = []
for i in range(n):
    new_a, new_b = [int(s) for s in input().split()]
    a.append(new_a)
    b.append(new_b)
 
correct = True
for i in range(n):
    for j in range(i + 1, n):
        if a[i] == a[j] or b[i] == b[j] or abs(a[i] - a[j]) == abs(b[i] - b[j]):
            correct = False
 
if correct:
    print('No')
else:
    print('Yes')