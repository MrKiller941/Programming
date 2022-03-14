def from_string_to_list(string, container):
    container += string.split()

a = [1,2,3]
from_string_to_list("", a)
print(*a)