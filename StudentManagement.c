#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

void clearBuffer()
{
    int s = 0;
    while (s != EOF && s != '\n')
    {
        s = getchar();
    }
}

int countRecord = 0;
int i,j;

struct student {
    int MSSV;
    char HoVaTen[100];
    char diaChi[100];
    int Tuoi;
    char gioiTinh;
    int VXL;
    int DTTT;
    int NLSCT;
    int CodeC;
    int japanese;
    int DLDT;
    float gpa;
}student;

int n = 0;
struct student students[MAX_STUDENTS];

void addStudent() {
    int id, i;
    printf("Nhap MSSV: ");
    scanf("%d", &id);
    for (i = 0; i < n; i++) {
        if (students[i].MSSV == id) {
            printf("MSSV da ton tai.\nVui long nhap lai.\n\n");
            addStudent();
            return;
        }
    }
    students[n].MSSV = id;
    clearBuffer();
    printf("Nhap Ho va ten: ");
    scanf("%49[^\n]", students[n].HoVaTen);
    clearBuffer();
    printf("Nhap Dia chi: ");
    scanf("%49[^\n]", students[n].diaChi);
    clearBuffer();
    printf("Nhap Tuoi: ");
    scanf("%d", &students[n].Tuoi);
    clearBuffer();
    printf("Nhap Gioi tinh (M/F): ");
    scanf(" %c", &students[n].gioiTinh);
    clearBuffer();
    printf("Nhap diem Vi Xu Ly: ");
    scanf("%d", &students[n].VXL);
    clearBuffer();
    printf("Nhap diem Dien Tu Tuong Tu: ");
    scanf("%d", &students[n].DTTT);
    clearBuffer();
    printf("Nhap diem Nguyen Ly Sieu Cao Tan: ");
    scanf("%d", &students[n].NLSCT);
    clearBuffer();
    printf("Nhap diem Ky thuat lap trinh C/C++: ");
    scanf("%d", &students[n].CodeC);
    clearBuffer();
    printf("Nhap diem Tieng Nhat: ");
    scanf("%d", &students[n].japanese);
    clearBuffer();
    printf("Nhap diem Do Luong Dien Tu: ");
    scanf("%d", &students[n].DLDT);
    clearBuffer();
    students[n].gpa = (students[n].VXL + students[n].DTTT + students[n].NLSCT + students[n].CodeC + students[n].japanese + students[n].DLDT) / 6.0;
    n++;
    printf("_____________________\n");
    printf("\n");
}


int searchStudent() {
    int MSSV;
    printf("Nhap MSSV can tim: ");
    scanf("%d", &MSSV);
    printf("\n");
    int count=0;
    for (i = 0; i < n; i++) {
        if (students[i].MSSV == MSSV) {
        printf("%5s %18s %13s %5s %2s %5s %5s %5s %5s %5s %5s %8s\n", "  MSSV   ", "Ho va ten     ", "Dia chi     ", "Tuoi  ", "Gioi tinh     ", "VXL     ", "DTTT     ", "NLSCT     ", "KTLT C/C++     ", "Tieng Nhat     ", "DLDT", "GPA");
        printf("%5d %15s %12s %9d %11c %8d %9d %10d %15d %15d %10d %8.1f\n", students[i].MSSV, students[i].HoVaTen, students[i].diaChi, students[i].Tuoi, students[i].gioiTinh, students[i].VXL, students[i].DTTT, students[i].NLSCT, students[i].CodeC, students[i].japanese, students[i].DLDT, students[i].gpa);
		count++;
        }
    }
    if(count==0) printf("Khong tim thay sinh vien ! \n");
    printf("_____________________\n\n");
    return -1;
}

void deleteStudent() {
    int MSSV;
    printf("Nhap MSSV can xoa: ");
    scanf("%d", &MSSV);
    int found = 0;
    for (i = 0; i < n; i++) {
        if (students[i].MSSV == MSSV) {
            for (j = i; j < n - 1; j++) {
                students[j] = students[j + 1];
            }
            found = 1;
            break;
        }
    }
    if (found) {
        n--;
        printf("Da xoa !\n");
        printf("_____________________\n");
    } else {
        printf("Khong tim thay sinh vien ! \n");
        printf("_____________________\n");
    }
}


