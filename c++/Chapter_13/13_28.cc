#include <string>

class TreeNode {
    public:
        TreeNode() : value("empty"), count(new int(1)), left(nullptr), right(nullptr) {};
        TreeNode(const TreeNode &org) : value(org.value), count(org.count), left(org.left), right(org.right) { ++*count; };
        TreeNode& operator=(TreeNode &org) {
            if (--*count == 0) {
                if (left) {
                    delete left;
                    left = nullptr;
                }
                if (right) {
                    delete right;
                    right = nullptr;
                }
                delete count;
                count = nullptr;
            }
            value = org.value;
            left = org.left;
            right = org.right;
            count = org.count;
            ++*count;
        };
        ~TreeNode() {
            if (--*count == 0) {
                if (left) {
                    delete left;
                    left = nullptr;
                }
                if (right) {
                    delete right;
                    right = nullptr;
                }
                delete count;
                count = nullptr;
            }
        };
    private:
        std::string value;
        int *count;
        TreeNode *left;
        TreeNode *right;
};

class BinStrTree {
    public:
        BinStrTree() : root(new TreeNode()) {};
        BinStrTree(const BinStrTree& org) root(new TreeNode(*org.root)) {};
        BinStrTree& operator=(BinStrTree& org) {
            TreeNode* tmp = new TreeNode(*org.root);
            if (root)
                delete root;
            root = tmp;
            return *this;
        };
    private:
        TreeNode *root;
};
