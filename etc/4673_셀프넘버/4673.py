def self_number(number):
	all_number = set()
	together_number = set()
	for i in range(1, number+1):
		all_number.add(i)
		num = i
		tmp = i
		while tmp > 0:
			num += tmp % 10
			tmp = int(tmp / 10)
		together_number.add(num)
	return sorted(all_number - together_number)
	
for i in self_number(10000):
	print(i)
