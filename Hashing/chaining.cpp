#include <bits/stdc++.h>
using namespace std;

class HashTable
{
private:
    static const int SIZE = 10;
    vector<int> table[SIZE];

    int hashFunction(int val)
    {
        return (val % SIZE);
    }

public:
    void insertValue(int val)
    {
        int idx = hashFunction(val);
        table[idx].push_back(val);
    }

    bool searchValue(int val)
    {
        int idx = hashFunction(val);

        for (auto v : table[idx])
        {
            if (v == val)
                return true;
        }
        return false;
    }

    void deleteValue(int val)
    {
        int idx = hashFunction(val);

        for (auto it = table[idx].begin(); it != table[idx].end();)
        {
            if (*it == val)
            {
                table[idx].erase(it);
                return;
            }
            it++;
        }
    }

    void display()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << i << ": ";
            for (auto v : table[i])
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

void solve()
{
    HashTable ht;
    ht.insertValue(11);
    ht.insertValue(21);
    ht.insertValue(31);
    ht.insertValue(14);
    ht.insertValue(15);
    ht.insertValue(25);
    ht.insertValue(46);
    ht.insertValue(99);
    ht.insertValue(49);
    ht.insertValue(69);

    // ht.deleteValue(31);
    ht.deleteValue(21);
    // ht.deleteValue(69);
    // ht.deleteValue(15);

    ht.display();
    cout << ht.searchValue(69);
    // cout << ht.searchValue(15);
}

int main()
{

    solve();

    return 0;
}