a = int(input())
b = int(input())
s = input()
print(s * a)
for i in range(b - 2):
    print(s, ' ' * (a - 2), s, sep='')
print(s * a)