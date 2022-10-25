#include <bits/stdc++.h>

using namespace std;

template <typename D>
class DynArr
{
private:
    size_t capacity;
    size_t nEntries;
    D **arr;

public:
    DynArr();
    ~DynArr();
    DynArr(const DynArr &A1);
    void clear();
    void operator=(const DynArr &A1);
    void innit(size_t start = 0);
    void expand();
    void add(const D &obj);
    int size();
    D &operator[](const int index);
};

int main()
{
    DynArr<int> test1;
    test1.add(55);
    test1.add(23);
    test1.add(72);

    cout << "test1: " << test1.size() << endl;
    for (int i = 0; i < test1.size(); i++)
    {
        cout << test1[i] << endl;
    }
    DynArr<int> test2(test1);
    cout << "test2: " << test2.size() << endl;
    for (int i = 0; i < test2.size(); i++)
    {
        cout << test2[i] << endl;
    }
    DynArr<int> test3 = test1;
    cout << "test3: " << test3.size() << endl;
    for (int i = 0; i < test3.size(); i++)
    {
        cout << test3[i] << endl;
    }

    return 0;
}

template <typename D>
DynArr<D>::DynArr()
{
    this->capacity = 10;
    this->nEntries = 0;
    this->arr = new D *[this->capacity];
    this->innit();
}

template <typename D>
DynArr<D>::DynArr(const DynArr &A1)
{
    capacity = A1.capacity;
    nEntries = A1.nEntries;
    this->arr = new D *[this->capacity];
    for (int i{}; i < this->nEntries; i++)
    {
        D d = *A1.arr[i];
        this->arr[i] = new D(d);
    }
}

template <typename D>
DynArr<D>::~DynArr()
{
    this->clear();
}

template <typename D>
void DynArr<D>::clear()
{
    for (size_t i{}; i < this->capacity; i++)
    {
        delete this->arr[i];
    }
    delete this->arr;
}

template <typename D>
void DynArr<D>::operator=(const DynArr &A1)
{
    this->clear();
    capacity = A1.capacity;
    nEntries = A1.nEntries;
    this->arr = new D *[this->capacity];
    for (int i{}; i < this->nEntries; i++)
    {
        D d = *A1.arr[i];
        this->arr[i] = new D(d);
    }
}

template <typename D>
void DynArr<D>::innit(size_t start)
{
    for (size_t i{start}; i < this->capacity; i++)
    {
        this->arr[i] = nullptr;
    }
}

template <typename D>
void DynArr<D>::expand()
{
    this->capacity *= 2;
    D **temp = new D *[this->capacity];
    for (int i{}; i < this->nEntries; i++)
    {
        temp[i] = new D(*this->arr[i]);
    }
    this->clear();

    this->arr = temp;
    this->innit(nEntries);
}

template <typename D>
void DynArr<D>::add(const D &obj)
{
    if (this->nEntries >= this->capacity)
    {
        this->expand();
    }
    this->arr[this->nEntries] = new D(obj);
    nEntries++;
}

template <typename D>
int DynArr<D>::size()
{
    return this->nEntries;
}

template <typename D>
D &DynArr<D>::operator[](const int index)
{
    if (index < 0 or index > this->nEntries)
    {
        throw invalid_argument{"index out of range"};
    }
    return *this->arr[index];
}