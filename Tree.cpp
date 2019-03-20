#include <iostream>
#include "Tree.hpp"
using namespace std;

/*
Constructor
*/
ariel::Tree::Tree()
{
    tree_root=NULL;
}
/*
Destructor
*/
ariel::Tree::~Tree()
{
    remove_sub_tree(tree_root);
}
ariel::Tree::Node* ariel::Tree::creatLeaf(int i)
{
    Node* n=new Node();
    n->value=i;
    n->left=NULL;
    n->right=NULL;

    return n;
}
 void ariel::Tree::insert(int i)
 {
      if (contains(i))
    {
        throw "The tree contains this number";
    }
     insert_node(i,tree_root);
 }
void ariel::Tree::insert_node(int i, Node* n)
{
   if(tree_root==NULL)
   {
     tree_root=creatLeaf(i);
   }
   else if (i<n->value)
   {
     if (n->left!=NULL)  
     {
       insert_node(i,n->left);
     }
     else
     {
     n->left=creatLeaf(i);
     }
   }
   else if (i>n->value)
   {
     if (n->right!=NULL)
     {
       insert_node(i,n->right);
     }
     else
     {
     n->right=creatLeaf(i);
     }
   }
}
void ariel::Tree::printinorder(Node* n)
{
   if (tree_root !=NULL)
   {
     if (n->left !=NULL)
     {
       printinorder(n->left);
     }
     cout <<n->value<<" ";
     if (n->right !=NULL)
     {
      printinorder(n->right);
     } 
   }
   else
   {
    cout <<"Tree is empty\n";
   }
}
void ariel::Tree::print()
{
  printinorder(tree_root);
}
 bool ariel::Tree:: contains(int i)
 {
   return contains_node(i,tree_root);
 }
 bool ariel::Tree:: contains_node(int i,Node* n)
 {
    if (n!= NULL)
    {
       if(n->value==i)
       {
           return true;
       }
       else
       {
           if (i< n->value)
           {
               return contains_node (i, n->left);
           }
           else
           {
               return contains_node (i, n->right);
           }
       }
    }
    return false;
 }

void ariel::Tree::remove_node(int i, Node* n)
{
  if (tree_root!=NULL)
  {
      if (tree_root->value==i)
      {
          removeroot();
      }
      else
      {
        if (i<n->value && n->left!=NULL)
        {
            if (n->left->value==i)
            {
                remove_match(n, n->left, true);
            }
            else
            {
                remove_node(i, n->left);
            }
            
        }
        else if (i>n->value && n->right!=NULL){
             if (n->right->value==i)
            {
                remove_match(n, n->right, false);
            }
            else
            {
                remove_node(i, n->right);
            }
        }
      }
      
  }
}
  void ariel::Tree::remove(int i)
  {
    if (!contains(i))
    {
        throw "The tree does not contains this number";
    }
   remove_node(i, tree_root);
  }

void ariel::Tree::removeroot()
{
    if (tree_root!=NULL)
    {
        Node* toDelete=tree_root;
        int rootval= tree_root->value;
        int smallest;

        if (tree_root->left == NULL && tree_root->right== NULL)
        {
            tree_root= NULL;
            delete toDelete;
        }
        else if (tree_root->left== NULL && tree_root->right!= NULL)
        {
            tree_root=tree_root->right;
            toDelete->right=NULL;
            delete toDelete;
        }
        else if (tree_root->left!= NULL && tree_root->right== NULL)
        {
            tree_root=tree_root->left;
            toDelete->left=NULL;
            delete toDelete;
        }
        else
        {
            smallest=findsmallest_node(tree_root->right);
            remove_node(smallest, tree_root);
            tree_root->value=smallest;
        }
    }
}
  int ariel::Tree::findsmallest ()
  {
   return findsmallest_node (tree_root);
  }

 int ariel::Tree::findsmallest_node (Node* n)
 {
  if (tree_root==NULL)
  {
      return -1000;
  }
 
   if (n->left != NULL)
   {
       return findsmallest_node(n->left);
    }
    
  return n->value;
      
}
  
  void ariel::Tree::remove_match(Node* p, Node* match, bool left)
  {
      if (tree_root != NULL)
      {
          Node* toDelete;
          int match_key=match->value;
          int smallet;

          if (match->left==NULL && match->right==NULL)
          {
              toDelete=match;
              left==true? p->left=NULL : p->right =NULL;
              delete toDelete;
          }
          else if (match->left==NULL && match->right!=NULL){
              left==true ? p->left=match->right: p->right=match->right;
              toDelete=match;
              delete toDelete;
          }
            else if (match->left!=NULL && match->right==NULL){
              left==true ? p->left=match->left: p->right=match->left;
              toDelete=match;
              delete toDelete;
          }
          else
          {
              smallet=findsmallest_node(match->right);
              remove_node(smallet, match);
              match->value=smallet;
          }
          
      }
  }

    void ariel::Tree::remove_sub_tree(Node* n)
    {
        if (n!= NULL)
        {
            if (n->left != NULL)
            {
                remove_sub_tree(n->left);
            }
             if (n->right != NULL)
            {
                remove_sub_tree(n->right);
            }
            delete n;
        }
    }

  

   int ariel::Tree::root()
   {
       return tree_root->value;
   }
    int ariel::Tree::size_sub_tree(Node* n)
    {
        if (n == NULL) 
        {
            return 0; 
        }
         
        
        return(size_sub_tree(n->left) + 1 + size_sub_tree(n->right)); 
        
        
    }

    int ariel::Tree::size()
    {
        return size_sub_tree(tree_root);
    }

     ariel::Tree::Node* ariel::Tree::findnode(int i, Node* n)
     {
         if (n !=NULL)
         {
             if(n->value==i)
             {
                 return n;
             }
             else
             {
                 if (i<n->value)
                 {
                     return findnode(i,n->left);
                 }
                 else
                 {
                     return findnode(i,n->right);
                 }
                 
             }
             

         }
         return NULL;
     }
    ariel::Tree::Node* ariel::Tree::findkey(int i)
    {
    return findnode(i, tree_root);
    }

      int ariel::Tree::left(int i)
      {
          Node* current=findkey(i);
          if (current->left==NULL)
          {
             throw "This leaf has no left children";
          }
          return current->left->value;
      }
    int ariel::Tree::right(int i)
      {
          Node* current=findkey(i);
          if (current->right==NULL)
          {
              throw "This leaf has no left children";
          }
          return current->right->value;
      }
     
 ariel::Tree:: Node* ariel::Tree::findparent(int i, Node* n)
 {
   
     if (n == NULL)
       return NULL;

    if(n->left == NULL && n->right == NULL)
       return NULL;

    if( (n->left != NULL && n->left->value == i)
        || (n->right != NULL && n->right->value == i))
       return n;

    if(n->value > i)
       return findparent(i,n->left);

    if(n->value < i)
       return findparent(i,n->right);

    return NULL;
 }

  int ariel::Tree::parent(int i)
  {
      Node* current=findnode(i,tree_root);
      if (current==tree_root)
          {
             throw "The root has no parent";
          }
      Node* parent=findparent(i,tree_root);
       
      return parent->value;
  }

  