s1 = {1, 2, 3, 4}
s2 = {3, 4, 5, 6}
inter = set()
for i in s1:
    if i in s2:
        inter.add(i)

print("Set 1:", s1)
print("Set 2:", s2)
print("Common Elements:", inter)
print("Intersection done 🤝🏻")
