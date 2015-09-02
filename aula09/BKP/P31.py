# Shayenne Moura
#!/usr/bin/env python

import math

n = int(raw_input())

f = [1, 1]

def fibonacci(n):
    try:
        return f[n-1]
    except IndexError:
        for i in range(len(f)-1, n):
            f.append(f[i]+f[i-1])

        return f[n-1]

if n > 2:
    print fibonacci(n) + fibonacci(n-1) + fibonacci(n-2)
else:
    print "2"

