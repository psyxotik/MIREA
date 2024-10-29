print('№1')

k, n = map(int, input('Введите числа k и n\n').split())
print((1 << k) + (1 << n))

print('№2')
n = int(input('Введите число n\n'))
print("No" if n & (n - 1) else "Yes")

print('№3')
a, k = map(int, input('Введите числа a и k\n').split())
print(a | (1 << k))


print('№4')
k, n = map(int, input('Введите числа k и n\n').split())
print((n >> k) << k)