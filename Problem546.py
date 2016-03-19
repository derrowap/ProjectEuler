"""
Author: Austin Derrow-Pinion
Purpose: Solve Problem 546 on Project Euler
Language: Python


"""
import math

def main():
	# print(floorRevenge(10, 5))
	# print(floorRevenge(100, 7))
	print(floorRevenge(1000, 2))
	answer = 0
	for k in range(2, 11):
		answer += floorRevenge(pow(10, 14), k)
	print(answer % (pow(10, 9) + 7))

def floorRevenge(n, k):
	if n == 0:
		return 1
	output = 0
	for i in range(0, n + 1):
		output += floorRevenge(int(math.floor(i / k)), k)
	return output
					
if __name__ == '__main__':
	main()