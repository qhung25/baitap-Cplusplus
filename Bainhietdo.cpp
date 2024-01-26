#include <stdio.h>

void timngaynhietdocaonhat(int n, float a[]) 
{
    int m = 0;
    for (int i = 1; i < n; i++) 
 {
        if (a[i] > a[m]) 
  {
            m = i;
        }
    }

    printf("Ngay co nhiet do cao nhat trong nam la ngay thu %d\n", m + 1);
}

void demngaynhietdocaohon(int n, float a[]) 
{
    int t = 0;
    int k = 5;

    for (int i = k; i < n - 1; i++) 
 {
        if (a[i + 1] > a[i]) 
  {
            t++;
        }
    }

    printf("Tu ngay thu %d, co %d ngay nhiet do cao hon ngay truoc do\n", k, t+1);
}

void ghimangnhietdo(int n, float b[]) 
{
    FILE *file = fopen("nhietdo.txt", "w");
    if (file == NULL) 
 {
        printf("Khong the mo tep nhietdo.txt\n");
        return;
    }

    fprintf(file, "%d\n", n);

    for (int i = 0; i < n; i++) 
 {
        fprintf(file, "%.2f", b[i]);
        if (i != n - 1) {
            fprintf(file, " ");
        }
    }

    fclose(file);
    printf("Da ghi mang nhiet do vao tep nhietdo.txt\n");
}

int main() {
    int n;
    printf("Nhap so ngay: ");
    scanf("%d", &n);

    float t[n];

    for (int i = 0; i < n; i++) {
        printf("Nhap nhiet do ngay thu %d: ", i + 1);
        scanf("%f", &t[i]);
    }

    timngaynhietdocaonhat(n, t);

    demngaynhietdocaohon(n, t);

    ghimangnhietdo(n, t);

    return 0;
}
