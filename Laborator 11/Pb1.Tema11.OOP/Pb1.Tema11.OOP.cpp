#include <iostream>
using namespace std;
template<typename T>
void sort(T lista[], int n)
{
    bool sortat;
    do
    {
        sortat = true;
        for (int i = 0; i <= n; i++)
            if (lista[i] > lista[i + 1])
            {
                sortat = false;
                int aux = lista[i];
                lista[i + 1] = lista[i];
                lista[i] = aux;
            }
    } while (sortat);
}
int main()
{
    int lista[] = { 4,8,3,2,8 };
    int lista2[] = { 4,8,3,2,8 };
    int lista3[] = { 2.3, 4.5, 3.6, 8.9, 4.9 };

    cout << "Lista initiala: ";
    for (int i = 0; i < 5; i++)
        cout << lista[i] << " ";
    cout << endl;

    sort(lista, 5);

    cout << "Lista dupa 'sortare': ";
    for (int i = 0; i < 5; i++)
        cout << lista[i] << " ";
    cout << endl;
    int este_sortat = 0;
    for (int i = 0; i < 5; i++)

        if (lista[i] != lista2[i])
            cout << "S-a schimbat lista" << endl;
        else
            cout << "Nu s-a schimbat lista" << endl;
 
    if (este_sortat)
        cout << "Lista este sortata corect";
    else
        cout << "EROARE: Lista nu a fost sortata";
    cout << endl;

    cout << "Lista initiala: ";
    for (int i = 0; i < 5; i++)
        cout << lista3[i] << " ";
    cout << endl;

    sort(lista3, 5);

    cout << "Lista dupa 'sortare': ";
    for (int i = 0; i < 5; i++)
        cout << lista3[i] << " ";
    cout << endl;

}