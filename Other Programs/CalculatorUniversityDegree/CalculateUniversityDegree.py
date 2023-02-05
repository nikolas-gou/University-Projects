import pandas as pd

def usingExcel(pathOfFile):
    df = pd.read_excel(pathOfFile)

    degree = df.iloc[:, 1].values
    ects = df.iloc[:, 2].values

    sum = 0;
    total_ects = 0;

    for i in range(0, len(degree)):
        if degree[i] >= 5:
            sum += degree[i] * ects[i];
            total_ects += ects[i];
    return sum / total_ects

def inputManualDegrees(numberCourses):
    sum = 0
    total_ects = 0
    for i in range(0, numberCourses):
        print("\nCourse " + str(i+1))
        print("=========")
        degree = float(input("--Degree: "))
        ects = int(input(("--Ects: ")))
        sum += degree * ects
        total_ects += ects
    return sum / total_ects

print("------- Menu ---------")
print("How do you want to introduce your grades:")
print("1. Using .xlsx file")
print("2. Input manual grades")
print("======================")
choice = int(input("===> "))

if choice == 1:
    nameOfFile = input("Give me the path of file: ")
    print("Your university degree is: " + "{:.2f}".format(usingExcel(nameOfFile)))
elif choice == 2:
    numberCourses = int(input("\nGive me the number of courses: "))
    print("Your university degree is: " + "{:.2f}".format(inputManualDegrees(numberCourses)))





