d = {"nums": [55, 22, 88, 11, 44]}
print("Before Sorting:", d)
lst = d["nums"]
for i in range(len(lst)):
    for j in range(i+1, len(lst)):
        if lst[i] > lst[j]:
            lst[i], lst[j] = lst[j], lst[i]

d["nums"] = lst
print("After Sorting:", d)
print("Sorting complete ✅")
