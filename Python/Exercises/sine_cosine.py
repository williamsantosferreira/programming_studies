#Create three functions that will do three things:
#
#    Multiply one number by the sine of another number.
#    Multiply one number by the COSINE of another number.
#    Multiply one number by the tangent of another number.
#
#In each function, you will be given 2 numbers: x and y. Another important thing to note, the numbers will be in degrees, not radians. That is extremely important. Remember to round the result to 2 decimal places, as well.

from math import*

def sine(x,y):
	result = x*sin(radians(y))
	result = round(result,2)
	return result

def cosine(x,y):
	result = x*cos(radians(y))
	result = round(result,2)
	return result

def tangent(x,y):
	result = x*tan(radians(y))
	result = round(result,2)
	return resut

print(sine(3,2))
