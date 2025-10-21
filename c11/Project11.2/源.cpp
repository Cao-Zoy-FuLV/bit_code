#include<iostream>
using namespace std;

//�������ṹ��
struct TreeNode {
	string name;
	TreeNode* left;
	TreeNode* right;
};

//���õ�ʵ�ֶ����������������ӡ���
void printTreePreOrder(TreeNode* root) {
	//��׼���������ǿ�������ֱ�ӷ���
	if (root == nullptr) return;
	
	//�ȴ�ӡ���ڵ��ֵ
	cout << root->name <<"\t";

	//�ݹ��ӡ��������
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