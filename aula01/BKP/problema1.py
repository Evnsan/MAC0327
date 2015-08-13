hold = 2
dh = dmax = dd = a[2] - a[1]


for i in range(1, n-1):
	da = dd
	dd = a[i+1] - a[i]
	if dd > dmax:
		dmax = dd
	di = da + dd
	if di < dh:
		hold = i
		dh = di
		if dh > dmax:
			dmax = dh
	
