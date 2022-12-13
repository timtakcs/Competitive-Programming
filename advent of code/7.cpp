#include <iostream>
#include<bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#pragma GCC optimize "trapv"

// function that parses a command
// function that executes a command
// tree to store the files and directories
//     stuct - {vector<node> children, node parent, string name}
// traverse the tree

struct node {
    vector<node * > children;
    node * parent;
    string name;
    string type;
    int size;
};

node * cd(string &command, node * current) {
    if (command == "..") {
        current = current->parent;
        return current;
    }
    else {
        for (int i = 0; i < current->children.size(); i++) {
            cout << "command: " << command << " name: " << current->children[i]->name << endl;
            if (current->children[i]->name == command) {
                current = current->children[i];
                return current;
            }
        }
    }

    return current;
}

void add_files(vector<pair<string, string>> &files, node *current) {
    for (int i = 0; i < files.size(); i++) {
        node * n;
        n -> parent = current;

        if (files[i].f == "dir") {
            n->type = "dir";
            n->name = files[i].s;
            current->children.push_back(n);
        }

        else {
            n->type = "file";
            n->size = stoi(files[i].f);
            n->name = files[i].s;
            current->children.push_back(n);
        }
    }
}

vector<string> parse_line(string &line) {
    vector<string> res;
    string cur = "";
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ' ') {
            res.push_back(cur);
            cur = "";
        }
        else {
            cur += line[i];
            continue;
        }
    }

    res.push_back(cur);

    return res;
}

void print_system(node * current, int tabs) {
    string t = "";
    for (int i = 0; i < tabs; i++) {
        t += ' ';
    }
    t += '>';
    t += ' ';

    node cur = *current;
    
    cout << t << cur.type << " " << cur.name << endl;

    for (auto c: cur.children) {
        print_system(c, tabs + 2);
    } 
}

int main() {
    ofstream fout (".out");
    ifstream fin ("elves.in");

    string line;
    vector<string> lines;
    while (getline(fin, line)) {
        lines.push_back(line);
    }

    node root;
    root.name = "/";
    root.type = "dir";

    node * current = &root;

    vector<pair<string, string>> elements;

    for (int i = 1; i < lines.size(); i++) {
        vector<string> parsed = parse_line(lines[i]);
        if (parsed[0] != "$") {
            elements.push_back(mp(parsed[0], parsed[1]));
        }
        else {
            add_files(elements, current);
            elements = {};

            if (parsed[1] == "cd") {
                current = cd(parsed[2], current);
            }
            if (parsed[1] == "ls") {
                continue;
            }
        }
    }

    print_system(&root, 0);
}