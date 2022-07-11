#ifndef _AVL_TREE_H
#define _AVL_TREE_H

#include <functional>
#include <list>

template <typename T>
struct Node {
    T data;
    struct Node *parent;
    struct Node *right;
    struct Node *left;
    int height;
};

template <typename T>
class AvlTree {
public:
    AvlTree();
    ~AvlTree();

    bool Insert(const T &data);
    bool Erase(const T &data);
    bool Find(const T &data);
    bool Empty();
    void Clear();

private:
    int Height(struct Node<T> *node);
    void ModHeight(struct Node<T> *node);
    int Bias(struct Node<T> *node);
    void Replace(struct Node<T> *before, struct Node<T> *after);
    struct Node<T> *SearchNode(struct Node<T> *node, const T &data);
    struct Node<T> *SearchParentNode(struct Node<T> *node, const T &data);
    struct Node<T> *LeftMax(struct Node<T> *node);

    struct Node<T> *RotateR(struct Node<T> *node);
    struct Node<T> *RotateL(struct Node<T> *node);
    struct Node<T> *RotateRL(struct Node<T> *node);
    struct Node<T> *RotateLR(struct Node<T> *node);

    void BalanceInsert(struct Node<T> *node);
    void BalanceErase(struct Node<T> *node);

    int FuncDFS(struct Node<T> *node, std::function<int(struct Node<T> *)> func);

    struct Node<T> *root_;
    struct Node<T> *null_node_;
};

template <typename T>
AvlTree<T>::AvlTree()
{
    null_node_ = new struct Node<T>;
    null_node_->right = nullptr;
    null_node_->left = nullptr;
    null_node_->parent = nullptr;
    null_node_->height = 0;

    root_ = null_node_;
}

template <typename T>
AvlTree<T>::~AvlTree()
{
    Clear();
}

template <typename T>
bool
AvlTree<T>::Insert(const T &data)
{
    struct Node<T> *new_node = new struct Node<T>;
    new_node->data = data;
    new_node->height = 1;
    new_node->right = null_node_;
    new_node->left = null_node_;

    if (root_ == null_node_) {
        new_node->parent = null_node_;
        root_ = new_node;
        return true;
    }

    struct Node<T> *parent = SearchParentNode(root_, data);
    if (parent->data == data) {
        return false;
    }
    if (data < parent->data) {
        if (parent->left != null_node_) {
            return false;
        }
        parent->left = new_node;
    } else {
        if (parent->right != null_node_) {
            return false;
        }
        parent->right = new_node;
    }
    new_node->parent = parent;
    BalanceInsert(new_node);
    return true;
}

template <typename T>
bool
AvlTree<T>::Erase(const T &data)
{
    struct Node<T> *delete_node = SearchNode(root_, data);

    if (delete_node == null_node_) {
        return false;
    }

    if (delete_node->left == null_node_) {
        Replace(delete_node, delete_node->right);
        BalanceErase(delete_node->right);
        delete delete_node;
    } else {
        struct Node<T> *left_max_node = LeftMax(delete_node);
        delete_node->data = left_max_node->data;
        Replace(left_max_node, left_max_node->left);
        BalanceErase(left_max_node->left);
        delete left_max_node;
    }
    return true;
}

template <typename T>
bool
AvlTree<T>::Find(const T &data)
{
    if (SearchNode(root_, data) == null_node_) {
        return false;
    } else {
        return true;
    }
}

template <typename T>
bool
AvlTree<T>::Empty()
{
    if (root_ == null_node_) {
        return true;
    } else {
        return false;
    }
}

template <typename T>
void
AvlTree<T>::Clear()
{
    if (root_ != null_node_) {
        FuncDFS(root_, [](struct Node<T> *node) {
            delete node;
            return 0;
        });
        root_ = null_node_;
    }
}

template <typename T>
int
AvlTree<T>::Height(struct Node<T> *node)
{
    return node->height;
}

template <typename T>
void
AvlTree<T>::ModHeight(struct Node<T> *node)
{
    int height_right = Height(node->right);
    int height_left = Height(node->left);

    node->height = 1 + (height_right > height_left ? height_right : height_left);
}

template <typename T>
int
AvlTree<T>::Bias(struct Node<T> *node)
{
    return Height(node->left) - Height(node->right);
}

template <typename T>
struct Node<T> *
AvlTree<T>::SearchNode(struct Node<T> *node, const T &data)
{
    struct Node<T> *tmp = node;
    while ((tmp != null_node_) && (tmp->data != data)) {
        if (data < tmp->data) {
            tmp = tmp->left;
        } else {
            tmp = tmp->right;
        }
    }
    return tmp;
}

