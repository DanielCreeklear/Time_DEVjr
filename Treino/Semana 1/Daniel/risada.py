answer = 'S'
risada = input()
risadaVogais = [caracter for caracter in risada if caracter == 'a' or caracter == 'e' or caracter == 'i' or caracter == 'o' or caracter == 'u']

i = 0
j = len(risadaVogais) - 1

while (i < j):
    if risadaVogais[i] != risadaVogais[j]:
        answer = 'N'
        break
    i += 1
    j -= 1
print(answer)
