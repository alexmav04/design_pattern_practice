#include "reverse_matching_strategy.h"
#include <algorithm>

ReverseMatchingStrategy::ReverseMatchingStrategy(MatchStrategy* strategy) 
    : strategy_(strategy) 
{
    
}

Individual* ReverseMatchingStrategy::match(Individual* self, std::vector<Individual*>& candidates) {
    if (candidates.size() < 2) {
        return nullptr;
    }

    std::vector<Individual*> remainingCandidates;
    for (Individual* candidate : candidates) {
        if (candidate != self) {
            remainingCandidates.push_back(candidate);
        }
    }
    if (remainingCandidates.size() < 2) {
        return nullptr;
    }

    while (remainingCandidates.size() > 1) {
        Individual* bestOne = strategy_->match(self, remainingCandidates);
        if (!bestOne) {
            return nullptr;
        }

        auto it = std::find(remainingCandidates.begin(), remainingCandidates.end(), bestOne);
        if (it != remainingCandidates.end()) {
            remainingCandidates.erase(it);
        }
    }
    return remainingCandidates.empty() ? nullptr : remainingCandidates[0];
}
