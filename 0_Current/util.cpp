#include <bits/stdc++.h>
using namespace std;

// Initialize 2D vector
int row,col;
vector<vector<int>> v(row, vector<int> (col,0));

/**
 * Display a list
 */
template<typename T> 
void display(std::initializer_list<T> text) 
{ 
    for (const auto & value: text) 
        std::cout << value << " "; 
}

/**
 * Assing Min Value
 */
template<typename T, typename U> 
static inline void amin(T &x, U y) 
{ 
    if (y < x) 
        x = y; 
} 
  
/**
 * Assing Max Value
 */
template<typename T, typename U> 
static inline void amax(T &x, U y) 
{ 
    if (x < y) 
        x = y; 
}