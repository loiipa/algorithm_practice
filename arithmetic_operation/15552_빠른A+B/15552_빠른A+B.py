import sys
case_num = int(sys.stdin.readline())
for i in range(case_num):
	a, b = map(int, sys.stdin.readline().split())
	print(a+b)
