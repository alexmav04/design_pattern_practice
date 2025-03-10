#include "distance_based_strategy.h"
#include <limits>
#include <cmath>

Individual* DistanceBasedStrategy::match(Individual* self, std::vector<Individual*>& candidates) {
    Individual* bestOne = nullptr;
    double minDistance = std::numeric_limits<double>::max();

    for (Individual* candidate : candidates) {
        if (candidate == self) {
            continue;
        }

        double distance = sqrt(pow(candidate->coord().first - self->coord().first, 2) + pow(candidate->coord().second - self->coord().second, 2));
        if (distance < minDistance || (distance == minDistance && candidate->id() < bestOne->id())) {
            minDistance = distance;
            bestOne = candidate;
        }
    }
    return bestOne;
}