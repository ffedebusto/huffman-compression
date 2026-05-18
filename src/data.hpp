#ifndef DATA
#define DATA

#include <iostream>
#include <queue>

using namespace std;

typedef string Encode; // is 'int' the right data type?

struct Elem
{
    char c; // the char
    unsigned int freq;
    Encode format; // the encoding format
    bool isChar;
    Elem *dx;
    Elem *sx;

    // Min-Heap frequency based.
    bool operator<(const Elem &others) const
    {
        return freq > others.freq;
    }
};
const Elem emptyElem = {'\0', 0, "", false, nullptr, nullptr};

/*priority_queue<Elem> -> Min-Heap Priority Queue*/

bool isInQueue(char c);

priority_queue<Elem> from_string_to_queue(string &s);

Elem Huffman(priority_queue<Elem> &s);

#endif