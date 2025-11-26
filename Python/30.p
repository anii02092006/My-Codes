lst = [4, 5, 5, 6, 6, 6, 7, 7]
freq = {}
for i in lst:
    if i in freq:
        freq[i] += 1
    else:
        freq[i] = 1

print("Given List:", lst)
print("Element Frequency:")
print(freq)
print("Calculation complete ✔")
