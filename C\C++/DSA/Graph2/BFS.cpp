#include <iostream>
#include <vector>
#include <queue>
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


void BFS(vector <node *> &v){

vector <bool> visited(v.size(), 0);
queue <int> q;

    q.push(0);

    while (!q.empty())
    {
        if (!visited[q.front()])
        {
            cout<<q.front()<<" ";
            visited[q.front()]=1;
        }

        struct node * temp = v[q.front()];
        while (temp != NULL)
        {
            if (!visited[temp->vert])
            {
                cout<<temp->vert<<" ";
                visited[temp->vert]=1;
                q.push(temp->vert);
                
            }
            temp = temp->next;
        }
        q.pop();
        
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

    cout<<"BFS\n";
    BFS(v);
    cout<<endl;
    
    return 0;
}
