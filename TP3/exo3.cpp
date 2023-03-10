/*#include "mainwindow.h"
#include "tp3.h"
#include <QApplication>*/
#include <iostream>
#include <vector>

using namespace std;
#include <time.h>
#include <stack>
#include <queue>
/*
MainWindow* w = nullptr;
using std::size_t;*/

struct SearchTreeNode
{    
    SearchTreeNode* left;
    SearchTreeNode* right;
    int value;

    void initNode(int value)
    {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }

	void insertNumber(int value) {
        // create a new node and insert it in right or left child
        if (value < this->value && this->left == nullptr){
            this->left = new SearchTreeNode(value);
        }
        else if (value > this->value && this->right == nullptr){
            this->right = new SearchTreeNode(value);;
        }
        else if (value > this->left->value){
            this->right->insertNumber(value);
        }
        else this->left->insertNumber(value);
        
    }

	uint height() const	{
        // should return the maximum height between left child and
        // right child +1 for itself. If there is no child, return
        // just 1
        if (this->left == nullptr && this->right == nullptr) return 1;
        else if (this->left != null) return 1+this->left.height();
        else if (this->right != null) return 1+this->right.height();
    }

	int nodesCount() const {
        // should return the sum of nodes within left child and
        // right child +1 for itself. If there is no child, return
        // just 1

        return 1;
	}

	bool isLeaf() const {
        // return True if the node is a leaf (it has no children)
        return false;
	}

	void allLeaves(SearchTreeNode* leaves[], uint& leavesCount) {
        // fill leaves array with all leaves of this tree
	}

	void inorderTravel(SearchTreeNode* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with inorder travel
	}

	void preorderTravel(SearchTreeNode* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with preorder travel
	}

	void postorderTravel(SearchTreeNode* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with postorder travel
	}

	SearchTreeNode* find(int value) {
        // find the node containing value
		return nullptr;
	}

    void reset()
    {
        if (left != NULL)
            delete left;
        if (right != NULL)
            delete right;
        left = right = NULL;
    }

    SearchTreeNode(int value) {initNode(value);}
    ~SearchTreeNode() {}
    int get_value() const {return value;}
    SearchTreeNode* get_left_child() const {return left;}
    SearchTreeNode* get_right_child() const {return right;}
};

SearchTreeNode* createNode(int value) {
    return new SearchTreeNode(value);
}

void printTree(SearchTreeNode* root) {
    if (root == NULL)
        return;
    cout << root->get_value() << " ";
    printTree(root->get_left_child());
    printTree(root->get_right_child());
}

/*

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 200;
    w = new BinarySearchTreeWindow<SearchTreeNode>();
	w->show();

	return a.exec();
}*/


int main(){
    SearchTreeNode* root = createNode(5);
    root->insertNumber(3);
    root->insertNumber(7);
    printTree(root);
}
