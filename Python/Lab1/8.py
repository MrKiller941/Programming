h=input()
x=0
min=190
max=150
while h != '!':
    h= int(h)    
    if  h>= 150 and h <= 190:
        x += 1
        if h >= max:
            max = h
        elif h <= min:
            min = h
    h = input() 
print(x)
print(min, max)
