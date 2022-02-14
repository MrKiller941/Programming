a = input()
b = input()
proverka = 0
while proverka == 0:
    if len(a) < 8:
        proverka = 0
        print("Короткий пароль!")
        a = input()
        b = input()
    elif "123" in a:
        proverka = 0
        print("Простой пароль !")
        a = input()
        b = input()
    elif a != b:
        proverka = 0
        print("Различаются пароли !")
        a = input()
        b = input()
    else:
        proverka = 1
        print("ОК")
