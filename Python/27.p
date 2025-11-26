t = (22, 5, 88, 1, 64, 10)
mx = t[0]
mn = t[0]
for i in t:
    if i > mx:
        mx = i
    if i < mn:
        mn = i

print("Max number:", mx)
print("Min number:", mn)
