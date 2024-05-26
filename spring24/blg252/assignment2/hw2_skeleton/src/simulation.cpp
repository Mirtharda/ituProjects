//   ______   _____   _        _
//  |  ____| |_   _| | |      | |
//  | |__      | |   | |      | |
//  |  __|     | |   | |      | |
//  | |       _| |_  | |____  | |____
//  |_|      |_____| |______| |______|

#include "factory.hpp"
#include "simulation.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void Simulation::printWelcomeMessage() const
{
    std::cout << "Welcome to the Car Factory!" << std::endl;
    std::cout << "You have " << m_total_days << " days to make as much money as possible" << std::endl;
    std::cout << "You can add workers, machines, and fast forward days" << std::endl;

    std::cout << "Available commands:" << std::endl;
    std::cout << "    wX: adds X workers" << std::endl;
    std::cout << "    mX: adds X machines" << std::endl;
    std::cout << "    pX: passes X days" << std::endl;
    std::cout << "    q: exit the game properly" << std::endl;
}

Simulation::Simulation(Factory& factory, int total_days, std::string workers_list_path, std::string machines_list_path) {
    this->m_factory = &factory; //?
    this->m_total_days = total_days;

    //for this->m_labor_market
    std::ifstream file(workers_list_path);
    if (!file.is_open()) {
        std::cerr << "ERROR: Failed to open file.\n";
    }

    std::string line_l;     //stands for labor line
    getline(file, line_l);
    while (getline(file, line_l)) {
        std::istringstream iss(line_l);
        std::string name;
        float daily_cost, daily_return;
        if (iss >> name >> daily_cost >> daily_return) {
            //initialize the m_labor_market list here
            m_labor_market.push_back(Worker(name, daily_cost, daily_return));
        }
        else {
            std::cerr << "ERROR: Failed to parse line: "
                << line_l << std::endl;
        }
    }
    file.close();

    //for this->m_machine_market
    std::ifstream file_m(machines_list_path);
    if (!file_m.is_open()) {
        std::cerr << "ERROR: Failed to open file.\n";
    }

    std::string line_m;     //stands for machine line
    getline(file_m, line_m);
    while (getline(file_m, line_m)) {
        std::istringstream iss(line_m);
        std::string name;
        float price, daily_cost, daily_return, fail_prob, repair_cost, repair_time;
        if (iss >> name >> price >> daily_cost >> daily_return >> fail_prob >> repair_cost >> repair_time) {
            m_machines_market.push_back(Machine(name, price, daily_cost, daily_return, fail_prob, repair_cost, repair_time));
        }
        else {
            std::cerr << "ERROR: Failed to parse line: " << line_m << std::endl;
        }
    }
    file_m.close();
}

Machine Simulation::buyRandomMachine() {
    int select = std::rand() % m_machines_market.size();
    Machine newmachine = m_machines_market[select];
    m_machines_market.erase(m_machines_market.begin() + select);

    //std::cout << newmachine.getName() << " is bought\n";
    return newmachine;
}

Worker Simulation::hireRandomWorker() {
    int select = std::rand() % m_labor_market.size();
    Worker newworker = m_labor_market[select];
    m_labor_market.erase(m_labor_market.begin() + select);

    //std::cout << newworker.getName() << " is hired\n";
    return newworker;
}



void Simulation::run() {
    //first we need to know what the user wants to do
    int current_day = 1;
    while (true) {
        std::string command;
        std::cout << "Enter command: ";
        std::cin >> command;

        if (command[0] == 'q') {
            std::cout << "Congrats! You have earned " << m_factory->getCapital() << " in " << m_total_days
                << " days\n";
            break;
        }
        else {
            if (command[0] == 'w' || command[0] == 'm' || command[0] == 'p') {
                // Extract the number of units to be hired/passed
                int count = 0;
                for (size_t i = 1; i < command.size(); ++i) {
                    if (isdigit(command[i])) {
                        count = count * 10 + (command[i] - '0');
                    }
                    else {
                        std::cerr << "ERROR: Invalid command.\n";
                        break;
                    }
                }
                if (command[0] == 'w') {
                    //hire workers value times 
                    for (int i = 0; i < count; ++i) {
                        m_factory->addUnit(Simulation::hireRandomWorker());
                    }
                }
                else if (command[0] == 'm') {
                    //hire machines value times
                    for (int i = 0; i < count; ++i) {
                        m_factory->addUnit(Simulation::buyRandomMachine());
                    }
                }
                else if (command[0] == 'p') {
                    for (int i = 0; i < count; ++i) {
                        std::cout << "--- Day: " << current_day << std::endl;
                        m_factory->passOneDay();
                        current_day += 1;

                        std::cout << "[C: " << m_factory->getCapital() << ", W: " << m_factory->getWorkerCount()
                            << ", M: " << m_factory->getMachineCount() << ", HW: " << m_factory->getHeadWorkerCount()
                            << "]\n";
                        if (m_factory->isBankrupt() == true) {
                            std::cout << "You went bankrupt!\n";
                            break;
                        }
                    }
                }
            }
            else {
                std::cerr << "ERROR: Invalid command.\n";
            }
        }
    }
}