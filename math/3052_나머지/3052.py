s = set()
while True:
	try:
		s.add(int(input()) % 42)
	except:
		break
print(len(s))
