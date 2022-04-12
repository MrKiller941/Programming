from sys import exit
 
 
class MailClient:
    def __init__(self, server, user):
        self.s = server
        self.u = user
 
    d = dict()
 
    def f(self):
        return self.d
 
    def list(self):
        self.d[self.s] = self.u
 
 
class Receive(MailClient):
 
    def __init__(self):
        super().f()
 
    def Mail(self):
        s = input('На какой сервер зайдем? ')
        if s in self.d.keys():
            if type(self.d[s]) == tuple:
                print(f'Получено письмо от пользователя {self.d[s][0]}: {self.d[s][1]}')
            else:
                print('В папке "Вся почта" пока пусто')
        else:
            print('К сожалению, такого сервера не существует')
 
 
class Send(MailClient):
 
    def __init__(self):
        super().f()
 
    def get_key(self, d, value):
        for k, v in d.items():
            if v == value:
                return k
 
    def send(self):
        un = input('Кому напишем это прекрасное сообещние? ')
        if un in self.d.values() and len(self.d[self.get_key(self.d, un)]) > 1:
            tom = input('Введите текст сообщения: ')
            for i in self.d.values():
                if i == un:
                    self.d[self.get_key(self.d, un)] = (i, tom)
            print(f'Сообщение успешно отправлено пользователю {un}!')
        else:
            print('Такого пользователя не существует, попробуйте другое имя')
 
 
def main():
    while True:
        print('Привет! Ты попал(а) на почтовый сервис Yandex!')
        serv = input('На какой сервер зайдем? ')
        name = input('Может, познакомимся? ')
        print(f'{name[0].upper() + name[1:].lower()}, Lобро пожаловатьна почту !')
        m = MailClient(serv, name)
        m.list()
        way = input('Что хотим сделать? ')
        if way.lower().strip() == 'Отправить сообщение' or way.lower().strip() == 'Написать сообщение'\
                or way.lower().strip() == 'Написать':
            s = Send()
            s.send()
        elif way.lower().strip() == 'Просмотреть ящик с новыми сообщениями' or way.lower().strip() == 'Посмотреть сообщения' \
                or way.lower().strip() == 'Прочитать сообщения' or way.lower().strip() == 'Почитать' \
                or way.lower().strip() == 'Псмотреть почту':
            r = Receive()
            r.Mail()
        else:
            print('Ошибка...')
 
        print('/-----------------------------------------\ ')
        s = '|"exit" - Выход                        |\n|"return" - Вернуться на домашнюю страницу|'
        print(s)
        print('\-----------------------------------------/ ')
        a = input()
        if a == 'exit':
            exit()
        elif a == 'return':
            pass
        else:
            print(' Ошибка...')
            exit()
 
 
main()