def triangle(a, b, c):
    a = int(a)
    b = int(b)
    c = int(c)
    if(a + b >= c and a + c >= b and b + c >= a):
        print("It's triangle")
    else:
        print("It isn't triangle")

a, b, c = input().split()
triangle(a, b, c)
