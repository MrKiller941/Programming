class Polynomial:

    def __init__(self, coefficients):
        self.coefficients = coefficients

    def __call__(self, x):
        resultat = 0
        for i in range(len(self.coefficients)):
            resultat += pow(x, i) * self.coefficients[i]
        return resultat

    def __add__(self, other):
        l = []
        resultat = Polynomial(l)
        if len(self.coefficients) < len(other.coefficients):
            n = len(self.coefficients)
        else:
            n = len(other.coefficients)
        for i in range(n):
            l.append(self.coefficients[i] + other.coefficients[i])
        if len(self.coefficients) > n:
            l += self.coefficients[n::]
        else:
            l += other.coefficients[n::]
        resultat.coefficients = l
        return resultat

poly_one = Polynomial([0, 1])
poly_two = Polynomial([10])
poly_three = poly_one + poly_two
poly_four = poly_two + poly_one
 
print(poly_three(-2), poly_four(-2))
print(poly_three(-1), poly_four(-1))
print(poly_three(0), poly_four(0))
print(poly_three(1), poly_four(1))
print(poly_three(2), poly_four(2))