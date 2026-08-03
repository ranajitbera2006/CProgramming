#include <stdio.h>
int main()
{
    int row,col;
    printf("Enter the row number ");
    scanf("%d",&row);
    printf("Enter the column number ");
    scanf("%d",&col);
    int a[row][col],b[row][col],c[row][col];
    printf("Enter the elements of matrix a\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d",&a[i][j]);
        }
        
    }
    printf("The matrix a is\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
        
    }
    printf("Enter the elements of matrix b\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d",&b[i][j]);
        }
        
    }
    printf("The matrix b is\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t",b[i][j]);
        }
        printf("\n");
        
    }
    printf("The sum of matrix is\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
        
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
        
    }
    
    
    return 0;
}