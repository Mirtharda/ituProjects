//   ______   _____   _        _
//  |  ____| |_   _| | |      | |
//  | |__      | |   | |      | |
//  |  __|     | |   | |      | |
//  | |       _| |_  | |____  | |____
//  |_|      |_____| |______| |______|

#include <iostream>;

#include "unit.hpp";
#include "machine.hpp";

Machine::Machine(std::string name, float price, float cost_per_day, float base_return_per_day, float failure_probability, int repair_time, float repair_cost)
	:Unit(name, cost_per_day, base_return_per_day) {
	//std::cout << "Machine Constructor is called.\n";

	//based on Marketplace Data
	this->m_price = price;
	this->m_failure_probability = failure_probability;
	this->m_repair_time = repair_time;
	this->m_repair_cost = repair_cost;
	
	this->m_days_until_repair = 0;
}

float Machine::getReturnPerDay() {
	//check if the machine is currently broken. If so return 0
	float r = ((double)std::rand() / (RAND_MAX)+1);
	if (m_days_until_repair != 0) {
		m_days_until_repair -= 1;
		return 0;
	}
	else {
		if (r < m_failure_probability) {
			m_days_until_repair = m_repair_time;

			m_days_until_repair -= 1;
			return -m_repair_cost;
		} else {
			return Unit::getReturnPerDay();
		}
	}
	//machine cannot be broken when it is bought
	//if it is broken in a specific day, a repair_cost is spent
	//after that there are not any repair cost, 
	//but its return is 0, until it is repaired
}
float Machine::getPrice() const { return this->m_price; }