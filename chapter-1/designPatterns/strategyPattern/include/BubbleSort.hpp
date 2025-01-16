#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include <iostream>
#include "ISort.hpp"

/*
procedure bubbleSort(A : list of sortable items)
    n := length(A)
    repeat
        swapped := false
        for i := 1 to n - 1 inclusive do
            if A[i - 1] > A[i] then
                swap(A[i - 1], A[i])
                swapped := true
            end if
        end for
        n := n - 1
    until not swapped
end procedure
*/

struct BubbleSort final : ISort 
{
    void sort(std::vector<int>& vector) override 
    {
        std::cout << "BubbleSort()::sort()" << std::endl;

        size_t n = vector.size();
        bool swapped;

        do 
        {
            swapped = false;
            for (size_t i = 1; i < n; ++i) 
            {
                if (vector[i - 1] > vector[i]) 
                {
                    std::swap(vector[i - 1], vector[i]);
                    swapped = true;
                }
            }
            --n;
        } while (swapped);
    }
};


#endif