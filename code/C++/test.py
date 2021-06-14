ans = 1;
mod = 1000000000 + 7;
# m = int(168 / 2);
for i in range (9):
	a = int(input());
	b = int(input());
	if(b > 1):
		if(b % 2 == 0):
			for i in range(b):
				ans *= a;
		else:
			for i in range(b - 1):
				ans *= a;
print(ans % mod);