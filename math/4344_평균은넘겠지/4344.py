n = int(input())
for _ in range(n):
	l = list(map(int, input().split()))
	num_of_all = l[0]
	del l[0]
	avg = sum(l)/len(l)
	num_of_upper = 0
	for i in l:
		if i > avg:
			num_of_upper += 1
	ans = num_of_upper/num_of_all * 100
	print('%.3f%%' % ans)
