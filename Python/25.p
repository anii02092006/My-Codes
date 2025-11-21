try:
    x = int(input("Enter number: "))
    print(10 / x)
except ZeroDivisionError:
    print("Can't divide by 0!")
except ValueError:
    print("Invalid input!")
