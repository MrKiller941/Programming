a = int(input())
b = int(input())
s = input()
print(s * a)
for i in range(1,  a-1):
    print(s + " " * (b-2) + s)
print(s * b)
