string = 'abc'
value1 = None

sum1 = 0
sum2 = 0

for x in string:
	x = ord(x)
	
	if value1 is None:
		value1 = str(x)
	else:
		value1 = value1 + str(x)
for x in value1:
	if x == '7':
		y = '1'
	else:
		y = x

	sum1 = sum1 + int(x)
	sum2 = sum2 + int(y)
else:
	print(sum1-sum2)
