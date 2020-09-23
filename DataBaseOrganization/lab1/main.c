#include "scripts/common.h"

/*int binarySearch(const int arr[], int x){
    int size = 5;
    int borders[2] = {0, size - 1};
    int middle;
    while (borders[0] <= borders[1]){
        middle = (borders[0] + borders[1]) / 2;

        if (x == arr[middle]){
            return middle;
        }
        borders[x < arr[middle]] = middle + 1 - 2 * (x < arr[middle]);
    }

    return -1 - (middle + 1 * (arr[middle] < x));
}

int main()
{
    int arr[] = { 2, 5, 8, 10, 40 };
    int x = 1;
    printf("%i", binarySearch(arr, x)) ;

    return 0;
}*/

int main() {
    initTables();
    printHelp();
    insert_m();

    return processCommands();
}
