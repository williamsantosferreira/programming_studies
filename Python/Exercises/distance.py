import math

def get_distance(a,b):
	dx = b[0]-a[0]
	dy = b[1]-a[1]

	h = math.sqrt(dx**2 + dy**2)
	return round(h,3)

a = [10,-5]
b = [8,16]

print(get_distance(a,b))
