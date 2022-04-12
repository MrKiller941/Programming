class Number:
 
    def __init__(self, a):
        self.a = [int(x) for x in a.split()]
 
    def make_negative(self):
        for i in range(len(self.a)):
            self.a[i] = -abs(self.a[i])
 
    def square(self):
        for i in range(len(self.a)):
            self.a[i] = (self.a[i]) ** 2
 
    def strange_command(self):
        for i in range(len(self.a)):
            if self.a[i] % 5 == 0:
                self.a[i] += 1
 
    def test_stringify(self):
        for i in range(len(self.a)):
            self.a[i] = str(self.a[i])
 
 
d = Number(input())
for i in range(int(input())):
    s = input()
    if s == 'make_negative':
        d.make_negative()
    elif s == 'square':
        d.square()
    else:
        d.strange_command()
d.test_stringify()
print(' '.join(d.a))