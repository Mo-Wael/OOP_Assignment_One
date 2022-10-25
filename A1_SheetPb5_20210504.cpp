#include <bits/stdc++.h>

using namespace std;
const int sizeD = 5;
struct dominoT
{
    int leftDots{};
    int rightDots{};
};
int chain[sizeD] = {-1};


bool foundNext(vector<dominoT> &dominos, int iChain);

bool FormsDominoChain(vector<dominoT> &dominos, int &iDomino, int iChain);

int main()
{

    vector<dominoT> dominos{{2, 6},
                            {4, 4},
                            {1, 4},
                            {6, 1},
                            {4, 3}};
    int iChain{0};
    for (int i{1}; i < sizeD; i++)
    {
        chain[i] = -1;
    }
    bool sorted = false;
    for (int i{}; i < sizeD; i++)
    {
        chain[0] = i;
        if (foundNext(dominos, iChain))
        {
            sorted = true;
            break;
        }
    }
    if (sorted)
    {

        for (int i = 0; i < sizeD - 1; i++)
        {
            cout << dominos[chain[i]].leftDots << " | " << dominos[chain[i]].rightDots << " - ";
        }
        cout << dominos[chain[sizeD - 1]].leftDots << " | " << dominos[chain[sizeD - 1]].rightDots << endl;
    }
    else
    {
        cout << "Dominos can't be sorted" << endl;
    }
    return 0;
}

bool FormsDominoChain(vector<dominoT> &dominos, int &iDomino, int iChain)
{
    for (int i : chain)
    {
        if (i == iDomino)
        {
            return false;
        }
    }
    if (dominos[chain[iChain - 1]].rightDots == dominos[iDomino].leftDots)
    {
        return true;
    }
    return false;
}

bool foundNext(vector<dominoT> &dominos, int iChain)
{
    iChain++;
    int iDomino = 0;
    while (sizeD > iDomino)
    {
        if (FormsDominoChain(dominos, iDomino, iChain))
        {
            chain[iChain] = iDomino;
            if (iChain == sizeD - 1)
            {
                return true;
            }
            if (foundNext(dominos, iChain))
            {
                return true;
            }
            else
            {
                chain[iChain] = -1;
            }
        }
        iDomino++;
    }
    return false;
}
