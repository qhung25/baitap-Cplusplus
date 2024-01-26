#include<stdio.h>
#include<math.h>
int chieu_vct;
void input_vct(float a[], char vct)
{
    for(int i = 0; i < chieu_vct; i++)
    {
        printf("%c[%d] = ", vct, i+1);
        scanf("%f", &a[i]);
    }
}
float do_dai(float a[])
{
    int sum = 0;
    for(int i = 0; i < chieu_vct; i++)
    {
        sum += pow(a[i],2);
    }
    return sqrt(sum);
}
int check_cungphuong(float a[], float b[])
{
    float ptgoc = a[0]/b[0];
    for(int i = 1; i < chieu_vct; i++)
    {
        if(ptgoc != (a[i] /b[i]))
        {
            return 0;
        }
    }
    return 1;
}
void ghi_file(float a[])
{
    FILE *f;
    f = fopen("vector.txt", "w");
    fprintf(f,"%d\n", chieu_vct);
    for(int i = 0; i < chieu_vct; i++)
    {
        fprintf(f,"%f ", a[i]); 
    }
    fclose(f);
}
float sum_file()
{
    int chieu;
    float sum = 0;
    FILE *f;
    f = fopen("vector.txt", "r");
    fscanf(f, "%d", &chieu);

    for (int i = 0; i < chieu; i++)
    {
        float a;
        fscanf(f,"%f", &a);
        sum += a;
    }
    fclose(f);
    return sum;
}
int main()
{
    printf("Nhap chieu vector: ");
    scanf("%d", &chieu_vct);
    float a[chieu_vct], b[chieu_vct];
    printf("Nhap vector A: \n");
    input_vct(a,'A');
    printf("Nhap vector B: \n");
    input_vct(b,'B');
    printf("\nDo dai cua vector A la: %.3f", do_dai(a));
    if(check_cungphuong(a,b))
    {
        printf("\nHai vector la hai vector cung phuong");
    }
    else
    {
        printf("\nHai vector la hai vector khong cung phuong");
    }
    ghi_file(b);
    printf("\nTong toa do vector la: %.2f", sum_file());

}

