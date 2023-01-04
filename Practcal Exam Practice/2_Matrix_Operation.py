#<-----------------------| Accept Matrix |---------------------------->
def accept(M):
    print("Enter Order of matrix (row, col) : ")
    r = int(input("Enter No of rows : "))
    c = int(input("Enter No of cols : "))

    print("Enter ELement of Matrix : ")
    for i in range(r):
        A = []
        for j in range(c):
            A.append(int(input()))
        M.append(A)
    print("Matrix Accepted Successfully...!")

#<-------------------| DISPLAY MATRIX |--------------------->
def display(M, r, c):
    print("Matrix (", r, c, ") : ")
    for i in range(r):
        for j in range(c):
            print("   ", M[i][j], end='')
        print()

#<-------------------| ADDITION OF MATRIX |--------------------------->
def addtion(M1, M2, M3, r, c):
    for i in range(r):
        A = []
        for j in range(c):
            A.append(M1[i][j] + M2[i][j])
        M3.append(A)

#<-------------------| SUBTRACTION OF MATRIX |--------------------------->
def subtracation(M1, M2, M3, r, c):
    for i in range(r):
        A = []
        for j in range(c):
            A.append(M1[i][j] - M2[i][j])
        M3.append(A)

#<-------------------| MULTIPLICTION OF MATRIX |--------------------------->
def multiplication(M1, M2, M3, r1, c2, c1):
    for i in range(r1):
        A = []
        for j in range(c2):
            sum = 0
            for k in range(c1):
                sum += M1[i][k] * M2[k][j]
            A.append(sum)
        M3.append(A)

#<------------------------| Transpose of matrix |------------------------------>
def transpose(M1, r, c, T):
    for i in range(r):
        A = []
        for j in range(c):
            A.append(M1[j][i])
        T.append(A)

#<-----------------------| Main Function |---------------------------------->
while True:
    M3 = []
    print("\n\n\n===========================================================")
    print("********************| MATRIX OPERATION |*******************")
    print("===========================================================")
    print("\t1. Accept Matrix")
    print("\t2. Display Matrix")
    print("\t3. Matrix Addition")
    print("\t4. Matrix Subtraction")
    print("\t5. Matrix Multiplication")
    print("\t6. Matrix Transpose")
    print("\t7. Exit")
    print("===========================================================")
    ch = int(input("Enter Your Choice : "))
    print("===========================================================")
    if ch==1:
        M1 = []
        M2 = []
        print("Enter first Matrix : ")
        accept(M1)
        r1 = len(M1)
        c1 = len(M1[0])

        print("Enter Second Matrix : ")
        accept(M2)
        r2 = len(M2)
        c2 = len(M2[0])

    elif ch == 2:
        print("Matrix 1 elements are : ")
        display(M1, r1, c1)
        print("Matrix 2 elmenents are : ")
        display(M2, r2, c2)

    elif ch == 3:
        if r1 == r2 and c1 == c2:
            addtion(M1, M2, M3, r2, c2)
            print("Addition Matrix : ")
            display(M3, r1 , c1)

    elif ch == 4:
        if r1 == r2 and c1 == c2:
            subtracation(M1, M2, M3, r2, c2)
            print("Subtraction Matrix : ")
            display(M3, r1, c1)

    elif ch == 5:
        if c1 == r2:
            multiplication(M1, M2, M3, r1, c2, c1)
            print("Multiplication Matrix : ")
            display(M3, r1, c1)

    elif ch == 6:
        print("First Matrix : ")
        display(M1, r1, c1)
        transpose(M1, r1, c1, M3)
        print("Transpose Matrix : ")
        display(M3, r1, c1)

        M3 = []
        print("Second Matrix : ")
        display(M2, r2, c2)
        transpose(M2, r2, c2, M3)
        print("Transpose Matrix : ")
        display(M3, r2, c2)

    elif ch == 7:
        print("***********************| THANK YOU |**************************")
        print("====================================================================")
        break

    else:
        print("Invalid choice...Enter VAlid Choice...!")

    print("====================================================================")