nominal = [1, 3, 4, 10, 50, 100]
n = int(input("Cнять со счёта: "))

lookup = [float("inf")] * (n+1)
lookup[0] = 0

for m in range(1, n+1):
    for i in range(len(nominal)):
        if m >= nominal[i] and lookup[m-nominal[i]] + 1 < lookup[m]:
            lookup[m] = lookup[m-nominal[i]] + 1

chisla = {}

while (n > 0):
    for i in range(len(nominal)):
        if lookup[n-nominal[i]] == lookup[n] - 1:
            n -= nominal[i]
            if nominal[i] in chisla:
                chisla[nominal[i]] += 1
            else:
                chisla[nominal[i]] = 1
            break

sorted_tuple = sorted(chisla.items(), key=lambda x: -x[0])
print(dict(sorted_tuple))