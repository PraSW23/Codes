#include <iostream>
#include <vector>

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

    vector<vector<int>> arr(m, vector<int>(m, 0)); // Correct 2D vector initialization

    for (int i = 0; i < m; i++) {
        int j = 0;
        node *tmp = v[i];
        while (tmp != NULL && j < m) {
            arr[i][tmp->vert] = 1;
            tmp = tmp->next;
            j++;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    // for (int i = 0; i < v.size(); i++)
    // {
    //     struct node * tmp = v[i];
    //     while (tmp!=NULL)
    //     {
    //         cout<<tmp->vert<<" ";
    //         tmp = tmp->next;
    //     }
    //     cout<<endl;
    // }
    

    return 0;
}
