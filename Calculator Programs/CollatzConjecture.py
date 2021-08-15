x = int(input("Enter a number: "))

c = 0
while True:
    if x % 2 == 0:
        x = x/2
    else:
        x= 3*x+1
    if x == 1:
        print("1.0")
        break
    c += 1
    print(x)

print("This process takes " + str(c+1) + " iterations")












