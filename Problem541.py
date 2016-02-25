"""
Author: Austin Derrow-Pinion
Purpose: Solve Problem 541 on Project Euler
Language: Python


"""
import math

def main():
	print(gcd(10, 12))

def M():
	print()

def harmonicDenominator(n):
	output = 0
	for k in range(1, n):
		output += k
	return output


def simplifyHarmonicDenominator(n):
	print()

def gcd(a, b):
	while a != b:
		if a > b:
			a -= b
		else:
			b -= a
	return a

def sieve(a, b):
	""" Implementation of the Sieve of Eratosthenes """
	primes = [False]*a
	for i in range(2, int(math.sqrt(len(primes)))):
		if primes[i] == False:
			for j in range(i*i, a, i):
				primes[j] = True
	for i in range(a-1, 2, -1):
		if (primes[i] == False) & (a % i == 0) & (b % i == 0):
			return i
	return 1





	
				
if __name__ == '__main__':
	main()