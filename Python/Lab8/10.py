with open('images/picture.bmp', 'rb') as input_file:
    temp = bytes(input_file.read())

negativ = []
for k, a in enumerate(temp):
    if k < 54:
        negativ.append(a)
    else:
        negativ.append(255 - a)

with open('images/output.bmp', 'wb') as output_file:
    output_file.write(bytes(negativ))