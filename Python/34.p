d = {"name": "Anitha", "age": 21, "city": "India", "dept": "CS"}
print("Original Dict:", d)
keys = ["age", "dept"]
for k in keys:
    if k in d:
        del d[k]

print("After deleting keys:", keys)
print(d)
print("Keys removed successfully ✔")
