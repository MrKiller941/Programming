r = int(input())
synonym = {}

for i in range(r):
    first, second = input().split()
    synonym[first] = second
    synonym[second] = first

print(synonym[input()])
