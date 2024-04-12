#include<stdio.h>
//ma tran m hang n cot
void input_matrix(int m, int n, float a[][100]);
void print_matrix(int m, int n, float a[][100], char name);
void sum_matrix(int m, int n, float a[][100], float b[][100]);
void multiply_matri(int m, int n, int p, float a[][100], float b[][100]);
int main(){
    int n, m, p;

    printf("m = ");
    scanf("%d", &m);
    printf("n = ");
    scanf("%d", &n);

    float a[100][100], b[100][100];

    printf("Nhap ma tran A: \n");
    input_matrix(m, n, a);

    printf("Nhap ma tran B: \n");
    input_matrix(m, n, b);
    printf("Ma tran A: \n");
    print_matrix(m, n, a, 'a');
    printf("Ma tran B: \n");
    print_matrix(m, n, b, 'b');
    printf("Ma tran C(A+B): \n");
    sum_matrix(m, n, a, b);

    float d[100][100], e[100][100];
    printf("p = ");
    scanf("%d", &p);
    
    printf("Nhap ma tran D: \n");
    input_matrix(m, n, d);
    printf("Ma tran D: \n");
    print_matrix(m, n, d, 'd');

    printf("Nhap ma tran E: \n");
    input_matrix(n, p, e);
    printf("Ma tran E: \n");
    print_matrix(n, p, e, 'e');

    multiply_matri(m, n, p, d, e);
    return 0;
}

void input_matrix(int m, int n, float a[][100], char name){
    int i, j;
    for(i = 1; i <= m; i++){
        for(j = 1; j <= n; j++){
            printf("%c[%d][%d] = ",name, i, j);
            scanf("%f", &a[i][j]);
        }
    }
}

void print_matrix(int m, int n, float a[][100]){
    int i, j;
    for(i = 1; i <= m; i++){
        for(j = 1; j <= n; j++){
            printf("%.1f ", a[i][j]);
        }
        printf("\n");
    }
}

void sum_matrix(int m, int n, float a[][100], float b[][100]){
    int i, j;
    float c[100][100];
    for(i = 1; i <= m; i++){
        for(j = 1; j <= n; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    print_matrix(m, n, c);

}

void multiply_matri(int m, int n, int p, float a[][100], float b[][100])
{
    int i, j, z;
    float f[100][100];
    for(i = 1; i <= m; i++){
        for(j = 1; j <= p; j++){
            for(z = 1; z <= n; z++){
                f[i][j] += a[i][z] * b[z][j];
            }
        }
    }
    printf("Ma tran F(DxE): \n");
    print_matrix(m, p, f, 'f');
}
