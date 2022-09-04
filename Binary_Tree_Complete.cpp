#include<bits/stdc++.h>
using namespace std;

class Node{
public:

    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void preorder(Node* root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int levelorder(Node* root, int k){

    if(root == NULL) return 0;

    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    int k1 = 1,sum = 0;

    while(!q.empty()){ 
        Node* curr = q.front();
        q.pop();

        if(q.empty()) break;

        if(curr == NULL){
            cout<<"X ";
            q.push(NULL);
            k1++;
            continue;
        }

        if(k1 == k) sum+= curr->data;
        cout<<curr->data<<" ";

        if(!(curr->left == NULL))  q.push(curr->left);
        if(!(curr->right == NULL)) q.push(curr->right);
        
    }
    cout<<endl;
    return sum;
}

int count_nodes(Node* root){
    if(root == NULL) return 0;
    return count_nodes(root->left)+count_nodes(root->right)+1; 
}

int sum_all_nodes(Node* root){
    if(root == NULL) return 0;
    return sum_all_nodes(root->left)+sum_all_nodes(root->right)+root->data; 
}

int calc_height(Node* root){
    if(root == NULL) return 0;
    return max(calc_height(root->right),calc_height(root->left)) + 1;
}

int diameter(Node* root){
    if(root == NULL) return 0;
    
    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);
    int lheight = calc_height(root->left);
    int rheight = calc_height(root->right);
    
    return max(lheight+rheight+1, max(ldiameter,rdiameter));
}

int search(int inorder[], int curr, int start, int end){
    for (int i = start; i <= end; ++i){
        if(inorder[i] == curr) return i;
    }
    // cout<<"f";
    return -1;
}

Node* build_from_preorder(int preorder[], int inorder[], int start, int end){

    if(start > end) return NULL;

    static int idx = 0;
    int curr = preorder[idx];

    Node* n = new Node(curr);
    idx++;

    if(start == end) return n;

    int pos = search(inorder, curr,start,end);
    n->left = build_from_preorder(preorder,inorder,start, pos-1);
    n->right = build_from_preorder(preorder,inorder,pos+1, end);

    return n;
}

void sum_replace(Node* root){

    if(root == NULL || root->left == NULL || root->right == NULL) return;

    sum_replace(root->left);
    sum_replace(root->right);

    root->data += root->left->data; 
    root->data += root->right->data; 

}

bool isbalanced(Node* root,int* height){

    if(root == NULL){
        // *height = 0;
        return true;
    }

    int lh = 0, rh = 0;

    if(!isbalanced(root->left, &lh)){
        return false;
    }
    if(!isbalanced(root->right, &rh)){
        return false;
    }

    *height = max(lh,rh) + 1;

    if(abs(rh-lh) <= 1) return true;
    return false;
}

// const int N = 1e5 + 10;
// vector<int> par(N);
unordered_map<Node*,Node*> par;

void create_parent(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(q.empty()) break;

        if(curr == NULL){
            q.push(NULL);
            continue;
        }

        if(curr->right != NULL){
            par[curr->right] = curr;
            q.push(curr->right);
        }
        if(curr->left != NULL){
            par[curr->left] = curr;
            q.push(curr->left);
        }
    }
}

void flatten(Node* root){

    if(root == NULL) return;

    flatten(root->right);
    flatten(root->left);

    Node* ptr = root;

    while(ptr->left != NULL){
        ptr = ptr->left;
    }

    ptr->left = root->right;
    root ->right = NULL;
}

