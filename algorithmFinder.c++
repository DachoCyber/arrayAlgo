#include <bits/stdc++.h>
using namespace std;

struct Data
{
    int x, y;
};

// Function to perform Lagrange Interpolation
double interpolate(Data f[], int xi, int n)
{
    double result = 0;

    for (int i = 0; i < n; i++) {
        double term = f[i].y;
        for (int j = 0; j < n; j++) {
            if (j != i)
                term = term * (xi - f[j].x) / double(f[i].x - f[j].x);
        }
        result += term;
    }

    return result;
}

int main()
{
    int a[100];
    int n;
    printf("Unesite broj elemenata niza: ");
    scanf("%d", &n);

    printf("Unesite niz:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    Data pol[100];
    Data pol2[100];
    bool algorithmExists = false;

    // Loop over possible degrees of the polynomial
    for (int i = 0; i <= n / 2; i++) {
        algorithmExists = true;

        // Prepare the data points for interpolation
        for (int j = 0; j < i; j++) {
            pol[j].x = a[j];
            pol[j].y = a[j + 1];
            pol2[i].x = j;
            pol2[i].y = a[j];
        }

        // Check if the polynomial interpolates the remaining points
        for (int j = i; j < n; j++) {
            if (a[j] != round(interpolate(pol, a[j-1], i + 1)) && a[j] != round(interpolate(pol, j, i + 1))) {
                algorithmExists = false;
                break;
            }
        }

        if (algorithmExists) {
            printf("Algoritam postoji!\n");
            return 0;
        }
    }

    printf("Algoritam ne postoji!\n");
    return 0;
}
