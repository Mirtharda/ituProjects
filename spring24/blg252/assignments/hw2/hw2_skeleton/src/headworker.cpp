//   ______   _____   _        _
//  |  ____| |_   _| | |      | |
//  | |__      | |   | |      | |
//  |  __|     | |   | |      | |
//  | |       _| |_  | |____  | |____
//  |_|      |_____| |______| |______|

#include <iostream>;
#include <string>;

#include "worker.hpp";
#include "headworker.hpp";


//this is grandchild of unit


//promotion will be done by factory
HeadWorker::HeadWorker(Worker& worker)
	:Worker{worker.getName(), worker.getCostPerDay(), worker.getReturnPerDay()} {
	//std::cout << "HeadWorker constructor called.\n";
	std::cout << worker.getName() << " promoted as Head Worker!\n";
}

float HeadWorker::getReturnPerDay() {
	//daily return = (base return) + (experience) * 5
	float baseReturn = Unit::getReturnPerDay();
	float experience = Worker::getExperience();
	float dailyReturn = baseReturn + experience * 5;
	
	//std::cout << "base return: " << baseReturn << std::endl;
	//std::cout << "experience: " << experience << std::endl;
	//std::cout << "daily return: " << dailyReturn << std::endl;

	return dailyReturn;
}