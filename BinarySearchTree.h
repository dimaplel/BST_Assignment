#ifndef ASD_2_4_BINARYSEARCHTREE_H
#define ASD_2_4_BINARYSEARCHTREE_H

#include <vector>
#include <iostream>

using std::vector, std::cout;

struct Data
{
    char call_sign;
    float combat_experience;
    float shooting_accuracy;
    int frags;
    Data()
    {
        call_sign = static_cast<char>(rand() % 26 + 65);
        combat_experience = static_cast<float>(rand()) / static_cast<float>(RAND_MAX / 8);
        shooting_accuracy = static_cast<float>(rand()) / static_cast<float>(RAND_MAX / 100);
        frags = rand() % 25;
    }
    ~Data() = default;

    bool operator<(const Data& secondSoldier) const
    {
        if(combat_experience != secondSoldier.combat_experience)
            return combat_experience < secondSoldier.combat_experience;
        if(shooting_accuracy != secondSoldier.shooting_accuracy)
            return shooting_accuracy < secondSoldier.shooting_accuracy;

        return frags < secondSoldier.frags;
    }
    bool operator==(const Data& secondSoldier) const
    {
        return(combat_experience == secondSoldier.combat_experience && shooting_accuracy == secondSoldier.shooting_accuracy
        && frags == secondSoldier.frags);
    }
};

struct Node
{
    Data data;
    Node* left;
    Node* right;
};

struct BinarySearchTree
{
    Node* root;

    BinarySearchTree();
    ~BinarySearchTree();
    void inorderTraversal(Node* node);
    Node* clear(Node* node);
    static Node* minValueNode(Node* node);
    Node* maxValueNode(Node* node);
    size_t sizeInner(Node* node);
    size_t heightInner(Node* curNode);
    Node* insertInner(Node* curNode, const Data& value);
    Node* findInner(Node* curNode, const Data& key);
    void findInRangeInner(vector<Data>& storage, Node* curNode, const Data &start, const Data &end);
    Node* eraseInner(Node* curNode, const Data& key);

    bool find(const Data &value);
    size_t findInRange(const Data& start, const Data& end);
    void insert(const Data &value);
    void erase(const Data& value);
    size_t size();
    size_t height();
    void print();
};
#endif //ASD_2_4_BINARYSEARCHTREE_H