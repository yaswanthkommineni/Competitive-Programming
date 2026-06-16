class Solution {
public:

static const int inf = 1e9;
class TreeNode {
public:
    int val, cnt, prefSum;
    TreeNode *left, *right, *parent;
    bool col;
    TreeNode(int value){
        val = value;
        cnt = 1;
        left = NULL;
        right = NULL;
        parent = NULL;
        col = false;
        prefSum = value;
    }
};

class RedBlackTree{
private:
    TreeNode *root;
    int getCnt(TreeNode *node){
        if(node != NULL){
            return node -> cnt;
        }
        return 0;
    }
    TreeNode* getClonedNode(TreeNode *curNode){
        TreeNode *node = new TreeNode(0);
        node -> val = curNode -> val;
        node -> cnt = curNode -> cnt;
        node -> right = NULL;
        node -> left = NULL;
        node -> parent = NULL;
        node -> col = curNode -> col;
        node -> prefSum = curNode -> prefSum;
        return node;
    }
    int getPrefSum(TreeNode *node){
        if(node != NULL){
            return node -> prefSum;
        }
        return 0;
    }
    void leftRotate(TreeNode *node){
        TreeNode *parent = node -> parent;
        if(parent == NULL) return;

        if(parent -> parent != NULL){
            if(parent -> parent -> left == parent){
                parent -> parent -> left = node;
            }
            if(parent -> parent -> right == parent){
                parent -> parent -> right = node;
            }
        }
        node -> parent = parent -> parent;

        TreeNode *leftChild = node -> left;

        node -> left = parent;
        parent -> parent = node;

        parent -> right = leftChild;
        if(leftChild != NULL) leftChild -> parent = parent;

        
        parent -> cnt = 1 + getCnt(parent -> right) + getCnt(parent -> left);

        parent -> prefSum = (parent -> val) + getPrefSum(parent -> right) + getPrefSum(parent -> left);
        
        node -> cnt = 1 + getCnt(node -> right) + getCnt(node -> left);

        node -> prefSum = (node -> val) + getPrefSum(node -> right) + getPrefSum(node -> left);
        
        if(root == parent){
            root = node;
        }

    }

    void rightRotate(TreeNode *node){
        TreeNode *parent = node -> parent;
        if(parent == NULL) return;
        TreeNode *rightChild = node -> right;

        if(parent -> parent != NULL){
            if(parent -> parent -> left == parent){
                parent -> parent -> left = node;
            }
            if(parent -> parent -> right == parent){
                parent -> parent -> right = node;
            }
        }
        node -> parent = parent -> parent;

        node -> right = parent;
        parent -> parent = node;

        parent -> left = rightChild;
        if(rightChild != NULL) rightChild -> parent = parent;

        parent -> cnt = 1 + getCnt(parent -> right) + getCnt(parent -> left);

        parent -> prefSum = (parent -> val) + getPrefSum(parent -> right) + getPrefSum(parent -> left);
        
        node -> cnt = 1 + getCnt(node -> right) + getCnt(node -> left);

        node -> prefSum = (node -> val) + getPrefSum(node -> right) + getPrefSum(node -> left);

        if(root == parent){
            root = node;
        }
    }


    void rebalance(TreeNode *node){
        if(node -> col == false){
                return;
        }

        if(node == root){
            node -> col = false;
            return;
        }

        if(!(node -> parent -> col)){
            return;
        }

        TreeNode *parent = node -> parent;
        TreeNode *grandParent = parent -> parent;

        TreeNode *newParent = NULL;

        if(grandParent -> left == parent){
            if(grandParent -> right != NULL && grandParent -> right -> col){
                grandParent -> col = true;
                grandParent -> left -> col = false;
                grandParent -> right -> col = false;
                rebalance(grandParent);
                return;
            }
            if(parent -> right == node){
                leftRotate(node);
                newParent = node;
            }
            else{
                newParent = parent;
            }
            rightRotate(newParent);
        }
        else{
            if(grandParent -> left != NULL && grandParent -> left -> col){
                grandParent -> col = true;
                grandParent -> left -> col = false;
                grandParent -> right -> col = false;
                rebalance(grandParent);
                return;
            }
            if(parent -> left == node){
                rightRotate(node);
                newParent = node;
            }
            else{
                newParent = parent;
            }
            leftRotate(newParent);
        }
        newParent -> col = false;
        if(newParent -> left){
            newParent -> left -> col = true;
        }
        if(newParent -> right){
            newParent -> right -> col = true;
        }
    }
public:
    RedBlackTree(){
        root = NULL;
    }
    void insert(int newValue){
        if(root == NULL){
            root = new TreeNode(newValue);
            return;
        }

        TreeNode *curNode = root, *newNode = new TreeNode(newValue);
        while(true){
            curNode -> cnt++;
            curNode -> prefSum += newValue;
            if(curNode -> val < newValue){
                if(curNode -> right != NULL){
                    curNode = curNode -> right;
                    continue;
                }
                curNode -> right = newNode;
                break;
            }
            else{
                if(curNode -> left != NULL){
                    curNode = curNode -> left;
                    continue;
                }
                curNode -> left = newNode;
                break;
            }
        }
        newNode -> parent = curNode;
        newNode -> col = true;
        rebalance(newNode);
    }
    int getPos(int value){
        if(root == NULL) return -1;
        TreeNode *curNode = root;
        int result = 0;
        while(curNode){
            if(curNode -> val < value){
                result += (getCnt(curNode -> left)+1);
                curNode = curNode -> right;
                continue;
            }
            curNode = curNode -> left;
        }
        return result;
    }
    int getValAt(int index){
        if(root == NULL) return -1;
        TreeNode *curNode = root;
        int rem = index + 1;
        while(curNode){
            int leftCount = 0;
            if(curNode -> left != NULL){
                leftCount = (curNode -> left -> cnt);
            }
            if(rem <= leftCount){
                curNode = curNode -> left;
            }
            else if(rem == leftCount + 1){
                return curNode -> val;
            }
            else{
                curNode = curNode -> right;
                rem -= (leftCount + 1);
            }
        }
        return -inf;
    }
    int getPrefSum(int index){
        if(root == NULL) return -1;
        TreeNode *curNode = root;
        int rem = index + 1;
        int result = 0;
        while(curNode){
            int leftCount = 0;
            if(curNode -> left != NULL){
                leftCount = (curNode -> left -> cnt);
            }
            if(rem <= leftCount){
                curNode = curNode -> left;
            }
            else if(rem == leftCount + 1){
                if(curNode -> left != NULL){
                    result += curNode -> left -> prefSum;
                }
                result += curNode -> val;
                return result;
            }
            else{
                result += curNode -> prefSum;
                curNode = curNode -> right;
                rem -= (leftCount + 1);
                result -= curNode -> prefSum;
            }
        }
        return -inf;
    }
    void freeUpDfs(TreeNode *node){
        if(node -> right != NULL){
            freeUpDfs(node -> right);
        }
        if(node -> left != NULL){
            freeUpDfs(node -> left);
        }
        delete(node);
    }
    void remove(int value){
        if(root == NULL) return;
        TreeNode *z = root;
        while(z != NULL){
            if(z -> val < value) z = z -> right;
            else if(z -> val > value) z = z -> left;
            else break;
        }
        if(z == NULL) return;
        TreeNode *y = z;
        bool yWasBlack = !y -> col;
        TreeNode *x = NULL;
        TreeNode *fixParent = NULL;
        bool fixLeft = false;
        if(z -> left == NULL || z -> right == NULL){
            x = (z -> left != NULL) ? z -> left : z -> right;
            fixParent = z -> parent;
            fixLeft = (fixParent != NULL && fixParent -> left == z);
            if(z -> parent == NULL) root = x;
            else if(fixLeft) fixParent -> left = x;
            else fixParent -> right = x;
            if(x != NULL) x -> parent = z -> parent;
            TreeNode *p = fixParent;
            while(p != NULL){
                p -> cnt = 1 + getCnt(p -> left) + getCnt(p -> right);
                p -> prefSum = p -> val + getPrefSum(p -> left) + getPrefSum(p -> right);
                p = p -> parent;
            }
            delete z;
        }
        else{
            y = z -> right;
            while(y -> left != NULL) y = y -> left;
            yWasBlack = !y -> col;
            x = y -> right;
            if(y -> parent == z){
                fixParent = y;
                fixLeft = false;
                if(x != NULL) x -> parent = y;
            }
            else{
                fixParent = y -> parent;
                fixLeft = (fixParent -> left == y);
                if(fixLeft) fixParent -> left = x;
                else fixParent -> right = x;
                if(x != NULL) x -> parent = fixParent;
                TreeNode *p = fixParent;
                while(p != NULL){
                    p -> cnt = 1 + getCnt(p -> left) + getCnt(p -> right);
                    p -> prefSum = p -> val + getPrefSum(p -> left) + getPrefSum(p -> right);
                    p = p -> parent;
                }
                y -> right = z -> right;
                y -> right -> parent = y;
            }
            TreeNode *zParent = z -> parent;
            bool zLeft = (zParent != NULL && zParent -> left == z);
            if(zParent == NULL) root = y;
            else if(zLeft) zParent -> left = y;
            else zParent -> right = y;
            y -> parent = zParent;
            y -> left = z -> left;
            y -> left -> parent = y;
            y -> col = z -> col;
            TreeNode *p = y;
            while(p != NULL){
                p -> cnt = 1 + getCnt(p -> left) + getCnt(p -> right);
                p -> prefSum = p -> val + getPrefSum(p -> left) + getPrefSum(p -> right);
                p = p -> parent;
            }
            delete z;
        }
        if(yWasBlack){
            if(x != NULL && x -> parent != NULL){
                rebalanceRemove(x -> parent, x == x -> parent -> left);
            }
            else if(x != NULL){
                x -> col = false;
            }
            else if(fixParent != NULL){
                rebalanceRemove(fixParent, fixLeft);
            }
        }
    }
     void rebalanceRemove(TreeNode *parent, bool isLeft){
        TreeNode *node = isLeft ? parent -> left : parent -> right;
        while(parent != NULL && parent != root && (node == NULL || node -> col == false)){
            if(isLeft){
                TreeNode *sibling = parent -> right;
                if(sibling != NULL && sibling -> col){
                    sibling -> col = false;
                    parent -> col = true;
                    leftRotate(sibling);
                    sibling = parent -> right;
                }
                if((sibling == NULL || sibling -> left == NULL || !sibling -> left -> col) &&
                   (sibling == NULL || sibling -> right == NULL || !sibling -> right -> col)){
                    if(sibling != NULL) sibling -> col = true;
                    node = parent;
                    parent = parent -> parent;
                    isLeft = (parent != NULL && parent -> left == node);
                }
                else{
                    if(sibling == NULL || sibling -> right == NULL || !sibling -> right -> col){
                        if(sibling != NULL && sibling -> left != NULL) sibling -> left -> col = false;
                        if(sibling != NULL) sibling -> col = true;
                        rightRotate(sibling -> left);
                        sibling = parent -> right;
                    }
                    if(sibling != NULL) sibling -> col = parent -> col;
                    parent -> col = false;
                    if(sibling != NULL && sibling -> right != NULL) sibling -> right -> col = false;
                    leftRotate(sibling);
                    node = root;
                    parent = NULL;
                }
            }
            else{
                TreeNode *sibling = parent -> left;
                if(sibling != NULL && sibling -> col){
                    sibling -> col = false;
                    parent -> col = true;
                    rightRotate(sibling);
                    sibling = parent -> left;
                }
                if((sibling == NULL || sibling -> right == NULL || !sibling -> right -> col) &&
                   (sibling == NULL || sibling -> left == NULL || !sibling -> left -> col)){
                    if(sibling != NULL) sibling -> col = true;
                    node = parent;
                    parent = parent -> parent;
                    isLeft = (parent != NULL && parent -> left == node);
                }
                else{
                    if(sibling == NULL || sibling -> left == NULL || !sibling -> left -> col){
                        if(sibling != NULL && sibling -> right != NULL) sibling -> right -> col = false;
                        if(sibling != NULL) sibling -> col = true;
                        leftRotate(sibling -> right);
                        sibling = parent -> left;
                    }
                    if(sibling != NULL) sibling -> col = parent -> col;
                    parent -> col = false;
                    if(sibling != NULL && sibling -> left != NULL) sibling -> left -> col = false;
                    rightRotate(sibling);
                    node = root;
                    parent = NULL;
                }
            }
        }
        if(node != NULL) node -> col = false;
    }
    void freeUp(){
        if(root == NULL) return;
        freeUpDfs(root);
    }
    TreeNode* cloneDfs(TreeNode* node){
        if(node == NULL){
            return NULL;
        }
        TreeNode* curNode = getClonedNode(node);
        curNode -> left = cloneDfs(node -> left);
        if(curNode -> left != NULL){
            curNode -> left -> parent = curNode;
        }
        curNode -> right = cloneDfs(node -> right);
        if(curNode -> right != NULL){
            curNode -> right -> parent = curNode;
        }
        return curNode;
    }
    RedBlackTree* clone(){
        auto newRoot = cloneDfs(root);
        RedBlackTree* rb = new RedBlackTree();
        rb -> root = newRoot;
        return rb;
    }
};


    vector<int> countSmaller(vector<int>& nums) {
        int siz = (int)nums.size();
        vector <int> result(siz,0);
        RedBlackTree *tree = new RedBlackTree();
        for(int i=siz-1;i>=0;i--){
            result[i] = max((int)0,tree->getPos(nums[i]));
            tree->insert(nums[i]);
        }
        return result;
    }
};
