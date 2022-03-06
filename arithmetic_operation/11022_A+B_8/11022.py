import sys
case_num = int(sys.stdin.readline())
for i in range(1, case_num+1):
	a, b = map(int, sys.stdin.readline().split())
	print('Case #%d: %d + %d = %d' %(i, a, b, a+b))
