#include <stdio.h>
struct DiemHocPhan
{
    float chuyenCan;
    float giuaKy;
    float cuoiKy;
};
void nhap(struct DiemHocPhan &d)
{
    printf("Nhap diem chuyen can: ");
    scanf("%f", &d.chuyenCan);
    printf("Nhap diem giua ky: ");
    scanf("%f", &d.giuaKy);
    printf("Nhap diem cuoi ky: ");
    scanf("%f", &d.cuoiKy);
}
float diemhp(struct DiemHocPhan &d)
{
    return (d.chuyenCan*0.1)+ (d.giuaKy*0.3)+ (d.cuoiKy*0.6);

}
int main()
{
    struct DiemHocPhan x;
    nhap(x);
    printf("\nDiem hoc phan la : %.3f", diemhp(x));


}


