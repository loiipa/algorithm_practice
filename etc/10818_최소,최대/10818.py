n = int(input())
max = -2000000
min = 2000000
for i in map(int, input().split()):
	if i > max:
		max = i
	if i < min:
		min = i
print(min, max)
