//   ______   _____   _        _
//  |  ____| |_   _| | |      | |
//  | |__      | |   | |      | |
//  |  __|     | |   | |      | |
//  | |       _| |_  | |____  | |____
//  |_|      |_____| |______| |______|

#include <iostream>;
#include <string>;

#include "worker.hpp";
#include "unit.hpp";

using namespace std;

//int Worker::m_num_head_workers;

void Worker::increaseHeadWorkerCount() {
	m_num_head_workers += 1;
	//std::cout << "increaseHeadWorkerCount called. New head worker number is: "
		//<< m_num_head_workers << std::endl;

}


Worker::Worker(std::string name, float cost_per_day, float base_return_per_day)
		:Unit{ name, cost_per_day, base_return_per_day } 
{
	//std::cout << "Worker Constructor Called.\n";
	this->m_experience = 0;
}

float Worker::getReturnPerDay() {
	//daily return = (base return) + (experience) * 2 + (number of head workers) * 3
	float baseReturn = Unit::getReturnPerDay();
	float dailyReturn = baseReturn + m_experience * 2 + m_num_head_workers * 3;

	m_experience++;


	if (m_experience == 10) {
		//checks if worker became head worker after this
		Worker::increaseHeadWorkerCount();
		//std::cout << "Experience of worker " << Unit::getName() << " is " 
			//<< m_experience << std::endl;
	}

	return dailyReturn;
}

int Worker::getExperience() const { return m_experience; }