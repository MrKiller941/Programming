def square_fibonacci(n):
    one = 1
    two = 0
    for _ in range(n):
        one, two = two, one + two
        yield two ** 2


print(list(square_fibonacci(5)))