def alphabet():
    n = ord('а') - 1
    while(n != ord('я')):
        n+= 1
        yield chr(n)

print(list(alphabet()))