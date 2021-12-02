#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};typedef struct Node *node;
int height(node N)
{
	if (N == NULL)
		return 0;
	return N->height;
}
int max(int a, int b)
{
	return (a > b)? a : b;
}
node newNode(int key)
{
	node new = (node)malloc(sizeof(struct Node));
	new->key = key;
	new->left = NULL;
	new->right = NULL;
	new->height = 1;
	return(new);
}
node rightRotate(node y)
{
	node x = y->left;
	node T2 = x->right;
	x->right = y;
	y->left = T2;
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;
	return x;
}
node leftRotate(node x)
{
	node y = x->right;
	node T2 = y->left;
	y->left = x;
	x->right = T2;
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;
	return y;
}
int getBalance(node N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}
node insert(node new, int key)
{
	if (new == NULL)
		return(newNode(key));
	if (key < new->key)
		new->left = insert(new->left, key);
	else if (key > new->key)
		new->right = insert(new->right, key);
	else
		return new;

	new->height = 1 + max(height(new->left),height(new->right));

	int balance = getBalance(new);
	
	if (balance > 1 && key < new->left->key)
		return rightRotate(new);

	if (balance < -1 && key > new->right->key)
		return leftRotate(new);

	if (balance > 1 && key > new->left->key)
	{
		new->left = leftRotate(new->left);
		return rightRotate(new);
	}
	
	if (balance < -1 && key < new->right->key){
		new->right = rightRotate(new->right);
		return leftRotate(new);
	}
	
	return new;
}
node minValueNode(node new)
{
    node current = new;
    while (current->left != NULL)
        current = current->left;
    return current;
}
node deleteNode(node root, int key)
{
    if (root == NULL)
        return root;
    if ( key < root->key )
        root->left = deleteNode(root->left, key);
    else if( key > root->key )
        root->right = deleteNode(root->right, key);
    else {
        if( (root->left == NULL) || (root->right == NULL) ){
            node temp = root->left ? root->left : root->right;
            if (temp == NULL){
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else{
            node temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    if (root == NULL)
      return root;
    root->height = 1 + max(height(root->left),height(root->right));
    int balance = getBalance(root);
    
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
 
    if (balance > 1 && getBalance(root->left) < 0){
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
 
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
 
    if (balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}
void preOrder(node root)
{
	if(root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}
int main()
{
    node root = NULL;
    int choice,x;
    for(;;){
        printf("\n\n1.Insert\n2.Delete\n3.Preorder traversal\n4.Exit\n");
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : printf("\nInsert value : ");
                scanf("%d",&x);
                root=insert(root,x);
                break;
            case 2 : printf("\nEnter value to delete : ");
                scanf("%d",&x);
                root=deleteNode(root,x);
                break;
            case 3 : printf("\nPreorder traversal of the constructed AVL tree is :\n");
                preOrder(root);
                break;
            case 4 : exit(0);
            default : printf("Enter correct instrution!!!\n");
        }
    }
    return 0;
}
