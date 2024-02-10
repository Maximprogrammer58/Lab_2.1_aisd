#ifndef LAB_1_INCLUDE_SET_H
#define LAB_1_INCLUDE_SET_H

#include <iostream>

struct Node {
	int value;
	Node* left, * right;

	Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

class Set {
	Node* _root;
	size_t _size;

public:
	Set() : _root(nullptr), _size(0) {}

	Set(const Set& other);

	~Set();

	Set& operator=(const Set& other);

	void print() const;

	bool contains(int value) const;

	Node* find(int value) const;

	Node* find_node(Node* node, int value) const;

	bool insert(int value);

	bool erase(int value);

	size_t size() const;

	Node* root() const;

private:
	void delete_assistant(Node* node);

	void print_assistant(Node* node) const;

	Node* clone(Node* node);

	bool contains_assistant(Node* node, int value) const;

	Node* insert_assistant(Node* node, int value);

	Node* erase_assistant(Node* node, int value);

	Node* find_min_node(Node* node) const;
};

#endif