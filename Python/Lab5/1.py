def triangle(a, b, c):
    if (a + b) > c and (b + c) > a and (a + c) > b:
        print('Треугольник')
    else:
        print('Не трегоугольник')
triangle(int(input()), int(input()), int(input()))