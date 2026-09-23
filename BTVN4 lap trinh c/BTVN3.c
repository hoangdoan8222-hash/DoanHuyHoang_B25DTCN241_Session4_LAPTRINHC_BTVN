#include <stdio.h>

int main() {
    int n;
    int drink_code;
    int size;
    int topping_count;
    int member_status;

    long long total_revenue = 0;
    long long base_price = 0;
    long long size_surcharge = 0;
    long long topping_surcharge = 0;
    long long order_total = 0;

    printf("=== COFFEE POS - SHIFT REVENUE AUDIT ===\n");
    printf("Nhap tong so giao dich trong ca: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Loi: Tong so giao dich phai lon hon 0!\n");
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        printf("\n========== GIAO DICH %d ==========\n", i);
        printf("Nhap ma mon (-1: Ngat khan cap, 0: Huy don, 1-3: Mon hop le): ");
        scanf("%d", &drink_code);

        if (drink_code == -1) {
            printf("CANH BAO: Phat hien tin hieu NGAT KHAN CAP!\n");
            printf("Dung xu ly ca lam viec ngay lap tuc.\n");
            break;
        }

        if (drink_code == 0) {
            printf("Thong bao: Don hang bi huy. Bo qua giao dich.\n");
            continue;
        }

        if (drink_code != 1 && drink_code != 2 && drink_code != 3) {
            printf("Canh bao: Ma do uong khong hop le. Bo qua giao dich.\n");
            continue;
        }

        printf("Nhap Size (1-S, 2-M, 3-L): ");
        scanf("%d", &size);

        printf("Nhap so luong Topping (0-5): ");
        scanf("%d", &topping_count);

        printf("Nhap trang thai Gold Member (1-Co, 0-Khong): ");
        scanf("%d", &member_status);

        if (size < 1 || size > 3) {
            printf("Canh bao: Size khong hop le. Bo qua giao dich.\n");
            continue;
        }

        if (topping_count < 0 || topping_count > 5) {
            printf("Canh bao: So luong Topping khong hop le. Bo qua giao dich.\n");
            continue;
        }

        if (member_status != 0 && member_status != 1) {
            printf("Canh bao: Trang thai Gold Member khong hop le. Bo qua giao dich.\n");
            continue;
        }

        switch (drink_code) {
            case 1:
                base_price = 29000;
                break;
            case 2:
                base_price = 39000;
                break;
            case 3:
                base_price = 49000;
                break;
        }

        switch (size) {
            case 1:
                size_surcharge = 0;
                break;
            case 2:
                size_surcharge = 6000;
                break;
            case 3:
                size_surcharge = 10000;
                break;
        }

        topping_surcharge = (long long)topping_count * 8000;

        order_total = base_price + size_surcharge + topping_surcharge;

        if (member_status == 1) {
            order_total = order_total * 90 / 100;
        }

        total_revenue += order_total;

        printf("Thanh tien giao dich: %lld VND\n", order_total);
        printf("Giao dich %d: THANH TOAN THANH CONG\n", i);
    }

    printf("\n========================================\n");
    printf("        BAO CAO CHOT DOANH THU CA\n");
    printf("========================================\n");
    printf("Tong doanh thu: %lld VND\n", total_revenue);
    printf("========================================\n");

    return 0;
}
