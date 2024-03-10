#include <iostream>

class TreeNode
{
public:
    friend std::ostream &operator<<(std::ostream &os, const TreeNode &obj);
    friend std::ostream &operator<<(std::ostream &os, const TreeNode *obj);

    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : value{val}, left{NULL}, right{NULL} {};
};

std::ostream &operator<<(std::ostream &os, const TreeNode &obj)
{
    os << obj.value;
    return os;
}

std::ostream &operator<<(std::ostream &os, const TreeNode *obj)
{
    if (obj == NULL)
        os << "Not Found";
    else
        os << obj->value;
    return os;
}

class BinarySearchTree
{
private:
    void iOTraverse(TreeNode *node);

public:
    TreeNode *root;

    BinarySearchTree(int value);
    TreeNode *lookup(int x);
    void insert(int num);
    void remove(int num);
    void inOrderTraverse() { iOTraverse(root); }
};

BinarySearchTree::BinarySearchTree(int value) { root = new TreeNode(value); }

TreeNode *BinarySearchTree::lookup(int x)
{
    TreeNode *ptr = root;
    while (ptr != NULL)
    {
        if (ptr->value == x)
            return ptr;
        else if (x < ptr->value)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    return NULL;
}

void BinarySearchTree::remove(int num)
{
}

void BinarySearchTree::insert(int num)
{
    TreeNode *node = new TreeNode(num);
    TreeNode *ptr = root;
    while (ptr != NULL)
    {
        if (node->value < ptr->value)
        {
            if (ptr->left == NULL)
            {
                ptr->left = node;
                break;
            }
            else
                ptr = ptr->left;
        }
        else if (node->value >= ptr->value)
        {
            if (ptr->right == NULL)
            {
                ptr->right = node;
                break;
            }
            else
            {
                ptr = ptr->right;
            }
        }
    }
}

void BinarySearchTree::iOTraverse(TreeNode *node)
{
    if (node == NULL)
        return;
    iOTraverse(node->left);
    std::cout << node << " ";
    iOTraverse(node->right);
}

int main()
{
    BinarySearchTree bst{9};
    bst.insert(4);
    bst.insert(20);
    bst.insert(1);
    bst.insert(6);
    bst.insert(15);
    bst.insert(170);
    bst.inOrderTraverse();
    std::cout << std::endl;
    std::cout << bst.lookup(20) << std::endl;
    std::cout << bst.lookup(2) << std::endl;
    return 1;
}