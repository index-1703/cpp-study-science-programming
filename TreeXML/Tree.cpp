#include "Tree.h"
#include <iomanip> 
#include <vector>

Tree::Tree()
	:head(NULL)
{
}

void destroyTree(tree_node* tree) {
	for (tree_node* node : tree->nodes) {
		destroyTree(node);
		delete node;
	}
}

Tree::~Tree()
{
	destroyTree(head);
	delete head;
}

void Tree::printAsBranch(tree_node* node, std::string const& prefix, bool root, bool last) {
	std::cout << prefix << (root ? "" : (last ? "\\-" : "|-")) << (node ? node->data : "") << std::endl;
	
	if (!node || node->nodes.size() == 0)
		return;
	
	std::vector<tree_node*> &v = node->nodes;

	for (size_t i = 0; i < v.size(); ++i)
		printAsBranch(v[i], prefix + (root ? "" : (last ? "  " : "| ")), false, i + 1 >= v.size());
}

void Tree::print(void)
{
	printAsBranch(head);
}

