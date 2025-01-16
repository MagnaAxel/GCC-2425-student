#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iostream>
#include <random>
#include "ISort.hpp"
#include <vector>

/*
partitionner(tableau T, entier premier, entier dernier, entier pivot)
    échanger T[pivot] et T[dernier]  // échange le pivot avec le dernier du tableau , le pivot devient le dernier du tableau
    j := premier
    pour i de premier à dernier - 1 // la boucle se termine quand i = (dernier élément du tableau).
        si T[i] <= T[dernier] alors
            échanger T[i] et T[j]
            j := j + 1
    échanger T[dernier] et T[j]
    renvoyer j

tri_rapide(tableau T, entier premier, entier dernier)
        si premier < dernier alors
            pivot := choix_pivot(T, premier, dernier)
            pivot := partitionner(T, premier, dernier, pivot)
            tri_rapide(T, premier, pivot-1)
            tri_rapide(T, pivot+1, dernier)
*/

struct QuickSort final : ISort 
{
    int randomPivot(const int& first, const int& last)
    {
        std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution dis(first, last);
        return dis(gen);
    }

    int partitionR(std::vector<int>& T, const int& first, const int& last, const int& pivot)
    {
        std::swap(T[pivot], T[last]);
        int j = first;
        for (int i = first; i < last; ++i)
        {
            if (T[i] <= T[last])
            {
                std::swap(T[i], T[j]);
                ++j;
            }
        }
        std::swap(T[last], T[j]);
        return j;
    }

    void quickSortR(std::vector<int>& T, const int& first, const int& last)
    {
        if (first < last)
        {
            int pivot = randomPivot(first, last);
            pivot = partitionR(T, first, last, pivot);

            quickSortR(T, first, pivot - 1);
            quickSortR(T, pivot + 1, last);
        }
    }

    void sort(std::vector<int>& vector) override 
    {
        std::cout << "QuickSort()::sort()" << std::endl;

        quickSortR(vector, 0, vector.size() - 1);
    }
};

#endif //QUICKSORT_HPP
