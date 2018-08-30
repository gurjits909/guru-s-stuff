#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right,*parent;
    char color;
};
struct node* create_node(int data)
{
    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent=NULL;
    return new_node;
}
struct node* right(struct node* main_focus)
{
    struct node * temp,*payrent,*grand_parent;
    temp = main_focus->right;
    payrent = main_focus->parent;
    grand_parent=payrent->parent;

    main_focus->right=payrent;
    payrent->parent=main_focus;

    payrent->left = temp;
    if(temp!=NULL)
        temp->parent=payrent;

    if(grand_parent!=NULL)
    {
        grand_parent->right=main_focus;
        main_focus->parent=grand_parent;
    }
    return main_focus;
}
struct node* left(struct node* main_focus)
{
    struct node * temp,*payrent,*grand_parent;
    temp = main_focus->left;
    payrent = main_focus->parent;
    grand_parent=payrent->parent;

    main_focus->left=payrent;
    payrent->parent=main_focus;

    payrent->right = temp;
    if(temp!=NULL)
        temp->parent = payrent;

    if(grand_parent!=NULL)
    {
        grand_parent->left=main_focus;
        main_focus->parent = grand_parent;
    }
    return main_focus;
}
void insertion_red_black(struct node* new_node)
{
    if(new_node->parent == NULL)
    {
        new_node->color ='B';
    }
    else
    {
        new_node->color = 'R';
        if((new_node->parent)->color == 'B')
            return ;
        else
        {
            struct node *grand_parent,*pay_rent,*sibling;
            pay_rent =new_node->parent;
            grand_parent = pay_rent->parent;
            //finding sibling
            if(pay_rent==grand_parent->left)
                sibling = grand_parent->right;
            else if(pay_rent == grand_parent->right)
                sibling = grand_parent->left;//sibling found

            //if parent sibling is red then reorder and check
            if(sibling == NULL || sibling->color == 'B')
            {
                 if(pay_rent->left == new_node && grand_parent->left==pay_rent)
                 {
                     //right rotation on child
                     struct node* temp;
                     temp = right(new_node->parent);
                     char c;
                     c=temp->color;
                     temp->color = (temp->right)->color;
                     (temp->right)->color=c;
                 }
                 else if(pay_rent->left == new_node && grand_parent->right==pay_rent)
                 {
                     //right rotation followed by left rotation
                     struct node *temp;
                     temp=right(new_node);
                     temp=left(temp);
                     char c ;
                     c=temp->color;
                     temp->color=temp->left->color;
                     temp->left->color=c;
                 }
                 else if(pay_rent->right == new_node && grand_parent->left==pay_rent)
                 {
                     //left rotation followed by right rotation
                     struct node* temp ;
                     temp = left(new_node);
                     temp = right(temp);
                     char c;
                     c=temp->color;
                     temp->color=temp->right->color;
                     temp->right->color=c;
                 }
                 else if(pay_rent->right == new_node && grand_parent->right==pay_rent)
                 {
                     //left rotation
                     struct node* temp;
                     temp = left(new_node->parent);
                     char c;
                     c=temp->color;
                     temp->color = (temp->left)->color;
                     (temp->left)->color=c;
                 }
            }
            //else if siblig is black or no sibling then rotate and reorder
            else if(sibling -> color == 'R')
            {
               //RECOLORING
               pay_rent->color = 'B';
               sibling->color = 'B';
               if(grand_parent->parent != NULL)
               {
                   grand_parent->color ='R' ;
                   insertion_red_black(grand_parent);
               }
               else
                return ;
            }
        }
    }
};
//adding node to the binary search tree
struct node* add_bst(struct node *root,struct node * new_node)
{
  struct node* temp=root;
  if(root==NULL)
  {
      root = new_node;
      insertion_red_black(root);
  }
  else
  {
      while(1)
      {
          if((temp->data) >= (new_node->data))
            {
              if(temp->left!=NULL)
                temp=temp->left;
              else
              {
                new_node->parent=temp;
                new_node->color='R';
                temp->left=new_node;
                //insertion in binary search tree
                insertion_red_black(new_node);
                break;
              }
            }
            else
            {
                if(temp->right!=NULL)
                    temp=temp->right;
                else
                {
                    new_node->parent=temp;
                    new_node->color='R';
                    temp->right=new_node;
                    //insertion in binary search tree
                    insertion_red_black(new_node);
                   break;
                }
            }
      }
  }
  return root;
}
void inorder_traversal(struct node* itr)
{
    if(itr==NULL)
        return ;
    inorder_traversal(itr->left);
    printf("%d ",itr->data);
    inorder_traversal(itr->right);
}
int main()
{
    struct node *root=NULL;
    int data,choice;
    while(1)
    {
    printf("Press 1 to add element and 0 to exit \n");

    scanf("%d",&choice);
    if(choice == 1)
    {
        printf("Enter the data \n");
    scanf("%d",&data);
    struct node *new_node;
    new_node=create_node(data);
    root = add_bst(root,new_node);
    }
    else if(choice==0)
    {
        break;
    }
    }
    inorder_traversal(root);
    printf("%c",root->color);
    return 0;
}
