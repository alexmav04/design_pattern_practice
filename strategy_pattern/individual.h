#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <string>
#include <vector>

enum class Gender
{
    MALE, FEMALE
};

class Individual
{
public:
    Individual(int id, Gender gender, int age, std::string intro, std::vector<std::string> habits, std::pair<int, int> coord)
        : id_(id), gender_(gender), age_(age), intro_(intro), habits_(habits), coord_(coord) {};

    int id() const;
    Gender gender() const;
    int age() const;
    std::string intro() const;
    std::vector<std::string> habits() const;
    std::pair<int, int> coord() const;
    
private:
    int id_;
    Gender gender_;
    int age_;
    std::string intro_;
    std::vector<std::string> habits_;
    std::pair<int, int> coord_;
};

#endif // INDIVIDUAL_H