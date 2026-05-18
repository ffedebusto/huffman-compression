#ifndef DATA
#define DATA

#include <iostream>
#include <queue>

using namespace std;

typedef string Encode; // is 'int' the right data type?
//const Elem emptyElem NULL;

struct Elem
{
    char c;        // the char
    Encode format; // the encoding format
    Elem *dx;
    Elem *sx;
    unsigned int frequency;
    bool isChar;
};

priority_queue<Elem> from_string_to_queue(string s);

Elem Huffman(priority_queue<Elem> s);

#endif