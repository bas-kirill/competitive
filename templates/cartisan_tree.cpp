    #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
using ull = unsigned long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

//mt19937 rr(random_device{}());

struct treap
{
    struct node {
        int key;
        int pri;
        node* left;
        node* right;
        node(int key, int pri) : key(key), pri(pri), left(nullptr), right(nullptr) {}
        node() : key(-1), pri(-1), left(nullptr), right(nullptr) {}
    };

    pair<node*, node*> split(node* v, int key)
    { // all <= key go left
        if (v == nullptr) {
            return {nullptr, nullptr};
        }
        if (v->key > key)
        {
            pair<node*, node*> p = split(v->left, key);
            v->left = p.second;
            return {p.first, v};
        }
        else
        {
            pair<node*, node*> p = split(v->right, key);
            v->right = p.first;
            return {v, p.second};
        }
    }

    node* merge(node* a, node* b) {
        if (a == nullptr) {
            return b;
        }
        if (b == nullptr) {
            return a;
        }
        if (a->pri > b->pri) {
            a->right = merge(a->right, b);
            return a;
        } else {
            b->left = merge(a, b->left);
            return b;
        }
    }

    node* insert(node* v, int key, int pri)
    {
        pair<node*, node*> p = split(v, key);
        v = merge(p.first, merge(new node(key, pri), p.second));
        return v;
    }

    node* remove(node *v, int key)
    {
        auto p = split(v, key-1);
        node *L = p.first;
        node *R = p.second;
        v = merge(L, split(R, key+1).second);
        return v;
    }

    bool find(node *v, int key)
    {
        if (v == nullptr)
        {
            return false;
        }

        cout << v->key << '\n';

        if (v->key == key)
        {
            return true;
        }
        else if (v->key < key)
        {
            find(v->right, key);
        }
        else if (v->key > key)
        {
            find(v->left, key);
        }
    }

    void print(node *v)
    {
        if (v == nullptr)
        {
            return;
        }

        print(v->left);
        cout << v->key << " " << v->pri << '\n';
        print(v->right);
    }
};


int main() {
    treap t;

    treap::node *v;

    v = t.insert(v, 7, 10);
    v = t.insert(v, 13, 8);
    v = t.insert(v, 4, 6);
    v = t.insert(v, 2, 4);
    v = t.insert(v, 6, 2);
    v = t.insert(v, 9, 7);
    v = t.insert(v, 11, 3);
    v = t.insert(v, 14, 4);
    v = t.insert(v, 12, 2);
    v = t.insert(v, 18, 1);

    t.print(v);
    cout << '\n';

    //v = t.remove(v, 13);

    t.print(v);
    treap::node *v1 = v;
    cout << t.find(v, 1);
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
