n = [1, 2, 3, 40, 20, 30]
print(list(filter(lambda x: x < 5, n)))
print(list(x for x in n if x < 5))
