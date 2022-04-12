class SparseArray:

    def __init__(self):
        self.data = {}

    def __getitem__(self, key):
        return self.data.get(key, 0)

    def __setitem__(self, key, value):
        self.data[key] = value

arr = SparseArray()
arr[8] = 167
for i in range(8, 10):
    print('arr[{}] = {}'.format(i, arr[i]))