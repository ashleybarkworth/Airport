Ashley Barkworth
11031168
r1a1b

LQueue.h: a header file containing all the member functions and variables of the class LQueue
LQueue.C: an implementation of all the member functions declared in LQueue.h
LQueue_driver.C: runs tests for the LQueue methods 
runway.C: A class with only one method, int main(), which runs the airport simulation as described in Part 2 of the assignment
Makefile: makefile for all files for the assignment

ASSUMPTIONS:

1. An error message should be printed in the move_to_front() method in LQueue.C in the case where
the queue is empty (however, the program should not terminate execution)
2. The move_to_front() method should do nothing if move_to_front() is called with a parameter that is not in the queue
3. The merge_two_queues() method will only be called on queues whose elements are listed in the correct order
4. The two random numbers generated in Part 2 are selected from an arbitrary range of values
5. The airport simulation must run until every plane in the queues have either landed or taken off, and the time to run
that the user specifies is only how long new landings and takeoffs should be generated

INSTRUCTION/FEATURES:
Part 1 requires no user input.
Part 2 has four additional features:
  1. A random number between 1 and 20 is generated each time a plane takes off or lands. If the number is greater than 17, then an additional 2 minutes is required for a plane to finish landing/taking off. 
  2. A few planes are designated VIP planes for landing and for taking off. If the current plane being enqueued is a designated VIP plane, then the VIP plane is moved to the front of the queue.
  3. The user is prompted as to how many runways they want to use. The user may enter any number greater than 1. At the end of each minute, the program will go through each runway and check if one is free for use. The plane landing/taking off will use the first vacant runway. 
  4. A random number between 0 and 3 times the # of runways will be generated. For a maximum of three times, if the number is less than the number of runways, another airport needs our airport to land its planes. The user is prompted for the number of airplanes it wants to take from the other airport, and the planes are added to our landing queue.

OUTPUT FOR TESTS:

PART 1
Queue created.  Empty? true
How many elements to add to the queue? 4
Contents of queue q1 (via  print):
100  200  300  400  

Contents of queue q2 after q2 = q1 (via  print):
100  200  300  400  

Queue q2 empty? false
Front value in q2: 100
Remove front -- Queue contents: 200  300  400  
Remove front -- Queue contents: 300  400  
Remove front -- Queue contents: 400  
Remove front -- Queue contents: 
Queue q2 empty? true
Front value in q2?
0
Creating new queue q with elements 1,2,3,4,5
Testing move_to_front() with front element
Contents of q now (should be the same):
1  2  3  4  5  

Testing move_to_front() on a middle value - in this case 3
Contents of q now (should be 3 1 2 4 5):
3  1  2  4  5  

Testing move_to_front() with end element
Contents of q now (should be 5 3 1 2 4):
5  3  1  2  4  

Testing move_to_front() with an element not in the list (should do nothing)
Contents of q now (should be 5 3 1 2 4):
5  3  1  2  4  

Creating new queue qu with no elements
Testing move_to_front() with the empty queue (should print warning statement)
*** Queue is empty -- can't move a value to the front ***

Creating new queue queue1 with elements 1,3,5
Creating new queue queue2 with elements 2,4,6
Testing merge_two_queues() on queue1 and queue2
Contents of queue queue1 (via  print)(should contain every element in queue1 and queue2):
1  2  3  4  5  6  

Contents of queue queue2 (via print)(should be empty):


Testing merge_two_queues() on non-empty queue and empty queue (using queue1 and queue2, respectively):
Contents of queue1 (should be the same as before)
1  2  3  4  5  6  

Contents of queue2 (should be the same as before)


Testing merge_two_queues() on empty queue and non-empty queue (using queue2 and queue1, respectively):
Contents of queue1 (should be now empty)


Contents of queue2 (should now contain every element)
1  2  3  4  5  6   

PART 2

Output for small time interval:

