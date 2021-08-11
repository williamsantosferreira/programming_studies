try:
	word = input('Write a number:')
	number = str(word)
except:
	number = -1

if number == -1 :
	print("It's not a number")
else :
	print(number)		
