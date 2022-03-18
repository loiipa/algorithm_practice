n = int(input())
a = int(n/10)
b = n%10
b_next = None
answer = 0

while True:
	b_next = (a + b) % 10
	a = b
	b = b_next
	answer += 1
	if n == 10*a + b:
		break

print(answer)