void updateStudent() {
    int MSSV;
    int count=0;
    printf("Nhap MSSV can thay doi: ");
    scanf("%d", &MSSV);
    for (i = 0; i < n; i++) {
        if (students[i].MSSV == MSSV) {
    	printf("\nNhap Ho va ten: ");
    	scanf(" %49[^\n]", students[i].HoVaTen);
    	printf("Nhap Dia chi: ");
    	scanf(" %49[^\n]", students[i].diaChi);
    	printf("Nhap Tuoi: ");
    	scanf("%d", &students[i].Tuoi);
    	printf("Nhap Gioi tinh (M/F): ");
    	scanf(" %c", &students[i].gioiTinh);
    	printf("Nhap diem Vi Xu Ly: ");
    	scanf("%d", &students[i].VXL);
    	printf("Nhap diem Dien Tu Tuong Tu: ");
    	scanf("%d", &students[i].DTTT);
    	printf("Nhap diem Nguyen Ly Sieu Cao Tan: ");
    	scanf("%d", &students[i].NLSCT);
    	printf("Nhap diem Ky thuat lap trinh C/C++: ");
    	scanf("%d", &students[i].CodeC);
    	printf("Nhap diem Tieng Nhat: ");
    	scanf("%d", &students[i].japanese);
    	printf("Nhap diem Do luong dien tu: ");
    	scanf("%d", &students[i].DLDT);
    	students[i].gpa = (students[i].VXL + students[i].DTTT + students[i].NLSCT + students[i].CodeC + students[i].japanese + students[i].DLDT) / 6.0;
    	count++;
    	printf("Da thay doi ! \n");
		}
    }
    if(count==0) printf("Khong tim thay sinh vien ! \n");
    printf("_____________________\n\n");
}


void showAllStudent() {
    if (n == 0) {
        printf("Danh sach hien tai chua co sinh vien. Vui long them sinh vien truoc !\n");
        printf("_____________________\n");

    } else {
        printf("%-10s %-30s %-20s %-6s %-10s %-10s %-10s %-10s %-15s %-15s %-10s %-6s\n", "MSSV", "Ho va ten", "Dia chi", "Tuoi", "Gioi tinh", "VXL", "DTTT", "NLSCT", "KTLT C/C++", "Tieng Nhat", "DLDT", "GPA");
        for (int i = 0; i < n; i++) {
            printf("%-10d %-30s %-20s %-6d %-10c %-10d %-10d %-10d %-15d %-15d %-10d %-6.2f\n", students[i].MSSV, students[i].HoVaTen, students[i].diaChi, students[i].Tuoi, students[i].gioiTinh, students[i].VXL, students[i].DTTT, students[i].NLSCT, students[i].CodeC, students[i].japanese, students[i].DLDT, students[i].gpa);
        }
    }
}


void showTop10VXL() {
    printf("%5s %20s %15s\n", "  MSSV  ", "Ho va ten", "VXL");
    for (i = 0; i < 10 && i < n; i++) {
        int max = i;
        for ( j = i + 1; j < n; j++) {
            if (students[j].VXL > students[max].VXL) {
                max = j;
            }
        }
        struct student temp = students[i];
        students[i] = students[max];
        students[max] = temp;
        printf("%5d %21s %14d\n", students[i].MSSV, students[i].HoVaTen, students[i].VXL);
    }
    printf("_____________________\n\n");
}

void showTop10DTTT() {
    printf("%5s %20s %18s\n", "  MSSV", "Ho va ten", "DTTT");
    for (i = 0; i < 10 && i < n; i++) {
        int max = i;
        for ( j = i + 1; j < n; j++) {
            if (students[j].DTTT > students[max].DTTT) {
                max = j;
            }
        }
        struct student temp = students[i];
        students[i] = students[max];
        students[max] = temp;
        printf("%5d %19s %17d\n", students[i].MSSV, students[i].HoVaTen, students[i].DTTT);
    }
    printf("_____________________\n\n");
}

