def check_password(password):
    def wrapper(func):
        def wrap(*args, **kwargs):
            if input('Пароль: ') != password:
                print('Неверный пароль')
                return
            return func(*args, **kwargs)
        return wrap
    return wrapper

@check_password('password')
def make_burger(typeOfMeat, withOnion=False, withTomato=True):
    print('burger')

make_burger(1)