#ifndef DISTANCE_BASED_STRATEGY_H
#define DISTANCE_BASED_STRATEGY_H

#include "match_strategy.h"

class DistanceBasedStrategy : public MatchStrategy
{
public:
    DistanceBasedStrategy() {}

    Individual* match(Individual* self, std::vector<Individual*>& candidates) override;
};

#endif // DISTANCE_BASED_STRATEGY_H