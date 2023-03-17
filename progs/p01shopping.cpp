#include<iostream>
#include<cstring>

using namespace std;

// 动态规划解决0-1背包问题
// 购物单： 购买附件必须购买主件，求解满意度最高的购买方案
// 输入总价格，总件数
// 输入各件商品的价格，权重，主附关系
// 输出最高满意度

int Max(int x, int y) {
    return x > y ? x : y;
}

int main() {
    int N, m; // 总预算，总件数
    int v, p, q; // 价格，重要度，主件编号
    int price[61][4] = { 0 }; // 存储价格 0，0+1，0+2，0+1+2 四种状态
    int w[61][4] = { 0 }; // 存储价格加权后的值 
    int dp[3201][61] = { 0 }; // 存储过程
    while (cin >> N >> m)
    {
        memset(price, 0, sizeof(int) * 61 * 4);
        memset(w, 0, sizeof(int) * 61 * 4);
        for (int i = 0; i < m; i++)
        {
            cin >> v >> p >> q;
            v /= 10; // 减少后期循环次数
            if (q == 0)
            {
                price[i][0] = v;
                w[i][0] = v * p;
            } else if (q != 0 && price[q-1][1] == 0) {
                price[q-1][1] = v;
                w[q-1][1] = v * p;
            } else {
                price[q-1][2] = v;
                w[q-1][2] = v * p;
            }
        }  
        for (int i = 0; i < m; i++)
        {
            price[i][1] += price[i][0];
            w[i][1] += w[i][0];
            price[i][2] += price[i][0];
            w[i][2] += w[i][0];    
            price[i][3] = price[i][1] + price[i][2] - price[i][0];
            w[i][3] = w[i][1] + w[i][2] - w[i][0];
        }
        
        N /= 10;
        memset(dp, 0, sizeof(int) * 3201 * 61);
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 1; j <= N; ++j) {
                for (int o = 0; o < 4; o++) {
                    if (o != 0) {
                        dp[j][i] = j >= price[i][o] ? Max(dp[j - price[i][o]][i - 1] + w[i][o], dp[j][i]) : dp[j][i];
                    } else {
                        dp[j][i] = j >= price[i][o] ? Max(dp[j - price[i][o]][i - 1] + w[i][o], dp[j][i - 1]) : dp[j][i - 1];
                    }
                }
            }
        }
        cout << dp[N][m - 1] * 10 << endl;
        #if 0
        cout << " ---   ---   begin   ---   --- " << endl;
        for (int i = 0; i < m; i++) {
            cout << " --- " << i << "   --- " << endl;
            for (int j = 0; j <= N; j++) {
                 cout << " j  = " << j << "  ---  "<< dp[j][i] << endl; 
            }
        }
        cout << " --- ---   end   ---   --- " << endl;
        #endif
    }

    return 0;
}