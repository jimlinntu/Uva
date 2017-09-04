import fileinput
import sys
DP = {1:1}
def algorithm(n):
	counter = DP.get(n)
	if counter != None:
		return counter
	oldn = n
	counter = 0
	while True:
		counter += 1
		if n == 1:
			break
		else:
			if n % 2 == 1:
				n = 3 * n + 1
			else:
				n = n / 2
	DP[oldn] = counter
	return counter
def main():
	for line in sys.stdin:
		maxvalue = -1
		tmp1 = int((line.split())[0])
		tmp2 = int((line.split())[1])
		left = min(tmp1, tmp2)
		right = max(tmp1, tmp2)
		for i in range(left, right+1):
			tmp = algorithm(i)
			if tmp > maxvalue:
				maxvalue = tmp
		print("%d %d %d" %(tmp1,tmp2 ,maxvalue))
if __name__ == "__main__":
	main()

#print(DP)

"""
try:
	while True:
		line = input()
		maxvalue = -1
		left = int(line.split()[0])
		right = int(line.split()[1])
		for i in range(left, right+1):
			tmp = algorithm(i)
			if tmp > maxvalue:
				maxvalue = tmp
		print("%d %d %d" % (left,right ,maxvalue))
except EOFError:
	pass
"""
