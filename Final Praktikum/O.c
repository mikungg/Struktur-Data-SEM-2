#include <stdio.h>
#include <stdlib.h>

typedef struct NodeGraph {
    int val;
}NodeGraph;

void autoFillUtil(NodeGraph **matrix, int i, int j, int lim){
    if(i == lim || j == lim){
        return;
    }

    matrix[i][j].val = 0;

    if(matrix[i][j+1].val != 0){
        autoFillUtil(matrix, i, j+1, lim);
    }
    
    autoFillUtil(matrix, i+1, j, lim);
}

void autoFill(NodeGraph **matrix, int lim){
    autoFillUtil(matrix, 0, 0, lim);
}

void coords(NodeGraph **matrix, int i, int j, int lim, int val){
    if(i == lim || j == lim || val == 5){
        return;
    }

    if(matrix[i][j].val > 0){

        if(val < matrix[i][j].val){

            matrix[i][j].val = val;
        }
    }
    else{
        matrix[i][j].val = val;
    }
    
    coords(matrix, i+1, j, lim, val + 1);
    coords(matrix, i-1, j, lim, val + 1);
    coords(matrix, i, j+1, lim, val + 1);
    coords(matrix, i, j-1, lim, val + 1);
}

int main() {
    int n, m, x, y;

    scanf("%d %d", &n, &m);

    NodeGraph** matrix = (NodeGraph**)malloc(n * sizeof(NodeGraph*)); //membuat matrix

    int i = 0;

    while(i < n){
        matrix[i] = (NodeGraph*)malloc(n * sizeof(NodeGraph));
        i++;
    }

    autoFill(matrix, n);

    while(m != 0) {
        scanf("%d %d", &x, &y);

        coords(matrix, y-1, x-1, n, 1);

        m--;
    }

    i = 0;
    
    while(i < n){
        int j = 0;
        while(j < n){
            printf("%d ", matrix[i][j].val);
            j++;
        }
        printf("\n");
        i++;
    }
}
