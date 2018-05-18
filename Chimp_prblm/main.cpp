#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
    int health = 2000;
    long int injuries = 1;
    long int max_injuries = 1000000;

    ifstream f1;
    f1.open(argv[1]);
    int damage[1000000], i=0;
    int x;
    while(f1>>x)
    {
        damage[i] = x;
        i++;
    }
    f1.close();

    int num[2000] = {0}; // just in case we encounter monkeys with damage 1 so we assume max size of array
    i = 0;
    int j=0;
    for(long int l=0; l<1000000; l++)
    {
        i=l;
        while(health > 0 && injuries < max_injuries)
        {
            health = health - damage[i];
            injuries = injuries * damage[i];
            num[j]++;
            i++;
        }
        if (health > 0)
            j++;
        else 
            break;
    }

    int largest = num[0];
    int len = j;
    for(int k = 1;k < len; k++)
    {
        if(largest < num[k])
            largest = num[k];
    }
    cout<<"Maximum monkeys defeated - "<<largest;
    return 0;
}
