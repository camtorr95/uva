#include <stdio.h>
#include <stdlib.h>
#define mllc (node*)malloc(sizeof(node))

typedef struct node
{
    int val;
    struct node *left, *right;
} node;

void add(node *root, const int x){
    if(root->val == -1){
        root->val = x;
        return;
    }
    node *temp = root;
    while(temp){
        if(temp->val < x){
            if(temp->right == 0){
                temp->right = mllc;
                temp->right->val = x;
                temp->right->left = 0;
                temp->right->right = 0;
            } else {
                if(temp->right->val == -1){
                    temp->right->val = x;
                } else {
                    temp = temp->right;
                }
            }
        } else {
            if(temp->left == 0){
                temp->left = mllc;
                temp->left->val = x;
                temp->left->left = 0;
                temp->left->right = 0;
            } else{
                if(temp->left->val == -1){
                    temp->left->val = x;
                } else {
                    temp = temp->left;
                }
            }
        }
    }
}

int main()
{
    int n,k;
    while(scanf("%d %d\n", &n, &k) == 2)
    {
        int i, counter = 0;
        for(i=0; i<n; ++i)
        {
            int j;
            node *root = mllc;
            root->val = -1;
            root->left = 0;
            root->right = 0;
            for(j=0; j<k; ++j)
            {
                int x;
                scanf("%d", &x);
                add(root,x);
            }
        }
    }
}
