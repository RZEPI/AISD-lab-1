#include <iostream>


using namespace std;

int FindElement(int tab[], int min, int max, int elementToFind, bool mon)
{

    if (min <= max)
    {
        int mid = (min + max) / 2;
        if (elementToFind == tab[mid])
            return mid;
        if (mon)
        {
            if (elementToFind > tab[mid])
                return FindElement(tab, mid + 1, max, elementToFind, mon);
            else if (elementToFind < tab[mid])
                return FindElement(tab, min, mid - 1, elementToFind, mon);
        }
        else
        {
            if (elementToFind < tab[mid])
                return FindElement(tab, mid + 1, max, elementToFind, mon);
            else if (elementToFind > tab[mid])
                return FindElement(tab, min, mid - 1, elementToFind, mon);
        }
    }
    return -1;
}

int main()
{
    int m, n, p;
    int k[10000];
    bool mon;
    int element;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> k[j];
        }
        if (k[0] > k[1])
            mon = 0;
        else
            mon = 1;
        cin >> p;
        for (int l = 0; l < p; l++)
        {
            cin >> element;
            cout << FindElement(k, 0, n - 1, element, mon) << endl;
        }
    }
    return 0;
}