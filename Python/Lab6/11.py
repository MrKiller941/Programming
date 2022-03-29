def print_operation_table(operation, num_rows=2, num_columns=2):
    for i in range(1, num_rows + 1):
        answer = []
        for n in range(1, num_columns + 1):
            answer.append(str(operation(i, n)))
        print(''.join(f'{a:<4}' for a in answer))


print_operation_table(lambda x, y: x * y)