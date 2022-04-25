import numpy as np

def make_field(size): # функция в которую поступают значения размеров доски
    chess = np.zeros((size, size), dtype='int8')
    chess[size % 2::3, ::2] = 2 
    chess[(size + 2) % 2::3, 1::2] = 1 
    return chess

print(make_field(20))