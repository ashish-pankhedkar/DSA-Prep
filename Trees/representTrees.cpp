#include<bits/stdc++.h>
using namespace std;
     
struct node {
    int data;
    node* left;
    node* right;

    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    return 0;
}