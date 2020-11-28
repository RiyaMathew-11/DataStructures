// Taking two matrices as input and displaying its sum in sparse form

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void read_matrix(int id, int mx[][3])
{
    int m, n;
    printf("Enter the order of matrix %d: ", id);
    scanf("%d %d", &m, &n);

    mx[0][0] = m, mx[0][1] = n, mx[0][2] = 0;

    for (int i = 0, c = 1; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int a;
            printf("enter element[%d][%d]: ", i, j);
            scanf("%d", &a);

            if (a != 0)
            {
                mx[c][0] = i, mx[c][1] = j, mx[c][2] = a;
                mx[0][2]++, c++;
            }
        }
    }
}

void display_matrix(int mx[][3])
{

    for (int i = 0; i < mx[0][2] + 1; ++i)
    {
        printf("%d %d %d\n", mx[i][0], mx[i][1], mx[i][2]);
    }
}

void tran_matrix(mx)
{









}
int add_matrix(int mx1[][3], int mx2[][3], int mx3[][3]) {

    if (mx1[0][0] != mx2[0][0] || mx2[0][1] != mx2[0][1]) {
        printf("\nmatrices of different order cannot be added");
        return 0;
    }

    mx3[0][0] = mx1[0][0], mx3[0][1] = mx1[0][1];
    int i = 1, j = 1, k = 1;

    while (i <= mx1[0][2] && j <= mx2[0][2]) {

        if (mx1[i][0] < mx2[j][0]) {

            mx3[k][0] = mx1[i][0], mx3[k][1] = mx1[i][1], mx3[k][2] = mx1[i][2];
            ++k, ++i;
        }

        else if (mx1[i][0] > mx2[j][0]) {

            mx3[k][0] = mx2[j][0], mx3[k][1] = mx2[j][1], mx3[k][2] = mx2[j][2];
            ++k, ++j;
        }

        else  {

            if (mx1[i][1] < mx2[j][1]) {

                mx3[k][0] = mx1[i][0], mx3[k][1] = mx1[i][1], mx3[k][2] = mx1[i][2];
                ++k, ++i;
            }

            else if (mx1[i][1] > mx2[j][1]) {

                mx3[k][0] = mx2[j][0], mx3[k][1] = mx2[j][1], mx3[k][2] = mx2[j][2];
                ++k, ++j;
            }

            else {
                mx3[k][0] = mx1[i][0] + mx2[j][0], mx3[k][1] = mx1[i][1] + mx2[j][1], mx3[k][2] = mx1[i][2] + mx2[j][2];
                ++k, ++i, ++j;
            }
        }
    }

    while (i <= mx1[0][2]) {
        mx3[k][0] = mx1[i][0], mx3[k][1] = mx1[i][1], mx3[k][2] = mx1[i][2];
        ++k, ++i;
    }

    while (j <= mx2[0][2]) {
        mx3[k][0] = mx2[j][0], mx3[k][1] = mx2[j][1], mx3[k][2] = mx2[j][2];
        ++k, ++j;
    }

    mx3[0][2] = k - 1;

    return 1;
}

int main() {

    int mx1[MAX][3], mx2[MAX][3], mx3[MAX][3];

    read_matrix(1, mx1);
    read_matrix(2, mx2);
    printf("\n Sparse Matrix 1 :\n");
    display_matrix(mx1);
    printf("\n Sparse Matrix 2:\n");
    display_matrix(mx2);


    if (add_matrix(mx1, mx2, mx3)) {
        printf("Sum of Matrices (Sparse form) :\n");
        display_matrix(mx3);
    }

    return 0;
}
