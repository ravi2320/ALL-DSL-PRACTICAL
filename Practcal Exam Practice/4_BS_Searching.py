def binary(arr, s):
    flag = 0
    for i in range(len(arr)):
        if arr[i] == s:
            print(s, "was present in training program")
            flag = 1
            break
    if(flag == 0):
        print(s, "was not present in training program")
def sentinal(arr, s):
    last = arr[len(arr)-1]
    arr[len(arr)-1] = s
    i = 0
    while arr[i] != s:
        i+=1
    arr[len(arr)-1] = last
    if i<len(arr)-1 or arr[len(arr)-1] == s:
        print(s, " was present in training program")
    else:
        print(s, " was not present in training program")

arr = []
n = int(input("Enter no of present students :"))
for i in range(n):
    p = int(input("Enter the no who present in training program : "))
    arr.append(p)
ch = 0
while(ch!=3):
    print("\n\n\n=============================================================")
    print("***********************| SEARCH STUDENT |*********************")
    print("==============================================================")
    print("\t1. Binary Search")
    print("\t2. Sentinal Search")
    print("\t3. Exit")
    print("===============================================================")
    ch = int(input("Enter Your choice : "))
    print("===============================================================")
    if(ch==3):
        print("**********************| THANK YOU |************************")
        print("===============================================================")
        break
    elif ch == 1:
        s = int(input("Enter the Roll do you want to search : "))
        binary(arr, s)
    elif ch == 2:
        s = int(input("Enter The Roll no you want to search : "))
        sentinal(arr, s)
    else:
        print("Invalid Choice...Enter Valid Choice...!")
    print("===============================================================")

