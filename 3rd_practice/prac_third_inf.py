from math import *


def f(x,y):
    return log(abs(sin(x + y)), e)


def f_2(x,y):
    if sin(x + y) <= -0.5:
        return atan(pow(abs(x - y), 1/3)) * (x * pow(e, y))
    elif sin(x + y) >= 0.5:
        return pow(x, 3) + pow(y, 1.5)
    return 3 * log(abs(x * y))


def f_3(x):
    return pow(cos(e * x), 3) + sin(abs(x))


def f_4(x, y):
    if x + y <= 2:
        return pow(sin(x * pow(e, 0.1 * y)), 1/3)
    return abs(log2(x + y))


print('№1')
x, y = int(input('Введите значение x\n')), int(input('Введите значение y\n'))
print(f'значение для x = {x} и y = {y} равно: {f(x , y)}')

print('№2')
x, y = int(input('Введите значение x\n')), int(input('Введите значение y\n'))
print(f'значение для x = {x} и y = {y} равно: {f_2(x , y)}')

print('№3')
for i in range(int(input('Введите значение a для отрезка [a,b]\n')),int(input('Введите значение b для отрезка [a,b]\n')) + 1, int(input('Введите значение hx для шага\n'))):
    print(f'значение для числа {i} равно:')
    print(f_3(i))


print('№4')
for j in range(2, 6):
    x = j/2
    for y in range(1, 5):
        print(f'при x = {x}, y = {y} значение:')
        print(f(x, y))
