#include "individual.h"
#include <iostream>

int Individual::id() const {
    return id_;
}

Gender Individual::gender() const {
    return gender_;
}

int Individual::age() const {
    return age_;
}

std::string Individual::intro() const {
    return intro_;
}

std::vector<std::string> Individual::habits() const {
    return habits_;
}

std::pair<int, int> Individual::coord() const {
    return coord_;
}

void Individual::printInfo() {
    std::cout << id_ << " | ";

    std::cout << ((gender_ == Gender::FEMALE) ? "FEMALE" : "MALE") << " | ";

    std::cout << age_ << " | " << intro_ << " | ";

    bool first = true;
    for (const auto& habit : habits_) {
        if (!first) {
            std::cout << ", ";
        }
        std::cout << habit;
        first = false;
    }
    std::cout << " | ";
    
    std::cout << "(" << coord_.first << "," << coord_.second << ")" << std::endl;
}
