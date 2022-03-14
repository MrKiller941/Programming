arr = [1, 2]

def mirror(arr):
    mirrored_part = arr.reverse()
    arr += list(mirrored_part)

mirror(arr)
print(*arr)