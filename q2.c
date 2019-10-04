/**
Ram Narayan Singh had recently started home delivery service for pizzas.
Ram has only a single delivery boy that delivers the orders by riding his motorcycle.
The motorcycle has an unlimited capacity of fuel tank. However, it is too old and
can only ride 1 km for each 1 liter of fuel.

There are N fuel stations near the restaurant. The i-th fuel station can fill a
fuel tank exactly Ki liters; not more and not less. Filling a fuel tank with any
amount of fuel in those stations tends to take a long time. Since the fuel stations
are placed near the restaurant, no fuel is needed to go to a fuel station.
Today Ram received N pizza orders, which is the same number of fuel stations fortuitously.
The house of the person that ordered the i-th order is Hi km away from the restaurant.
The delivery boy cannot deliver more than one order at a time. Therefore, after delivering an order,
he must return back to the restaurant to take the next order.

The delivery boy is an efficient person and thus he wants to fill the fuel tank
with the exact amount of fuel required to deliver an order and return back.
He also does not want to spends much time filling the tank, so he wants to minimize
the number of times he fills the tank. Help him determine the minimum number of
times he must fill the tank to deliver all orders.
*/

#include <stdio.h>
#include <stdlib.h>

int comparator(const void* p, const void* q){
    int l = *((const int*)p);
    int r = *((const int*)q);

    if(l>r) return -1;
    return 1;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int N,max = 0;
        scanf("%d",&N);
        int H[N],K[N];
        for(int i=0; i<N; i++){
            int tmp;
            scanf("%d",&tmp);
            H[i] = 2*tmp;
            if(H[i] > max) max = H[i];
        }
        int dp[max+1];
        dp[0] = 0;
        for(int i=1;i<=max;i++) dp[i] = 1000000;
        for(int i=0; i<N; i++) scanf("%d",&K[i]);
        qsort((void *)K , N, sizeof(K[0]), comparator);
        for(int i=0;i<N;i++){
            for(int j=K[i];j<=max;j++){
                if(dp[j]>(1+dp[j-K[i]])) dp[j]=1+dp[j-K[i]];
            }
        }
        
        int count = 0;
        for(int i=0;i<N;i++){
            count += dp[H[i]];
        }
        printf("%d\n", count);
    }
    return 0;
}
