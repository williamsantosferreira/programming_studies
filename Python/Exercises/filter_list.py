#Create a function that takes a list of non-negative integers and strings and return a new list without the strings.

def filter_list(list):
	new_list = []
	for element in list:
		if type(element) is int:
			new_list.append(element)
	return new_list

list = [1, 2, "aasf", "1", "123", 123]

print(filter_list(list))
