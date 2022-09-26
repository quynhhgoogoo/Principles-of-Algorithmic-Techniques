#include <iostream>

void multiply(int A[2][2],int B[2][2])
{
    int w = A[0][0]*B[0][0] + A[0][1]*B[1][0];
    int x = A[0][0]*B[0][1] + A[0][1]*B[1][1];
    int y = A[1][0]*B[0][0] + A[1][1]*B[1][0];
    int z = A[1][0]*B[0][1] + A[1][1]*B[1][1];

    A[0][0] = w;
    A[0][1] = x;
    A[1][0] = y;
    A[1][1] = z;
}

void power(int M[2][2],int n)
{
    int F[2][2]={{1,1},{1,0}};
    if (n == 0 || n == 1)
        return;
    else
    {
        power(M,n/2);
        multiply(M,M);

        if (n%2 != 0)
        {
            multiply(M,F);
        }
    }

}


int fib(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
    {
        int F[2][2]={{1,1},{1,0}};
        power(F,n-2);
        return F[0][0];
    }

}

int main()
{
    printf("%d\n",fib(9));
    return 0;
}