#include "stdio.h"
#include "string.h"
struct ThueDoanhNghiep{
    char name[100];
    long revenue;
};
void input_Data(ThueDoanhNghiep &info)
{
    printf("\nNhap ten doanh nghiep: ");
    fflush(stdin);
    gets(info.name);
    printf("\nNhap doanh thu trong mot thang: ");
    scanf("%ld", &info.revenue);
}
long thue(ThueDoanhNghiep info)
{
    if(info.revenue > 50000000)
    {
        return (info.revenue - 50000000)*0.02;
    }
    else
    {
        return 0;
    }
}
int main()
{
    struct ThueDoanhNghiep doanhNghiep;
    input_Data(doanhNghiep);
    printf("\nTien thue kinh doanh cua doanh nghiep la %ld", thue(doanhNghiep));

}
