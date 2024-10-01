
#1
print('№1')
n = int(input("Введите основание системы счисления (n): "))
A = input("Введите число в системе счисления с основанием n: ")

decimal_value = int(A, n)

print(f"Число {A} в системе с основанием {n} равно {decimal_value} в десятичной системе.")

#2
print('№2')
a = input('Введите двузначное число: ')
if a.count('3') != 0:
    print('есть 3')
else:
    print('нет 3')

# b = int(input('Введите двузначное число: '))
# if b // 10 == 3 or b % 10 == 3:
#     print('есть 3')
#3
print('№3')
a = int(input('Введите двузначное число: '))
print(f'Наибольшая цифра: {a // 10 if (a // 10) > (a % 10) else a % 10}')

#4
print('№4')
a = int(input('Введите коэффициэнт a: '))
b = int(input('Введите коэффициэнт b: '))
c = int(input('Введите коэффициэнт c: '))
d = b ** 2 - 4 * a * c
if d < 0:
    print('корней нет')
else:
    x1 = (-b + d ** 0.5) / (2 * a)
    x2 = (-b - d ** 0.5) / (2 * a)
    print(f'x1 = {x1}, x2 = {x2}' if x1 != x2 else f'x1 = {x1}')

#5
print('№5')
numb = int(input('Введите число: '))
for i in range(2, numb + 1):
    if numb % i == 0:
        print(f'Наименьший делитель числа {numb} - число {i}')
        break

#6
print('№6')
n = int(input('введите число: '))
print(f'сумма первых n членов равна: {(n + 1) // 2 * n}')

#7
print('№7')
a = int(input('Введите число: '))
flag = True
for i in range(2, a):
    if a % i == 0:
        print('Не простое')
        flag = False
        break
if flag:
    print('Простое число')

#8
print('№8')
n = int(input('Введите десятичное число: '))
a = int(input('Введите систему счисления: '))
letters = '0123456789ABCDEFGHIJKLMNOPQRSTYVWXYZ'
s = ''
while n > 0:
    s = letters[n % a] + s
    n //= a
print(f'десятичное число {n} в системе счисления {a} равно {s}')