#include "matchmaking_system.h"
#include <fstream>
#include <sstream>
#include <iostream>

void MatchmakingSystem::setStrategy(MatchStrategy* strategy) {
    strategy_ = strategy;
}

Individual* MatchmakingSystem::match(Individual* self, std::vector<Individual*>& candidates) {
    return strategy_->match(self, candidates);
}

std::vector<Individual*> MatchmakingSystem::loadIndividuals(const std::string& filename) {
    std::vector<Individual*> individuals;
    std::ifstream file(filename);
    if (!file.is_open()) {
        return individuals;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string idStr, genderStr, ageStr, intro, habitStr, xStr, yStr;

        if (!std::getline(iss, idStr, '|') ||
            !std::getline(iss, genderStr, '|') ||
            !std::getline(iss, ageStr, '|') ||
            !std::getline(iss, intro, '|') ||
            !std::getline(iss, habitStr, '|') ||
            !std::getline(iss, xStr, '|') ||
            !std::getline(iss, yStr)) {
            continue;
        }

        int id = std::stoi(idStr);
        int age = std::stoi(ageStr);
        int x = std::stoi(xStr);
        int y = std::stoi(yStr);
        Gender gender = (genderStr == "MALE") ? Gender::MALE : Gender::FEMALE;

        std::vector<std::string> habits;
        std::istringstream habitStream(habitStr);
        std::string habit;
        while (std::getline(habitStream, habit, ',')) {
            if (!habit.empty()) {
                habits.push_back(habit);
            }
        }
        individuals.push_back(new Individual(id, gender, age, intro, habits, std::make_pair(x, y)));
    }
    // print all individuals info
    std::cout << "Individuals:" << std::endl;
    std::cout << "ID | Gender | Age | Location" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    for (Individual* i : individuals) {
        std::cout << i->id() << " | " << (i->gender() == Gender::MALE ? "MALE" : "FEMALE")
                  << " | " << i->age() << " | " << i->coord().first << ", " << i->coord().second << std::endl;
    }
    file.close();
    return individuals;
}
