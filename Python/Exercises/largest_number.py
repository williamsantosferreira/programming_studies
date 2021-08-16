# Find the largest number in the list

numbers = [12,30,1,14,20]

largest_number = None

print 'Numbers:',numbers

for i in numbers:
	if largest_number is None:
		largest_number = i
	elif largest_number < i:
		largest_number = i
else:
	print 'The largest number is:',largest_number
