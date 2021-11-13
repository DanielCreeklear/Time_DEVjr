appeared_number = [0 for i in range(10)]
N = int(input())

for i in range(N):
    number = input()
    for digit in number:
        appeared_number[int(digit)] += 1

for i in range(10):
    print(f'{i} - {appeared_number[i]}')