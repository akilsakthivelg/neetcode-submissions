/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:

    Node* helper(vector<vector<int>>& grid,int a,int b,int x,int y,vector<vector<int>>& sum) {
        int s = sum[x+1][y+1]-sum[x+1][b]-sum[a][y+1]+sum[a][b];
        if (s==(x-a+1)*(x-a+1) || s==0) return new Node(grid[a][b],true);
        Node *root = new Node(1,false);
        int d=(x-a+1)/2;
        root -> topRight = helper(grid,a,b+d,x-d,y,sum);
        root -> bottomRight = helper(grid,a+d,b+d,x,y,sum);
        root -> topLeft = helper(grid,a,b,x-d,y-d,sum);
        root -> bottomLeft = helper(grid,a+d,b,x,y-d,sum);
        return root;
    }

    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> sum(n+1,vector<int>(n+1));
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                sum[i+1][j+1]=sum[i][j+1]+sum[i+1][j]-sum[i][j]+grid[i][j];
            }
        }
        return helper(grid,0,0,n-1,n-1,sum);

    }
};