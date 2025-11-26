lst = ["red", "blue", "green", "yellow"]
flag = False
for i in lst:
    if i == "green":
        flag = True

print("Checking for green...")
print("Exists ✅" if flag else "Not found ❌")
print("List scanned!")
print("Finished")
