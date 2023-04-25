#include <stdio.h>
#include "bag.h"
struct bag
{
    int *data;
    int n;
    int size;
};
Bag *create(int n)
{
    Bag *bag = (Bag *)malloc(sizeof(Bag));
    bag->data = (int *)calloc(n, sizeof(int));
    bag->n = n;
    bag->size = 0; // zero, pois nenhum elemento foi inserido.
    printf("Instância de Bag criada em %p!\n\n", bag);
    return bag;
}
int insert(Bag *bag, int e)
{
    if (bag->size < bag->n && e > 0)
    { // avalia se bag não está cheio e se o elemento ‘e’ é positivo
        int i = 0;
        do
        {
            i = rand() % bag->n;     // atribui um valor a i, tal que 0 <= i < n
        } while (bag->data[i] != 0); // avalia se em i já não há um elemento
        bag->data[i] = e;
        printf("Elemento %i inserido em bag->[%i].\n\n", e, i);
        return i;
    }
    return -1;
}
int get(Bag *bag)
{
    int i = 0;
    do
    {
        i = rand() % bag->n;
    } while (bag->data[i] == 0);
    printf("Elemento %i retirado de bag->[%i].\n\n", bag->data[i], i);
    bag->data[i] = 0;

    return i;

    return 0;
}
int search(Bag *bag, int e)
{
    for (int i = 0; i < bag->n; i++)
    {
        if (bag->data[i] == e)
        {
            printf("%i encontrado em bag->[%i].\n\n", e, i);
            return i;
        }
    }
    return 0;
}
int size(Bag *bag)
{
    while (bag->data[bag->size] != 0)
    {
        bag->size++;
    }
    return bag->size;
}
void printAll(Bag *bag)
{
    printf("Bag: [");
    for (int i = 0; i < bag->n; i++)
    {
        printf("%i", bag->data[i]);
        if (i < bag->n - 1)
        {
            printf(", ");
        }
    }
    printf("]\n\n");
}
