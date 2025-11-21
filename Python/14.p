n = input("Enter number: ")
s = sum(int(d)**3 for d in n)
print("Armstrong" if s == int(n) else "Not Armstrong")
