#include "habit_based_strategy.h"
#include <algorithm>

Individual* HabitBasedStrategy::match(Individual* self, std::vector<Individual*>& candidates) {
    if (candidates.size() < 2) {
        return nullptr;
    }

    Individual* bestOne = nullptr;
    int maxHabitMatch = -1;

    for (Individual* candidate : candidates) {
        if (candidate == self) {
            continue;
        }

        int habitMatch = 0;
        for (const std::string& habit : candidate->habits()) {
            const std::vector<std::string>& selfHabits = self->habits();
            if (std::find(selfHabits.begin(), selfHabits.end(), habit) != selfHabits.end()) {
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