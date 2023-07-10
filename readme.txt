Q1

A:
	PART A: 
	We were instructed to implement the dining philosophers problem with strict ordering of resources without the use of semaphores for which I have sent pthreads in chunks of two where none of the 2 pthreads are of adjacent philosophers 
	pthreads are parallel sub-processes which enable us to give each of the philosopher to try to get a fork  
	each philosopher is a function which "eats" and returns once done.
	Pthreads also join back in chunk of two allowing inversion btw the chunks for each pthread
	ASSUMPTION TAKEN: eating operating of each philosopher is 1 instruction which is printf

	PART B: 
	In this problem we had to implement the dining philosophers problem using semaphores, Since now there are no chunks of 2 to send the philosopher pthreads i have sent all the philosophers and avoidied the deadlocks by usinginversion since it was instructed that the order doesn't matter in this part of the problem, In order to avoid the deadlocks I have used inversions of philosophers order of picking up forks ie: even numbered philosophers pick right side fork first while odd numbered philosophers pick up left side fork first , basically each adjacent philosopher picks up opposite side of the fork in order to avoid each of the philosopher picking up the right or left sided fork in 1 instant causing a deadlock 
	
B: 
	PART A:
	We had to again use strict ordering in this part but with an additional catch of the bowl , again i have used the logic of using chunks of size 2 of pthreads.
	The difference in this problem is that now we have 2 bowls as well ie: now other that eating we also need to do the process of taking a bowl which is printed explicitly in the program , so basically in other words we are have to access the mutix 2 at a time , which makes it very similar to the question from A and hence the code doesn't differ much in implementation and uses the same logic as used in the first program

	PART B: 
	In this part we have to have 2 bowls and 5 philosophers and we need to send them all at once and prevent deadlocks , we are providing access of 2 bowls. I have implemented this by using a nonbinary semaphore with S value of 2 which is called bowl, this basically allows 2 people to access the semaphore at once and block and third accessor. To avoid deadlocks I have used a similar method as previously and coded it such that odd person picks the opposite fork than the even person to avoid deadlocks. Other things are all the same as explained in the above program. 

NOTE: I have written an infinite while loop to show that there is no deadlock formation, we can remove it and see the results alterantely. 






















