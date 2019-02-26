#include <stdio.h>
#include <limits.h>
int main()
{
    int row, column, i, n, j, x;
    printf("Enter number of row: ");
    scanf("%d", &row);
    printf("Enter number of column: ");
    scanf("%d", &column);
    int ar[row][column], temp[row];
    for(i=1; i<=row; i++)
    {
        for(j=1; j<=column; j++)
            scanf("%d", &ar[i][j]);
        temp[i]=0;
    }
    int maxSum=INT_MIN, sum, top, bottom, left, right, maxLeft, maxRight, maxTop, maxBottom;
    for(left=1; left<=column; left++)
    {
        for(right=left; right<=column; right++)
        {
            for(i=left; i<=right; i++)
            {
                for(n=1; n<=row; n++)
                    temp[n]+=ar[n][i];
            }
            sum=0;
            for(x=1; x<=row; x++)
            {
                if(x==1)
                {
                    if(temp[x]>=0)
                    {
                        top=x;
                        sum+=temp[x];
                    }
                    else
                        top=x+1;
                }
                else if(x==row)
                {
                    if(temp[x]>=0)
                    {
                        bottom=x;
                        sum+=temp[x];
                    }
                    else
                        bottom=x-1;
                }
                else
                    sum+=temp[x];
            }
            if(sum>=maxSum)
            {
                maxSum=sum;
                maxLeft=left;
                maxRight=right;
                maxTop=top;
                maxBottom=bottom;
            }
            for(n=1; n<=row; n++)
                temp[n]=0;
        }
    }
    printf("\nMax Sum = %d\n", maxSum);
    printf("Left = %d\n", maxLeft);
    printf("Right = %d\n", maxRight);
    printf("Top = %d\n", maxTop);
    printf("Bottom = %d\n\n", maxBottom);
    for(i=maxLeft; i<=maxRight; i++){
        for(j=maxTop; j<=maxBottom; j++)
            printf("%d ", ar[i][j]);
        printf("\n");
    }
    return 0;
}
