#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;

    struct Node* left;
    struct Node* right;

} Node;

int empty_tree(Node *root) {
    return root == NULL;
}

Node* insert(Node *root, int data) {
      Node *temp = (Node*) malloc(sizeof(Node));
      
      temp->data = data;
      temp->left = NULL;
      temp->right = NULL;

      if (root == NULL) {
          root = temp;
     
      } else {
          Node *current = root;
	  Node *parent = NULL;
	  while(1) {
	      parent = current;
	      if (data < parent->data) {
	         current = current->left;

		 if (current == NULL) {
		    parent->left = temp;
		    return root;
		 }
	      } else {
	          current = current->right;

		  if (current == NULL) {
		     parent->right = temp;
		     return root;
		  }
	      }
	  }
      }
      return root;
}

Node* search(Node *root, int data) {
    Node *current = root;
    printf("\n ");
    printf("Visiting elements: ");

    while(current) {
        printf("%d\n", current->data);

	if (data < current->data) {
	   current = current->left;
	} else if (data > current->data) {
	    current = current-> right;
	} else {
	    return current;
	}
    }
}

// in order left - root - right 
void inorder_traversal(Node* root) {
    if (root) {
      inorder_traversal(root->left);
      printf("%d\n", root->data);
      inorder_traversal(root->right);
    }
}

//pre order  root - left - right
void preorder(Node *root){
    if (root) {
        printf("%d\n", root->data); 
        preorder(root->left);
        preorder(root->right); 	
    }   
}

// pos order  left - right - root
void posorder(Node *root){
    if (root) {
       posorder(root->left);
       posorder(root->right); 
       printf("%d\n", root->data);
    }
} 


void print_tree(Node* root) {
     if (root) {
        printf("%d\t", root->data);
	print_tree(root->right);
	print_tree(root->left);
     }    
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int tree_tall(Node *root) {
    if (empty_tree(root)) 
       return -1;
    return 1 + max(tree_tall(root->left),tree_tall(root->right));
    
}

int main() {
    int i;
    int array[11] = 
	{ 15, 6, 18, 17, 20, 3, 7, 13,
	  9, 4, 2 };
    Node *root = NULL;

    for(i = 0; i < 11; i++) {
       root = insert(root, array[i]);
       printf("Inserted: %d\n", array[i]);
    }
    
    printf("\n\n Binary Search Tree\n\n");
    print_tree(root);

    printf("\nInorder traversal: ");
    inorder_traversal(root);
    
    printf("\nPre Order: ");
    preorder(root);
    
    printf("\nPos order: ");
    posorder(root);
    
    printf("\nTall Tree: ");
    printf("\n%d",tree_tall(root));
    
    Node* temp = search(root, 7);
    if(temp) {
      printf("[%d] Found.\n",temp->data);
    } else {
        printf("[x] (%d) Not Found.\n", i);
    }
    
    free(temp);
    free(root);

    return 0;

}
