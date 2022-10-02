import turtle


def draw_triangle (size, t, quant = 1):
    if(quant > 0):
        t.pendown()
        for i in range(quant):
            t.begin_fill()
            t.penup()
            t.forward(size) # движение черепашки вперёд
            t.pendown()
            t.left(120) # движение черепашки налево на 120 градусов
            t.forward(size)
            t.left(120) # движение черепашки налево на 120 градусов 
            t.forward(size)
            t.penup()
            t.left(120) # движение черепашки налево на 120 градусов 
            t.forward(size)
            t.end_fill()
        t.penup()
        t.left(60) # движение черепашки налево на 60 градусов
        t.forward(size/2)
        t.left(40) # движение черепашки налево на 40 градусов
        t.forward(size*(quant-0.75))
        t.right(180) # движение черепашки направо на 180 градусов
        draw_triangle(size, t, quant-1)


t = turtle.Turtle()
t.penup()
t.fillcolor("red") # выбор цвета треугольника
t.goto(-500, -200)
t.pendown()
t.speed(1000)
myWin = turtle.Screen()
draw_triangle(200, t, 5)

myWin.exitonclick()