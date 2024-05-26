//   ______   _____   _        _
//  |  ____| |_   _| | |      | |
//  | |__      | |   | |      | |
//  |  __|     | |   | |      | |
//  | |       _| |_  | |____  | |____
//  |_|      |_____| |______| |______|

#include "worker.hpp"
#include "headworker.hpp"
#include "machine.hpp"
#include "factory.hpp";

#include <iostream>
#include <vector>

//capital means "sermaye"

Factory::Factory(float capital) {
	this->m_capital = capital;
	this->m_is_bankrupt = false;
}

void Factory::passOneDay() {
	//daily costs and returns for workers
	for (size_t i = 0; i < m_workers.size(); ) {
		this->m_capital = m_capital - m_workers[i].getCostPerDay();
		this->m_capital = m_capital + m_workers[i].getReturnPerDay();

		//to promote a worker to head worker
		if (m_workers[i].getExperience() == 10) {
			//std::cout << "The experience of " << m_workers[i].getName() << "is 10. So became a HeadWorker.";

			m_head_workers.push_back(HeadWorker(m_workers[i]));
			m_workers.erase(m_workers.begin() + i);
		}
		else { ++i; }
		//std::cout << "Experience: " << m_workers[i].getExperience() << std::endl;
	}

	//daily costs and returns for machines
	for (size_t i = 0; i < m_machines.size(); i++) {
		this->m_capital = m_capital - m_machines[i].getCostPerDay();
		this->m_capital = m_capital + m_machines[i].getReturnPerDay();
	}

	//daily costs and returns for headWorkers
	for (size_t i = 0; i < m_head_workers.size(); i++) {
		this->m_capital = m_capital - m_head_workers[i].getCostPerDay();
		this->m_capital = m_capital + m_head_workers[i].getReturnPerDay();
	}
	if (m_capital < 0) {
		m_is_bankrupt = true;
	}
}

void Factory::addUnit(const Worker& rhs_worker) { 
	m_workers.push_back(rhs_worker); 
	std::cout << rhs_worker.getName() << " is hired\n";
}
void Factory::addUnit(const Machine& rhs_machine) { 
	m_machines.push_back(rhs_machine);
	std::cout << rhs_machine.getName() << " is bought\n";
}

bool Factory::isBankrupt() const { return m_is_bankrupt; }
float Factory::getCapital() const { return m_capital; }

int Factory::getWorkerCount() const { return m_workers.size(); }
int Factory::getMachineCount() const { return m_machines.size(); }
int Factory::getHeadWorkerCount() const { return m_head_workers.size(); }