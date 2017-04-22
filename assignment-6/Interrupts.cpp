#include <iostream>
#include <string>

#include "include/seq_linear_list.hpp"
#include "MinPriorityQueue.hpp"

class Interrupt {
public:
	unsigned int dev_id;
	unsigned int burst_time; // in ms
	unsigned int priority; // lower is higher priority
	unsigned int time_left;

	Interrupt() {
		dev_id = 0;
		burst_time = 0;
		priority = 9; // max priority

		time_left = burst_time;
	}

	Interrupt(unsigned int did, unsigned int bt, unsigned int p) {
		dev_id = did;
		burst_time = bt;
		priority = p; // max priority

		time_left = burst_time;
	}

	bool operator<(const Interrupt& other) { return priority < other.priority; }
	bool operator>(const Interrupt& other) { return priority > other.priority; }
};

int main() {
	cs202::MinPriorityQueue<Interrupt> q;
	unsigned int current_time;

	std::string command;	
	while (std::cin >> command) {
		if (command == "interrupt") {
			unsigned int dev_id, burst_time, priority;
			std::cin >> dev_id >> burst_time >> priority; 
			if (priority > 9) {
				std::cerr << "Priority cannot be greater than 9 for an interrupt" << std::endl;
			} else {
				q.insert(Interrupt(dev_id, burst_time, priority));
			}
		} else if (command == "tick") {
			unsigned int time_to_tick;
			std::cin >> time_to_tick;

			while (time_to_tick > 0) {
				if (q.empty()) {
					current_time += time_to_tick;
					std::cout << current_time << " ms : CPU performed it's own operations for " << time_to_tick << " ms." << std::endl;
					time_to_tick = 0;
				} else {
					Interrupt& interrupt = q.minimum();
					// If we can execute the interrupt in the time available
					if (interrupt.time_left <= time_to_tick) {
						current_time += interrupt.time_left;
						time_to_tick -= interrupt.time_left;
						std::cout << current_time << " ms : CPU executed interrupt by device " << interrupt.dev_id << " for " << interrupt.time_left << " ms." << std::endl;
						std::cout << current_time << " ms : CPU completed executing interrupt by device " << interrupt.dev_id << std::endl;

						q.extract_min();
					} else {
						current_time += time_to_tick;
						interrupt.time_left -= time_to_tick;
						std::cout << current_time << " ms : CPU executed interrupt by device " << interrupt.dev_id << " for " << time_to_tick << " ms." << std::endl;
						time_to_tick = 0;
					}
				}
			}
		}
	}

	return 0;
}