void showTop10NLSCT() {
    printf("%5s %20s %17s\n", "  MSSV", "Ho va ten", "NLSCT");
    for (i = 0; i < 10 && i < n; i++) {
        int max = i;
        for (j = i + 1; j < n; j++) {
            if (students[j].NLSCT > students[max].NLSCT) {
                max = j;
            }
        }
        struct student temp = students[i];
        students[i] = students[max];
        students[max] = temp;
        printf("%5d %19s %16d\n", students[i].MSSV, students[i].HoVaTen, students[i].NLSCT);
    }
    printf("_____________________\n\n");
}

void showTop10CodeC() {
    printf("%5s %20s %22s\n", "  MSSV", "Ho va ten", "KTLT C/C++");
    for ( i = 0; i < 10 && i < n; i++) {
        int max = i;
        for ( j = i + 1; j < n; j++) {
            if (students[j].CodeC > students[max].CodeC) {
                max = j;
            }
        }
        struct student temp = students[i];
        students[i] = students[max];
        students[max] = temp;
        printf("%5d %19s %21d\n", students[i].MSSV, students[i].HoVaTen, students[i].CodeC);
    }
    printf("_____________________\n\n");
}

void showTop10Japanese() {
    printf("%5s %20s %19s\n", "  MSSV", "Ho va ten", "Tieng Nhat");
    for ( i = 0; i < 10 && i < n; i++) {
        int max = i;
        for ( j = i + 1; j < n; j++) {
            if (students[j].japanese > students[max].japanese) {
                max = j;
            }
        }
        struct student temp = students[i];
        students[i] = students[max];
        students[max] = temp;
        printf("%5d %19s %18d\n", students[i].MSSV, students[i].HoVaTen, students[i].japanese);
    }
    printf("_____________________\n\n");
}

void showTop10DLDT() {
    printf("%5s %20s %20s\n", "  MSSV", "Ho va ten", "DLDT");
    for (i = 0; i < 10 && i < n; i++) {
        int max = i;
        for ( j = i + 1; j < n; j++) {
            if (students[j].DLDT > students[max].DLDT) {
                max = j;
            }
        }
        struct student temp = students[i];
        students[i] = students[max];
        students[max] = temp;
        printf("%5d %19s %19d\n", students[i].MSSV, students[i].HoVaTen, students[i].DLDT);
    }
    printf("_____________________\n\n");
}

void showTop15GPA() {
    printf("%5s %20s %15s\n", "  MSSV", "Ho va ten", "GPA");
    for ( i = 0; i < 15 && i < n; i++) {
        int max = i;
        for ( j = i + 1; j < n; j++) {
            if (students[j].gpa > students[max].gpa) {
                max = j;
            }
        }
        struct student temp = students[i];
        students[i] = students[max];
        students[max] = temp;
        printf("%5d %19s %14.1f\n", students[i].MSSV, students[i].HoVaTen, students[i].gpa);
    }
    printf("_____________________\n\n");
}

int main() {
    int choice;
    do {
        printf("1. Them sinh vien\n");
        printf("2. Tim kiem sinh vien\n");
        printf("3. Xoa sinh vien\n");
        printf("4. Cap nhat sinh vien\n");
        printf("5. Hien thi tat ca sinh vien\n");
        printf("6. Top 10 sinh vien mon Vi Xu Ly\n");
        printf("7. Top 10 sinh vien mon Dien tu tuong tu\n");
        printf("8. Top 10 sinh vien mon Nguyen ly sieu cao tan\n");
        printf("9. Top 10 sinh vien mon Ky thuat lap trinh C/C++\n");
        printf("10. Top 10 sinh vien mon Tieng Nhat\n");
        printf("11. Top 10 sinh vien mon Do luong dien tu\n");
        printf("12. Top 10 sinh vien co GPA cao nhat\n");
        printf("0. Exit\n");
        printf("_____________________\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1: addStudent(); break;
            case 2: searchStudent(); break;
            case 3: deleteStudent(); break;
            case 4: updateStudent(); break;
            case 5: showAllStudent(); break;
            case 6: showTop10VXL(); break;
            case 7: showTop10DTTT(); break;
            case 8: showTop10NLSCT(); break;
            case 9: showTop10CodeC(); break;
            case 10: showTop10Japanese(); break;
            case 11: showTop10DLDT(); break;
            case 12: showTop15GPA(); break;
        }
    } while (choice != 0);
    return 0;
}