template <typename T>
struct Node<T> *
AvlTree<T>::SearchParentNode(struct Node<T> *node, const T &data)
{
    struct Node<T> *parent = node;
    struct Node<T> *tmp = data < node->data ? node->left : node->right;
    while ((tmp != null_node_) && (tmp->data != data)) {
        parent = tmp;
        if (data < tmp->data) {
            tmp = tmp->left;
        } else {
            tmp = tmp->right;
        }
    }
    return parent;
}

template <typename T>
struct Node<T> *
AvlTree<T>::LeftMax(struct Node<T> *node)
{
    struct Node<T> *left_max_node = node->left;
    while (left_max_node->right != null_node_) {
        left_max_node = left_max_node->right;
    }
    return left_max_node;
}

template <typename T>
void
AvlTree<T>::Replace(struct Node<T> *before, struct Node<T> *after)
{
    struct Node<T> *parent = before->parent;

    if (before == root_) {
        root_ = after;
    } else if (parent->left == before) {
        parent->left = after;
    } else {
        parent->right = after;
    }

    after->parent = parent;
}

template <typename T>
struct Node<T>*
AvlTree<T>::RotateR(struct Node<T> * node)
{
    struct Node<T> *left = node->left;
    Replace(node, left);
    node->left = left->right;
    if (left->right != null_node_) {
        left->right->parent = node;
    }
    left->right = node;
    node->parent = left;

    ModHeight(left->right);
    ModHeight(left);

    return left;
}

template <typename T>
struct Node<T>*
AvlTree<T>::RotateL(struct Node<T> * node)
{
    struct Node<T> *right = node->right;
    Replace(node, right);
    node->right = right->left;
    if (right->left != null_node_) {
        right->left->parent = node;
    }
    right->left = node;
    node->parent = right;

    ModHeight(right->left);
    ModHeight(right);

    return right;
}

template <typename T>
struct Node<T>*
AvlTree<T>::RotateRL(struct Node<T> * node)
{
    RotateR(node->right);
    return RotateL(node);
}

template <typename T>
struct Node<T>*
AvlTree<T>::RotateLR(struct Node<T> * node)
{
    RotateL(node->left);
    return RotateR(node->right);
}

template <typename T>
void
AvlTree<T>::BalanceInsert(struct Node<T> *node)
{
    struct Node<T> *target = node;
    while (target->parent != null_node_) {
        struct Node<T> *parent = target->parent;
        int height = parent->height;
        if (parent->left == target) {
            if (Bias(parent) == 2) {
                if (Bias(parent->left) >= 0) {
                    parent = RotateR(parent);
                } else {
                    parent = RotateLR(parent);
                }
            } else {
                ModHeight(parent);
            }
        } else {
            if (Bias(parent->right) == -2) {
                if (Bias(parent->right) <= 0) {
                    parent = RotateL(parent);
                } else {
                    parent = RotateRL(parent);
                }
            } else {
                ModHeight(parent);
            }
        }
        if (height == parent->height) {
            break;
        }
        target = parent;
    }
}

template <typename T>
void
AvlTree<T>::BalanceErase(struct Node<T> *node)
{
    struct Node<T> *target = node;
    while (target->parent != null_node_) {
        struct Node<T> *parent = target->parent;
        int height = parent->height;
        if (parent->right == target) {
            if (Bias(parent) == 2) {
                if (Bias(parent->left) >= 0) {
                    parent = RotateR(parent);
                } else {
                    parent = RotateLR(parent);
                }
            } else {
                ModHeight(parent);
            }
        } else {
            if (Bias(parent) == -2) {
                if (Bias(parent->right) <= 0) {
                    parent = RotateL(parent);
                } else {
                    parent = RotateRL(parent);
                }
            } else {
                ModHeight(parent);
            }
        }
        if (height == parent->height) {
            break;
        }
        target = parent;
    }
}

template <typename T>
int
AvlTree<T>::FuncDFS(struct Node<T> *node, std::function<int(struct Node<T> *)> func)
{
    int ret;
    std::list<struct Node<T> *> list;
    list.push_back(node);
    while (list.size() != 0) {
        struct Node<T> *back = list.back();
        list.pop_back();
        if (back->right != null_node_) {
            list.push_back(back->right);
        }
        if (back->left != null_node_) {
            list.push_back(back->left);
        }
        ret = func(back);
    }
    return ret;
}

#endif // _AVL_TREE_H