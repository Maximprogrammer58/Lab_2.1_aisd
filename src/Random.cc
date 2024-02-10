#include "../include/Random.h"

size_t lcg() {
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}

Set generate_random_set(size_t lenght) {
	Set set;
	for (int i = 0; i < lenght; ++i) 
		set.insert(lcg());
	return set;
}

std::vector<size_t> generate_random_vector(size_t lenght) {
	std::vector<size_t> vect;
	for (int i = 0; i < lenght; ++i)
		vect.push_back(lcg());
	return vect;
}