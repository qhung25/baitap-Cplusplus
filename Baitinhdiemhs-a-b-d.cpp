#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void nhapmon(float a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Nhap diem mon %d: ", i+1);
        scanf("%f", &a[i]);

    }
}
void export_diem(float a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", a[i]);
    }
}
float trungbinhcong(float a[], int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum+= a[i];
    }
    return (float )sum/(float )n;
}
void convert_to_4(float a[], float b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        float point_convert;
        if(a[i] < 4)
            point_convert = 0;
        else if(a[i] >=4 && a[i] < 5)
        {
            point_convert = 1.5;
        }
        else if(a[i] >=5 && a[i] < 6)
        {
            point_convert = 2;
        }
        else if(a[i] >=6 && a[i] < 7)
        {
            point_convert = 2.5;
        }
        else if(a[i] >=7 && a[i] < 8)
        {
            point_convert = 3;
        }
        else if(a[i] >=8 && a[i] < 9)
        {
            point_convert = 3.5;
        }
        else if(a[i] >=9 && a[i] <= 10)
        {
            point_convert = 4;
        }
        b[i] = point_convert;
    }
}
void write_point(float a[], int n)
{
    FILE *f;
    f = fopen("diem.txt", "w");
    if(f==NULL)
    {
        printf("loi file");
        exit(0);
    }
    for(int i = 0; i < n; i++)
    {
        fprintf(f, "%f ", a[i]);
    }
    fclose(f);

}
void read_file(float  a[], int n)
{
    FILE *f;
    f = fopen("diem.txt", "r");
    if(f==NULL)
    {
        printf("loi file");
        exit(0);
    }
    for(int i = 0; i < n; i++)
    {
        fscanf(f, "%f", &a[i]);
    }
    fclose(f);
}
float max(float a[], int n)
{
    float max = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] > max)
            max = a[i];
    }
    return max;
}

int main()
{
    int n;
    printf("Nhap so mon hoc: ");
    scanf("%d", &n);
    float point[n], point_4[n];
    nhapmon(point,n);
    printf("Trung binh cong cac mon la: %.3f", trungbinhcong(point,n));
    convert_to_4(point, point_4, n);
    printf("Trung binh cong cac mon diem 4 la: %.3f", trungbinhcong(point_4,n));
    printf("\nDiem he 10 la: ");
    export_diem(point, n);
    printf("\nDiem he 4 la: ");
    export_diem(point_4, n);
    write_point(point_4,n);
    read_file(point_4,n);
    printf("\nDiem cao nhat la %.3f", max(point, n));
}
