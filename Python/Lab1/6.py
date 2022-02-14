x = int(input())
c = int(x % 10)
b = int((x % 100) / 10)
a = int(x / 100)
if a > c:
    k = a
    a = c
    c = k
if a > b:
    k = a
    a = b
    b = k
if c < b:
    k = c
    c = b
    b = k
if (a + c) / 2 == b:
    print("Вы ввели красивое число")
else:
    print("Жаль, вы ввели обычное число")