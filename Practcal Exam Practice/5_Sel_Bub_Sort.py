def accept(A):
    n = int(input("Enter Total No of students : "))
    for i in range(n):
        ele = int(input("Enter the first year percentage of student : "))
        A.append(ele)
    print("Array Accepted successfully..!")

def display(A):
    print("Array of FE Marks : ", end='')
    for i in range(len(A)):
        print(A[i], " ", end='')
    print()

def bubble(arr):
    n = len(arr)
    for i in range(n-1):
        for j in range(n - i - 1):
            if arr[j] < arr[j+1]:
                temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp

def selection(arr):
    n = len(arr)
    for i in range(n-1):
        min = i
        for j in range(i+1, n):
            if arr[min] > arr[j]:
                min = j
        temp = arr[min]
        arr[min] = arr[i]
        arr[i] = temp
def top_5(A):
    print("Top Five Marks are : ", end='')
    for i in range(5):
        print(A[i], " ", end='')
    print()
ch = 0
while ch != 5:
    print("\n\n\n==============================================================")
    print("*********************| SORTING |*******************************")
    print("===============================================================")
    print("\t1. Accept and Display Array")
    print("\t2. Bubble Sort")
    print("\t3. Selection Sort")
    print("\t4. Top Five Element")
    print("\t5. Exit")
    print("===============================================================")
    ch = int(input("Enter your choice : "))
    print("===============================================================")
    if ch == 5:
        print("*********************| THANK YOU |*************************")
        print("===========================================================")
        break
    elif ch == 1:
        A = []
        accept(A)
        display(A)
    elif ch == 2:
        print("Before Sorting ")
        display(A)
        print("After Sorting")
        bubble(A)
        display(A)

    elif ch == 3:
        print("Before Sorting ")
        display(A)
        print("After Sorting")
        selection(A)
        display(A)
    elif ch == 4:
        top_5(A)
    else:
        print("Invalid choice...Enter Valid Choice...!")
    print("=========================================================")