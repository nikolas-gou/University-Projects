import pandas as pd

def usingExcel(pathOfFile):
    df = pd.read_excel(pathOfFile);
    course = df.iloc[:, 0].values;
    degree = df.iloc[:, 1].values;
    ects = df.iloc[:, 2].values;
    # print(course, degree)

    sum = 0;
    total_ects = 0;
    passed_courses = 0;
    total_courses = 0;

    for i in range(0, len(degree)):
        if degree[i] >= 5:
            if sum == 0:
                 print("\nCourses that you have not pass:")
            sum += degree[i] * ects[i];
            total_ects += ects[i];
            passed_courses = passed_courses + 1;
        else:
            print(i+2, course[i], degree[i])
        total_courses = total_courses + 1;
    return { 'degrees': sum / total_ects, 'passed_courses': passed_courses, 'total_courses': total_courses, "total_ects": total_ects };

def inputManualDegrees(numberCourses):
    sum = 0;
    total_ects = 0;
    for i in range(0, numberCourses):
        print("\nCourse " + str(i+1));
        print("=========");
        degree = float(input("--Degree: "));
        ects = int(input(("--Ects: ")));
        sum += degree * ects;
        total_ects += ects;
    return sum / total_ects;

print("------- Menu ---------");
print("How do you want to introduce your grades:");
print("1. Using .xlsx file");
print("2. Input manual grades");
print("======================");
choice = int(input("===> "));

if choice == 1:
    nameOfFile = input("Give me the path of file: ")
    # define a default file
    if not nameOfFile:
        nameOfFile = "degrees.xlsx"
    result = usingExcel(nameOfFile)
    passed_courses = str(result['passed_courses'])  # Convert integer to string
    total_courses = str(result['total_courses'])  # Convert integer to string
    total_ects = str(result['total_ects'])  # Convert integer to string
    print("\nYou have passed: " + passed_courses + "/ " + total_courses, " ects:", total_ects)
    print("Your university degree is: {:.2f}".format(result['degrees']))
elif choice == 2:
    numberCourses = int(input("\nGive me the number of courses: "))
    print("Your university degree is: {:.2f}".format(inputManualDegrees(numberCourses)))


