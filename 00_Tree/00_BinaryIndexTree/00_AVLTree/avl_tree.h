#ifndef _AVL_TREE_H
#define _AVL_TREE_H

template <typename T>
struct Node {
    T data;
    struct Node *parent;
    struct Node *right;
    struct Node *left;
    int height;
    int bias;
};

template <typename T>
class AvlTree {
public:
    AvlTree();
    ~AvlTree();

    bool Search(const T &data);
    bool Append(T data);
    bool Erase(const T &data);
private:
    int Bias(struct Node<T> *node);
};

#endif // _AVL_TREE_H