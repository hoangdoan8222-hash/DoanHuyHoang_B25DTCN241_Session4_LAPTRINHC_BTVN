#include <stdio.h>
#include <ctype.h>

int main() {
    int total_orders = 0;
    int valid_orders = 0;
    int invalid_orders = 0;
    int emergency_stop = 0;

    long long total_shift_revenue = 0;
    long long max_order_value = 0;

    printf("=== COFFEE POS - CHOT SO DOANH THU CA ===\n");
    printf("Nhap so luong hoa don trong ca: ");
    scanf("%d", &total_orders);

    if (total_orders <= 0) {
        printf("\nCa lam viec trong.\n");
        printf("Tong don hang hop le: 0\n");
        printf("Tong don hang loi: 0\n");
        printf("Tong doanh thu: 0 VND\n");
        printf("Don hang lon nhat: 0 VND\n");
        return 0;
    }

    for (int i = 1; i <= total_orders; i++) {
        long long base_price;
        long long order_value;
        long long discount_amount;
        long long size_surcharge = 0;
        long long topping_surcharge;
        int topping_count;
        int member_status;
        char size;

        printf("\n========== HOA DON %d ==========\n", i);

        printf("Nhap gia co so Size S (VND): ");
        scanf("%lld", &base_price);

        printf("Nhap Size (S/M/L): ");
        scanf(" %c", &size);

        size = (char)toupper((unsigned char)size);

        printf("Nhap so luong topping: ");
        scanf("%d", &topping_count);

        printf("Nhap trang thai hoi vien (1-Gold, 0-Thuong): ");
        scanf("%d", &member_status);

        if (topping_count < 0) {
            printf("\nCANH BAO BAO MAT: Phat hien so luong topping am!\n");
            printf("He thong dung khan cap de bao ve du lieu.\n");
            emergency_stop = 1;
            break;
        }

        if (base_price <= 0) {
            printf("Loi: Gia co so khong hop le. Bo qua hoa don %d.\n", i);
            invalid_orders++;
            continue;
        }

        if (size != 'S' && size != 'M' && size != 'L') {
            printf("Loi: Size khong hop le. Bo qua hoa don %d.\n", i);
            invalid_orders++;
            continue;
        }

        if (member_status != 0 && member_status != 1) {
            printf("Loi: Trang thai hoi vien khong hop le. Bo qua hoa don %d.\n", i);
            invalid_orders++;
            continue;
        }

        if (size == 'M') {
            size_surcharge = 6000;
        } else if (size == 'L') {
            size_surcharge = 10000;
        }

        topping_surcharge = (long long)topping_count * 8000;

        order_value = base_price + size_surcharge + topping_surcharge;

        if (member_status == 1) {
            discount_amount = order_value * 10 / 100;
            order_value -= discount_amount;
        }

        total_shift_revenue += order_value;
        valid_orders++;

        if (order_value > max_order_value) {
            max_order_value = order_value;
        }

        printf("Gia tri hoa don: %lld VND\n", order_value);
        printf("Hoa don %d: THANH TOAN THANH CONG\n", i);
    }

    printf("\n========================================\n");
    printf("        BAO CAO CHOT SO DOANH THU\n");
    printf("========================================\n");

    if (emergency_stop == 1) {
        printf("TRANG THAI: DUNG KHAN CAP\n");
    } else {
        printf("TRANG THAI: HOAN TAT CA LAM VIEC\n");
    }

    printf("Tong don hang hop le: %d\n", valid_orders);
    printf("Tong don hang loi/bi bo qua: %d\n", invalid_orders);
    printf("Tong doanh thu: %lld VND\n", total_shift_revenue);
    printf("Don hang thanh cong lon nhat: %lld VND\n", max_order_value);

    return 0;
}
