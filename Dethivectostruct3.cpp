#include<stdio.h>
#include<math.h>
struct Diem
{
    int x;
    int y;
};
void nhap_diem(struct Diem &vct, char name)
{
    printf("Nhap toa do diem %c(x,y)", name);
    scanf("%d%d", &vct.x, &vct.y);
}
float khoangcach(struct Diem a, struct Diem b)
{
    struct Diem c;
    c.x = b.x - a.x;
    c.y = b.y - a.y;
    return sqrt(pow(c.x,2)+pow(c.y,2));
}
int check_OX_OY(struct  Diem a)
{

    if(a.x == 0)
    {
        return 1; 
    }
    else if(a.y == 0)
    {
        return 2; 
    }
    else if(a.x == 0 && a.y == 0)
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
int main()
{
    struct Diem a ,b,x;
    nhap_diem(a,'A');
    nhap_diem(b,'B');
    printf("\nToa do vector A la: (%d, %d)", a.x, a.y);
    printf("\nToa do vector B la: (%d, %d)", b.x, b.y);
    printf("\nKhoang cach giua hai diem la: %.3f", khoangcach(a,b));
    printf("\nDiem doi xung cua A qua OX la:(%d, %d)", a.x, a.y - a.y*2);
    printf("\nDiem doi xung cua A qua OY la:(%d, %d)", a.x - a.x*2, a.y);
    printf("\nDiem doi xung cua A qua goc toa do la:(%d, %d)\n", a.x - a.x*2, a.y - a.y*2);
    nhap_diem(x, 'X');
    if(check_OX_OY(x) == 1)
    {
        printf("\nDiem nam tren truc tung");
    }
    else if(check_OX_OY(x) == 2)
    {
        printf("\nDiem nam tren truc hoanh");
    }
    else if(check_OX_OY(x) == 3)
    {
        printf("\nDiem nam tren goc toa do");
    }
    else
    {
        printf("\nDiem khong nam tren truc tung va truc hoanh");
    }

}
