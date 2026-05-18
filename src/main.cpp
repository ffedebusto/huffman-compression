#include "data.hpp"

int main(int argc, char const *argv[])
{
    string input;
    cout << "Give a string" << endl;

    cin >> input;

    priority_queue<Elem> ris;
    ris = from_string_to_queue(input);

    while (!ris.empty())
    {
        Elem a = ris.top();
        cout << "value:" << a.c << " freq: " << a.freq << endl;
        ris.pop();
    }

    return 0;
}

priority_queue<Elem> from_string_to_queue(string &s)
{
    priority_queue<Elem> res;
    unsigned int freq[26] = {0}; // only lowercase and uppercase letters;

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

Elem Huffman(priority_queue<Elem> &s)
{
    Elem res;
    return res;
}