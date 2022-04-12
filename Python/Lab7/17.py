import datetime
 
 
class Conference:
 
    def __init__(self):
        self.start = None
        self.end = None
        self.answers = None
 
 
def add(conf):
    date = list(map(int, input('Задайте дату выступления в формате часов, минут и года').split('-')))
    time = list(map(int, input('Задайте время начала выступленя'
                               'в формате "часов и минут"').split('-')))
    start = datetime.datetime(date[2], date[1], date[0], time[0], time[1])
    delta = list(map(int, input('Задайте время выступления в формате "часов и минут')))
    delta = datetime.timedelta(hours=delta[0], minutes=delta[1])
    end = start + delta
    theme = input('Задайте темц выступления')
    for i in conf.answers:
        if not i.check(start, end):
            print('Текущее выступление затрагивает другое, Побробуйте ещё раз и создайте новое.')
            return
    conf.answers.append(Answer(start, end, theme))
    if conf.start:
        if start < conf.start:
            conf.start = start
    else:
        conf.start = start
    if conf.end:
        if end < conf.end:
            conf.end = end
    else:
        conf.end = end
 
 
def endwork(conf):
    conf.answers.sort(key=conf.end)
    print('Вы успешно создали конференцию!')
    print(f'Общая продолжительность: {conf.end - conf.start}')
    print(f'Количество выступлений: {len(conf.answers)}')
    print('График выступлений:')
    for i in range(len(conf.answers)):
        print(f'{i + 1}: {conf.answers[i].output}')
 
 
class Answer:
    def __init__(self, starttime, endtime, theme):
        self.start = starttime
        self.end = endtime
        self.theme = theme
 
    def check(self, minn, maxx):
        if maxx < self.start or self.end < minn:
            return True
        return False
 
    def output(self):
        return f'Тема: {self.theme}, начало: {self.start} конец: {self.end}'
 
 
def anscheck(conf):
    if conf.answers:
        return True
    else:
        return False
 
 
def main():
    print('Вас приветствует менеджер конференций')
    conf = Conference
    command = None
    while command != 'end':
        print('Действие?')
        print('Комманда "add" - Добавление нового выступления')
        print('Комманда "end" - Вывод конференции и завершение работы')
        command = input()
        if command == 'add':
            add(conf)
        else:
            if anscheck(conf):
                endwork(conf)
            print('Завершение работы')
            break
 
 
main()