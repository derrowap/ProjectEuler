"""
Author: Austin Derrow-Pinion
Purpose: Solve Problem 9 on Project Euler
Language: Python

Finds a pythagorean triplet with a, b, and c summing to 1000
Pythagorean triplet is a set of three numbers, a < b < c,
for which a^2 + b^2 c^2
Prints out the product of a, b, and c for the solution.
"""

def main():
	pythagoreanTriplet(1000)

def pythagoreanTriplet(sum):
	""" Prints out product of a, b, and c that are a Pythagorean 
		triplet and add up to the specified sum. """
	for a in range(1, sum):
		for	b in range(a, sum - a):
			for c in range(b, sum - b - a + 1):
				if a + b + c == sum:
					if (a * a) + (b * b) ==  (c * c):
						print("a: ", a, " b: ", b, " c : ", c)
						print("Procuct of a, b, and c: ", a * b * c)
				
if __name__ == '__main__':
	main()