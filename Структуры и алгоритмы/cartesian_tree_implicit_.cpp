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

struct treap
{
    struct node {
        int key;
        int sz;

        node* left;
        node* right;

        node(int key) : key(key), sz(1), left(nullptr), right(nullptr) {}
        node() : key(-1), sz(1), left(nullptr), right(nullptr) {}
    };

    int get_sz(node *v)
    {
        if (v == nullptr)
        {
            return 0;
        }
        else
        {
            return v->sz;
        }
    }

    void upd_sz(node *v)
    {
        if (v == nullptr)
        {
            return;
        }
        else
        {
            v->sz = get_sz(v->left) + get_sz(v->right) + 1;
        }
    }

    pair<node*, node*> split(node* v, int key)
    { // first key elements go left
        if (v == nullptr)
        {
            return {nullptr, nullptr};
        }

        if (get_sz(v->left) >= key)
        {
            pair<node*, node*> p = split(v->left, key);
            v->left = p.second;
            upd_sz(v);
            return {p.first, v};
        }
        else
        {
            pair<node*, node*> p = split(v->right, key - 1 - get_sz(v->left));
            v->right = p.first;
            upd_sz(v);
            return {v, p.second};
        }
    }

    node* merge(node* a, node* b)
    {
        if (a == nullptr)
        {
            return b;
        }
        if (b == nullptr)
        {
            return a;
        }
        if (a->key > b->key)
        {
            a->right = merge(a->right, b);
            upd_sz(a);
            return a;
        } else
        {
            b->left = merge(a, b->left);
            upd_sz(b);
            return b;
        }
    }

    node* insert(node *v, int pos, int key)
    {
        auto p = split(v, pos);
        v = merge(p.first, merge(new node(key), p.second));
        return v;
    }

    node* remove(node *v, int pos)
    {
        auto p = split(v, pos);
        node *L = p.first;
        node *R = p.second;
        auto p1 = split(v, pos - 1);
        v = merge(p1.first, p.second);
        return v;
    }

    void print(node *v)
    {
        if (v == nullptr)
        {
            return;
        }

        print(v->left);
        cout << v->key  << '\n';
        print(v->right);
    }
};


int main() {
    treap t;

    treap::node *v;


    v = t.insert(v, 1, 3);
    v = t.insert(v, 2, 5);
    v = t.insert(v, 3, 2);
    v = t.insert(v, 4, 7);
    v = t.insert(v, 5, 8);
    v = t.insert(v, 6, 4);
    v = t.insert(v, 7, 1);
    v = t.insert(v, 8, 6);
    v = t.insert(v, 9, 0);

    v = t.remove(v, 8);

    t.print(v);
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
