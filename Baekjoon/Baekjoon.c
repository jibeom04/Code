#include <stdio.h>

int main()
{
    int n, max, sum, temp=0;
    scanf("%d %d", &n, &max);

    int nums[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &nums[i]);
    }

    for(int i=0; i<n; i++)
    {
        sum+=nums[i];
        for(int j=0; j<n; j++)
        {
            if(j==i) continue;
            sum+=nums[j];
            for(int k=0; k<n; k++)
            {
                if(k==i || k==j) continue;
                sum+=nums[k];
                if(temp < sum && sum <=max) temp = sum;
                sum-=nums[k];
            }
            sum-=nums[j];
        }
        sum-=nums[i];
    }

    printf("%d", temp);

    return 0;
}