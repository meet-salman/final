#include <bits/stdc++.h>
using namespace std;

class HashTable
{
private:
    int table[10];

    int hashFunction(int val)
    {
        return (val % 10);
    }

public:
    HashTable()
    {
        for (int i = 0; i < 10; i++)
            table[i] = -1;
    }

    void insertValue(int val)
    {
        int idx = hashFunction(val);

        if (table[idx] == -1)
            table[idx] = val;
        else
        {
            for (int i = 0; i < 10; i++)
            {
                idx = (idx + 1) % 10;

                if (table[idx] == -1)
                {
                    table[idx] = val;
                    return;
                }
            }
        }
    }

    bool searchValue(int val)
    {
        int idx = hashFunction(val);

        for (int i = 0; i < 10; i++)
        {
            int probeIdx = (idx + i) % 10;

            if (table[probeIdx] == val)
                return true;
        }

        return false;
    }

    void deleteValue(int val)
    {
        int idx = hashFunction(val);

        for (int i = 0; i < 10; i++)
        {
            int probeIdx = (idx + i) % 10;

            if (table[probeIdx] == val)
            {
                table[probeIdx] = -1;
                return;
            }
        }
    }

    void display()
    {
        for (int i = 0; i < 10; i++)
            cout << i << ": " << table[i] << endl;
    }
};

void solve()
{
    HashTable ht;
    ht.insertValue(11);
    ht.insertValue(21);
    ht.insertValue(31);
    // ht.insertValue(14);
    // ht.insertValue(15);
    // ht.insertValue(15);
    // ht.insertValue(46);
    // ht.insertValue(99);
    // ht.insertValue(49);
    // ht.insertValue(69);

    // ht.deleteValue(11);
    // ht.deleteValue(21);
    // ht.deleteValue(69);
    // ht.deleteValue(15);

    ht.display();
    cout << ht.searchValue(31);
    // cout << ht.searchValue(15);
}

int main()
{

    solve();

    return 0;
}