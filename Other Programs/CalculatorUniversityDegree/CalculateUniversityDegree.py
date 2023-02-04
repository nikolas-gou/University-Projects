import pandas as pd

df = pd.read_excel('degrees.xlsx')

degree = df.iloc[:, 1].values
ects = df.iloc[:, 2].values

sum = 0;
total_ects = 0;

for i in range(0, len(degree)):
    if degree[i] >= 5:
        sum += degree[i] * ects[i];
        total_ects += ects[i];

print("Your university degree is: " + "{:.2f}".format(sum/total_ects))
