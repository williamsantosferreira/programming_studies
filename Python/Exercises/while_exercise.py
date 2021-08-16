avg = 0
i = 0
while True:
	number = raw_input('> ')

	if number == 'done':
		break			
	try:
		e_number = float(number)
	except:
		print 'Invalid Data'
		e_number = None

	if e_number is not None:
		i+=1
		avg+=e_number

avg = avg/i

print 'Average =',avg

