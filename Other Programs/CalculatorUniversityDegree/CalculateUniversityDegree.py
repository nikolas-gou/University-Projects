import pandas as pd

df = pd.read_excel('degrees.xlsx')

array_1 = df.iloc[:, 1].values
array_2 = df.iloc[:, 2].values

sum = 0;
total_ects = 0;

for i in range(0, 39):
    if array_1[i] >= 5:
        sum += array_1[i] * array_2[i];
        total_ects += array_2[i];

print("Your university degree is: ", sum/total_ects)

for i in range(0, 39):
    if array_1[i] >= 5:
        sum += array_1[i] * array_2[i];
        total_ects += array_2[i];


