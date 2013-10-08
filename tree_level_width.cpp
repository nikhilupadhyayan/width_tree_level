#include<iostream>
#include<stack>
using namespace std;
typedef struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
}Node;
Node* insert_util(Node* root,Node* temp)
{
    if(root==NULL)
        root=temp;
    else{
        if(temp->val>=root->val)
            root->right=insert_util(root->right,temp);
        else
            root->left=insert_util(root->left,temp);
    }
    return root;

}
Node* insert(Node* root,int val)
{
    Node* temp=new Node;
    temp->left=temp->right=NULL;
    temp->val=val;
    root=insert_util(root,temp);
    return root;
}

void print_width(Node* root)
{
    stack<Node*> s1;
    stack<Node*> s2;
    if(root==NULL)
        return ;
    int i=1;
    cout<<"Level "<<i++<<": "<<1<<endl;
    s1.push(root);
    while(s1.empty()==false)
    {
        int temp_count=0;
        while(s1.empty()==false)
        {
            Node* top=s1.top();
            s1.pop();
            if(top->left)s2.push(top->left);
            if(top->right)s2.push(top->right);

        }
        if(!s2.empty())
        {cout<<"Level "<<i++<<": "<<s2.size()<<endl;
        s1=s2;
        while(!s2.empty())s2.pop();
        }
    }
}
void print_zigzag(Node* root)
{
    stack<Node*> s1;
    stack<Node*> s2;
    if(root==NULL)
        return;
    s1.push(root);
    Node* temp;
    cout<<"Zigzag: ";
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            temp=s1.top();
            s1.pop();
            cout<<temp->val<<"\t";
            if(temp->right)s2.push(temp->right);
            if(temp->left)s2.push(temp->left);

        }
        while(!s2.empty())
        {
            temp=s2.top();
            s2.pop();
            cout<<temp->val<<"\t";
            if(temp->left)s1.push(temp->left);
            if(temp->right)s1.push(temp->right);
        }
    }
}
int main()
{
        Node* root=NULL;
        root=insert(root,6);
        root=insert(root,3);
        root=insert(root,9);
        root=insert(root,2);
        root=insert(root,4);
        root=insert(root,8);
        root=insert(root,10);
        root=insert(root,11);
        print_width(root);
        print_zigzag(root);
}
