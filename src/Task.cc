#include "../include/Task.h"

Set Union(const Set& set_a, const Set& set_b) {
	Set set;
	unionSet(set_a.root(), set);
	unionSet(set_b.root(), set);
	return set;
}

Set symmetricDifference(const Set& set_a, const Set& set_b) {
	Set difference1 = Difference(set_a, set_b);
	Set difference2 = Difference(set_b, set_a);
	return Union(difference1, difference2);
}


Set Difference(const Set& set_a, const Set& set_b) {
	Set set = set_a;
	DifferenceSet(set, set_b.root());
	return set;
}

void unionSet(Node* root, Set& set) {
	if (root) {
		set.insert(root->value);
		unionSet(root->left, set);
		unionSet(root->right, set);
	}
}

void DifferenceSet(Set& set, Node* root) {
	if (root) {
		set.erase(root->value);
		DifferenceSet(set, root->left);
		DifferenceSet(set, root->right);
	}
}