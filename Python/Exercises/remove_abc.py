'''
Create a function that will remove the letters "a", "b" and "c" from the given string and return the modified version. If the given string does not contain "a", "b", or "c", return None.
'''
def remove_abc(string=''):
	old_string = string
	string = string.replace('a','')
	string = string.replace('b','')
	string = string.replace('c','')
	if(string == old_string):
		return False
	else:
		return string

string = "This might be a bit hard"
new_string = remove_abc(string)

if(new_string):
	print(new_string)
else:
	print('None')
