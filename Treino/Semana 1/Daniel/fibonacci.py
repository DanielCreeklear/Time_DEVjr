fibonacci_calculated = {}

def fibonacci(n: int) -> int:
    if fibonacci_calculated[n] != -1:
        return fibonacci_calculated[n]
    else:
        fibonacci_calculated[n] = fibonacci(n - 1) + fibonacci(n - 2)
        return fibonacci_calculated[n]

n = int(input())
for i in range(n + 1):
    fibonacci_calculated[i] = -1

fibonacci_calculated[0] = fibonacci_calculated[1] = 1
print(fibonacci(n))