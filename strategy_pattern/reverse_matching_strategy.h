#ifndef REVERSE_MATCHING_STRATEGY_H
#define REVERSE_MATCHING_STRATEGY_H

#include "match_strategy.h"

class ReverseMatchingStrategy : public MatchStrategy
{
public:
    ReverseMatchingStrategy(MatchStrategy* strategy) : strategy_(strategy) {}

    Individual* match(Individual* self, std::vector<Individual*>& candidates) override;

private:
    MatchStrategy* strategy_;
};

#endif // REVERSE_MATCHING_STRATEGY_H