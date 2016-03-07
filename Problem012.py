"""
Author: Austin Derrow-Pinion
Purpose: Solve Problem 12 on Project Euler
Language: Python


"""

def main():
	# print(firstWithNumFactors(500))
	# triangleNumber(5)
	numOfFactors(6)

def firstWithNumFactors(number):
	currentTriangle = 1
	i = 1
	while(numOfFactors(currentTriangle) < number):
		currentTriangle = triangleNumber(i)
		i+=1
	return currentTriangle

def triangleNumber(index):
	output = 1
	for i in range (2, index + 1):
		output += i
	return output

def numOfFactors(number):
	output = 1
	return output
				
if __name__ == '__main__':
	main()