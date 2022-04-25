with open('images/input.txt', 'r') as input_file:
    y = [int(i) for i in input_file.read().split()]

mark1 = []
mark2 = []
mark3 = []

for i in y:
    if i > 0:
        mark1.append(i)
    elif i < 0:
        mark2.append(i)
    else:
        mark3.append(i)

with open('images/output.txt', 'w') as output_file:
    print(len(y), file=output_file)
    print('1', len(mark1), '-1', len(mark2), '0', len(mark3), file=output_file)