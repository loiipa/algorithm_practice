l = [input() for i in range(0, 3)]
num = int(l[0]) * int(l[1]) * int(l[2])

s = str(num)
for i in range (0, 10):
	print(s.count(str(i)))
