#include <iostream>
#include <string>
#include <vector>
using namespace std;

// int helper(vector<int>& coins, int amount,vector<int>& saved) {
//     if (amount == 0) return 0;
//     if(saved[amount]>-2) return saved[amount];
//     int min = -1;
//     for(int coin : coins){
//         int sum = -1;
//         if (amount - coin >= 0) {
//             sum = helper(coins, amount - coin,saved) + 1;
//         }
//         if( sum != 0 && (min > sum || min == -1)){
//             min = sum;
//         }
//     }
//     saved[amount] = min;
//     return saved[amount];
// }

// int coinChange(vector<int>& coins, int amount) {
//     vector<int> saved(amount+1,-2);
//     return helper(coins,amount,saved);
// }

int helper(vector<int>& coins, int amount, vector<int>& saveCoin)
{
    if(amount == 0){
        return 0;
    }
    if(saveCoin[amount] != -2){
        return saveCoin[amount];
    }
    int minTotalCoin = -1;
    int totalCoin;
    for(auto coin: coins){
        if(amount - coin>=0 && helper(coins,amount - coin,saveCoin) != -1){
            totalCoin = helper(coins,amount - coin,saveCoin) + 1;
            if(totalCoin < minTotalCoin || (minTotalCoin == -1 && totalCoin>=0)){
                minTotalCoin = totalCoin;
            }
        }
    }
    saveCoin[amount] = minTotalCoin;
    return saveCoin[amount];
}
int coinChange(vector<int>& coins, int amount) {
    vector<int> saveCoin(amount+1,-2);
    for(auto coin: coins){
        saveCoin[coin] = 1;
    }
    // sort(coins.begin(), coins.end(), greater<int>());
    return helper(coins,amount,saveCoin);
}

int main() {
    vector<int> coins = {186,419,83,408};
    cout << coinChange(coins,6249);
    return 1;
}
