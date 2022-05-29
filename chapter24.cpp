//Poisson-nal 10 érték kiíratása
#include <iostream>
#include <iterator>
#include <random>

using namespace std;

int main (){

    const int nrolls = 10; // number of experiments

    default_random_engine generator;
    poisson_distribution<int> distribution(4.1);

    for (int i=0; i<nrolls; ++i){
    int number = distribution(generator);
    cout<<number<<" "<<endl;

    }
}