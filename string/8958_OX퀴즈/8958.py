n = int(input())
for _ in range(n):
	count = 0
	ans = 0
	ox = input()
	for c in ox:
		if c == 'O':
			count += 1
		else:
			ans += int(count * (count+1) / 2)
			count = 0
	ans += int(count * (count+1) / 2)
	print(ans)
