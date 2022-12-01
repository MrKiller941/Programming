money = { # монеты номиналом
    1: 10,
    3: 5,
    4: 4,
    10: 10,
    50: 3,
    100: 4,
}
nominal = [1, 3, 4, 10, 50, 100]

clients_num = int(input("Кол-во клиентов: "))

for c in range(clients_num):
    print("Клиент", c+1)
    sum = int(input("Снять со счёта: "))
    lookup = [float("inf")] * (sum+1)
    lookup[0] = 0
    for m in range(1, sum+1):
        for i in range(len(nominal)):
            if m >= nominal[i] and lookup[m-nominal[i]] + 1 < lookup[m]:
                lookup[m] = lookup[m-nominal[i]] + 1

    chisla = {}
    while (sum > 0):
        for i in range(len(nominal)):
            if lookup[sum-nominal[i]] == lookup[sum] - 1:
                sum -= nominal[i]
                if nominal[i] in chisla:
                    chisla[nominal[i]] += 1
                else:
                    chisla[nominal[i]] = 1
                break

    chisla_keys = list(chisla.keys())
    money_c = money.copy()

    status = True
    for coin in chisla_keys:
        money_c[coin] -= chisla[coin]
        if money_c[coin] < 0:
            status = False
            break
    if status:
        money = money_c
        sorted_tuple = sorted(chisla.items(), key=lambda x: -x[0])
        print("Выдача денег: ", dict(sorted_tuple))
        print("Деньги:", money)
    else:
        print("Сумму выдать невозможно")