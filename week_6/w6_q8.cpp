#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
int N;
using Matrix = vector<vector<long long>>;


Matrix multiply(Matrix &A, Matrix &B) {
    Matrix C(N, vector<long long>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int k = 0; k < N; ++k)
            for (int j = 0; j < N; ++j)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}


Matrix matrix_power(Matrix A, long long K) {
    Matrix result(N, vector<long long>(N, 0));

   
    for (int i = 0; i < N; ++i)
        result[i][i] = 1;

    while (K > 0) {
        if (K % 2 == 1)
            result = multiply(result, A);
        A = multiply(A, A);
        K /= 2;
    }

    return result;
}

int main() {
    long long K;
    cin >> N >> K;

    Matrix adj(N, vector<long long>(N));

    
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> adj[i][j];

    
    Matrix result = matrix_power(adj, K);

    
    long long total_paths = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            total_paths = (total_paths + result[i][j]) % MOD;

    cout << total_paths << endl;
    return 0;
}
