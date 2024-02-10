#ifndef LAB_1_INCLUDE_TASK_H
#define LAB_1_INCLUDE_TASK_H

#include "Set.h"

Set Union(const Set& set_a, const Set& set_b);

Set symmetricDifference(const Set& set_a, const Set& set_b);

Set Difference(const Set& set_a, const Set& set_b);

void unionSet(Node* root, Set& set);

void DifferenceSet(Set& set, Node* root);

#endif