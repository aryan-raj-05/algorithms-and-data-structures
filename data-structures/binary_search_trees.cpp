template <typename T>
class BinarySearchTree {
private:
    class Node {
    public:
        T item;
        Node *left;
        Node *right;
        Node(): left(nullptr), right(nullptr) {}
        Node(T val): item(val), left(nullptr), right(nullptr) {}
        Node(T val, Node *l, Node *r): item(val), left(l), right(r) {}
    };

    Node *root;

public:
    BinarySearchTree(): root(nullptr) {}

    void insert(const T& value) {
        root = auxInsert(root, value);
    }

    bool search(const T& value) {
        return auxSearch(root, value);
    }

    void remove(T value) {
        root = auxRemove(root, value);
    }

    ~BinarySearchTree() {
        auxFree(root);
    }

private:
    Node *auxInsert(Node *r, const T& value) {
        if (r == nullptr) r = new Node(value);
        else if ((r->item) > value) r->left = auxInsert(r->left, value);
        else r->right = auxInsert(r->right, value);
        return r;
    }

    bool auxSearch(Node *r, const T& value) {
        if (r == nullptr) return false;
        if (r->item == value) return true;
        else if (r->item > value) return auxSearch(r->left, value);
        else return auxSearch(r->right, value);
    }

    Node *minValueNode(Node *node) {
        Node *current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    Node *auxRemove(Node *r, const T& value) {
        if (r == nullptr) return nullptr;

        if (value < r->item) r->left = auxRemove(r->left, value);
        else if (value > r->item) r->right = auxRemove(r->right, value);
        else {
            if (r->left == nullptr) {
                Node *tmp = r->right;
                delete r;
                return tmp;
            } else if (r->right == nullptr) {
                Node *tmp = r->left;
                delete r;
                return tmp;
            }

            Node *successor = minValueNode(r->right);
            r->item = successor->item;
            r->right = auxRemove(r->right, successor->item);
        }

        return r;
    }

    void auxFree(Node *r) {
        if (r == nullptr) return;
        auxFree(r->left);
        auxFree(r->right);
        delete r;
    }
};
