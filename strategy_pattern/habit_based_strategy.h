#ifndef HABIT_BASED_STRATEGY_H
#define HABIT_BASED_STRATEGY_H

#include "match_strategy.h"

class HabitBasedStrategy : public MatchStrategy
{
public:
    HabitBasedStrategy() {}

    Individual* match(Individual* self, std::vector<Individual*>& candidates) override;
};

#endif // HABIT_BASED_STRATEGY_H