#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "individual.h"

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos) {
        return "";
    }
    size_t last = str.find_last_not_of(" \t");
    
    return str.substr(first, last - first + 1);
}

std::vector<Individual*> loadIndividuals(const std::string& filename) {
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

        int id = std::stoi(trim(idStr));
        int age = std::stoi(trim(ageStr));
        int x = std::stoi(trim(xStr));
        int y = std::stoi(trim(yStr));
        Gender gender = (trim(genderStr) == "MALE") ? Gender::MALE : Gender::FEMALE;
        intro = trim(intro);

        std::vector<std::string> habits;
        std::istringstream habitStream(habitStr);
        std::string habit;
        while (std::getline(habitStream, habit, ',')) {
            habit = trim(habit);
            if (!habit.empty()) {
                habits.push_back(habit);
            }
        }
        individuals.push_back(new Individual(id, gender, age, intro, habits, std::make_pair(x, y)));
    }
    file.close();
    return individuals;
}