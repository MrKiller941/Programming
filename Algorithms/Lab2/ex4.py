import turtle

width = 1200
height = 600
screen = turtle.Screen()
screen.setup(width, height, 0, 0) # начальная точка движения черепашки


def draw_koch_curve(t, ln):
    if ln > 6:
        ln3 = ln // 3
        draw_koch_curve(t, ln3)
        t.left(60) # поровот черепашки налево на 60 градусов
        draw_koch_curve(t, ln3)
        t.right(120) # поровот черепашки направо на 120 градусов
        draw_koch_curve(t, ln3)
        t.left(60) # поровот черепашки налево на 60 градусов
        draw_koch_curve(t, ln3)
    else:
        t.fd(ln) # движение черепашки прямо
        t.left(60)
        t.fd(ln)
        t.right(120)
        t.fd(ln)
        t.left(60)
        t.fd(ln)

    
t = turtle.Turtle()
t.ht() # скрытие черепашки
t.speed(150) # скорость черепашки

draw_koch_curve(t,150)

turtle.done()