#include <stdio.h>

#define MAX 20

typedef struct
{
    int item;
    float profit;
    float weight;
    float ratio;
} Item;

Item items[MAX];
float result[MAX]; // Fraction of items taken
int n;
float capacity;

// a) Function to read number of items, profit, weight, and knapsack capacity
void readItems()
{
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    for (int i = 0; i < n; i++)
    {
        items[i].item = i + 1;
        printf("Enter profit and weight for item %d: ", i + 1);
        scanf("%f %f", &items[i].profit, &items[i].weight);
        items[i].ratio = items[i].profit / items[i].weight;
    }
}

// b) Sort items by profit-to-weight ratio (descending)
void itemsort()
{
    Item temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (items[j].ratio < items[j + 1].ratio)
            {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

// c) Function to implement fractional knapsack
float knapsack()
{
    float totalProfit = 0.0;
    float remainingCapacity = capacity;

    for (int i = 0; i < n; i++)
    {
        if (items[i].weight <= remainingCapacity)
        {
            // Take full item
            result[i] = 1.0;
            totalProfit += items[i].profit;
            remainingCapacity -= items[i].weight;
        }
        else
        {
            // Take fraction of item
            result[i] = remainingCapacity / items[i].weight;
            totalProfit += result[i] * items[i].profit;
            break;
        }
    }
    return totalProfit;
}

// d) Display the result vector and max profit
void optimal(float maxProfit)
{
    printf("\nResult Vector (Fractions of Items Taken):\n");
    printf("Item\tProfit\tWeight\tTaken\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n", items[i].item, items[i].profit, items[i].weight, result[i]);
    }

    printf("\nMaximum Profit: %.2f\n", maxProfit);
}

// Main function
int main()
{
    readItems();
    itemsort();
    float maxProfit = knapsack();
    optimal(maxProfit);
    return 0;
}
