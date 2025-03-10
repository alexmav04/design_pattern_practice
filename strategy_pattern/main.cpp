#include "distance_based_strategy.h"
#include "habit_based_strategy.h"
#include "reverse_matching_strategy.h"
#include "matchmaking_system.h"
#include "individual.h"

#include <iostream>

int main() {
    std::vector<Individual*> individuals = MatchmakingSystem::loadIndividuals("./individuals.txt");
    if (individuals.empty()) {
        return 1;
    }
    
    DistanceBasedStrategy distanceStrategy;
    HabitBasedStrategy habitStrategy;
    ReverseMatchingStrategy reverseDistanceStrategy(&distanceStrategy);
    ReverseMatchingStrategy reverseHabitStrategy(&habitStrategy);

    MatchmakingSystem system(&distanceStrategy);

    // enter an index of an individual to match
    int index;
    std::cout << "Enter an index of an individual to match (0-19): ";
    std::cin >> index;
    Individual* user1 = individuals[index];

    // distance-based
    system.setStrategy(&distanceStrategy);
    Individual* match_distance = system.match(user1, individuals);
    std::cout << "Best match by distance: " << (match_distance ? match_distance->id() : -1) << std::endl;

    // reverse distance-based
    system.setStrategy(&reverseDistanceStrategy);
    Individual* match_distance_reverse = system.match(user1, individuals);
    std::cout << "Worst match by distance: " << (match_distance_reverse ? match_distance_reverse->id() : -1) << std::endl;

    // habit-based
    system.setStrategy(&habitStrategy);
    Individual* match_habit = system.match(user1, individuals);
    std::cout << "Best match by habits: " << (match_habit ? match_habit->id() : -1) << std::endl;

    // reverse habit-based
    system.setStrategy(&reverseHabitStrategy);
    Individual* match_habit_reverse = system.match(user1, individuals);
    std::cout << "Worst match by habits: " << (match_habit_reverse ? match_habit_reverse->id() : -1) << std::endl;

    for (Individual* i : individuals) {
        delete i;
    }

    return 0;
}