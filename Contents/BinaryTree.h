#include <iostream>

struct Node{
	int value;
	Node *left;
	Node *right;
};
	Node* new_root(int v,Node *leaf){
		
			if(leaf == NULL){
				leaf = new Node;
				leaf->value = v;
				leaf->left = NULL;
				leaf->right = NULL;
				
			return leaf;
			}	
			else if(v < leaf->value){
				if(leaf->left != NULL)
					new_root(v,leaf->left);
				else{
					leaf->left = new Node;
					leaf->left->value = v;
					leaf->left->left = NULL;
					leaf->left->right = NULL;
				}
			}
			else if(v >= leaf->value){
				if(leaf->right != NULL){
					new_root(v,leaf->right);
				}
				else{
					leaf->right = new Node;
					leaf->right->value = v;
					leaf->right->left = NULL;
					leaf->right->right = NULL;
				}
			}
			return leaf;
			}

	Node* search(int v, Node* leaf){
				if(v == leaf->value)
					return leaf;
				else if(v > leaf->value)
					search(v,leaf->right);
				else if(v < leaf->value)
					search(v,leaf->left);
				else
					return NULL;
			}
			
	void inorder(Node *leaf){
				
				if(leaf != NULL){
					inorder(leaf->left);
					std::cout<<leaf->value<<" ";
					inorder(leaf->right);
				}
			}
	Node* minValueNode(Node *root){
			Node *current = root;
			
			if(current!=NULL){
				
			while(current->left != NULL)
				current = current->left;
			}
			return current;
		}	
		
	struct Node* deleteNode(Node *root, int key){
					
					if(root == NULL)
						return root;
		
					if(key < root->value)
						root->left = deleteNode(root->left,key);
					else if(key > root->value)
						root->right= deleteNode(root->right,key);
					else{
						if(root->left == NULL){
							Node *temp = root->right;
							delete(root);
							return temp;
							}
						else if (root->right == NULL){
							Node *temp = root->left;
							delete(root);
							return temp;
							}
						else if(root->left == NULL && root->right == NULL){
							delete(root);
							return NULL;
							}
						
						Node *temp = minValueNode(root->right);
						
						root->value = temp->value;
						
						root->right = deleteNode(root->right,temp->value);
					
						}
						return root;
					}
