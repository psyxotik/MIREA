#№1
print('Тажетдинов Равиль, БФБО-07-24')
#№2
print(int(input()) + int(input()))
#№3
x = int(input())
print(x ** 5 - 2 * x ** 3 + 1)
#№4
strange = [ [],1]
print(type(strange))
#№5
for x in range(100):
    for y in range(100):
        if ((x or y) and (not(x) or y) and not(x and y)):
            print(x, y)
            break
#№6
from random import randint
spis = [randint(1, 100) for x in range(4)]
print(spis)
for i in range(1, 5):
    print(spis[-i], end=' ')
print()
#№7
from math import log2, tan, cos, sin, log, exp
k = int(input())
print(log2(k))
#№8
a = float(input())
b = float(input())
print((-a * log2(a)) + (-b * log2(b)))
#№9
y = int(input())
print(tan(((cos(y) * sin(2 * y)) / (y * exp(y)))) ** log(y, 7))
#№10.1
bit = [randint(0,1) for x in range(8)]
if bit.count(1) % 2 == 0:
    bit.append(0)
else:
    bit.append(1)
print(bit)
#№10.2
bit = input()
if bit.count('1') % 2 == 0:
    bit += '0'
else:
    bit += '1'
print(bit)


a, b, c, d = int(input())