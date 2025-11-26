lst = [[1,2,3], [4,5], [6], [7,8,9]]
flat = []
print("Nested List:", lst)
for sub in lst:
    for val in sub:
        flat.append(val)

print("Flattened list:")
print(flat)
print("Flattening done ✅")
