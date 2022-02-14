a = int(input())
b = 1
c = 0
for i in range(1, a + 1):
    print(i, end=" ")
    c = c + 1
    if c == b:
        print()
        b = b + 1
        c = 0
 

