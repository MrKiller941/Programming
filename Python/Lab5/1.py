def triangle(a, b, c):
    a = int(a)
    b = int(b)
    c = int(c)
    if(a + b >= c and a + c >= b and b + c >= a):
        print("Это треугольник")
    else:
        print("Это не треугольник")

a, b, c = input().split()
triangle(a, b, c)
