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

        int sz;
        int sum;

        node* left;
        node* right;
        node(int key, int pri) : key(key), pri(pri), sz(1), sum(0), left(nullptr), right(nullptr) {}
        node() : key(-1), pri(-1), sz(1), sum(0), left(nullptr), right(nullptr) {}
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

    int get_sum(node *v)
    {
        if (v == nullptr)
        {
            return 0;
        }
        else
        {
            return v->sum;
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
            v->sz = 1 + get_sz(v->left) + get_sz(v->right);
        }
    }

    void upd_sum(node *v)
    {
        if (v == nullptr)
        {
            return;
        }
        else
        {
            return get_sum(v->left) + get_sum(v->right) + get_sum(v);
        }
    }

    pair<node*, node*> split(node* v, int key)
    {
        // all <= key go left
        if (v == nullptr)
        {
            return {nullptr, nullptr};
        }
        if (v->key > key)
        {
            pair<node*, node*> p = split(v->left, key);
            v->left = p.second;
            upd_sz(v);
            upd_sum(v);
            return {p.first, v};
        }
        else
        {
            pair<node*, node*> p = split(v->right, key);
            v->right = p.first;
            upd_sz(v);
            upd_sum(v);
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
        if (a->pri > b->pri)
        {
            a->right = merge(a->right, b);
            upd_sz(a);
            upd_sum(a);
            return a;
        } else
        {
            b->left = merge(a, b->left);
            upd_sz(b);
            upd_sum(b);
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

    node* kth(node *v, int k)
    {
        cout << v->key << " " << v->sz << " " << k << '\n';
        if (get_sz(v->left) == k)
        {
            return v;
        }
        else if (get_sz(v->left) > k)
        {
            kth(v->left, k);
        }
        else if (get_sz(v->left) < k)
        {
            k = k - get_sz(v->left) - 1;
            kth(v->right, k);
        }
    }

    int GET(node *v, int L, int R)
    {
        auto p = split(v, L);
        auto p1 = split(p.second, B);
        return get_sum(p1.first);
    }

    void print(node *v)
    {
        if (v == nullptr)
        {
            return;
        }

        print(v->left);
        cout << v->key << " " << v->pri << " " << v->sz << '\n';
        print(v->right);
    }
};


int main() {
    treap t;

    treap::node *v;

    v = t.insert(v, 10, 8);
    v = t.insert(v, 8, 7);
    v = t.insert(v, 4, 5);
    v = t.insert(v, 1, 3);
    v = t.insert(v, 6, 2);
    v = t.insert(v, 14, 6);
    v = t.insert(v, 11, 4);
    v = t.insert(v, 16, 0);
    v = t.insert(v, 13, 1);

    t.print(v);
    cout << '\n';

    treap::node *v1 = v;
    v1 = t.kth(v1, 6);
    cout << v1->key << " " << v1->pri;
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
