def reverse():
    with open('images/input.dat', 'rb') as input_file:
        y = input_file.read()
    with open('images/output.dat', 'wb') as out_file:
        out_file.write(y[::-1])

reverse()