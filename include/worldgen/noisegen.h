#ifndef NOISEGEN_H
#define NOISEGEN_H

#include <initializer_list>
#include <vector>
#include "worldgen/noisespace.h"

namespace KevinQuest::WorldGen {
    class NoiseGenerator {
        public:

        /**
         * Allows setting coefficients for random distribution
         */
        virtual void SetDistribution(std::initializer_list<int> coefficients) = 0;
        virtual NoiseSpace& GetNoiseSpace() = 0;
        
    };
}

#endif // NOISEGEN_H