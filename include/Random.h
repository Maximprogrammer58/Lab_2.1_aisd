#ifndef LAB_1_INCLUDE_RANDOM_H
#define LAB_1_INCLUDE_RANDOM_H

#include <vector>
#include "Set.h"

size_t lcg();

Set generate_random_set(size_t lenght);

std::vector<size_t> generate_random_vector(size_t lenght);



#endif