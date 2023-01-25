#include "Encode.h"
#include<bits/stdc++.h>

using namespace std;
struct node {
    char str;
    int frequency;
};

class Compare {
public:
    bool operator()(node *below, node *above) {
        if (below->frequency > above->frequency) {
            return true;
        }


        return false;
    }
};

void Encode::getFrequencies(char *str) {

    map<char, int>::iterator itr;
    map<char, int> m;


    priority_queue<node *, vector<node *>, Compare> pq;


    int i = 0;
    while (str[i]) {
        m[str[i]]++;
        i++;
    }


    for (itr = m.begin(); itr != m.end(); itr++) {

        qInfo() << itr->first << "->" << itr->second;

        pq.push(new node{itr->first, itr->second});


    }

    while (!pq.empty()) {
        cout << ' ' << pq.top()->str << "->" << pq.top()->frequency;
        pq.pop();
    }


}
