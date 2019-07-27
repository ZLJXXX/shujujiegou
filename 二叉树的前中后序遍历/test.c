#define _CRT_SECURE_NO_WARNINGS
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


/**
* Note: The returned array must be malloced, assume caller calls free().
*/
//前序遍历
int _returnsize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return _returnsize(root->left) + _returnsize(root->right) + 1;
}
void numpreorder(struct TreeNode* root, int* preorder, int* pi)
{
	if (root == NULL)
		return;
	preorder[*pi] = root->val;
	(*pi)++;
	printf("%d,", root);
	numpreorder(root->left, preorder, pi);
	numpreorder(root->right, preorder, pi);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
	int num = 0;
	*returnSize = _returnsize(root);
	int* preorder = (int*)malloc(*returnSize*sizeof(int));
	numpreorder(root, preorder, &num);
	return preorder;
}
//中序遍历
int arraysize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return arraysize(root->left) + arraysize(root->right) + 1;
}
//为了避免递归算法开辟空间多次
int numinorder(struct TreeNode* root, int* array, int* pi)
{
	if (root == NULL)
		return;
	numinorder(root->left, array, pi);
	array[*pi] = root->val;
	(*pi)++;
	printf("%d,", root);
	numinorder(root->right, array, pi);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
	*returnSize = arraysize(root);
	int* array = (int*)malloc(*returnSize*sizeof(int));
	int num = 0;
	numinorder(root, array, &num);
	return array;
}
//后序遍历
int arraysize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return arraysize(root->left) + arraysize(root->right) + 1;
}
//为了避免递归算法开辟空间多次
int numinorder(struct TreeNode* root, int* array, int* pi)
{
	if (root == NULL)
		return;
	numinorder(root->left, array, pi);
	numinorder(root->right, array, pi);
	array[*pi] = root->val;
	(*pi)++;
	printf("%d,", root);
}
int* postorderTraversal(struct TreeNode* root, int* returnSize){

	*returnSize = arraysize(root);
	int* array = (int*)malloc(*returnSize*sizeof(int));
	int num = 0;
	numinorder(root, array, &num);
	return array;
}
