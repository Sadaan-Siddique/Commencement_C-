#include <iostream>
using namespace std;

int countWhiteSpaces(int (*dataPtr)[5], int m, int k)
{
    int whiteCount = 0, mostlyWhiteCount = 0;
    for (int i = 0; i <= m - k; i++)
        for (int j = 0; j <= 5 - k; j++)
        {
            whiteCount = 0;
            for (int r = i; r < i + k; r++)
            {
                for (int c = j; c < j + k; c++)
                {
                    cout << *(*(dataPtr + r) + c) << " ";
                    if(*(*(dataPtr + r) + c) == 0)
                    {
                        whiteCount++;
                    }  
                }
                cout << endl;
            }
            if(whiteCount > ((k * k) / 2) )
                mostlyWhiteCount++;
            cout << endl;
        }
        return mostlyWhiteCount;
}
int main()
{
    int m = 4, n = 5, k = 2; 
    int zeroesCount = 0, whiteCount = 0, mostlyWhiteCount = 0;
    // Here, m x n is the order of original matrix and k is the value for the order of k x K sub-matrices in the original matrix 

    int data[m][n]{
        {0, 1, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 1, 1, 0},
        {0, 1, 0, 1, 0}};

    int subMatrices = (m - (k - 1)) * (n - (k - 1));
    cout << "Sub-matrices would be: " << subMatrices << endl;

    for (int i = 0; i <= m - k; i++)
        for (int j = 0; j <= n - k; j++)
        {
            whiteCount = 0;
            for (int r = i; r < i + k; r++)
            {
                for (int c = j; c < j + k; c++)
                {
                    cout << data[r][c] << " ";
                    if(data[r][c] == 0)
                    {
                        whiteCount++;
                        zeroesCount++;
                    }  
                }
                cout << endl;
            }
            if(whiteCount > ((k * k) / 2) )
                mostlyWhiteCount++;
            cout << endl;
        }

    cout << "Total Sub-matrices are: " << subMatrices << endl;
    cout << "Total zeroes(white counts) in " << subMatrices << " sub-matrices are: " << zeroesCount++ << endl;
    cout<< "Total mostly White sub-matrices are: "<<mostlyWhiteCount<<endl;
}