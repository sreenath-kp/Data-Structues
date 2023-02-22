#include <stdio.h>
void print(int b[][3], int p, int q)
{
    for (int i = 0; i < p; i++)
    {                                           // transpose of sparse
        for (int j = 0; j < q; j++)            // not fast transpose
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int sparse(int a[][10], int s[][3], int m, int n)
{
    int k = 1;
    s[0][0] = m;
    s[0][1] = n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                s[k][2] = a[i][j];
                s[k][1] = j;
                s[k++][0] = i;
            }
        }
    }
    s[0][2] = k - 1;
    print(s, k, 3);
    return k;
}
void transpose(int s[][3], int k, int t[][3], int n)
{
    t[0][0] = s[0][1];
    t[0][1] = s[0][0];
    t[0][2] = s[0][2];
    int r = 1;
    for (int j = 0; j < n; j++)
    {
        for (int i = 1; i < k; i++)
        {
            if (s[i][1] == j)
            {
                t[r][0] = s[i][1];
                t[r][1] = s[i][0];
                t[r][2] = s[i][2];
                r++;
            }
        }
    }
}
void main()
{
    int a[10][10], m, n;
    int s[10][3], t[10][3];
    printf("Enter dimension: ");
    scanf("%d%d", &m, &n);
    printf("Enter matrix:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Sparse matrix:\n");
    int k = sparse(a, s, m, n);
    transpose(s, k, t, n);
    printf("Transpose:\n");
    print(t, k, 3);
}