#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;

struct node {
    int vert;
    int cost;
    struct node *next;

    node(int v, int c, node *n) : vert(v), cost(c), next(n) {} // Constructor to initialize vert and next
};

node *insert_edge(node *v, int p, int q ,int c) {
    node *ptr = new node(q, c, NULL);
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
        cout<<"from "<<i<<" to : ";
        struct node * tmp = v[i];
        while (tmp!=NULL)
        {
            cout<<tmp->vert<<" ";
            tmp = tmp->next;
        }
        cout<<endl;
    }

}


vector < node *> Prims(vector <node *> v){

    vector <node * > st(v.size(),NULL);
    vector <node * > exp(v.size(),NULL);
    vector <bool> visited(v.size(), false);
    exp[0] = v[0];
    visited[0] = true;

    int count = 1;

    while (count < v.size())
    {
        int min_cost = INT_MAX;
        pair <int, int> p;

        for (int i = 0; i < exp.size(); i++)
        {
            struct node * tmp = exp[i];
            while (tmp != NULL)
            {
                if (!visited[tmp->vert] && min_cost > tmp->cost)
                {
                    min_cost = tmp->cost;
                    p.first = i;
                    p.second = tmp->vert;
                }
                
                tmp = tmp->next;
            }
            
            
        }
        st[p.first] = insert_edge(st[p.first], p.first, p.second, min_cost);
        st[p.second] = insert_edge(st[p.second], p.second, p.first, min_cost);
        exp[p.second] = v[p.second];
        visited[p.second] = true;
        count++;
        
    }
    
return st;
    
}

int main() {
    int m, n;

    cout << "Enter NO. of vertices and edges : ";
    cin >> m >> n;

    vector<node *> v(m, NULL); 
    cout << "Enter Edges with cost (like from i to j enter i j c)" << endl;

    for (int i = 0; i < n; i++) {
        int p, q, c;
        cin >> p >> q >> c;
        v[p] = insert_edge(v[p], p, q, c);
        v[q] = insert_edge(v[q], q, p, c);
    }

    print_graph_list(v);
    cout<<endl;

    vector <node *> ST = Prims(v);
    print_graph_list(ST);
    cout<<endl;

    
    return 0;
}