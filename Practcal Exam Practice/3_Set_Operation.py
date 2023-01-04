C = ["Ravindra", "Sagar", "Neha", "Prajakta", "Akshata","Yash", "Nikhil"]
B = ["Ravindra", "Shrushti", "Vaishanvi", "Akshata"]
F = ["Neha", "Ravindra", "Sampada", "Akshata"]

#finding the length of all
clen = len(C)
blen = len(B)
flen = len(F)

print("=====================================================================")
print("Student who play both cricket and badminton : ")
CB = []
for i in range(blen):
    for j in range(clen):
        if B[i] == C[j]:
            CB.append(B[i])
            break
print(CB)

print("\n===============================================================================")
print("List of students who play either cricket or badminton but not both : ")
CBN = []
flag = 0
for i in range(blen):
    for j in range(clen):
        if B[i] == C[j]:
            flag = 1
            break
    if flag == 0:
        CBN.append(B[i])
    flag = 0

for i in range(clen):
    for j in range(blen):
        if C[i] == B[j]:
            flag = 1
            break
    if flag == 0:
        CBN.append(C[i])
    flag = 0
print(CBN)


print("\n==========================================================================")
print("List of student who play neither cricket and nor badminton : ")
NCNB =[]
flag = 0
for i in range(flen):
    for j in range(blen):
        if F[i] == B[j]:
            flag = 1
            break
    for k in range(clen):
        if F[i] == C[k]:
            flag = 1
            break
    if flag == 0:
        NCNB.append(F[i])
    flag = 0
print(NCNB)

print("\n======================================================")
print("List of student who play cricket and football but not badminton : ")
CFNB = []
CF = []
flag = 0
for i in range(clen):
    for j in range(flen):
        if C[i] == F[j]:
            flag = 1
            break
    if flag == 1:
        CF.append(C[i])
    flag = 0
flag = 0
for i in range(len(CF)):
    for j in range(blen):
        if CF[i] == B[j]:
            flag = 1
            break
    if flag == 0:
        CFNB.append(CF[i])
    flag = 0
print(CFNB)