#ifndef MATCHMAKING_SYSTEM_H
#define MATCHMAKING_SYSTEM_H

#include "match_strategy.h"
#include <map>

class MatchmakingSystem
{
public:
    MatchmakingSystem() { };

    Individual* match(const std::string strategy, Individual* self, std::vector<Individual*>& candidates);

    void addStrategy(const std::string& name, MatchStrategy* strategy);

private:
    MatchStrategy* strategy_;

    std::map<std::string, MatchStrategy*> strategies_;
};

#endif // MATCHMAKING_SYSTEM_H