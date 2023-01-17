int maxProfit(vector<int> &price)
{
    // Write your code here..
    int n = price.size();
    vector<int> profit(n, 0);

    int max_price = price[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (max_price < price[i])
            max_price = price[i];

        profit[i] = max(profit[i + 1], max_price - price[i]);
    }

    int min_price = price[0];
    for (int i = 1; i < n; i++)
    {
        if (min_price > price[i])
            min_price = price[i];

        profit[i] = max(profit[i - 1], profit[i] + (price[i] - min_price));
    }

    return profit[n - 1];
}