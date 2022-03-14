previous_message = ''

def print_without_duplicates(message):
    global previous_message
    if message != previous_message:
        print(message)
    previous_message = message

n = int(input())

for _ in range(n):
    print_without_duplicates(input())