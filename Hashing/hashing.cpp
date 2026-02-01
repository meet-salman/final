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
        table[idx] = val;
    }

    bool searchValue(int val)
    {
        int idx = hashFunction(val);
        return (table[idx] == val);
    }

    void deleteValue(int val)
    {
        int idx = hashFunction(val);
        table[idx] = -1;
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
    ht.insertValue(42);
    ht.insertValue(15);
    ht.insertValue(14);
    ht.insertValue(11);
    ht.insertValue(46);

    ht.display();
}

int main()
{

    solve();

    return 0;
}