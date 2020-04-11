#include <bits/stdc++.h>

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