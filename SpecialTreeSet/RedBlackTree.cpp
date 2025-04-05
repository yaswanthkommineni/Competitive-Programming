class Solution {
public:

    class TreeNode {
    public:
        int val, cnt;
        TreeNode *left, *right, *parent;
        bool col;
        TreeNode(int value){
            val = value;
            cnt = 1;
            left = NULL;
            right = NULL;
            parent = NULL;
            col = false;
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
            
            node -> cnt = 1 + getCnt(node -> right) + getCnt(node -> left);
            
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
            
            node -> cnt = 1 + getCnt(node -> right) + getCnt(node -> left);

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
