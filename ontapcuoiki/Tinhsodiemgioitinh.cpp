#include "stdio.h"
#include "string.h"
#include "stdlib.h"
struct HocSinh{
    char HoTen[100];
    char GioiTinh[3];
    float DiemToan;
    float DiemVan;
};
void input_info(HocSinh &student)
{
    fflush(stdin);
    printf("Nhap ho ten: ");
    gets(student.HoTen);
    fflush(stdin);
    printf("Nhap gioi tinh: ");
    gets(student.GioiTinh);
    printf("Nhap diem toan: ");
    scanf("%f", &student.DiemToan);
    printf("Nhap diem van: ");
    scanf("%f", &student.DiemVan);

}
float avg_point(HocSinh student)
{
    return (student.DiemToan*2 + student.DiemVan)/(float )3;
}
int main()
{
    struct HocSinh a,b;
    printf("\nNhap thong tin hoc sinh A: \n");
    input_info(a);
    printf("\nNhap thong tin hoc sinh B: \n");
    input_info(b);
    printf("\nDiem trung binh hoc sinh A: %.3f\nDiem trung binh hoc sinh B: %.3f", avg_point(a), avg_point(b));
    if(avg_point(a)> avg_point(b))
    {
        printf("\nDiem trung binh A cao hon");
    }
    else if(avg_point(a)< avg_point(b))
    {
        printf("\nDiem trung binh B cao hon");
    }
    else
    {
        printf("\nDiem trung binh A va B bang nhau!");
    }

}
