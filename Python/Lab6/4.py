n = list(i for i in range(10, 30))
print(list(map(lambda x: x / 2, filter(lambda x: x > 17, n))))
print(list(x / 2 for x in n if x > 1))
