#include "habit_based_strategy.h"
#include <algorithm>

Individual* HabitBasedStrategy::match(Individual* self, std::vector<Individual*>& candidates) {
    Individual* bestOne = nullptr;
    int maxHabitMatch = -1;

    for (Individual* candidate : candidates) {
        if (candidate == self) {
            continue;
        }

        int habitMatch = 0;
        for (const std::string& habit : candidate->habits()) {
            if (std::find(self->habits().begin(), self->habits().end(), habit) != self->habits().end()) {
                habitMatch++;
            }
        }

        if (habitMatch > maxHabitMatch || (habitMatch == maxHabitMatch && (!bestOne || candidate->id() < bestOne->id()))) {
            maxHabitMatch = habitMatch;
            bestOne = candidate;
        }
    }
    return bestOne;
}