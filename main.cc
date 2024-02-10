#include "../include/Random.h"
#include "../include/TimeTest.h"
#include "../include/Task.h"

int main() {
	Set set1;
	Set set2;

	set1.insert(1);
	set1.insert(2);
	set1.insert(3);
	set1.insert(7);

	set2.insert(1);
	set2.insert(3);
	set2.insert(4);
	set2.insert(8);
	
	Set union_set = Union(set1, set2);

	Set difference_set = symmetricDifference(set1, set2);

	for (auto el : set1)
		std::cout << el << " ";
	std::cout << std::endl;

	for (auto el : set2)
		std::cout << el << " ";
	std::cout << std::endl;

	union_set.print();
	difference_set.print();

	// Time test
	Set set = generateRandomSet(1000);
	std::vector<size_t> vec = generateRandomVector(1000);

	std::cout << averageFillingTime(generateRandomSet, 1000) << std::endl;
	std::cout << averageFillingTime(generateRandomVector, 1000) << std::endl;

	std::cout << averageInsertVector(vec, 10, 105) << std::endl;
	std::cout << averageEraseVector(vec, 10) << std::endl;
	
	return 0;
}