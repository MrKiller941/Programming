number = int(input())
a = int(number % 10)
b = int((number % 100) / 10)
c = int((number / 100) % 10)
d = int(number / 1000)
if a > b:
    a, b = b, a
if b > c:
    b, c = c, b
if c > d:
    c, d = d, c
if a > b:
    a, b = b, a
if b > c:
    b, c = c, b
if a > b:
    a, b = b, a
print(d + 10 * (c + 10 * (b + 10 * a)))
