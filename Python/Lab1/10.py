a = int(input())
b = input()
if b == "+":
    c = int(input())
    print(a + c)
if b == "-":
    c = int(input())
    print(a - c)
if b == "*":
    c = int(input())
    print(a * c)
if b == "/":
    c = int(input())
    print(a / c)
if b == "%":
    c = int(input())
    print(a % c)
if b == "!":
    f = 1
    while a > 1:
        f *= a
        a -= 1
    print(f)
if b == "x":
    print(a)
