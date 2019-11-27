import math

T = int(input())

R = [0]
G = [0]
B = [0]

for i in range(1000000000+1):
	if(i == 0):
		continue
	tmp = long(2**(i-1))
	print(tmp)
	if(tmp % 3 == 1):
		tmp_R = math.floor(tmp/3)+1
		tmp_G = math.floor(tmp/3)
		tmp_B = math.floor(tmp/3)

	if(tmp % 3 == 2):
		tmp_R = math.floor(tmp/3)+1
		tmp_G = math.floor(tmp/3)+1
		tmp_B = math.floor(tmp/3)

	R.append(R[-1]+tmp_R)
	G.append(G[-1]+tmp_G)
	B.append(B[-1]+tmp_B)

for i in range(T):
	n = int(input())

	print("%d %d %d\n", R[n], G[n], B[n])
