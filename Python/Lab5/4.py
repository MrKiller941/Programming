def power(a, n):
    i = 1
    for _ in range(n):
        i *= a
    return i

print(power(int(input()), int(input())))