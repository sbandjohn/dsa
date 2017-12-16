import random

with open("large.in", "w") as f:
	n = 100
	f.write(str(n)+'\n');
	for i in range(n):
		op = random.randint(1,8)
		if (op in [1,2,3] ): op = 1
		if (op in [4,5]): op = 2
		if (op in [6]): op = 3;
		if (op in [7, 8]): op = 4;
		a = 0
		if (op == 1):
			a = random.randint(1,100)
		if (op == 2):
			a = random.randint(0,1)
		if (op == 3):
			a = random.randint(0,1)
		if (op == 4):
			a = random.randint(1,100)
		f.write(str(op)+' '+str(a)+'\n')
