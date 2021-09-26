dic = []
max = -1
for i in range(9):
	n = int(input())
	dic.append(n)
	if n > max:
		max = n
print(max)
print(dic.index(max) + 1)
