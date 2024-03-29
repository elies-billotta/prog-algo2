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
        int l = 0;
        int r = 0;
        if (this->left == nullptr && this->right == nullptr) return 1;
        if (this->left != nullptr) l = this->left.height();
        if (this->right != nullptr) r = this->right.height();
        return 1+max(l,r);
    }

	int nodesCount() const {
        // should return the sum of nodes within left child and
        // right child +1 for itself. If there is no child, return
        // just 1
        int l = 0;
        int r = 0;
        if (this->left == nullptr && this->right == nullptr) return 1;
        if (this->left != nullptr) l = this->left.nodesCount();
        if (this->right != nullptr) r = this->right.nodesCount();
        return 1+l+r;
	}

	bool isLeaf() const {
        return this->left == nullptr && this->right == nullptr;
	}

	void allLeaves(SearchTreeNode* leaves[], uint& leavesCount) {
        if(this->isLeaf()){
            leaves[leavesCount] = this;
            leavesCount++;
        }
        else{
            if (this->left != nullptr) this->left->allLeaves(leaves, leavesCount);
            if (this->right != nullptr) this->right->allLeaves(leaves, leavesCount);
        }
	}

	void inorderTravel(SearchTreeNode* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with inorder travel
        if (this->left != nullptr) this->left->inorderTravel(nodes, nodesCount);
        nodes[nodesCount] = this;
        nodesCount++;
        if (this->right != nullptr) this->right->inorderTravel(nodes, nodesCount);
	}

	void preorderTravel(SearchTreeNode* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with preorder travel
        nodes[nodesCount] = this;
        nodesCount++;
        if (this->left != nullptr) this->left->preorderTravel(nodes, nodesCount);
        if (this->right != nullptr) this->right->preorderTravel(nodes, nodesCount);
	}

	void postorderTravel(SearchTreeNode* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with postorder travel
        if (this->left != nullptr) this->left->postorderTravel(nodes, nodesCount);
        if (this->right != nullptr) this->right->postorderTravel(nodes, nodesCount);
        nodes[nodesCount] = this;
        nodesCount++;
	}

	SearchTreeNode* find(int value) {
        // find the node containing value
        if (this->value == value) return this;
        else if (this->left != nullptr) return this->left->find(value);
        else if (this->right != nullptr) return this->right->find(value);
		else return nullptr;
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
