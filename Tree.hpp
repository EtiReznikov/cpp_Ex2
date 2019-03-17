namespace ariel{
class Tree
{
  private:
    struct Node
    {
      int value;
       Node* left;
       Node* right;
    };

    Node* tree_root;

    void insert_node(int i, Node* n);
    void printinorder(Node* n);
    bool contains_node(int i,Node* n);
    void remove_node(int i, Node* n);
    void removeroot();
    int findsmallest_node (Node* n);
    void remove_match(Node* p, Node* match, bool left);
    Node* creatLeaf(int i);
    void remove_sub_tree(Node* n);
    int size_sub_tree(Node* n);
    Node* findnode(int i, Node* n);
    Node* findparent(int i, Node* n);
    
    
  public:

    Tree();
    ~Tree();
    void insert(int i);
    void remove(int i);
    int size();
    bool contains(int i);
    int root();
    int parent(int i);
    int left(int i);
    int right(int i);
    void print();
    Node* findkey(int i);

    int findsmallest();
};
}