#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct node {
    int vert;
    struct node *next;

    node(int v, node *n) : vert(v), next(n) {} // Constructor to initialize vert and next
};

node *insert_edge(node *v, int p, int q) {
    node *ptr = new node(q, NULL);
    node *temp = v;

    if (v == NULL) {
        return ptr;
    }

    while (v->next != NULL) {
        v = v->next;
    }

    v->next = ptr;
    return temp;
}

void print_graph_list(vector <node *> &v){

for (int i = 0; i < v.size(); i++)
    {
        struct node * tmp = v[i];
        while (tmp!=NULL)
        {
            cout<<tmp->vert<<" ";
            tmp = tmp->next;
        }
        cout<<endl;
    }

}

void DFS(vector<node *> v) {
    stack<int> stk;
    vector<bool> visited(v.size(), false);

    stk.push(0);

    while (!stk.empty()) {
        int val = stk.top();
        stk.pop();

        if (!visited[val]) {
            cout << val << " ";
            visited[val] = true;

            struct node *temp = v[val];

            while (temp != NULL) {
                if (!visited[temp->vert]) {
                    stk.push(temp->vert);
                }
                temp = temp->next;
            }
        }
    }
}


void DFS1(vector<node *> &v, int val = 0) {
    stack<int> stk;
    static vector<bool> visited(v.size(), 0);

    if (!visited[val]) {
        // Mark as visited before pushing to avoid unnecessary recursion
        visited[val] = 1;

        stk.push(val);
        cout << val << " ";

        while (!stk.empty()) {
            int current = stk.top();

            // Explore unvisited neighbors of the current vertex
            struct node *temp = v[current];
            while (temp != NULL) {
                if (!visited[temp->vert]) {
                    visited[temp->vert] = 1; // Mark as visited before pushing
                    stk.push(temp->vert);
                    cout << temp->vert << " ";
                }
                temp = temp->next;
            }

            stk.pop(); // Backtrack after exploring all neighbors
        }
    }
}


int main() {
    int m, n;

    cout << "Enter NO. of vertices and edges : ";
    cin >> m >> n;

    vector<node *> v(m, NULL); // Vector of pointers to nodes

    cout << "Enter Edges (like from i to j enter i j)" << endl;

    for (int i = 0; i < n; i++) {
        int p, q;
        cin >> p >> q;
        v[p] = insert_edge(v[p], p, q);
    }

    print_graph_list(v);

    cout<<"DFS\n";
    DFS(v);
    cout<<endl;
    
    return 0;
}