Enter: Time for a plane to land (in minutes): 2
Time for a plane to takeOff (in minutes): 2
Landing rate (planes per hour): 3
Takeoff rate (planes per hour): 3
Number of runways the airport has: 1
How long to run the simulation (in minutes): 10
Time = 1
Disaster strikes at a nearby airport. They need us to land some of their planes. How many do you want to take? 2
Time = 2
Plane 1001 wants to land; added to landing queue; 3 planes want to land
Landing: Plane 2000 on Runway 1
Disaster strikes at a nearby airport. They need us to land some of their planes. How many do you want to take? 1
Time = 3
Plane 1002 wants to land; added to landing queue; 4 planes want to land
Every runway busy, no new takeoffs or landings at this time.
Disaster strikes at a nearby airport. They need us to land some of their planes. How many do you want to take? 2
Time = 4
Plane 1003 wants to takeoff; added to takeoff queue; 1 planes want to take off
Every runway busy, no new takeoffs or landings at this time.
Time = 5
Every runway busy, no new takeoffs or landings at this time.
Time = 6
Landing: Plane 2001 on Runway 1
Time = 7
Plane 1004 wants to land; added to landing queue; 6 planes want to land
Plane 1005 wants to takeoff; added to takeoff queue; 2 planes want to take off
VIP Plane wants to take off, moved to front of takeoff queue
Every runway busy, no new takeoffs or landings at this time.
Time = 8
Landing: Plane 1000 on Runway 1
Time = 9
Plane 1006 wants to takeoff; added to takeoff queue; 3 planes want to take off
Every runway busy, no new takeoffs or landings at this time.
Time = 10
Every runway busy, no new takeoffs or landings at this time.
No new takeoffs or landings will be generated.
Time: 11
Time: 12
Landing: Plane 2002 on Runway 1
Time: 13
Time: 14
Landing: Plane 1001 on Runway 1
Time: 15
Time: 16
Landing: Plane 2003 on Runway 1
Time: 17
Time: 18
Landing: Plane 2004 on Runway 1
Time: 19
Time: 20
Landing: Plane 1003 on Runway 1
Time: 21
Time: 22
Taking off: Plane 1002 on Runway 1
Time: 23
Time: 24
Taking off: Plane 1004 on Runway 1
Time: 25
Time: 26
Taking off: Plane 1005 on Runway 1
End of program.
STATISTICS
Maximum number of planes in landing queue was: 6
Average minutes spent waiting to land: 8.625
Maximum number of planes in takeoff queue was: 3
Average minutes spent waiting to takeoff: 17.3333

Output for large time interval:

