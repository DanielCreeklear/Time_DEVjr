# EXCEPTION
answer = -1

N = int(input())

sum_columns = [0 for i in range(N)]
sum_lines = [0 for i in range(N)]
sum_main_diagonal = 0
sum_secondary_diagonal = 0

for i in range(N):
    line = input().split(' ')
    for j in range(N):
        number = int(line[j])
        
        sum_columns[j] += number
        sum_lines[i] += number

        if i == j:
            sum_main_diagonal += number
        if j == N - 1 - i:
            sum_secondary_diagonal += number

if sum_main_diagonal == sum_secondary_diagonal and sum_main_diagonal == int(sum_columns[0]) and sum_main_diagonal == int(sum_lines[0]):
    for i in range(1, N):
        if sum_columns[i] != sum_main_diagonal or sum_lines[i] != sum_main_diagonal:
            break
        if i + 1 == N:
            answer = sum_main_diagonal
print(answer)