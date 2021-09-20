a = int(input())
b = int(input())
div = 1

for i in range(0, 3):
	print(a * (int(b / div) % 10))
	div *= 10
print(a*b)
