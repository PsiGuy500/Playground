##order DOES not matter for this

def factorial(f):
    if f == 1:
        return f
    else:
        return f*factorial(f-1)

p = float(input("Enter probability of success: "))
k = int(input("Enter number of successes: "))
n = int(input("Enter number of trials: "))

x = factorial(n)/(factorial(k)*factorial(n-k))
y = p**k
z = (1-p)**(n-k)

d = float(x*y*z)
e = round(d,3)

txt = "The probability of receiving {} successes in {} trials is {}".format(k,n,e)
print(txt)


