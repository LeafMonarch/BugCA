//
// Created by USER on 11/4/2024.
//

#include "BufferedReader.h"
BufferedReader::BufferedReader(string filename){
    ifstream fin(filename);
    if(fin){
        while(!fin.eof()){
            string temp;
            getline(fin, temp);
            lines.push_back(temp);
        }
    }
    cursor = 0;
}

ostream& operator<<(ostream& out, const BufferedReader& br){
    out << br.lines[br.cursor] << endl;
    return out;
}

BufferedReader BufferedReader::operator++(){
    if(cursor < lines.size()-1){
        cursor++;
    }
    return *this;
}

BufferedReader BufferedReader::operator++(int u){
    BufferedReader org = *this;
    if(cursor < lines.size()-1){
        cursor++;
    }
    return org;
}

const string& BufferedReader::operator[](int index){
    if(index < lines.size()){
        cursor = index;
    }
    else{
        throw logic_error("index out of bounds");
    }
    return lines[index];
}