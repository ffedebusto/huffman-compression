#include "data.hpp"

int main(int argc, char const *argv[])
{
    string input;
    cout << "Give a string" << endl;

    cin >> input;

    priority_queue<Node> res;
    res = Huffman(input);

    /*
        while (!res.empty())
        {
            Node a = res.top();
            cout << "value:" << a.c << " freq: " << a.freq << endl;
            res.pop();
        }
    */

    return 0;
}

priority_queue<Node> from_string_to_queue(string &s)
{
    priority_queue<Node> res;
    unsigned int freq[26] = {0}; // only lowercase letters;

    for (char c : s)
    {
        if (c < 'a' && c > 'z')
        {
            cout << "*** stack smashing detected ***" << endl;
            return res;
        }

        freq[c - 'a'] += 1;
    }

    int i = 0;
    for (char c : s)
    {
        if (freq[c - 'a'] != 0)
        {
            res.push({c, freq[c - 'a'], "", true, nullptr, nullptr});
            i++;
        }
        freq[c - 'a'] = 0;
    }

    return res;
}

Node createTree(priority_queue<Node> &q)
{
    Node res;
    if (q.size() <= 1)
        return res;

    while (q.size() > 1)
    {
        // extracting the two Nodes with lowest frequency
        Node sx = q.top();
        q.pop();
        Node dx = q.top();
        q.pop();

        unsigned int newFreq = sx.freq + dx.freq;

        q.push({'\0', newFreq, "", false, nullptr, nullptr});
    }

    res = q.top();
    q.pop(); // clear

    return res;
}

priority_queue<Node> createEncode(Node &n) // Bottom-Up approach
{

    priority_queue<Node> res;

    return res;
}

priority_queue<Node> Huffman(string &s)
{
    priority_queue<Node> q = from_string_to_queue(s);

    Node Tree = createTree(q);

    priority_queue<Node> res = createEncode(Tree);
    return res;
}