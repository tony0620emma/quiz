#include "tree.h"

void flatten(struct TreeNode *root)
{
	if (!root)
	  	return;
	if (root->left) {
		struct TreeNode *temp = root->left;
		while (temp->right)				
			temp = temp->right;			
		temp->right = root->right;			
		root->right = root->left;			
		root->left = NULL;			
	}
	flatten(root->right);
}


int main()
{
    return 0;
}
