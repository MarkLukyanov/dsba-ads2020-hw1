import matplotlib.pyplot as plt
import csv

x1 = []
x2 = []
x3 = []

y = []

with open('/Users/glas/Desktop/test.csv') as csvfile:
    plot = csv.reader(csvfile, delimiter = ';')
    for row in plot:
        y.append(float(row[0]))
        x1.append(float(row[1]))
        x2.append(float(row[2]))
        x3.append(float(row[3]))

# plt.ylim(0, 10)
# plt.xlim(1000, 10100)

plt.plot(y, x1, label = 'Grade School Multiplication')
plt.plot(y, x2, label = 'Divide&Conquer')
plt.plot(y, x3, label = 'Karatsuba')
plt.xlabel('The length of multipliers')
plt.ylabel('Runtime(in secs)')
plt.title('From 1 to 5000 digits')
plt.legend()
plt.show()