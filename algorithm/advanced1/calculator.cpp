#include <cctype>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

struct node {
    double num;
    char op;
    bool flag;
};

string str;
stack<node> s;
queue<node> q;
map<char, int> op;

void translate() {
    node temp;
    for(int i = 0; i < str.length();) {
        if(isdigit(str[i])) {
            temp.flag = true;
            temp.num = str[i] - '0';
            while(++i < str.length() && isdigit(str[i])) {
                temp.num = 10 * temp.num + (str[i] - '0');
            }
            q.push(temp);
        }
        else {
            temp.flag = false;
            temp.op = str[i];
            while(!s.empty() && op[s.top().op] <= temp.op) {
                q.push(s.top());
                s.pop();
            }
            s.push(temp);
            i++;
        }
    }
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

double calculate() {
    double temp1, temp2;
    node cur, temp;
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        if(cur.flag) {
            s.push(cur);
        }
        else {
            temp2 = s.top().num;
            s.pop();
            temp1 = s.top().num;
            s.pop();
            temp.flag = true;
            if(cur.op == '+') {
                temp.num = temp1 + temp2;
            }
            else if(cur.op == '-') {
                temp.num = temp1 - temp2;
            }
            else if(cur.op == '*') {
                temp.num = temp1 * temp2;
            }
            else {
                temp.num = temp1 / temp2;
            }
            s.push(temp);
        }
    }
    return s.top().num;
}

int main() {
    str = "2 / 3 * 4";
    for(auto it = str.begin(); it < str.end(); it++) {
        if(*it == ' ') {
            str.erase(it);
        }
    }
    translate();
    cout << calculate() << endl;
    return 0;
}