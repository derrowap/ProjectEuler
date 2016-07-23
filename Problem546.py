"""
Author: Austin Derrow-Pinion
Purpose: Solve Problem 546 on Project Euler
Language: Python


"""
import math

def main():
	# print(floorRevenge(10, 5))
	# print(floorRevenge(100, 7))
	# print floorRevengeOptimized(100, 7)
	# print floorRevengeOptimized1(1000, 2)
	# print floorRevengeOptimized(1000, 2)
	# print(floorRevenge(1000, 2))
	# print floorRevengeOptimized3(10, 5)
	# print floorRevengeOptimized3(100, 7)
	# print floorRevengeOptimized3(1000, 2)
	print floorRevengeOptimized3(100000000000000, 10)
	# answer = 0
	# for k in range(2, 11):
	# 	answer += floorRevengeOptimized3(pow(10, 14), k)
	# 	print k, answer
	# print(answer % (pow(10, 9) + 7))

def floorRevenge(n, k):
	if n == 0:
		print "n =", n, "output is 1"
		return 1
	output = 0
	for i in range(0, n + 1):
		if n == 1000:
			print "recursive step i =", i
		output += floorRevenge(i / k, k)
	print "n =", n, "output is", output
	return output

"""
Gives correct answer, but ignores base cases and uses less optimized, 2nd solution.
"""
def floorRevengeOptimized1(n, k):
	output = k
	i = k
	previous = 1
	while i != n + 1:
		if n - i >= k - 1:
			previous += floorRevengeOptimized2(i / (k * k), k)
			output += previous * k
			i += k
		else:
			previous += floorRevengeOptimized2(i / (k * k), k)
			output += previous * (n - i + 1)
			break
	return output

"""
Gives correct answer, but uses a large array to keep track of values.
For the actual answer, it ran out of memory because the array would have to be too large.
"""
def floorRevengeOptimized3(n, k):
	answers = range(1, k + 1)
	i = k
	addBy = 1
	output = k
	while i != n + 1:
		addBy += answers[i / (k * k)]
		if n - i >= k:
			if i <= n / (k * k):
				total = output
				for j in range(k):
					total += addBy
					answers.append(total)
			output += k * addBy
			i += k
		else:
			output += addBy * (n - i + 1)
			break
	print answers, len(answers)
	return output


""" 
Gives correct answer, but still too slow.
This does the same as the original equation, but instead of increasing
the index by 1 each time, it increases by k since the output is the same for
every group of k.

"""
def floorRevengeOptimized2(n, k):
	if n == 0:
		return 1
	output = 0
	index = 0
	while n + 1 != index:
		if n - index >= k - 1:
			# print "index =", index, "output =", output, "true"
			output += k * floorRevengeOptimized2(index / k, k)
			index += k
		else:
			# print "index =", index, "output =", output, "false"
			output += floorRevengeOptimized2(index / k, k)
			index += 1
	# print "index =", index, "output =", output, "end n =", n
	return output

if __name__ == '__main__':
	main()