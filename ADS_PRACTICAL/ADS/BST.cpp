/*
Write a program in C++ to implement the following operations on Binary Search Tree: create,
 recursive inorder traversal, 
 recursive preorder traversal,
 recursive postorder traversal, 
 non recursive inorder traversal, 
 non recursive preorder traversal, 
 non recursive postorder traversal, 
 delete a node, insert a node, 
 level wise printing
*/

#include <iostream>
using namespace std;

#define max 10

class node
{
public:
    int data;
    node *left;
    node *right;
    node()
    {
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    node *root;
    BST() { root = NULL; }
    void insert_node(node *, node *);
    void levelwise_traversal(node *);
    void inorder_recursion(node *);
    void preorder_recursion(node *);
    void postorder_recursion(node *);
    void inorder_nonrecursion(node *);
    void preorder_nonrecursion(node *);
    void postorder_nonrecursion(node *);
    void search(node *,int);
    node* delete_1(node *,int);
};

void BST::insert_node(node *current_node, node *new_node)
{
    // adding node to the right of the node
    if (new_node->data > current_node->data)
    {
        if (current_node->right != NULL)
        {
            insert_node(current_node->right, new_node);
        }
        else
        {
            node *temp = new node;
            temp = new_node;
            current_node->right = temp;
            cout << "\n"
                 << temp->data << " added node at right " << current_node->data << endl;
        }
    }

    // adding node to left of the node
    else
    {
        if (current_node->left != NULL)
        {
            insert_node(current_node->left, new_node);
        }
        else
        {
            node *temp = new node;
            temp = new_node;
            current_node->left = temp;
            cout << "\n"
                 << temp->data << " added node at left " << current_node->data << endl;
        }
    }
}

void BST::levelwise_traversal(node *root)
{
    node *queue[max];
    int rear = 0, front = 0;
    queue[rear] = root;
    while (front <= rear )
    {
        node *temp = queue[front++];

        if (temp != NULL)
        {
            cout << temp->data << "   ";
            if(temp->left!=NULL)
                queue[++rear] = temp->left;
            if(temp->right!=NULL)
                queue[++rear] = temp->right;
        }
    }
}

void BST::inorder_recursion(node *root)
{
    if (root == NULL)
        cout << "Tree is empty.";
    else
    {
        if (root->left != NULL)
        {
            inorder_recursion(root->left);
        }

        cout << root->data << "   ";

        if(root->right != NULL)
        {
            inorder_recursion(root->right);
        }
    }
}

void BST::preorder_recursion(node *root)
{
    if (root == NULL)
        cout << "Tree is empty.";
    else
    {
        cout<<root->data<<"   ";

        if (root->left != NULL)
            preorder_recursion(root->left);

        if(root->right != NULL)
            preorder_recursion(root->right);
    }
}

void BST::postorder_recursion(node *root)
{
    if (root == NULL)
        cout << "Tree is empty.";
    else
    {
        if (root->left != NULL)
            postorder_recursion(root->left);

        if(root->right != NULL)
            postorder_recursion(root->right);

        cout<<root->data<<"   ";
    }
}

void BST::inorder_nonrecursion(node *root)
{
    node *Stacknode[max];
    int top = -1;
    if(root == NULL)
        cout << "Tree is Empty.";
    else
    {
        node *temp = root;
        do
        {
            while(temp!=NULL)
            {
                Stacknode[++top] = temp;
                temp = temp->left;
            }
            if(top != -1)
            {
                temp = Stacknode[top--];
                cout << temp->data << "   ";
                temp = temp->right;
            }
            else
            {
                break;
            }
        }while(1);
    }
}

void BST::preorder_nonrecursion(node *root)
{
    node *Stacknode[max];
    int top = -1;
    if(root == NULL)
        cout << "Tree is Empty.";
    else
    {
        node *temp = root;

        while(temp != NULL || top != -1)
        {
            if(temp != NULL)
            {
                cout<<temp->data<<"   ";
                Stacknode[++top] = temp;
                temp = temp->left;
            }
            else
            {
                temp = Stacknode[top--];
                temp = temp->right;
            }
        }

    }
}

void BST::postorder_nonrecursion(node *root)
{
    node *Stacknode[max];
    int top = -1;
    if(root == NULL)
        cout << "Tree is Empty.";
    else
    {
        while(top != -1)
        {
            node *temp = root;
        Stacknode[top++] = temp->right;
        Stacknode[top++] = temp;
        temp = temp->left;
        }


    }
}
void BST::search(node *root, int val) 
{
	 if(root == NULL)
	 cout << "Element not found in the tree" << endl;
		
	 else {
	  if(root->data == val) {
	   cout << root->data <<" Is found in the tree " <<endl;
	   return;
	  }
	  
	  else if(val < root->data)
	   search(root->left, val);
	  
	  else if(val > root->data)
	   search(root->right, val);
	 }
}

node * BST :: delete_1(node * root,int val)
{
	if (root == NULL)
	{
		cout << "Tree is Empty";
		return root;
	}
	if (val < root->data)
	{
		root->left = delete_1(root->left, val);
		return root;
	}
	else if (val > root->data)
	{
		root->right = delete_1(root->right, val);
		return root;
	}
	if (root->left == NULL)
	{
		node *temp = root->right;
		delete root;
		return temp;
	}
	else if (root->right == NULL)
	{
		node *temp = root->left;
		delete root;
		return temp;
	}
	else
	{
		node *parent = root;
		node *node_successor = root->right;
		while (node_successor->left != NULL)
		{
			parent = node_successor;
			node_successor = node_successor->left;
		}
		if (parent != root)
		{
			parent->left = node_successor->right;
		}
		else
		{
			parent->right = node_successor->right;
			root->data = node_successor->data;
			delete node_successor;
			return root;
			
		}
		
	}


	
	
	
	
	
	
	/* if (root == NULL)
	 {
	  cout << "Tree is Empty";
	  return root;
	  
	 }
	 if (val1 < root->data)
	 {
	  root->left = delete_node(root->left, val1);
	  return root;
	  
	 }
	 else if (val1 > root->data)
	 {
	  root->right = delete_node(root->right, val1);
	  return root;
	  
	 }
	 if (root->left == NULL)
	 {
	  node *temp = root->right;
	  delete root;
	  return temp;
	 }
	 else if (root->right == NULL)
	 {
	  node *temp = root->left;
	  delete root;
	  return temp;
	 }
	 else
	 {
	  node *parent = root;
	  node *node_successor = root->right;
	  while (node_successor->left != NULL)
	  {
	   parent = node_successor;
	   node_successor = node_successor->left;
	  }
	  if (parent != root)
	  {
	   parent->left = node_successor->right;
	  }
	  else
	  {
	   parent->right = node_successor->right;
	   root->data = node_successor->right;
	   delete node_successor;
	   return root;
	   
	  }
	  root->data = node_successor->right;
	  
	 }*/


}

int main()
{
    BST B;
	

    int exit_code;
    int choice = -1;
    do
    {
    	cout << "<------------------------------------------> \n"<< " 1.to insert the node\n" << " 2.to levelwise display\n" << " 3. for inorder(recursion) traversal\n";
    	cout << " 4. for preorder(recursion) traversal\n" << " 5. for postorder(recursion) traversal\n"<< " 6. for inorder(non-recursion) traversal\n";
   		cout << " 7. for preorder(non-recursion) traversal\n" << " 8. for postorder(non-recursion) traversal\n" << " 9.for searching a node\n" << "10.for Delete node\n";
    	cout << "\n<------------------------------------------>\n";
        cout << "Enter your choice : ";
        cin >> choice;
        int ec;
        switch (choice)
        {
        case 1:
            ec = 1;
            while (ec != -1)
            {
                node *temp = new node;
                cout << "Enter node : ";
                cin >> temp->data;

                if (B.root == NULL)
                {
                    B.root = temp;
                    cout << "\n BST is created \n\n";
                }
                else
                {
                    B.insert_node(B.root, temp);
                }
                cout << "\n Enter -1 to exit or 1 to add one more node : ";
                cin >> ec;
            }
            break;

        case 2:
            cout << "\n Levelwise display : ";
            B.levelwise_traversal(B.root);
            break;

        case 3:
            cout << "Inorder traversal using recursive method : ";
            B.inorder_recursion(B.root);
            break;
            
        case 4:
            cout << "Preorder traversal using recursive method : ";
            B.preorder_recursion(B.root);
            break;

        case 5:
            cout << "Postorder traversal using recursive method : ";
            B.postorder_recursion(B.root);
            break;

        case 6:
            cout<<"Inorder traversal using non-recursive method : ";
            B.inorder_nonrecursion(B.root);
            break;

        case 7:
            cout<<"Preorder traversal using non-recursive method : ";
            B.preorder_nonrecursion(B.root);
            break;

        case 8:
            cout<<"Postorder traversal using non-recursive method : ";
            B.postorder_nonrecursion(B.root);
            break;
        
        case 9:
        	int val;
        	cout<<"Enter the value for search :";
        	cin>>val;
        	B.search(B.root,val);
        	break;
        	
        case 10:
        	int val1 ;
        	cout << "Enter the Value for delete :";
        	cin>>val;
        	B.delete_1(B.root,val1);
        	break;
        	

        default:
            cout << "\nEnter valid choice ! \n";
        }
        cout << "\n Enter -1 to exit or 1 to continue \n";
        cin >> exit_code;
    } while (exit_code != -1);

    return 0;
}
