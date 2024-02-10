#include "../include/Random.h"
#include "../include/TimeTest.h"


int main() {

	Set set = generate_random_set(1000);
	std::vector<size_t> vec = generate_random_vector(1000);
	std::cout << average_find_set(set, 3) << std::endl;
	std::cout << average_find_vector(vec, 3) << std::endl;

	return 0;
}


/*
class Set {
	struct Node {
		int value;
		Node *left, *right;

		Node(int value) : value(value), left(nullptr), right(nullptr) {}
	};

	Node* _root;
	size_t _size;

public:
	Set() : _root(nullptr), _size(0) {}

	Set(const Set& other) {
		_root = clone(other._root);
		_size = other._size;
	}

	~Set() {
		delete_assistant(_root);
		_size = 0;
	}

	Set& operator=(const Set& other) {
		if (this != &other) {
			delete_assistant(_root);
			_root = clone(other._root);
			_size = other._size;
		}
		return *this;
	}

	void print() const {
		print_assistant(_root);
		std::cout << std::endl;
	}

	bool contains(int value) const {
		return contains_assistant(_root, value);
	}

	bool insert(int value) {
		if (contains(value))
			return false;
		_root = insert_assistant(_root, value);
		_size++;
		return true;
	}

	bool erase(int value) {
		if (!contains(value))
			return false;
		_root = erase_assistant(_root, value);
		_size--;
		return true;
	}

	size_t size() const {
		return _size;
	}

private:
	void delete_assistant(Node* node) {
		if (node) {
			delete_assistant(node->left);
			delete_assistant(node->right);
			delete node;
		}
	}

	void print_assistant(Node* node) const {
		if (node) {
			print_assistant(node->left);
			std::cout << node->value << " ";
			print_assistant(node->right);
		}
	}

	Node* clone(Node* node) {
		if (!node)
			return nullptr;
		Node* clone_node = new Node(node->value);
		clone_node->left = clone(node->left);
		clone_node->right = clone(node->right);
		return clone_node;
	}

	bool contains_assistant(Node* node, int value) const {
		if (!node)
			return false;
		if (node->value == value)
			return true;
		if (node->value > value)
			return contains_assistant(node->left, value);
		return contains_assistant(node->right, value);
	}

	Node* insert_assistant(Node* node, int value) {
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

	Node* erase_assistant(Node* node, int value) {
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

	Node* find_min_node(Node* node) const {
		while (!node->left)
			node = node->left;
		return node;
	}
};
*/