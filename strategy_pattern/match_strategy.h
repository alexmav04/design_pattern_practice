#ifndef MATCH_STRATEGY_H
#define MATCH_STRATEGY_H

#include <vector>
#include "individual.h"

class MatchStrategy
{
public:
    MatchStrategy() {}

    virtual Individual* match(Individual* self, std::vector<Individual*>& candidates) = 0;
};

#endif // MATCH_STRATEGY_H