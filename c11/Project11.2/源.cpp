#include<iostream>
using namespace std;

//二叉树结构体
struct TreeNode {
	string name;
	TreeNode* left;
	TreeNode* right;
};

//利用递实现二叉树的先序遍历打印输出
void printTreePreOrder(TreeNode* root) {
	//基准情况：如果是空树，就直接返回
	if (root == nullptr) return;
	
	//先打印根节点的值
	cout << root->name <<"\t";

	//递归打印左右子树
	printTreePreOrder(root->left);
	printTreePreOrder(root->right);
}

int main() {
	TreeNode G = { "G",nullptr,nullptr };
	TreeNode F = { "F",nullptr,nullptr };
	TreeNode E = { "E",&G,nullptr}		;
	TreeNode D = { "D",nullptr,nullptr };
	TreeNode C = { "C",nullptr,&F };     
	TreeNode B = { "B",&D,&E };			 
	TreeNode A = { "A",&B,&C };			 
	TreeNode* tree = &A;

	/*	     A
 		   /   \
 		  B     C
        /   \    \
 	   D     E    F
 		    /
 	       G
	*/
	printTreePreOrder(tree);
}