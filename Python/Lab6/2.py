n = [1, 2, 3, 40, 20, 30]
print(list(map(lambda x: x / 2, n)))
print(list(x / 2 for x in n))