//
// Created by yjs on 2022/4/21.
//

#include <bits/stdc++.h>


using namespace std;

int main(){
    std::uniform_int_distribution<int> dist {1, 7};
    std::random_device rd; // Non-deterministic seed source
    std::default_random_engine randomEngine {rd()}; // Create random number generator
    for(size_t i{}; i < 8; ++i)
        std::cout << std::setw (2) << dist (randomEngine) << " ";
// -3 0 5 1 -2 -4 0 4







    cout <<endl;


    return 0;



}

