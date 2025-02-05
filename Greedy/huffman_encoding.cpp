// Problem Link: https://www.geeksforgeeks.org/problems/huffman-encoding3345/1

class Node {
    public:
    int data;
    char ch; // To store the character for the Huffman code
    Node* left;
    Node* right;
    
    Node(int d, char c = '\0') { // Constructor with an optional char for leaf nodes
        data = d;
        ch = c;
        left = NULL;
        right = NULL;
    }
};

class cmp {
    public:
    bool operator()(Node* a, Node* b) { // Corrected operator overload
        return a->data > b->data;
    }
};

class Solution {
    public:

    void traverse(Node* root, vector<string>& ans, string temp) {
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(temp);
            return;
        }

        traverse(root->left, ans, temp + '0');
        traverse(root->right, ans, temp + '1');
    }

    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        priority_queue<Node*, vector<Node*>, cmp> pq;

        // Create a leaf node for each character
        for(int i = 0; i < N; i++) {
            Node* temp = new Node(f[i], S[i]);
            pq.push(temp);
        }

        // Build the Huffman tree
        while(pq.size() > 1) {
            Node* left = pq.top();
            pq.pop();
            Node* right = pq.top();
            pq.pop();

            Node* newNode = new Node(left->data + right->data);
            newNode->left = left;
            newNode->right = right;
            pq.push(newNode);
        }

        vector<string> ans;
        Node* root = pq.top();

        traverse(root, ans, "");  // Start the traversal with an empty string

        return ans;
    }
};
