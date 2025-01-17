#include <iostream>
#include <vector>
#include <random>
#include <memory>

#include "BubbleSort.hpp"
#include "InsertionSort.hpp"
#include "QuickSort.hpp"

constexpr int minRandom = 0;
constexpr int maxRandom = 255;

void genericSorting(std::vector<int>& vector)
{
    std::unique_ptr<ISort> sortingAlgorithm = std::make_unique<QuickSort>();

    if (std::size_t collectionSize = vector.size(); collectionSize < 16)
    {
        sortingAlgorithm = std::make_unique<BubbleSort>();
    } 
    else if(collectionSize < 64)
    {
        sortingAlgorithm = std::make_unique<InsertionSort>();
    }
    
    sortingAlgorithm->sort(vector);
}

void displayVector(const std::vector<int>& vector)
{
    std::cout << "[ ";
    for (const int& i : vector)
    {
       std::cout << i << " "; 
    }
    std::cout << "]" << std::endl;
}

std::vector<int> randomSizedVector (const size_t& size) 
{
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution dis(minRandom, maxRandom);

    std::vector<int> vector = std::vector<int>();
    vector.reserve(size);

    for (size_t i = 0; i < size; i++)
    {
        vector.emplace_back(dis(gen));
    }
    
    return vector;
}

int main(int argc, char **argv) 
{
    for (size_t i = 1; i < size_t(argc); i++)
    {
        std::vector<int> vector = randomSizedVector(atoi(argv[i]));
        displayVector(vector);
        genericSorting(vector);
        displayVector(vector);
    }
}