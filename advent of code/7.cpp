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
        node * n = new node;
        n->parent = current;

        if (files[i].f == "dir") {
            n->type = "dir";
            n->name = files[i].s;
            n->size = 0;
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
    
    cout << t << cur.type << " " << cur.name << " size: " << cur.size << endl;

    for (auto c: cur.children) {
        print_system(c, tabs + 2);
    } 
}

int set_size(node * current) {
    if (current->size != 0) {
        return current->size;
    }
    else {
        int total_size = 0;
        for (auto c: current->children) {
            total_size += set_size(c);
        }
        current->size = total_size;
        return total_size;
    }
}

int get_sum(node * current, int sum) {
    if (current->type == "dir") {
        sum += current->size;
    }

    for (auto c: current->children) {
        sum += get_sum(c, 0);
    }

    return sum;
}

void get_directory_sizes(node * current, vector<int> &sizes) {
    if (current->type == "dir") {
        sizes.push_back(current->size);
    }

    for (auto c: current->children) {
        get_directory_sizes(c, sizes);
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
    root.size = 0;

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

    add_files(elements, current);

    set_size(&root);
    print_system(&root, 0);

    vector<int> sizes;

    get_directory_sizes(&root, sizes);
    sort(sizes.begin(), sizes.end());

    int to_clear = 30000000 - (70000000 - root.size);

    cout << to_clear << endl;

    for (int i = 0; i < sizes.size() - 1; i++) {
        if (sizes[i] > to_clear) {
            cout << "answer: " << sizes[i] << endl;
            break;
        }
    }
}   