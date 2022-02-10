#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *lchild, *rchild;
};

struct Node *Insert(struct Node*, int);
struct Node *Delete(struct Node *, int);
struct Node * Search(struct Node *, int);
void Inorder(struct Node *);
void Preorder(struct Node*);
void Postorder(struct Node*);
struct Node * New_Node(int);
struct Node *Find_min(struct Node*);

int main(){
    int choice, want_continue, data,key;
    printf("Enter 1:Insert ; 2:Delete ; 3: Search ; 4:Inorder ; 5:Preorder ; 6:Postorder\n");
    struct Node *root = NULL,*r;
    do{
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1 : printf("Enter the value:");
                     scanf("%d",&data);
                     root = Insert(root,data);
                     break;
                     
            case 2: printf("Enter the value: ");
                    scanf("%d",&data);
                    root = Delete(root,data);
                    break;
                    
            case 3 : Inorder(root);
                     break;
                     
            case 4 : Preorder(root);
                     break;
                     
            case 5 : Postorder(root);
                     break;
                     
            case 6 : printf("Enter the value to be searched : ");
                     scanf("%d",&key);
                     r = Search(root,key);
                     if(r == NULL){
                         printf("Element Found\n");
                     }
                     else{
                         printf("Sucessfull - Element Found\n");
                     }
                     break;
        }
        printf("Wnat to continue, Enter 1: ");
        scanf("%d",&want_continue);
    }while(want_continue == 1);
    return 0;
}


struct Node *Insert(struct Node *root, int data){
    if(root == NULL){
        return New_Node(data);
    }
    else if(data > (root->data)){
        root -> rchild = Insert(root ->rchild, data);
    }
    else{
        root ->lchild = Insert(root -> lchild,data);
    }
    return root;
}


struct Node *New_Node(int data){
    struct Node *p;
    p = malloc(sizeof(struct Node));
    p -> data = data;
    p -> lchild = NULL;
    p -> rchild = NULL;
    return p;
}

struct Node * Find_min(struct Node *root){
    if(root == NULL){
        return NULL;
    }
    else if(root -> lchild != NULL){
        return Find_min(root -> lchild);
    }
    return root;
}




struct Node *Delete(struct Node *root, int data){
    if(root == NULL){
        return NULL;
    }
    if(data > root -> data){
        root -> rchild = Delete(root ->rchild,data);
    }
    else if(data < root -> data){
        root -> lchild = Delete(root -> lchild,data);
    }
    else{
        if((root -> lchild == NULL) && (root -> rchild == NULL)){
            free(root);
            return NULL;
        }
        else if((root -> lchild == NULL) || (root -> rchild == NULL)){
            struct Node *temp;
            if(root -> lchild == NULL){
                temp = root -> rchild;
            }
            else{
                temp = root -> rchild;
            }
            free(root);
            return temp;
        }
        else{
            struct Node *temp = Find_min(root -> rchild);
            root -> data = temp->data;
            root -> rchild = Delete(root -> rchild, temp -> data);
        }
    }
    return root;
}

struct Node *Search(struct Node *root, int key){
    if((root == NULL) || (root -> data = key)){
        return root;
    }
    else if(key < root -> data){
        return Search(root -> lchild, key);
    }
    else{
        return Search(root -> rchild, key);
    }
}


void Inorder(struct Node* root)
{
    if (root == NULL){
        return;
    }
    Inorder(root->lchild);
    printf("%d ", root->data);
    Inorder(root->rchild);    
    
}


void Postorder(struct Node* root)
{
    if (root == NULL){
        return;
    }
    Postorder(root->lchild);
    Postorder(root->rchild);
    printf("%d ", root->data);
    
}


void Preorder(struct Node* root)
{
    if (root == NULL){
        return;
    }
    printf("%d ", root->data);
    Preorder(root->lchild);
    Preorder(root->rchild);
        
    
}