Enter: Time for a plane to land (in minutes): 3
Time for a plane to takeOff (in minutes): 3
Landing rate (planes per hour): 10
Takeoff rate (planes per hour): 10
Number of runways the airport has: 4
How long to run the simulation (in minutes): 100
Time = 1
Disaster strikes at a nearby airport. They need us to land some of their planes. How many do you want to take? 3
Time = 2
Landing: Plane 2000 on Runway 1
Disaster strikes at a nearby airport. They need us to land some of their planes. How many do you want to take? 4
Time = 3
Plane 1001 wants to land; added to landing queue; 7 planes want to land
Plane 1002 wants to takeoff; added to takeoff queue; 1 planes want to take off
Every runway busy, no new takeoffs or landings at this time.
Landing: Plane 2001 on Runway 2
Time = 4
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Landing: Plane 2002 on Runway 3
Disaster strikes at a nearby airport. They need us to land some of their planes. How many do you want to take? 3
Time = 5
Plane 1003 wants to takeoff; added to takeoff queue; 2 planes want to take off
Landing: Plane 2003 on Runway 1
Time = 6
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Landing: Plane 2004 on Runway 4
Time = 7
Plane 1004 wants to takeoff; added to takeoff queue; 3 planes want to take off
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Landing: Plane 2005 on Runway 3
Time = 8
Landing: Plane 2006 on Runway 1
Time = 9
Every runway busy, no new takeoffs or landings at this time.
Landing: Plane 1000 on Runway 2
Time = 10
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Landing: Plane 2007 on Runway 3
Time = 11
Landing: Plane 2008 on Runway 1
Time = 12
Every runway busy, no new takeoffs or landings at this time.
Landing: Plane 2009 on Runway 2
Time = 13
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Taking off: Plane 1001 on Runway 4
Takeoff complete; 2 in queue
Time = 14
Plane 1005 wants to land; added to landing queue; 1 planes want to land
Landing: Plane 1004 on Runway 1
Time = 15
Plane 1006 wants to land; added to landing queue; 1 planes want to land
Every runway busy, no new takeoffs or landings at this time.
Landing: Plane 1005 on Runway 2
Time = 16
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Taking off: Plane 1002 on Runway 3
Takeoff complete; 1 in queue
Time = 17
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Taking off: Plane 1003 on Runway 4
Takeoff complete; 0 in queue
Time = 18
Every runway busy, no new takeoffs or landings at this time.
Time = 19
Plane 1007 wants to takeoff; added to takeoff queue; 1 planes want to take off
Taking off: Plane 1006 on Runway 1
Takeoff complete; 0 in queue
Time = 20
Every runway busy, no new takeoffs or landings at this time.
Time = 21
Plane 1008 wants to takeoff; added to takeoff queue; 1 planes want to take off
Every runway busy, no new takeoffs or landings at this time.
Taking off: Plane 1007 on Runway 2
Takeoff complete; 0 in queue
Time = 22
Plane 1009 wants to takeoff; added to takeoff queue; 1 planes want to take off
Taking off: Plane 1008 on Runway 1
Takeoff complete; 0 in queue
Time = 23
Plane 1010 wants to takeoff; added to takeoff queue; 1 planes want to take off
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Taking off: Plane 1009 on Runway 3
Takeoff complete; 0 in queue
Time = 24
Every runway busy, no new takeoffs or landings at this time.
Time = 25
Time = 26
Time = 27
Time = 28
Plane 1011 wants to takeoff; added to takeoff queue; 1 planes want to take off
Taking off: Plane 1010 on Runway 1
Takeoff complete; 0 in queue
Time = 29
Plane 1012 wants to takeoff; added to takeoff queue; 1 planes want to take off
Every runway busy, no new takeoffs or landings at this time.
Taking off: Plane 1011 on Runway 2
Takeoff complete; 0 in queue
Time = 30
Plane 1013 wants to land; added to landing queue; 1 planes want to land
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Landing: Plane 1012 on Runway 3
Time = 31
Plane 1014 wants to land; added to landing queue; 1 planes want to land
Landing: Plane 1013 on Runway 1
Time = 32
Every runway busy, no new takeoffs or landings at this time.
Time = 33
Every runway busy, no new takeoffs or landings at this time.
Time = 34
Plane 1015 wants to takeoff; added to takeoff queue; 1 planes want to take off
Taking off: Plane 1014 on Runway 1
Takeoff complete; 0 in queue
Time = 35
Plane 1016 wants to takeoff; added to takeoff queue; 1 planes want to take off
Every runway busy, no new takeoffs or landings at this time.
Taking off: Plane 1015 on Runway 2
Takeoff complete; 0 in queue
Time = 36
Plane 1017 wants to land; added to landing queue; 1 planes want to land
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Landing: Plane 1016 on Runway 3
Time = 37
Time = 38
Plane 1018 wants to takeoff; added to takeoff queue; 1 planes want to take off
Taking off: Plane 1017 on Runway 1
Takeoff complete; 0 in queue
Time = 39
Every runway busy, no new takeoffs or landings at this time.
Time = 40
Every runway busy, no new takeoffs or landings at this time.
Time = 41
Time = 42
Time = 43
Time = 44
Plane 1019 wants to land; added to landing queue; 1 planes want to land
Landing: Plane 1018 on Runway 1
Time = 45
Plane 1020 wants to land; added to landing queue; 1 planes want to land
VIP Plane wants to land, moved to front of landing queue
Every runway busy, no new takeoffs or landings at this time.
Landing: Plane 1019 on Runway 2
Time = 46
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Time = 47
Plane 1021 wants to takeoff; added to takeoff queue; 1 planes want to take off
Taking off: Plane 1020 on Runway 1
Takeoff complete; 0 in queue
Time = 48
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Time = 49
Plane 1022 wants to takeoff; added to takeoff queue; 1 planes want to take off
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Taking off: Plane 1021 on Runway 3
Takeoff complete; 0 in queue
Time = 50
Time = 51
Time = 52
Time = 53
Plane 1023 wants to land; added to landing queue; 1 planes want to land
Landing: Plane 1022 on Runway 1
Time = 54
Every runway busy, no new takeoffs or landings at this time.
Time = 55
Every runway busy, no new takeoffs or landings at this time.
Time = 56
Time = 57
Time = 58
Plane 1024 wants to land; added to landing queue; 1 planes want to land
Landing: Plane 1023 on Runway 1
Time = 59
Plane 1025 wants to land; added to landing queue; 1 planes want to land
Every runway busy, no new takeoffs or landings at this time.
Landing: Plane 1024 on Runway 2
Time = 60
Plane 1026 wants to takeoff; added to takeoff queue; 1 planes want to take off
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Taking off: Plane 1025 on Runway 3
Takeoff complete; 0 in queue
Time = 61
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Time = 62
Every runway busy, no new takeoffs or landings at this time.
Time = 63
Plane 1027 wants to takeoff; added to takeoff queue; 1 planes want to take off
Taking off: Plane 1026 on Runway 1
Takeoff complete; 0 in queue
Time = 64
Every runway busy, no new takeoffs or landings at this time.
Time = 65
Every runway busy, no new takeoffs or landings at this time.
Time = 66
Plane 1028 wants to land; added to landing queue; 1 planes want to land
Landing: Plane 1027 on Runway 1
Time = 67
Plane 1029 wants to land; added to landing queue; 1 planes want to land
Every runway busy, no new takeoffs or landings at this time.
Landing: Plane 1028 on Runway 2
Time = 68
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Time = 69
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Time = 70
Plane 1030 wants to land; added to landing queue; 1 planes want to land
Every runway busy, no new takeoffs or landings at this time.
Landing: Plane 1029 on Runway 2
Time = 71
Time = 72
Plane 1031 wants to land; added to landing queue; 1 planes want to land
Landing: Plane 1030 on Runway 1
Time = 73
Plane 1032 wants to takeoff; added to takeoff queue; 1 planes want to take off
Every runway busy, no new takeoffs or landings at this time.
Taking off: Plane 1031 on Runway 2
Takeoff complete; 0 in queue
Time = 74
Plane 1033 wants to land; added to landing queue; 1 planes want to land
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Landing: Plane 1032 on Runway 3
Time = 75
Time = 76
Plane 1034 wants to land; added to landing queue; 1 planes want to land
Landing: Plane 1033 on Runway 1
Time = 77
Every runway busy, no new takeoffs or landings at this time.
Time = 78
Plane 1035 wants to land; added to landing queue; 1 planes want to land
Every runway busy, no new takeoffs or landings at this time.
Landing: Plane 1034 on Runway 2
Time = 79
Time = 80
Plane 1036 wants to land; added to landing queue; 1 planes want to land
Landing: Plane 1035 on Runway 1
Time = 81
Plane 1037 wants to land; added to landing queue; 1 planes want to land
Every runway busy, no new takeoffs or landings at this time.
Landing: Plane 1036 on Runway 2
Time = 82
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Time = 83
Plane 1038 wants to land; added to landing queue; 1 planes want to land
Landing: Plane 1037 on Runway 1
Time = 84
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Time = 85
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Time = 86
Plane 1039 wants to land; added to landing queue; 1 planes want to land
Landing: Plane 1038 on Runway 1
Time = 87
Plane 1040 wants to land; added to landing queue; 1 planes want to land
Every runway busy, no new takeoffs or landings at this time.
Landing: Plane 1039 on Runway 2
Time = 88
Plane 1041 wants to land; added to landing queue; 1 planes want to land
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Landing: Plane 1040 on Runway 3
Time = 89
Time = 90
Time = 91
Time = 92
Plane 1042 wants to land; added to landing queue; 1 planes want to land
Plane 1043 wants to takeoff; added to takeoff queue; 1 planes want to take off
Landing: Plane 1041 on Runway 1
Time = 93
Plane 1044 wants to land; added to landing queue; 1 planes want to land
Every runway busy, no new takeoffs or landings at this time.
Landing: Plane 1043 on Runway 2
Time = 94
Plane 1045 wants to land; added to landing queue; 1 planes want to land
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Landing: Plane 1044 on Runway 3
Time = 95
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Every runway busy, no new takeoffs or landings at this time.
Taking off: Plane 1042 on Runway 4
Takeoff complete; 0 in queue
Time = 96
Every runway busy, no new takeoffs or landings at this time.
Time = 97
Time = 98
Time = 99
Plane 1046 wants to land; added to landing queue; 1 planes want to land
Landing: Plane 1045 on Runway 1
Time = 100
Every runway busy, no new takeoffs or landings at this time.
No new takeoffs or landings will be generated.
End of program.
STATISTICS
Maximum number of planes in landing queue was: 7
Average minutes spent waiting to land: 1.07895
Maximum number of planes in takeoff queue was: 3
Average minutes spent waiting to takeoff: 1.88889


