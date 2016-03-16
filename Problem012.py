"""
Author: Austin Derrow-Pinion
Purpose: Solve Problem 12 on Project Euler
Language: Python

Finds the value of the first triangle number
to have over 500 divisors.

Triangle number: sum of all number less than or equal to itself.

Divisors found by multiplying the powers + 1 of all prime factor
divisors for a given number together.
"""

def main():
	print "First triangle number with 500 factors:", firstWithNumFactors(500)

""" Retursn the first triangle number with the specified number
	of factors """
def firstWithNumFactors(number):
	currentTriangle = 1
	i = number
	while(numOfFactors(currentTriangle) < number):
		currentTriangle = triangleNumber(i)
		i+=1
	return currentTriangle

""" Returns the nth, index, triange number such that it is 
	the sum of all number less than or equal to itself. """
def triangleNumber(index):
	output = 1
	for i in range (2, index + 1):
		output += i
	return output

""" Returns the integer square root of a number, n """
def isqrt(n):
    x = n
    y = (x + 1) // 2
    while y < x:
        x = y
        y = (x + n // x) // 2
    return x

""" Returns the number of factors a number has """
def numOfFactors(number):
	output = 1
	for i in range (2, isqrt(number)+1):
		power = 1
		while number % i == 0:
			number /= i
			power += 1
		output *= power
	if (number > 1):
		output *= 2
	return output
				
if __name__ == '__main__':
	main()