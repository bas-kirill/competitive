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

//Need tests
class BigNum
{
    public:
        BigNum(int a)
        {
            data_.push_back(a);
        }

        BigNum()
        {
            data_.push_back(0);
        }
        BigNum& operator=(int a)
        {
            data_.clear();
            data_.push_back(a);
        }
        BigNum& operator+=(const BigNum &n)
        {
            int carry = 0;
            for(int i = 0; (i < n.data_.size()) || carry; ++i) {
                if(i == data_.size()) {
                    data_.push_back(0);
                }
                data_[i] += carry + ((i < n.data_.size())?n.data_[i]:0);
                carry = data_[i] / base_;
                data_[i] %= base_;
            }
        }
        BigNum operator*(const BigNum &n) const
        {
            BigNum res;
            res.data_.resize(n.data_.size() + data_.size());
            for(size_t i = 0; i < data_.size(); ++i) {
                for(int j = 0, carry = 0; j<(int)n.data_.size() || carry; ++j) {
                    long long cur = res.data_[i+j] + data_[i] * 1ll * (j < (int)n.data_.size() ? n.data_[j] : 0) + carry;
                    res.data_[i+j] = int (cur % base_);
                    carry = int (cur / base_);
                }
            }
            while (res.data_.size() > 1 && res.data_.back() == 0)
                res.data_.pop_back();
            return res;
        }
        void print()
        {
            printf("%d", data_.back());
            for(int i = static_cast<int>(data_.size()) - 2; i >= 0; --i) {
                printf("%03d", data_[i]);
            }
        }
    private:
        static const int base_ = 1000;
        vector <int> data_;
};

int main() {
    int n;
    cin >> n;
    vector<BigNum> d(n + 1);
    d[1] = BigNum();
    BigNum cur = 1;
    for (int i = 2; i <= n; i++)
    {
        d[i] = BigNum(i - 1) * cur;
        cur = d[i - 1];
        cur += d[i];
    }

    d[n].print();
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
