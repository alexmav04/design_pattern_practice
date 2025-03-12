#include "distance_based_strategy.h"
#include "habit_based_strategy.h"
#include "reverse_matching_strategy.h"
#include "match_strategy.h"
#include "matchmaking_system.h"
#include "individual.h"
#include "helpers.h"

int main() {
    std::vector<Individual*> individuals = loadIndividuals("./individuals.txt");
    if (individuals.empty()) {
        return 1;
    }
    
    DistanceBasedStrategy distanceStrategy;
    HabitBasedStrategy habitStrategy;
    ReverseMatchingStrategy reverseDistanceStrategy(&distanceStrategy);
    ReverseMatchingStrategy reverseHabitStrategy(&habitStrategy);

    MatchmakingSystem system;
    system.addStrategy("distance", &distanceStrategy);
    system.addStrategy("habit", &habitStrategy);
    system.addStrategy("reverse_distance", &reverseDistanceStrategy);
    system.addStrategy("reverse_habit", &reverseHabitStrategy);

    // enter an index of an individual to match
    int index;
    std::cout << "Enter an index of an individual to match (1-20): ";
    std::cin >> index;
    Individual* user1 = individuals[index-1];
    user1->printInfo();
    std::cout << "=================================================" << std::endl;

    Individual* match = nullptr;

    // distance-based
    match = system.match("distance", user1, individuals);
    std::cout << "Best match by distance: " << (match ? match->id() : -1) << std::endl;
    match->printInfo();
    std::cout << "----" << std::endl;

    // reverse distance-based
    match = system.match("reverse_distance", user1, individuals);
    std::cout << "Worst match by distance: " << (match ? match->id() : -1) << std::endl;
    match->printInfo();
    std::cout << "----" << std::endl;

    // habit-based
    match = system.match("habit", user1, individuals);
    std::cout << "Best match by habits: " << (match ? match->id() : -1) << std::endl;
    match->printInfo();
    std::cout << "----" << std::endl;

    // reverse habit-based
    match = system.match("reverse_habit", user1, individuals);
    std::cout << "Worst match by habits: " << (match ? match->id() : -1) << std::endl;
    match->printInfo();
    std::cout << "----" << std::endl;

    for (Individual* i : individuals) {
        delete i;
    }

    return 0;
}