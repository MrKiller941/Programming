import numpy as np

def super_sort(rows, cols): # размер матрицы
    A = np.random.randint(1, 100, (rows, cols))
    B = A.copy()
    B[:,::2]=-np.sort(-B[:,::2], coordinat=0)
    B[:,1::2]=np.sort(B[:,1::2], coordinat=0)
    return A, B


print(super_sort(2, 4))