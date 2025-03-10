#include "reverse_matching_strategy.h"
#include <algorithm>

Individual* ReverseMatchingStrategy::match(Individual* self, std::vector<Individual*>& candidates) {
    if (candidates.size() < 2) {
        return nullptr;
    }

    std::vector<Individual*> remainingCandidates = candidates;
    Individual* worstOne = nullptr;

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
    worstOne = remainingCandidates[0];
    return worstOne;
}
