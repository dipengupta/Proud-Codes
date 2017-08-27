'''

This is an elaborate program to implement Round Robin scheduling algorithm.
This was written in 3 hours, around midnight, and the logic used would be
quite hard to recreate later on. But this works. 100%.

Coded by Dipen.

'''

print("Round Robin Algorithm")

general_quantum_size = 4


def calcGanttsChart() : 
	'''

	This is a helper function for calcWaitingTime.
	It will make Gantt's chart as a list within a list.
	The sublist will contain the following (in order) :
	[process_number, arrival_time, burst_time, remaining_burst_time]

	'''

	gantts_chart=[]

	new_arrival_time = data[0][1]

	sum_of_burst_times = 0
	
	for x in range(n) :
		sum_of_burst_times = sum_of_burst_times + data[x][2]

	while (new_arrival_time < sum_of_burst_times) :

		for x in range(n) : 

			process = data[x][0]
			arrival = new_arrival_time

			remaining_burst_time = data[x][3]

			if remaining_burst_time is 0 :
				time_spent = 0
				continue

			if remaining_burst_time < general_quantum_size :
				time_spent = remaining_burst_time
				remaining_burst_time = 0 

			else :
				remaining_burst_time = data[x][3] - general_quantum_size
				time_spent = general_quantum_size

			data[x][3] = remaining_burst_time

			departure = arrival + time_spent
			new_arrival_time = departure


			gantt_input = [process, arrival, departure, remaining_burst_time]
			gantts_chart.append(gantt_input)


	return(gantts_chart)




def calcWaitingTime(gantts_chart) : 
	'''

	This makes use of calcGanttsChart()
	
	Input : Gantt's Chart (lists within a list)
	Returns : list containing waiting times for processes.

	'''

	waiting_time = []
	flag = []

	for x in range(n) :
		waiting_time.append(0)
		flag.append(0)

	for x in range(n) :
		waiting_time[x] = waiting_time[x] - data[x][1]


	for ele in gantts_chart :
		process_no = ele[0]
		add_no = ele[1]
		sub_no = ele[2]
		waiting_time[process_no] = waiting_time[process_no] + add_no - sub_no

	gantts_chart.reverse()

	for ele in gantts_chart :
		process_no = ele[0]

		if flag[process_no] is 0 : 
			waiting_time[process_no] = waiting_time[process_no] + ele[2]
			flag[process_no] = 1

	gantts_chart.reverse()

	return(waiting_time)



# Main Function : 

# [process_number, arrival_time, burst_time, remaining_burst_time]
data = {
	# 0 : [0,1,10,10],
	# 1 : [1,3,5,5],
	# 2 : [2,5,9,9],
	# 3 : [3,7,7,7],
	# 4 : [4,9,3,3]
}


n = int(input("Enter number of processes : "))

for x in range(n) : 
	a_t = int(input("Enter arrival time of process " + str(x) + " : "))
	b_t = int(input("Enter bust time of process " + str(x) + " : "))
	data[x] = [x, a_t, b_t, b_t]


g_c = calcGanttsChart()
waiting_time = calcWaitingTime(g_c)
turn_around_time=[]

for x in range(n) :
	foo = waiting_time[x] + data[x][2]
	turn_around_time.append(foo)

average_waiting_time = sum(waiting_time)/float(len(waiting_time))
average_turn_around_time = sum(turn_around_time)/float(len(turn_around_time))

print("Average waiting time is : " + str(average_waiting_time))
print("Average turn around time is : " + str(average_turn_around_time))
print("Gantt's Chart : ")
print(g_c)




'''

OUTPUT : 

Guptas-MacBook-Pro:Downloads Dipen$ python3 exp5.py
Round Robin Algorithm
Enter number of processes : 5
Enter arrival time of process 0 : 1
Enter bust time of process 0 : 10
Enter arrival time of process 1 : 3
Enter bust time of process 1 : 5
Enter arrival time of process 2 : 5
Enter bust time of process 2 : 9
Enter arrival time of process 3 : 7
Enter bust time of process 3 : 7
Enter arrival time of process 4 : 9
Enter bust time of process 4 : 3
Average waiting time is : 17.4
Average turn around time is : 24.2
Gantt's Chart : 
[[0, 1, 5, 6], [1, 5, 9, 1], [2, 9, 13, 5], [3, 13, 17, 3], 
[4, 17, 20, 0], [0, 20, 24, 2], [1, 24, 25, 0], [2, 25, 29, 1], 
[3, 29, 32, 0], [0, 32, 34, 0], [2, 34, 35, 0]]
Guptas-MacBook-Pro:Downloads Dipen$ 



'''





