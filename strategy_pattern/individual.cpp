#include "individual.h"

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