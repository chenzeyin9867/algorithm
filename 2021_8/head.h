// include some necessary heads for convinient
#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include <algorithm>
#include <stack>
using namespace std;



inline void printVector(vector<int> & v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}

#endif