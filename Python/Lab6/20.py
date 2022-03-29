def cached(func):
    ch = {}
    
    def wrapper(*args, **kwargs):
        nonlocal ch
        print(ch)
        if not ch.get(args):
            g = func(*args, **kwargs)
            ch[args] = g
            return g
        else:
            return ch[args]

    return wrapper

@cached
def fibonachi(n): 
    if n == 1 or n == 2: 
        return 1 
    else: 
        return fibonachi(n - 1) + fibonachi(n - 2)

print(fibonachi(6))