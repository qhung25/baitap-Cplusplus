#include "stdio.h"
#include "math.h"
#include <stdlib.h>
void input_mark(float a[][100], int n)
{
    for (int i = 0; i < n; ++i) {
        printf("Nhap so tin chi va so diem cho hoc phan thu %d: ", i+1);
        scanf("%f%f", &a[0][i], &a[1][i]);
        
    }
}
float calc_mark(float a[][100], int n, int type)
{
    float raw_point = 0, sum_tc = 0;
    for (int i = 0; i < n; ++i) {
        raw_point += a[0][i] * a[type][i];
        sum_tc+= a[0][i];
    }
    return raw_point/sum_tc;
}
void convert_to_4(float a[][100], int n)
{
    for (int i = 0; i < n; ++i) {
        float point_convert;
        if(a[1][i] < 4)
            point_convert = 0;
        else if(a[1][i] >=4 && a[1][i] < 5)
        {
            point_convert = 1.5;
        }
        else if(a[1][i] >=5 && a[1][i] < 6)
        {
            point_convert = 2;
        }
        else if(a[1][i] >=6 && a[1][i] < 7)
        {
            point_convert = 2.5;
        }
        else if(a[1][i] >=7 && a[1][i] < 8)
        {
            point_convert = 3;
        }
        else if(a[1][i] >=8 && a[1][i] < 9)
        {
            point_convert = 3.5;
        }
        else if(a[1][i] >=9 && a[1][i] <= 10)
        {
            point_convert = 4;
        }
        a[2][i] = point_convert;
    }
}
int main()
{
    int n;
    printf("Nhap so mon hoc: ");
    scanf("%d", &n);
    float diem_hp[100][100];
    input_mark(diem_hp, n);
    printf("\nDiem hoc ky he 10 la: %.2f", calc_mark(diem_hp, n, 1));
    convert_to_4(diem_hp, n);
    printf("\nDiem hoc ky he 4 la: %.2f", calc_mark(diem_hp,n,2));


}

