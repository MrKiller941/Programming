class Summator:
    def transform(self, n):
        return n
 
    def sum(self, N):
        s = 0
        for i in range(1, N + 1):
            s += self.transform(i)
        return s
 
 
class Sum(Summator):
    def __init__(self, b):
        self.b = b
 
    def transform(self, n):
        return n ** self.b
 
 
class SquareSummator(Sum):
    def __init__(self):
        super().__init__(2)
 
 
class CubeSummator(Sum):
    def __init__(self):
        super().__init__(3)
N = 3
summator = SquareSummator()
print(summator.sum(N))
print(N * (N + 1) / 2)