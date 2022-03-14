def palindrome(s):
    s1 = s[::-1]
    if(s == s1):
        return "Палидром"
    else:
        return "Не палидром"

print(palindrome(input()))