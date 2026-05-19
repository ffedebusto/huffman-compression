#include "data.hpp"

int main()
{
    string input;
    cout << "Give a string" << endl;

    cin >> input;

    priority_queue<Node> res;
    res = Huffman(input);

    while (!res.empty())
    {
        Node a = res.top();
        cout << "Value: " << a.c << " Freq: " << a.freq << " Format: " << a.format << endl;
        res.pop();
    }

    return 0;
}

priority_queue<Node> from_string_to_queue(string &s)
{

    priority_queue<Node> res;
    unsigned int freq[26] = {0}; // only lowercase letters;

    for (char c : s)
    {
        if (c < 'a' || c > 'z')
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
        Node *sx = new Node(q.top()); // lost the possibility to free allocate them
        q.pop();
        Node *dx = new Node(q.top()); // lost the possibility to free allocate them
        q.pop();

        unsigned int newFreq = sx->freq + dx->freq;

        q.push({'\0', newFreq, "", false, sx, dx}); // a pointer to sx and a pointer to dx
    }

    res = q.top();
    q.pop(); // clear

    return res;
}

void auxCreateEncode(priority_queue<Node> &q, Node &n, string s)
{
    if (n.isChar) // if it's a char change its format.
    {
        n.format = s;
        cout << "Char: " << n.c << " Format: " << n.format << " Freq: " << n.freq << endl;
        s = "";
        q.push(n);
    }

    if (n.sx == nullptr && n.dx == nullptr)
        return;

    if (n.sx != nullptr) // left edge
    {
        auxCreateEncode(q, *n.sx, s + '0');
    }

    if (n.dx != nullptr) // right edge
    {
        auxCreateEncode(q, *n.dx, s + '1');
    }
}

priority_queue<Node> createEncode(Node &n) // Top-Down approach
{

    priority_queue<Node> res;
    auxCreateEncode(res, n, ""); // format upgraded!

    return res;
}

priority_queue<Node> Huffman(string &s)
{

    priority_queue<Node> q = from_string_to_queue(s);

    Node Tree = createTree(q);

    priority_queue<Node> res = createEncode(Tree);
    return res; // could be better returning a map<char, string> in newest versions
}