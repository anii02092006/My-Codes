lst = [["a", 10], ["b", 20], ["c", 30], ["d", 40]]
d = {}
for i in lst:
    d[i[0]] = i[1]

print("Nested List:", lst)
print("Converted to Dictionary:")
print(d)
print("Data stored ✔")
