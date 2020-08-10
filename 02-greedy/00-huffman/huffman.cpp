#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>


using namespace std;

typedef struct Node {

    char charcter;
    int frequence;
    Node *left;
    Node *right;
}Node;


typedef struct Compare
{
    bool operator()(Node *left, Node *right) {

        return left->frequence > right->frequence;
    }
}Compare;

//function to allocate a new Node
Node *getNode(char character, int frequence, Node *left, Node *right)
{
    Node *node = new Node;
    node->charcter = character;
    node->frequence = frequence;
    node->left = left;
    node->right = right;

    return node;
}

/*travese the huffman tree and store huffman codes*/

void encode(Node *root, string str, unordered_map<char, string> &huffmancode) 
{
    if(root == nullptr)
        return;

    if(!root->left && !root->right) {
        huffmancode[root->charcter] = str;
    }    
    encode(root->left, str + "0", huffmancode);
    encode(root->right, str + "1", huffmancode);

}

void decode(Node *root, int &index, string srt)
{
    if(root == nullptr)
        return;

    if(!root->left && !root->right) {

        cout << root->charcter;
        return;
    }    

    ++index;
    if(srt[index] == '0')
        decode(root->left, index, srt);
    else
    {
        decode(root->right, index, srt);
    }
        
}


void buildHuffmanTree(string text)
{
    unordered_map<char, int> freq;
    for(char ch: text)
        ++freq[ch];

    priority_queue<Node*, vector<Node*>, Compare> queue;

    for(auto pair: freq) {
        queue.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    while(queue.size() != 1) {

        Node *left = queue.top(); queue.pop();
        Node *right = queue.top(); queue.pop();

        int sum = left->frequence + right->frequence;
        queue.push(getNode('\0', sum, left, right));
    }
    Node *root = queue.top();

    unordered_map<char, string> huffmancode;
    encode(root, "", huffmancode);
    

    cout << "Huffman codes are:\n" << '\n';
    for(auto pair: huffmancode)
        cout << pair.first << " " << pair.second << '\n';

   cout << "original string was:\n" << text << endl;

   string str = "";
   for(char ch: text)
        str += huffmancode[ch];

    cout << "Encoded string is: \n " << str << endl;

    int index= -1;
    cout << "\nDecoded String is: \n";
    while(index < (int)str.size() -2) {
        decode(root, index, str);
    } 

    cout << endl;        
}



int main(int argc, char const *argv[])
{
    string text = "Huffman code is a data compression algorithm.";
    buildHuffmanTree(text);

    return 0;
}
