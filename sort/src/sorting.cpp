#include "sorting/sorting.hpp"

void bubbleSort(std::vector<int>& tab)
{

    for(int j = 0; j < (size(tab) - 1); j++)
        for(int i = 0; i < (size(tab) - j - 1); i++)
            if(tab[i] > tab[i + 1])
                std::swap(tab[i], tab[i + 1]);
}

void quickSorting(std::vector<int>& tab, int left, int right)
{
    int pivot = tab[(left + right) / 2];

    int i = left;
    int j = right;

    while(i <= j)
    {
        while(tab[i] < pivot)
        {
            i++;
        }

        while(tab[j] > pivot)
        {
            j--;
        }

        if(i <= j)
        {
            std::swap(tab[i], tab[j]);
            i++;
            j--;
        }
    }

    if(left < j)
    {
        quickSorting(tab, left, j);
    }

    if(i < right)
    {
        quickSorting(tab, i, right);
    }
}


void quickSort(std::vector<int>& tab)
{
    quickSorting(tab,0,size(tab)-1);
}


void pessQuickSorting(std::vector<int>& tab, int left, int right)
{
    int pivot = tab[left];

    int i = left;
    int j = right;

    while(i <= j)
    {
        while(tab[i] < pivot)
        {
            i++;
        }

        while(tab[j] > pivot)
        {
            j--;
        }

        if(i <= j)
        {
            std::swap(tab[i], tab[j]);
            i++;
            j--;
        }
    }

    if(left < j)
    {
        pessQuickSorting(tab, left, j);
    }

    if(i < right)
    {
        pessQuickSorting(tab, i, right);
    }
}


void pessQuickSort(std::vector<int>& tab)
{
    pessQuickSorting(tab,0,size(tab)-1);
}

void merge(std::vector<int>& tab, int left, int middle, int right)
{

    int m = middle - left + 1;
    int n = right - middle;

    std::vector<int> container1(m);
    std::vector<int> container2(m);

    for(int i = 0; i < m; i++)
    {
        container1[i] = tab[left + i];
    }
    for(int j = 0; j < n; j++)
    {
        container2[j] = tab[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while(i < m && j < n)
    {
        if(container1[i] <= container2[j])
        {
            tab[k] = container1[i];
            i++;
        }
        else
        {
            tab[k] = container2[j];
            j++;
        }
        k++;
    }

    while(i < m)
    {
        tab[k] = container1[i];
        i++;
        k++;
    }

    while(j < n)
    {
        tab[k] = container2[j];
        j++;
        k++;
    }
}

void mergeSorting(std::vector<int>& tab, int left, int right)
{

    if(left < right)
    {
        int middle = left + (right - left) / 2;
        mergeSorting(tab, left, middle);
        mergeSorting(tab, (middle + 1), right);
        merge(tab, left, middle, right);
    }
}

void mergeSort(std::vector<int>& tab)
{
    mergeSorting(tab,0,size(tab)-1);
}