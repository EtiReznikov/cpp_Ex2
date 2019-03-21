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
/*
A function that receives a number and creates a new leaf.
*/
ariel::Tree::Node* ariel::Tree::creatLeaf(int i)
{
    Node* n=new Node();
    n->value=i;
    n->left=NULL;
    n->right=NULL;

    return n;
}
/*
 A function that receives a number and use the 'insert_node' function to add this to the tree.
 Throws exception if this number arleady in the tree.
*/
 void ariel::Tree::insert(int i)
 {
      if (contains(i))
    {
        throw "The tree contains this number";
    }
     insert_node(i,tree_root);
 }
 /*
 A function that receives a number and a node(the root of the subtree),creat new leaf and add it to right place at the subtree.
*/
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

 /*
 A function that receives a node(the root of the subtree) print the numbers in the subtree inorder.
 Throws exception if the tree is empty
*/
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
    throw "the tree is empty";
   }
}

/*
 A function that print the all tree inorder, using the 'printinorder' function with the root of the tree.
*/
void ariel::Tree::print()
{
  printinorder(tree_root);
}

/*
  A function that receives a number and use the 'contains_node' function to check if this number is in the tree.
*/
 bool ariel::Tree:: contains(int i)
 {
   return contains_node(i,tree_root);
 }

 /*
  A function that receives a number and a node(the root of the subtree) and check if this number is in the subtreetree.
*/
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

 /*
 A function that receives a number and use the 'remove_node' function to remove this number from the tree.
 Throws exception if this number is not in the tree.
*/
  void ariel::Tree::remove(int i)
  {
    if (!contains(i))
    {
        throw "The tree does not contains this number";
    }
   remove_node(i, tree_root);
  }


/*
 A function that receives a number and a node(the root of the subtree),
 and send it to the 'remove_match' function that removes the leaf that contains the number and arranges the tree
*/
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

/*
 A function that removes the root of the tree and arranges the tree
*/
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

/*
 A function that receives a node to remove, a node that is the parnet of the first node, and bool variable that say to the function if this is a left child.
 Removes the match node from to tree and arranges it.
*/
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

/*
A function that use the 'findsmallest_node' function to find the smallest number in the tree
*/
int ariel::Tree::findsmallest ()
{
   return findsmallest_node (tree_root);
}

/*
 A function that receives a node(the root of the subtree) and find the smallest number in the subtree
 Throws exception if the tree is empty
 */
 int ariel::Tree::findsmallest_node (Node* n)
 {
  if (tree_root==NULL)
  {
    throw "The tree is empty";
  }
 
  if (n->left != NULL)
  {
    return findsmallest_node(n->left);
  }

  return n->value;
      
 }
  
/*
 A function that receives a node(the root of the subtree) and remove all the sub tree.
 */
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

/*
  A function that return the value of the root
  Throws exception if the tree is empty
*/
int ariel::Tree::root()
{
    if(tree_root==NULL)
    {
        throw "The tree is empty";
    }
    return tree_root->value;
}

/*
  A function that return the size of the tree using the 'size_subtree' function
*/
int ariel::Tree::size()
{
    return size_subtree(tree_root);
}

/*
 A function that receives a node(the root of the subtree) and return the size of this subtree
 */
int ariel::Tree::size_subtree(Node* n)
{
    if (n == NULL) 
    {
        return 0; 
    }
    return(size_subtree(n->left) + 1 + size_subtree(n->right));     
}

/*
  A function that receives a value and return the node that contains this value using the 'findnode' function
*/

ariel::Tree::Node* ariel::Tree::findkey(int i)
{
   return findnode(i, tree_root);
}

/*
 A function that receives a node(the root of the subtree) and a n value, and return the node that contains this value
*/
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

/*
 A function that receives a value, find the node that contains this value using the 'findkey' function, and return the value of it left child
 Throws exception if this leaf has no left children
*/
int ariel::Tree::left(int i)
{
    Node* current=findkey(i);
    if (current->left==NULL)
    {
        throw "This leaf has no left children";
    }
    return current->left->value;
}

/*
 A function that receives a value, find the node that contains this value using the 'findkey' function, and return the value of it right child
 Throws exception if this leaf has no right children
*/
int ariel::Tree::right(int i)
{
    Node* current=findkey(i);
    if (current->right==NULL)
    {
        throw "This leaf has no left children";
    }
    return current->right->value;
}

/*
 A function that receives a value, find the node that contains this value using the 'findkey' function, 
 find this node parent and return the value of the parent
 Throws exception if this is the root (root has no parent)
*/
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
 /*
 A function that receives a value and node, 
 return this node parent
*/    
 ariel::Tree:: Node* ariel::Tree::findparent(int i, Node* n)
 {
   
     if (n == NULL)
     {
       return NULL;
     }

    if(n->left == NULL && n->right == NULL)
    {
       return NULL;
    }

    if( (n->left != NULL && n->left->value == i)|| (n->right != NULL && n->right->value == i))
    {
       return n;
    }

    if(n->value > i)
    {
       return findparent(i,n->left);
    }

    if(n->value < i)
    {
       return findparent(i,n->right);
    }

    return NULL;
 }



  