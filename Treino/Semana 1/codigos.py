digits = [1, 0, 0]
codes_found = 0
digit = 0

N = int(input())
code = [int(number) for number in input().split(' ')]

for input_code in code:
    if input_code == digits[digit]:
        if digit == 2:
            codes_found += 1
            digit = 0
        else:
            digit += 1
    else:
        if input_code == digits[0]:
            digit = 1
        else:
            digit = 0
print(codes_found)
