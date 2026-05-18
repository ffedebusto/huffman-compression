#ifndef DATA
#define DATA

#include <iostream>
#include <queue>

using namespace std;

typedef string Encode; // is 'int' the right data type?

struct Node
{
    char c; // the char
    unsigned int freq;
    Encode format; // the encoding format
    bool isChar;
    Node *dx;
    Node *sx;

    // Min-Heap frequency based.
    bool operator<(const Node &others) const
    {
        return freq > others.freq;
    }
};
const Node emptyNode = {'\0', 0, "", false, nullptr, nullptr};

/*priority_queue<Node> -> Min-Heap Priority Queue*/

bool isInQueue(char c);

priority_queue<Node> from_string_to_queue(string &s);

Node createTree(priority_queue<Node> &q);

priority_queue<Node> createEncode(Node &n);

priority_queue<Node> Huffman(string &s);

#endif