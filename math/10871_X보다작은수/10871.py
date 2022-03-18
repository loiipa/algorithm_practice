n, x = map(int, input().split())
s = str()
for i in map(int, input().split()):
	if i < x:
		s += str(i) + ' '
s.rstrip()
print(s)
