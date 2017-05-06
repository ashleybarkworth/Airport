#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <time.h>

using namespace std;

#include "LQueue.h"

Queue landing_queue;
Queue takeoff_queue;

int num1;
int num2;

int num_landing_planes_queueing = 0;
int num_takeoff_planes_queueing = 0; 

int max_num_landing_planes_queueing = 0;
int max_num_takeoff_planes_queueing = 0;

int total_num_planes_landing = 0;
int total_num_planes_takeoff = 0;

int total_landing_queueing_time = 0;
int total_takeoff_queueing_time = 0;

int starting_flight_number = 1000;

int runway_time = 0;

int main(void)
{
	cout << "Enter: ";
	cout << "Time for a plane to land (in minutes): ";
	int landing_time;
	cin >> landing_time;
	cout << "Time for a plane to takeOff (in minutes): ";
	int takeoff_time;
	cin >> takeoff_time;
	cout << "Landing rate (planes per hour): ";
	int landing_rate;
	cin >> landing_rate;
	cout << "Takeoff rate (planes per hour): ";
	int takeoff_rate;
	cin >> takeoff_rate;
	cout << "How long to run the simulation (in minutes): ";
	int timeToRun;
	cin >> timeToRun;

	srand(time(0));

	for(int i = 1; i <= timeToRun; i++) {
		cout << "Time = " << i << "\n";
		num1 = rand() % landing_rate*2 + 1;
		num2 = rand() % takeoff_rate*2 + 1;

		if(num1 % 60 < landing_rate) {
			landing_queue.enqueue(++starting_flight_number);
			num_landing_planes_queueing++;
			if(num_landing_planes_queueing > max_num_landing_planes_queueing) {
				max_num_landing_planes_queueing = num_landing_planes_queueing;
			}
			cout << "Plane " << starting_flight_number << " wants to land; added to landing queue; " << num_landing_planes_queueing << " planes want to land\n";

		}

		if(num2 < takeoff_rate) {
			takeoff_queue.enqueue(++starting_flight_number);
			num_takeoff_planes_queueing++;
			if(num_takeoff_planes_queueing > max_num_takeoff_planes_queueing) {
				max_num_takeoff_planes_queueing = num_takeoff_planes_queueing;
			}
			cout << "Plane " << starting_flight_number << " wants to takeoff; added to takeoff queue; " << num_takeoff_planes_queueing << " planes want to take off\n";
		}

		if(runway_time == 0) {
			if(!landing_queue.empty()) {
				cout << "Landing: Plane " << landing_queue.front() << "\n";
				runway_time += landing_time;
				landing_queue.dequeue();
				num_landing_planes_queueing--;
                total_num_planes_landing++;
			} else if(!takeoff_queue.empty()) {
				cout << "Taking off: Plane " << takeoff_queue.front() << "\n";
				runway_time+=takeoff_time;
				takeoff_queue.dequeue();
				num_takeoff_planes_queueing--;
                total_num_planes_takeoff++;
				cout << "Takeoff complete; " << num_takeoff_planes_queueing << " in queue\n";
			}
		} 
        if(runway_time > 0) {
  			runway_time--;
        }
        total_landing_queueing_time += num_landing_planes_queueing;
        total_takeoff_queueing_time += num_takeoff_planes_queueing;
	}
	cout << "No new takeoffs or landings will be generated.\n";
	int j = timeToRun+1;
	while(!landing_queue.empty()) {
		cout << "Time: " << j << "\n";
		if(runway_time==0) {
			cout << "Landing: Plane " << landing_queue.front() << "\n";
			landing_queue.dequeue();
        	total_num_planes_landing++;
			num_landing_planes_queueing--;
			runway_time += landing_time;
		} 
		if(runway_time > 0) {
			runway_time--;
		}
        total_landing_queueing_time += num_landing_planes_queueing;
        total_takeoff_queueing_time += num_takeoff_planes_queueing;
		j++;
	}

	while(!takeoff_queue.empty()) {
		cout << "Time: " << j << "\n";
		if(runway_time==0) {
			cout << "Taking off: Plane " << takeoff_queue.front() << "\n";
			takeoff_queue.dequeue();
            total_num_planes_takeoff++;
			num_takeoff_planes_queueing--;
			runway_time += takeoff_time;
		}
		if(runway_time > 0) {
			runway_time--;
		}
        total_takeoff_queueing_time += num_takeoff_planes_queueing;
		j++;
	}

	cout << "End of program.\n";

	cout << "STATISTICS\n";
	cout << "Maximum number of planes in landing queue was: " << max_num_landing_planes_queueing << "\n";
	cout << "Average minutes spent waiting to land: " << (1.0)*total_landing_queueing_time/total_num_planes_landing << "\n";
	cout << "Maximum number of planes in takeoff queue was: " << max_num_takeoff_planes_queueing << "\n";
	cout << "Average minutes spent waiting to takeoff: " << (1.0)*total_takeoff_queueing_time/total_num_planes_takeoff << "\n";
} 
