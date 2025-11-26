d = {"one": 1, "two": 2, "three": 3}
new = {}
print("Original:", d)
for k, v in d.items():
    new[v] = k

print("Swapped dictionary:")
print(new)
print("Keys and values swapped 🔄")
print("Completed ✅")
