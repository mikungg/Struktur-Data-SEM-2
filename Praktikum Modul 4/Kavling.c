#include <stdio.h>
#include <stdlib.h>

typedef struct NodeGraph {
    char type;
    int ukuran;
}NodeGraph;

int calculate(NodeGraph** matrix, int N, int M, int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= M || matrix[i][j].type != 'K')
    {
        return 0;
    }

    int ukuran = matrix[i][j].ukuran;
    matrix[i][j].type = 'X'; 

    ukuran += calculate(matrix, N, M, i - 1, j); // Atas
    ukuran += calculate(matrix, N, M, i, j - 1); // Kiri
    ukuran += calculate(matrix, N, M, i, j + 1); // Kanan
    ukuran += calculate(matrix, N, M, i + 1, j); // Bawah

    return ukuran;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    NodeGraph** matrix = (NodeGraph**)malloc(n * sizeof(NodeGraph*)); //membuat matrix
    for(int i=0; i < n; i++)
    {
        matrix[i] = (NodeGraph*)malloc(m * sizeof(NodeGraph));
    };

    for(int i=0; i < n; i++)
    {
        for(int j=0; j < m; j++)
        {
            char t;
            int s;
            scanf(" %c %d", &t, &s);
            matrix[i][j].type = t;
            matrix[i][j].ukuran = s;
        }
    }

    int kavlingterbesar = 0;

    for(int i=0; i < n; i++)
    {
        for(int j=0; j < m; j++)
        {
            if (matrix[i][j].type == 'K')
            {
                int currentkavling = calculate(matrix, n, m, i, j);

                if(currentkavling > kavlingterbesar)
                {
                    kavlingterbesar = currentkavling;
                }
            }
        }
    }

    printf("%d\n", kavlingterbesar);
}
