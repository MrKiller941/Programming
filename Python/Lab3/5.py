Count_of_strings = int(input())
List = []
for i in range(Count_of_strings):
    for element in input().split():
        List.append(element)
        
print(len(set(List)))