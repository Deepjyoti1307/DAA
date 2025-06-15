#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure to represent a job
typedef struct
{
    char id[5];
    int deadline;
    int profit;
} Job;

// Function to read job details
void readJobs(Job jobs[], int *n)
{
    printf("Enter the number of jobs: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++)
    {
        printf("Enter Job ID, Profit and Deadline for Job %d: ", i + 1);
        scanf("%s %d %d", jobs[i].id, &jobs[i].profit, &jobs[i].deadline);
    }
}

// Function to sort jobs by descending profit
void sortJobs(Job jobs[], int n)
{
    Job temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (jobs[j].profit < jobs[j + 1].profit)
            {
                temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

// Function to find maximum deadline
int findMaxDeadline(Job jobs[], int n)
{
    int max = jobs[0].deadline;
    for (int i = 1; i < n; i++)
    {
        if (jobs[i].deadline > max)
            max = jobs[i].deadline;
    }
    return max;
}

// Function to schedule jobs to maximize profit
int jobSequencing(Job jobs[], int n, char result[][5])
{
    int maxDeadline = findMaxDeadline(jobs, n);
    int slot[MAX];
    int totalProfit = 0;

    for (int i = 0; i < maxDeadline; i++)
        slot[i] = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i].deadline - 1; j >= 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                strcpy(result[j], jobs[i].id);
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    return totalProfit;
}

// Function to display job sequence and max profit
void displayResult(char result[][5], int maxDeadline, int maxProfit)
{
    printf("\nJob Sequence: ");
    for (int i = 0; i < maxDeadline; i++)
    {
        if (strcmp(result[i], "") != 0)
            printf("%s ", result[i]);
    }
    printf("\nMaximum Profit: %d\n", maxProfit);
}

// Main function
int main()
{
    Job jobs[MAX];
    int n;

    readJobs(jobs, &n);
    sortJobs(jobs, n);

    int maxDeadline = findMaxDeadline(jobs, n);
    char result[MAX][5];

    // Initialize job sequence array
    for (int i = 0; i < maxDeadline; i++)
        strcpy(result[i], "");

    int maxProfit = jobSequencing(jobs, n, result);
    displayResult(result, maxDeadline, maxProfit);

    return 0;
}
