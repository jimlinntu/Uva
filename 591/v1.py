number = 0
while True:
	N = int(input())
	number += 1
	if(N == 0):
		break
	sumarray = 0
	counter = 0
	#input array
	array = input().split()
	#print(array)
	array = [int(i) for i in array]
	#print(array)
	#averge height
	average_h = sum(array) / N
	#count min step
	for i in range(0,N):
		for j in range(0,N):
			if(i == j):
				continue
			if(array[i] <= average_h):
				continue
			else:
				if(array[j] < average_h):
					if(array[i] - average_h >= average_h - array[j]):
						counter += average_h - array[j]
						array[i] -= average_h - array[j]
						array[j] = average_h
					else:
						counter += array[i] - average_h
						array[j] += array[i] - average_h
						array[i] = average_h
	print("Set #"+ str(number) + "\nThe minimum number of moves is " + str((int)(counter)) + ".\n")
