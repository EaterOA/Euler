#!/usr/bin/python

import sys, math

def main():
	D = 1000
	d = 1
	maxX = 0
	maxD = 0
	while d <= D:
		dd = pow(d, 0.5)
		a0 = int(dd)
		if dd == a0:
			d = d + 1
			continue
		#Find continued fractions for sqrt(d)
		a = []
		num = -a0
		den = 1
		while True:
			newDen = d - num*num
			newDen = newDen / den
			newNum = -num
			aNext = int((dd+newNum)/newDen)
			a.append(aNext)
			newNum = newNum - aNext * newDen
			num = newNum
			den = newDen
			if den == 1: break	
		#Find convergents of d until x and y solves equation
		x = [0, 1, a0]
		y = [1, 0, 1]
		i = 0
		while x[2]*x[2] - d*y[2]*y[2] != 1:
			x[0] = x[1]
			x[1] = x[2]
			y[0] = y[1]
			y[1] = y[2]
			x[2] = a[i]*x[1] + x[0]
			y[2] = a[i]*y[1] + y[0]
			i = (i+1) % len(a)
		#print d, x[2]
		if x[2] > maxX:
			maxX = x[2]
			maxD = d
				d = d + 1
	print maxD, maxX

if __name__ == "__main__":
	main()

