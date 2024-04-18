//
// Created by USER on 11/4/2024.
//

#ifndef CLASSES_BUFFEREDREADER_H
#define CLASSES_BUFFEREDREADER_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class BufferedReader {
    vector<string> lines;
    int cursor;
public:
    BufferedReader(string filename);
    friend ostream& operator<<(ostream& out, const BufferedReader& br);
    BufferedReader operator++();
    BufferedReader operator++(int u);
    const string& operator[](int index);
};


#endif //CLASSES_BUFFEREDREADER_H