void flatten_Morris_Traversal(Node* root){

    Node* curr = root;

    while(curr){

        if(curr->left){
           Node* prev = curr->left;
            while(prev->right) prev = prev->right;

            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

Node* LCA(Node* root, int n1, int n2){

    if(root == NULL) return NULL;

    if(root->data == n1 || root->data == n2) return root;

    Node* leftLCA = LCA(root->left, n1, n2);
    Node* rightLCA = LCA(root->right, n1, n2);

    if(leftLCA && rightLCA) return root;
    if(leftLCA != NULL) return leftLCA;
    return rightLCA;
}

int find_distance(Node* root, int n, int dist){

    if(root == NULL) return -1;

    if(root->data == n) return dist;

    int x = find_distance(root->left, n, dist+1);
    if(x != -1) return x;
    return find_distance(root->right, n, dist+1);
}


int distance_bw_two_node(Node* root, int n1, int n2){

    Node* LCAA = LCA(root, n1, n2);

    int d1 = find_distance(LCAA, n1, 0);
    int d2 = find_distance(LCAA, n2, 0);
    
    return d1+d2;
}

void print_all_nodes_at_level_k(Node* root,Node* target, int k){
    create_parent(root);
    unordered_map<Node* , bool> vis;

    queue<Node*> q;
    q.push(target);
    vis[target] = true;

    int lvl = 0;

    while(!q.empty()){
        
        int n = q.size();
        if(lvl++ == k) break;

        for (int i = 0; i < n; ++i){
            Node* curr = q.front();
            q.pop();


            if(curr->left!=NULL && !vis[curr->left]) {
                q.push(curr->left);
                vis[curr->left] = true;
            }
            if(curr->right!=NULL && !vis[curr->right]) {
                q.push(curr->right);
                vis[curr->right] = true;
            }
            if(par[curr] && !vis[par[curr]]) {
                q.push(par[curr]);
                vis[par[curr]] = true;
            }
        }
    }

    while(!q.empty()){
        cout<<q.front()->data<<" ";
        q.pop();
    }
}


int maxPathSumUtil(Node* root, int &ans){

    if(root == NULL) return 0;

    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);

    int NodeMax = max(max(root->data, root->data + left + right), 
                        max(root->data + left, root->data + right));

    ans = max(ans, NodeMax);

    return max(root->data, max(root->data + left, root->data + right));
}


int maxPathSum(Node* root){
    int ans = INT_MIN;
    maxPathSumUtil(root, ans);
    return ans;
}

int main(){

    // Build This tree :-
    //
    //      12
    //    /  \
    //   2    20
    //  / \  / \
    // 4  5  18  7
    //     /
    //    8

    Node* root = new Node(12);
    root->left = new Node(2);
    root->right = new Node(20);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(18);
    root->right->left->left = new Node(8);
    root->right->right = new Node(7);
    preorder(root);
    cout<<endl;




    // LEVEL ORDER, COUNT ALL NODES, SUM ALL NODES, CALCULATE HEIGHT and DIAMATER


    // int k = 3;
    // cout<<levelorder(root, k)<<endl;
    // cout<<count_nodes(root)<<endl;
    // cout<<sum_all_nodes(root)<<endl;
    // cout<<calc_height(root)<<endl; // O(N)
    // cout<<diameter(root)<<endl;


    // BUILD FROM PREOREDER


    // int preorder2[] = {1,2,4,3,5};
    // int inorder[] = {4,2,1,5,3};

    // Node* root2 = build_from_preorder(preorder2,inorder,0,4);
    
    // preorder(root2);
    // cout<<endl;
    // levelorder(root2,1);



    // SUM REPLACE AND COUNT NODE



    // sum_replace(root);
    // cout<<endl;
    // preorder(root);
    // cout<<endl;
    //levelorder(root,1);
    //count_nodes(root);
    

    // IS BALANCED


    //int height = 0;
    // cout<<isbalanced(root,&height)<<endl;



    // LCA THRU PARENT ARRAY (Probably Unstable)



    // create_parent(root);
    // vector<int> v1,v2;
    // v1.push_back(8);
    // v2.push_back(4);

    // while(par[*(v1.end()-1)] != 0 || par[*(v2.end()-1)]!=0){
    //     if(par[*(v1.end()-1)]!=0) v1.push_back(par[*(v1.end()-1)]);
    //     if(par[*(v2.end()-1)]!=0) v2.push_back(par[*(v2.end()-1)]);
    // }

    // for(auto el : v1) cout<<el<<" ";
    // cout<<endl;
    // for(auto el : v2) cout<<el<<" ";
    // cout<<endl;

    // reverse(v1.begin(), v1.end());
    // reverse(v2.begin(), v2.end());

    // int mins = min(v1.size(),v2.size());

    // int LCA = root->data;
    // for (int i = 0; i < mins; ++i){
    //     if(v1[i] != v2[i]){
    //         break;
    //     }
    //     LCA = v1[i];
    // }

    // cout<<LCA<<endl;
    // cout<<endl;




    // FLATTEN IN PREORDER INTO ROOT->RIGHT (LEFT WOULD'VE BEEN SIMPLER THOUGH)




    // flatten(root);

    // cout<<endl; levelorder(root,2);

    // // root->right = root->left;
    // // root->left = NULL;

    // cout<<endl;
    // // levelorder(root2,1);

    // Node* ptr = root;

    // while(ptr != NULL){
    //     ptr->right = ptr->left;
    //     ptr->left = NULL;
    //     ptr = ptr->right;
    // }

    // ptr = root;

    // while(ptr != NULL){
    //     cout<<ptr->data<<" ";
    //     ptr = ptr->right;
    // }


    // LCA (Recursively)

    // Node* LCAA = LCA(root, 4, 18);
    // cout<<LCAA->data<<endl;





    // DISTANCE BETWEEN TWO NODES




    // cout<<endl<<distance_bw_two_node(root, 8,5)<<endl;


    // FLATTEN USING MORRIS TARVERSAL


    // flatten_Morris_Traversal(root);
    // levelorder(root, 1);



    // PRINT ALL NODES THAT ARE AT A DISTANCE K FROM A TARGET NODE


    // cout<<endl;
    // print_all_nodes_at_level_k(root,root->right, 3);


    // MAXIMUM PATH SUM IN THE TREE

    cout<<maxPathSum(root)<<endl;

}