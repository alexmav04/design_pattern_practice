#include "matchmaking_system.h"

Individual* MatchmakingSystem::match(const std::string strategy, Individual* self, std::vector<Individual*>& candidates) {
    auto it = strategies_.find(strategy);
    if (it == strategies_.end()) {
        return nullptr;
    }
    return it->second->match(self, candidates);
}

void MatchmakingSystem::addStrategy(const std::string& name, MatchStrategy* strategy) {
    strategies_[name] = strategy;
}
