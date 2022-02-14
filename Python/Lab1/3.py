a = input()
b = input()
if ('@' in a):
    print("Неверный логин")
else:
    print("Верный логин")
if ('@' in b):
    print("Верный резервный адрес")
else:
    print("Неверный резервный адрес")
