s = input("Enter string: ")
v = "aeiouAEIOU"
count = sum(1 for i in s if i in v)
print("Vowels:", count)
