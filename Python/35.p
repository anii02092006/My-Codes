lst = [1, 1, 2, 3, 3, 4, 5, 5, 6]
uni = []
for i in lst:
    if i not in uni:
        uni.append(i)

print("Original List:", lst)
print("Unique List:", uni)
print("Duplicates removed ✨")
print("Process completed")
