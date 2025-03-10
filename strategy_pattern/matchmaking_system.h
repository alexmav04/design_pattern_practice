#ifndef MATCHMAKING_SYSTEM_H
#define MATCHMAKING_SYSTEM_H

#include "match_strategy.h"

class MatchmakingSystem
{
public:
    MatchmakingSystem(MatchStrategy* strategy) : strategy_(strategy) {}

    void setStrategy(MatchStrategy* strategy);

    Individual* match(Individual* self, std::vector<Individual*>& candidates);

    static std::vector<Individual*> loadIndividuals(const std::string& filename);

private:
    MatchStrategy* strategy_;
};

#endif // MATCHMAKING_SYSTEM_H