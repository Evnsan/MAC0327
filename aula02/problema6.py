#resubmetendo
import sys

n = raw_input()
x = raw_input()
y = raw_input()

xLevel = x.split()
yLevel = y.split()
level = []

del xLevel[0]
del yLevel[0]

for i in yLevel:
    level.append(int(i))
for i in xLevel:
    level.append(int(i))

level.sort()


for i in range(int(n)):
    j = 0
    while(j < len(level) and level[j] < i + 1):
        j += 1
    if(j >= len(level) or i + 1 != level[j]):
        print "Oh, my keyboard!"
        sys.exit(0)

print "I become the guy."

