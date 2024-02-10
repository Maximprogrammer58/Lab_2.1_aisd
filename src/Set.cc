#include "../include/Set.h"

Set::Set(const Set& other) {
	_root = clone(other._root);
	_size = other._size;
}

Set::~Set() {
	delete_assistant(_root);
	_size = 0;
}

Set& Set::operator=(const Set& other) {
	if (this != &other) {
		delete_assistant(_root);
		_root = clone(other._root);
		_size = other._size;
	}
	return *this;
}

void Set::print() const {
	print_assistant(_root);
	std::cout << std::endl;
}

bool Set::contains(int value) const {
	return contains_assistant(_root, value);
}

bool Set::insert(int value) {
	if (contains(value))
		return false;
	_root = insert_assistant(_root, value);
	_size++;
	return true;
}

bool Set::erase(int value) {
	if (!contains(value))
		return false;
	_root = erase_assistant(_root, value);
	_size--;
	return true;
}

size_t Set::size() const {
	return _size;
}

Node* Set::root() const {
	return _root;
}

void Set::delete_assistant(Node* node) {
	if (node) {
		delete_assistant(node->left);
		delete_assistant(node->right);
		delete node;
	}
}

void Set::print_assistant(Node* node) const {
	if (node) {
		print_assistant(node->left);
		std::cout << node->value << " ";
		print_assistant(node->right);
	}
}

Node* Set::clone(Node* node) {
	if (!node)
		return nullptr;
	Node* clone_node = new Node(node->value);
	clone_node->left = clone(node->left);
	clone_node->right = clone(node->right);
	return clone_node;
}

bool Set::contains_assistant(Node* node, int value) const {
	if (!node)
		return false;
	if (node->value == value)
		return true;
	if (node->value > value)
		return contains_assistant(node->left, value);
	return contains_assistant(node->right, value);
}

Node* Set::find(int value) const {
	return find_node(_root, value);
}

Node* Set::find_node(Node* node, int value) const {
	if (!node)
		return nullptr;
	if (node->value == value)
		return node;
	if (node->value > value)
		return find_node(node->left, value);
	return find_node(node->right, value);
}

Node* Set::insert_assistant(Node* node, int value) {
	if (!node)
		return new Node(value);
	if (value < node->value) {
		node->left = insert_assistant(node->left, value);
	}
	else if (value > node->value) {
		node->right = insert_assistant(node->right, value);
	}
	return node;
}

Node* Set::find_min_node(Node* node) const {
	while (!node->left)
		node = node->left;
	return node;
}

Node* Set::erase_assistant(Node* node, int value) {
	if (!node) {
		return nullptr;
	}
	if (value < node->value) {
		node->left = erase_assistant(node->left, value);
	}
	else if (value > node->value) {
		node->right = erase_assistant(node->right, value);
	}
	else {
		if (!node->left && !node->right) {
			delete node;
			return nullptr;
		}
		else if (!node->left) {
			Node* tmp = node->right;
			delete node;
			return tmp;
		}
		else if (!node->right) {
			Node* tmp = node->left;
			delete node;
			return tmp;
		}
		else {
			Node* tmp = find_min_node(node->right);
			node->value = tmp->value;
			node->right = erase_assistant(node->right, tmp->value);
		}
	}
	return node;
}