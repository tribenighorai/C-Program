#include <stdio.h>

struct Item {
    int weight, value;
};
int main() {
    int n, W;
    printf("Enter number of items:");
    scanf("%d", &n);

    struct Item arr[n];
    printf("Enter value and weight of items:");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].value, &arr[i].weight);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    double ratio[n];
    for (int i = 0; i < n; i++) {
        ratio[i] = (double)arr[i].value / arr[i].weight;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                double tempR = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempR;

                struct Item temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            totalValue += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }
    printf("Maximum value in Knapsack = %.2f\n", totalValue);
    return 0;
}
