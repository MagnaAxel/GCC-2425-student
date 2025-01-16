#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP

#include <iostream>
#include "ISort.hpp"

/*
function insertionSortR(Aay A, int n)
    if n > 0
        insertionSortR(A, n-1)
        x ← A[n]
        j ← n-1
        while j >= 0 and A[j] > x
            A[j+1] ← A[j]
            j ← j-1
        end while
        A[j+1] ← x
    end if
end function
*/

struct InsertionSort final : ISort 
{
    void insertionSortR(std::vector<int>& A, int n)
    {
        if (n > 0)
        {
            insertionSortR(A, n - 1);
            
            int x = A[n];
            int j = n - 1;

            while (j >= 0 && A[j] > x)
            {
                A[j + 1] = A[j];
                --j;
            }
            A[j + 1] = x;
        }
    }

    void sort(std::vector<int>& vector) override 
    {
        std::cout << "InsertionSort()::sort()" << std::endl; 

        insertionSortR(vector, vector.size() - 1);
    }
};


#endif //INSERTIONSORT_HPP