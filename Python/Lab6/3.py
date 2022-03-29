print(sum(map(lambda x: x**2 ,filter(lambda x: x % 9 == 0, 
list(n for n in range(2, 120))))))