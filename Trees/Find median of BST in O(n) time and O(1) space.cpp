https://practice.geeksforgeeks.org/problems/median-of-bst/1#:~:text=Your%20task%20is%20to%20complete,n%2B1)%2F2th%20node


Given a Binary Search Tree, find median of it.

If no. of nodes are even: then median = ((n/2th node + (n+1)/2th node) /2
If no. of nodes are odd : then median = (n+1)/2th node.



Implementation:
1- Count the no. of nodes in the given BST
   using Morris Inorder Traversal.
2- Then Perform Morris Inorder traversal one 
   more time by counting nodes and by checking if 
   count is equal to the median point.
   To consider even no. of nodes an extra pointer
   pointing to the previous node is used.





/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
Structure of the binary Search Tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete the Function
// Note: Function should return median of the BST
int x,y;
void inOrder(Node* root,int &count,int n){
    if(root==NULL)
        return;
    inOrder(root->left,count,n);
    count++;
    if(count==n/2){
        x=root->data;
    }
    if(count==(n/2)+1){
        y=root->data;
    }
    inOrder(root->right,count,n);
}
int size(Node* root){
    if(root==NULL)
        return 0;
    
    return size(root->left) + 
           size(root->right) + 1;
}
float findMedian(struct Node *root,int n)
{
    x=0;
    y=0;
    int count=0;
    n=size(root);
    inOrder(root,count,n);
    if(n%2==0)
        return (float)(x+y)/2.0;
    else
        return y;
}


