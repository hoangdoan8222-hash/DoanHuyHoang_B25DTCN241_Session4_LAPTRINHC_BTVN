#include <stdio.h>

int main() {
    int total_orders;
    int order_status;
    int size;
    int topping_count;
    int member_status;

    long long base_price;
    long long size_surcharge;
    long long topping_surcharge;
    long long order_total;
    long long discount_amount;
    long long total_revenue = 0;

    int successful_orders = 0;
    int skipped_orders = 0;

    printf("=== HIGHLANDS COFFEE POS TRANSACTION ENGINE ===\n");
    printf("Nhap tong so don hang trong ca: ");
    scanf("%d", &total_orders);

    if (total_orders <= 0) {
        printf("Loi: So luong don hang phai lon hon 0!\n");
        return 0;
    }

    for (int i = 1; i <= total_orders; i++) {
        printf("\n========== DON HANG %d ==========\n", i);

        printf("Nhap ma trang thai don hang:\n");
        printf("1 - Thanh toan\n");
        printf("2 - Huy/loi don hang\n");
        printf("3 - Dung ca khan cap\n");
        printf("Lua chon: ");
        scanf("%d", &order_status);

        if (order_status == 3) {
            printf("\nCANH BAO: Nhan tin hieu DUNG CA KHAN CAP!\n");
            printf("He thong ngat xu ly va chot doanh thu hien tai.\n");
            break;
        }

        if (order_status == 2) {
            printf("Don hang %d bi huy/loi. Bo qua.\n", i);
            skipped_orders++;
            continue;
        }

        if (order_status != 1) {
            printf("Loi: Ma trang thai don hang khong hop le. Bo qua.\n");
            skipped_orders++;
            continue;
        }

        printf("Nhap gia goc Size S (VND): ");
        scanf("%lld", &base_price);

        printf("Nhap Size (1-S, 2-M, 3-L): ");
        scanf("%d", &size);

        printf("Nhap so luong topping: ");
        scanf("%d", &topping_count);

        printf("Nhap trang thai thanh vien (1-Gold, 0-Thuong): ");
        scanf("%d", &member_status);

        if (base_price <= 0) {
            printf("Loi: Gia goc khong hop le. Bo qua don hang.\n");
            skipped_orders++;
            continue;
        }

        if (size < 1 || size > 3) {
            printf("Loi: Size khong hop le. Bo qua don hang.\n");
            skipped_orders++;
            continue;
        }

        if (topping_count < 0) {
            printf("Loi: So luong topping khong duoc am. Bo qua don hang.\n");
            skipped_orders++;
            continue;
        }

        if (member_status != 0 && member_status != 1) {
            printf("Loi: Trang thai thanh vien khong hop le. Bo qua don hang.\n");
            skipped_orders++;
            continue;
        }

        size_surcharge = 0;

        if (size == 2) {
            size_surcharge = 6000;
        } else if (size == 3) {
            size_surcharge = 10000;
        }

        topping_surcharge = (long long)topping_count * 8000;

        order_total = base_price + size_surcharge + topping_surcharge;

        discount_amount = 0;

        if (member_status == 1) {
            discount_amount = order_total * 10 / 100;
            order_total -= discount_amount;
        }

        total_revenue += order_total;
        successful_orders++;

        printf("\nThanh tien: %lld VND\n", order_total);
        printf("Giam gia: %lld VND\n", discount_amount);
        printf("Don hang %d: THANH TOAN THANH CONG\n", i);
    }

    printf("\n========================================\n");
    printf("       BAO CAO TONG KET CA BAN HANG\n");
    printf("========================================\n");
    printf("So don thanh cong: %d\n", successful_orders);
    printf("So don huy/bo qua: %d\n", skipped_orders);
    printf("Tong doanh thu: %lld VND\n", total_revenue);
    printf("========================================\n");

    return 0;
}
