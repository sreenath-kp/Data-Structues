/*
    K P SREENATH
    Roll no: 34
    Cycle 2 EX10
    Convert Sparse matrix to tuple form and find transpose using arrays
*/
#include <stdio.h>
typedef struct
{
    int row, col, val;
} spar;

void read(int r, int c, int M[][10])
{
    int i, j;
    printf("Input elements :\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &M[i][j]);
}

void display(spar s[])
{
    int value = s[0].val;
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i <= value; i++)
        printf("%d\t%d\t%d\n", s[i].row, s[i].col, s[i].val);
}

void convsparse(int r, int c, int M[][10], spar s[], int value)
{
    int i, j, k = 0;
    s[0].row = r, s[0].col = c, s[0].val = value;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            if (M[i][j] != 0)
            {
                k++;
                s[k].row = i;
                s[k].col = j;
                s[k].val = M[i][j];
            }
}

void readsparse(spar s[], int n)
{
    printf("Input the sparse matrix :\n");
    for (int i = 0; i <= n; i++)
        scanf("%d%d%d", &s[i].row, &s[i].col, &s[i].val);
}

void transpose(spar s[], spar t[])
{
    int i, j, term = s[0].val, colterm = s[0].col, rowterm[50], startpos[50];
    t[0].row = colterm, t[0].col = s[0].row, t[0].val = term;
    if (term > 0)
    {
        for (i = 0; i < colterm; i++)
            rowterm[i] = 0;
        for (i = 1; i <= term; i++)
            rowterm[s[i].col]++;
        startpos[0] = 1;
        for (i = 1; i < colterm; i++)
            startpos[i] = startpos[i - 1] + rowterm[i - 1];
        for (i = 1; i <= term; i++)
        {
            j = startpos[s[i].col]++;
            t[j].row = s[i].col;
            t[j].col = s[i].row;
            t[j].val = s[i].val;
        }
    }
}

void add(spar a[], spar b[], spar c[])
{
    int i = 1, j = 1, k = 1;
    int r1 = a[0].row, c1 = a[0].col, r2 = b[0].row, c2 = b[0].col;
    int terms1 = a[0].val, terms2 = b[0].val;
    if (r1 == r2 && c1 == c2)
    {
        c[0].row = r1, c[0].col = c1;
        while (i <= terms1 && j <= terms2)
        {
            if (a[i].row == b[j].row && a[i].col == b[j].col)
            {
                c[k].row = b[j].row;
                c[k].col = b[j].col;
                c[k].val = a[i].val + b[j].val;
                k++;
                i++;
                j++;
            }
            else if (a[i].row == b[j].row)
            {
                if (a[i].col <= b[j].col)
                {
                    c[k].row = a[i].row;
                    c[k].col = a[i].col;
                    c[k].val = a[i].val;
                    k++;
                    i++;
                }
                else
                {
                    c[k].row = b[j].row;
                    c[k].col = b[j].col;
                    c[k].val = b[j].val;
                    k++;
                    j++;
                }
            }
            else
            {
                if (a[i].row <= b[j].row)
                {
                    c[k].row = a[i].row;
                    c[k].col = a[i].col;
                    c[k].val = a[i].val;
                    k++;
                    i++;
                }
                else
                {
                    c[k].row = b[j].row;
                    c[k].col = b[j].col;
                    c[k].val = b[j].val;
                    k++;
                    j++;
                }
            }
        }
        c[0].val = k - 1;
    }
}

void main()
{
    int r1, c1, r2, c2, i, j, value1 = 0, value2 = 0, k, M1[10][10], M2[10][10], ch;
    int op = 1;
    do
    {
        printf("MENU\n1.Convert two matrices to tuple form\n2.Transpose of a matrix\n3.Sum of two matrices\n4.Exit\n");
        printf("Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {

            printf("Enter row and column of the matrix : ");
            scanf("%d%d", &r1, &c1);
            read(r1, c1, M1);
            printf("\nEnter row and column of the matrix : ");
            scanf("%d%d", &r2, &c2);
            read(r2, c2, M2);

            for (i = 0; i < r1; i++)
                for (j = 0; j < c1; j++)
                    if (M1[i][j] != 0)
                        value1++;
            printf("Value 1 :%d\n", value1);
            for (i = 0; i < r2; i++)
                for (j = 0; j < c2; j++)
                    if (M2[i][j] != 0)
                        value2++;
            printf("Value 2 :%d\n", value2);

            spar s1[10], s2[10];

            convsparse(r1, c1, M1, s1, value1);
            printf("Sparse Matrix 1\n");
            display(s1);

            convsparse(r2, c2, M2, s2, value2);
            printf("\nSparse Matrix 2\n");
            display(s2);
            break;
        }
        case 2:
        {
            int n;
            spar s[50], t[50];
            printf("Non zero terms in sparse matrix : ");
            scanf("%d", &n);
            readsparse(s, n);
            printf("Original sparse matrix :\n");
            display(s);
            transpose(s, t);
            printf("Transpose sparse matrix :\n");
            display(t);
            break;
        }
        case 3:
        {
            int n1, n2;
            spar a[50], b[50], c[50];
            printf("Non zero terms in sparse matrix A : ");
            scanf("%d", &n1);
            readsparse(a, n1);
            printf("Non zero terms in sparse matrix B : ");
            scanf("%d", &n2);
            readsparse(b, n2);
            add(a, b, c);
            printf("SUM\n");
            display(c);
            break;
        }
        case 4:
        {
            op = 0;
            break;
        }
        }

    } while (op == 1);
}