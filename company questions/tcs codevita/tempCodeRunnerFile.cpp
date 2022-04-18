int knapSack(int W, int wt[], int val[], int n)
// {
//     int i, w;
//     int K[2][W + 1];    
  
//     for (i = 0; i <= n; i++) {
//         for (w = 0; w <= W; w++) {
//             if (i == 0 || w == 0)
//                 K[i % 2][w] = 0;
//             else if (wt[i - 1] <= w)
//                 K[i % 2][w] = max(val[i - 1] + K[(i - 1) % 2][w - wt[i - 1]], K[(i - 1) % 2][w]);
//             else
//                 K[i % 2][w] = K[(i - 1) % 2][w];
//         }
//     }
//     return K[n % 2][W];
// }