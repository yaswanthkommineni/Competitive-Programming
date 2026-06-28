#include <bits/stdc++.h>
using namespace std;
typedef int ll;

/*
Approach:
Segment tree where nodes represent the ranges, and at each node, we store the indexes who have this range
Purpose:
Can answer queries like Number of numbers <= k in a[l..r] in log(n)
Can answer queries like kth smallest in a[l..r] in log(n) 
*/

class IndexTreeNode{
public:
    // if the index was taken from the leftNode
    vector <int> indexes, mapLeft, mapRight;
    IndexTreeNode *left;
    IndexTreeNode *right;
    IndexTreeNode(){
        left = NULL;
        right = NULL;
    }
};

class IndexTree{
public:
    IndexTreeNode *root;
    vector < vector <int>> indMapper;
    int mx;
    // numbers should be continous from 0 to maxVal
    IndexTree(vector <int> &v, int maxVal){
        indMapper = vector < vector <int>> (maxVal+1, vector <int> ());
        for(int i=0;i<(int)v.size();i++){
            indMapper[v[i]].push_back(i);
        }
        mx = maxVal;
        root = build(0, maxVal);
    }
    IndexTreeNode *build(int l, int r){
        if(r < l){
            return NULL;
        }
        IndexTreeNode *curNode = new IndexTreeNode();
        if(l == r){
            for(auto &x : indMapper[l]){
                (curNode -> indexes).push_back(x);
            }
            return curNode;
        }
        int mid = (l+r)/2;
        auto leftNode = build(l,mid);
        auto rightNode = build(mid+1,r);

        curNode -> left = leftNode;
        curNode -> right = rightNode;

        int a = 0, b = 0;
        while(a < (leftNode ->indexes).size() && b < (rightNode-> indexes).size()){
            if((leftNode->indexes)[a] < (rightNode->indexes)[b]){
                (curNode->indexes).push_back((leftNode->indexes)[a]);
                (curNode->mapLeft).push_back(a);
                (curNode->mapRight).push_back(b-1);
                a++;
            }
            else{
                (curNode->indexes).push_back((rightNode->indexes)[b]);
                (curNode->mapLeft).push_back(a-1);
                (curNode->mapRight).push_back(b);
                b++;
            }
        }
        while(a < (leftNode ->indexes).size()){
            (curNode->indexes).push_back((leftNode->indexes)[a]);
            (curNode->mapLeft).push_back(a);
            (curNode->mapRight).push_back(b-1);
            a++;
        }
        while(b < (rightNode-> indexes).size()){
            (curNode->indexes).push_back((rightNode->indexes)[b]);
            (curNode->mapLeft).push_back(a-1);
            (curNode->mapRight).push_back(b);
            b++;
        }
        return curNode;
    }
    int findLessIn(int l, int r, int k){
        int curLeft = 0, curRight = mx;
        auto curNode = root;
        int ans = 0;
        while(true){
            if(l > r){
                break;
            }
            if(curLeft == curRight){
                if(curLeft <= k){
                    ans += (r - l) + 1;
                }
                break;
            }
            int mid = (curLeft + curRight)/2;
            int leftMapped = (curNode -> mapLeft)[l];
            int rightMapped = (curNode -> mapLeft)[r];
            int leftl, leftr;
            // check if k belongs to left and left is 0, then you are done, exit
            // if k belongs to right and the left is 0, nothing to do, just traverse to right
            if((curNode -> left -> indexes).size() == 0){
                if(k <= mid){
                    break;
                }
                curLeft = mid+1;
                curNode = curNode -> right;
                continue;
            }
            // left mapping is finding the index in left that is <= original index l
            if(leftMapped != -1 && ((curNode -> left) ->indexes)[leftMapped] == (curNode->indexes)[l]){
                leftl = leftMapped;
            }
            else{
                leftl = leftMapped+1;
            }
            leftr = rightMapped;
            // if went into if loop then even if the right path has no indexes, we don't care
            if(k <= mid){
                l = leftl;
                r = leftr;
                curRight = mid;
                curNode = curNode -> left;
            }
            else{
                ans += (leftr-leftl)+1;
                // check if the right has no path forward, but the k is in right then exit
                if((curNode -> right -> indexes).size() == 0){
                    break;
                }
                leftMapped = (curNode -> mapRight)[l];
                rightMapped = (curNode -> mapRight)[r];
                if(leftMapped != -1 && ((curNode -> right) ->indexes)[leftMapped] == (curNode->indexes)[l]){
                    l = leftMapped;
                }
                else{
                    l = leftMapped+1;
                }
                r = rightMapped;
                curLeft = mid+1;
                curNode = curNode -> right;
            }
        }
        return ans;
    }
};

void solve() {
	int n;
    cin >> n;
    vector <int> v(n);
    int mx = 0;
    for(int i=0;i<n;i++){
        cin >> v[i];
        mx = max(mx, v[i]);
    }
    auto tree = new IndexTree(v, mx);
    int l,r,k;
    cin >> l >> r >> k;
    cout.flush();
    cout<< "BUILD OK" << endl;
    cout << tree -> findLessIn(l,r,k) << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r",stdin);
    // freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout.tie(0);
    int tc;
    tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}

/*build and execute:
g++ -std=c++17 primary.cpp -o primary
.\primary.exe

time g++ -std=c++17 -O2 primary.cpp -o primary



*/
