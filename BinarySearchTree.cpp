#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree():
        root(nullptr){}

BinarySearchTree::~BinarySearchTree()
{
    clear(root);
}

Node *BinarySearchTree::minValueNode(Node *node)
{
    Node* current = node;

    while(current && current->left)
        current = current->left;

    return current;
}

void BinarySearchTree::inorderTraversal(Node *node)
{
    if(!node)
        return;
    inorderTraversal(node->left);
    cout << node->data.combat_experience << "->";
    inorderTraversal(node->right);
}

size_t BinarySearchTree::heightInner(Node* curNode)
{
    if(!curNode)
        return -1;

    size_t leftHeight = heightInner(curNode->left);
    size_t rightHeight = heightInner(curNode->right);

    if(leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

Node *BinarySearchTree::clear(Node *node)
{
    if(node == nullptr)
        return node;
    {
        clear(node->left);
        clear(node->right);
        delete node;
    }
    return nullptr;
}

size_t BinarySearchTree::sizeInner(Node* node)
{
    if (!node)
        return 0;
    else
        return (sizeInner(node->left) + 1 + sizeInner(node->right));
}

Node *BinarySearchTree::insertInner(Node *curNode, const Data &value)
{
    if(!curNode)
    {
        curNode = new Node;
        curNode->data = value;
        curNode->left = curNode->right = nullptr;
        return curNode;
    }
    if(value < curNode->data)
        curNode->left = insertInner(curNode->left, value);
    else if(curNode->data < value)
        curNode->right = insertInner(curNode->right, value);
    return curNode;
}

Node *BinarySearchTree::findInner(Node *curNode, const Data &key)
{
    if(curNode == nullptr || curNode->data == key)
        return curNode;
    if(key < curNode->data)
        return findInner(curNode->left, key);
    else
        return findInner(curNode->right, key);
}

Node *BinarySearchTree::eraseInner(Node *curNode, const Data &key)
{
    if(!curNode)
        return curNode;

    if(key < curNode->data)
        curNode->left = eraseInner(curNode->left, key);
    else if(curNode->data < key)
        curNode->right = eraseInner(curNode->right, key);
    else if(curNode->left && curNode->right)
    {
        Node* temp = minValueNode(curNode->right);
        curNode->data = temp->data;
        curNode->right = eraseInner(curNode->right, curNode->data);
    }
    else
    {
        Node* temp = curNode;
        if(!curNode->left)
            curNode = curNode->right;
        else if(!curNode->right)
            curNode = curNode->left;
        delete temp;
    }

    return curNode;
}

void BinarySearchTree::findInRangeInner(vector<Data>& storage, Node* curNode, const Data &start, const Data &end)
{
    if(!curNode)
        return;

    else if(curNode->data < start)
        findInRangeInner(storage, curNode->right, start, end);
    else if(end < curNode->data)
        findInRangeInner(storage, curNode->left, start, end);
    else
    {
        storage.push_back(curNode->data);
        findInRangeInner(storage, curNode->left, start, end);
        findInRangeInner(storage, curNode->right, start, end);
    }
}

bool BinarySearchTree::find(const Data &value)
{
    return findInner(root, value);
}

void BinarySearchTree::insert(const Data& value)
{
    root = insertInner(root, value);
}

void BinarySearchTree::erase(const Data& value)
{
    root = eraseInner(root, value);
}

Node *BinarySearchTree::maxValueNode(Node *node)
{
    if(node == nullptr || !node->right)
        return node;
    return maxValueNode(node->right);
}

size_t BinarySearchTree::size()
{
    return sizeInner(root);
}

void BinarySearchTree::print()
{
    inorderTraversal(root);
}

size_t BinarySearchTree::height()
{
    return heightInner(root);
}

size_t BinarySearchTree::findInRange(const Data &start, const Data &end)
{
    vector<Data> storage;
    findInRangeInner(storage, root, start, end);
    return storage.size();
}