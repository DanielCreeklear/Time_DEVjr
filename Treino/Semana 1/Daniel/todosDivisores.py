X = int(input())

for i in range(1, X + 1):
    remainingDivision = X % i
    if (remainingDivision == 0) and (i > 0):
        print(i, end=' ')