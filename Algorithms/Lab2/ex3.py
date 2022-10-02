
import turtle
import random


def tree(branchLen, t):
    if branchLen > 7:
        t.color("red")
        t.pensize(branchLen/25) # Изменяет толщину ветвей, чтобы при уменьшении branchLen линии становились тоньше
        t.forward(branchLen)
        rnd = random.uniform(1.7, 7.1)  # Изменяет угол поворота черепахи, чтобы каждая ветвь поворачивалась  произвольным образом в некотором диапазоне.
        t.right(branchLen * rnd)
        rand = random.randint(4, 5) # Измените рекурсивную часть branchLen, чтобы каждый раз вычиталось  произвольное значение из некоторого диапазона вместо некой постоянной  величины.
        tree(branchLen - rand, t)
        t.left(branchLen * rnd * 2)
        tree(branchLen - rand, t)
        t.right(branchLen * rnd)
        t.color("green") # Измените цвет ветвей таким образом, чтобы самые короткие ветви окрашивались как листья
        t.backward(branchLen)

def main():
  t = turtle.Turtle()
  t.speed(1000)
  myWin = turtle.Screen()
  t.left(90)
  t.up()
  t.backward(100)
  t.down()
  t.color("brown")
  tree(50, t)
  myWin.exitonclick()


main()