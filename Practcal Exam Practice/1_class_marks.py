#<--------------- Total And Average marks in class -------------------------->
def average(marksInFDS):
    total = 0
    for i in range(len(marksInFDS)):
        total += marksInFDS[i]
    print("Total Marks are : ", total)
    print("Average marks are : ", total/len(marksInFDS))

#<---------------- Max marks in class ------------------->
def max_min_marks(marksInFDS):
    max = 0
    min = marksInFDS[0]
    for i in range(len(marksInFDS)):
        if(max < marksInFDS[i]):
            max = marksInFDS[i]
        if marksInFDS[i]!=0:
            if marksInFDS[i] < min:
                min = marksInFDS[i]
    print("Max Marks are : ", max)
    print("Min Marks are : ", min)

#<---------------- Absent Student in class ------------------------>
def absent(marksInFDS):
    cnt = 0
    for i in range(len(marksInFDS)):
        if marksInFDS[i] == 0:
            cnt +=1
    print("No of absent students are : ", cnt)

#<-------------- Marks and frequency ----------------------------->
def maxFrequency(marksInFDS):
    print("| MARKS | FREQUENCY |")
    j=0
    max = 0
    for i in marksInFDS:
        if (marksInFDS.index(i) == j):
            print("| ",i, " | ", marksInFDS.count(i)," |")
            if marksInFDS.count(i) > max:
                max = marksInFDS.count(i)
                mark = i
        j += 1
    print("Highest frequency mark is ", mark, " that frequency is : ", max)
# Main Function

marksInFDS = []

n = int(input("\nEnter the number of students : "))
print("Note : FOr absent student enter 0")
for i in range(n):
    mark = int(input("Enter Marks of student"+str(i+1)+" : "))
    marksInFDS.append(mark)

flag = True
while(flag):
    print("\n\n\n==========================================================")
    print("**********************| MENU |****************************")
    print("==========================================================")
    print("\t1. Total and Average Marks of the class ")
    print("\t2. Highest and Lowest marks in the class")
    print("\t3. Number of Student absent for the Test")
    print("\t4. Marks with highest frequency")
    print("\t5. Exit")
    print("==========================================================")
    ch = int(input("Enter Your choice : "))
    print("===========================================================")
    if ch == 1:
        average(marksInFDS)
    elif ch == 2:
       max_min_marks(marksInFDS)
    elif ch == 3:
        absent(marksInFDS)
    elif ch == 4:
        maxFrequency(marksInFDS)
    elif ch == 5:
        flag = False
        print("**********************| THANK YOU |***********************")
    else:
        print("Invalid choic...Enter Valid choice...!")
    print("===========================================================")
