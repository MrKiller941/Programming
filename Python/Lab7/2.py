class Balance:

    left = 0
    right = 0

    def add_right(self, n):
        self.right += int(n)

    def add_left(self, n):
        self.left += int(n)

    def result(self):
        if self.left > self.right:
            return "L"
        elif self.left < self.right:
            return 'R'
        else:
            return '='


balance = Balance()
balance.add_right(1)
balance.add_left(2)
balance.add_left(3)
print(balance.result())
balance.add_left(4)
print(balance.result())
