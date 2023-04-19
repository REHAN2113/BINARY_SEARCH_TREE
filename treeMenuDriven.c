#include<stdio.h>
#include<stdlib.h>

 typedef struct node{

  int info;

  struct node *left,*right;

}NODE;

  NODE*create(NODE*root)
  {

      NODE *temp,*parent,*newnode;
      int i,n;
      printf("\n enter limit:");
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {

          newnode=(NODE*)malloc(sizeof(NODE));
          printf("\n enter value:");
          scanf("%d",&newnode->info);
          newnode->left=newnode->right=NULL;

          if(root==NULL)
          {
              root=newnode;


          }
          else{


          temp=root;
          while(temp!=NULL)
          {

              parent=temp;
              if(newnode->info >= temp->info)
              {

                  temp=temp->right;
              }
              else{
                temp=temp->left;

              }

          }
           if(newnode->info>=parent->info)
           {

               parent->right=newnode;
           }
           else{
            parent->left=newnode;
           }
          }


      }
      return root;
  }

    void inorder(NODE *root)
    {
         if(root!=NULL)
         {
        inorder(root->left);
        printf("%d\t",root->info);
        inorder(root->right);
         }
    }
     void preorder(NODE *root)
    {
         if(root!=NULL)
         {
             printf("%d\t",root->info);
        preorder(root->left);

        preorder(root->right);
         }
    }
     void postorder(NODE *root)
    {
         if(root!=NULL)
         {
        postorder(root->left);

        postorder(root->right);
        printf("%d\t",root->info);
         }
    }

    NODE *search(NODE *root,int val)
    {
        NODE *temp=root;

        while(temp!=NULL)
        {
            if(temp->info==val)
            {

                return temp;
            }
            else if(val>=temp->info)
            {

                temp=temp->right;
            }
            else{
                temp=temp->left;

            }

        }
        return NULL;
    }

    NODE *insert(struct node *root,int val)
    {
        NODE *temp=root,*parent,*newnode;
        newnode=(NODE*)malloc(sizeof(NODE));
        newnode->info=val;
        newnode->left=newnode->right=NULL;

        if(root==NULL)
        {

            return newnode;
        }
        while(temp!=NULL)
        {
            parent=temp;
            if(val>=temp->info)
            {

                temp=temp->right;
            }
            else{
                temp=temp->left;

            }

        }
        if(val>=parent->info)
        {

            parent->right=newnode;
        }
        else{
            parent->left=newnode;
        }

        return root;

    }

      NODE *del_BST(NODE *root,int val)
      {
          NODE *temp;

          if(root==NULL)
          {

              return root;
          }
         if(val>root->info)
         {

             root->right=del_BST(root->right,val);
         }
         else if(val<root->info)
            {
            root->left=del_BST(root->left,val);
         }
         else if(val==root->info)
         {

             if(root->left==NULL)
             {

                 temp=root->right;
                 free(root);
                 return temp;
             }
             else if(root->right==NULL)
             {

                 temp=root->left;
                 free(temp);
                 return temp;
             }
              temp=root->right;

              while(temp!=NULL&&temp->left!=NULL)
              {

                  temp=temp->left;
              }
              root->info=temp->info;
              root->right=del_BST(root->right,temp->info);

         }
         return root;


      }


            int count_leaf_node(NODE *root)
            {

                static int count=0;
                NODE *temp=root;

                    if(temp!=NULL)
                    {



                    if(temp->left==NULL&&temp->right==NULL)
                    {

                        count++;

                    }

                       count_leaf_node(temp->left);
                        count_leaf_node(temp->right);

                    }
                return count;
            }
             int count_non_leaf_node(NODE *root)
            {

                static int count=0;
                NODE *temp=root;

                   if(temp!=NULL)
                   {



                    if(temp->left!=NULL||temp->right!=NULL)
                    {

                        count++;

                    }
                        count_non_leaf_node(temp->left);
                        count_non_leaf_node(temp->right);
                   }

                return count;

            }
                 NODE *copy(NODE *root)
                 {
                     NODE *newnode;

                         if(root!=NULL)
                       {


                        newnode=(NODE*)malloc(sizeof(NODE));
                        newnode->info=root->info;


                        newnode->left=copy(root->left);
                        newnode->right=copy(root->right);
                        return newnode;



                     }
                     else{



                     return NULL;
                     }
                 }
                  NODE *mirror(NODE *root)
                 {
                     NODE *newnode;

                         if(root!=NULL)
                       {


                        newnode=(NODE*)malloc(sizeof(NODE));
                        newnode->info=root->info;


                        newnode->left=mirror(root->right);
                        newnode->right=mirror(root->left);
                        return newnode;



                     }
                     else{



                     return NULL;
                     }
                 }


     void display_copy(NODE *root1)
     {


        if(root1!=NULL)
        {

             display_copy(root1->left);
             printf("%d\t",root1->info);
             display_copy(root1->right);

        }
     }

     void display_mirror(NODE *root1)
     {


        if(root1!=NULL)
        {

             display_mirror(root1->left);
             printf("%d\t",root1->info);
             display_mirror(root1->right);

        }
     }


            NODE*create_2(NODE*root1)
  {

      NODE *temp,*parent,*newnode;
      int i,n;
      printf("\n enter limit:");
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {

          newnode=(NODE*)malloc(sizeof(NODE));
          printf("\n enter value:");
          scanf("%d",&newnode->info);
          newnode->left=newnode->right=NULL;

          if(root1==NULL)
          {
              root1=newnode;


          }
          else{


          temp=root1;
          while(temp!=NULL)
          {

              parent=temp;
              if(newnode->info >= temp->info)
              {

                  temp=temp->right;
              }
              else{
                temp=temp->left;

              }

          }
           if(newnode->info>=parent->info)
           {

               parent->right=newnode;
           }
           else{
            parent->left=newnode;
           }
          }


      }
      return root1;
  }

   void inorder_1(NODE *root1)
    {
         if(root1!=NULL)
         {
        inorder_1(root1->left);
        printf("%d\t",root1->info);
        inorder_1(root1->right);
         }
    }

        NODE *compare_tree(NODE *root,NODE *root1)
        {
             static int f=0;
           NODE *temp=root,*temp1=root1;
            if(temp!=NULL||temp1!=NULL)
           {
               if(temp->info!=temp1->info)
               {

                f=1;
                return f;
               }

               compare_tree(temp->left,temp1->left);
               compare_tree(temp->right,temp1->right);
           }
              return f;

        }

         int compare(NODE *root,NODE *root1)
         {

             if(root==NULL&&root1==NULL)
             {

                 return 1;
             }
             else if(root!=NULL&&root1!=NULL)
             {

                 if(root->info==root1->info)
                 {

                     if(compare(root->left,root1->left))
                     {



                        return compare(root->right,root1->right);

                     }


                 }

             }

              return 0;

         }


         void main ()
         {

             NODE *root=NULL,*temp,*root1=NULL,*temp1;
             int ch,val,count,f,k;
             do{

                printf("\n1-create\n2-inorder\n3-preorder\n4-postorder\n5-search\n6-insert\n7-del_BST\n8-count_leaf_node\n9-count_non_leaf_node\n10-copyTree\n11-MirrorTree\n12-display_copy_tree\n13-display_mirror_tree\n14-create_second_tree\n15-display_second_tree\n16-compare_both_tree\n17-search_recursively\n18-compare1::");
                printf("\n enter choice :");
                scanf("%d",&ch);
                switch(ch)
                {

                    case 1 : root=create(root);
                             break;
                    case 2 : inorder(root);
                             break;
                    case 3 : preorder(root);
                             break;
                    case 4 : postorder(root);
                             break;

                    case 5 :  printf("\n enter num to search:");
                             scanf("%d",&val);
                             temp=search(root,val);
                             if(temp!=NULL)
                             {
                                 printf("\n found ");

                             }
                             else{
                                printf("\n not found:");

                             }
                             break;
                    case  6 : printf("\n enter value to insert :");
                             scanf("%d",&val);
                             root=insert(root,val);
                             break;
                    case 7 : printf("\n enter number to delete :");
                             scanf("%d",&val);
                             root=del_BST(root,val);
                             break;
                    case 8:  count=count_leaf_node(root);
                             printf("count = %d",count);
                             break;
                    case 9: count=count_non_leaf_node(root);
                             printf(" count = %d",count);
                             break;
                    case 10: temp1=copy(root);
                             break;
                    case 11: temp1=mirror(root);
                             break;
                    case 12 :display_copy(temp1);
                             break;
                    case 13 :display_mirror(temp1);
                             break;
                    case 14 :root1=create_2(root1);
                             break;
                    case 15:inorder_1(root1);
                            break;
                    case 16:f=compare_tree(root,root1);
                            if(f==1)
                            {

                                printf("\n Tree is not identical  ");

                            }
                            else{

                                printf("\n Tree is  identical");
                            }
                            break;
                    case 17: k=compare(root,root1);
                             if(k==1)
                             {
                                 printf("\n tree is same ");

                               }
                               else{

                                printf("\n tree is not same");
                               }
                               break;


                }
             }while(ch<18);


         }
