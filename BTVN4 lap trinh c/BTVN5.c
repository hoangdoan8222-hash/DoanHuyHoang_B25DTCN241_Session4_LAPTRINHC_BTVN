#include <stdio.h>

int main() {
    int n;
    int gia_tri_don;

    int so_don_hop_le = 0;

    long long tong_doanh_thu_goc = 0;
    long long tong_tien_giam_gia = 0;
    long long tong_doanh_thu_thuc_thu = 0;

    printf("Nhap so luong hoa don: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Loi: So luong hoa don phai lon hon 0.\n");
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        printf("Nhap gia tri don %d: ", i);
        scanf("%d", &gia_tri_don);

        if (gia_tri_don < 0) {
            printf("Don %d: Loi du lieu am! Dung he thong khan cap.\n", i);
            break;
        }

        if (gia_tri_don == 0) {
            printf("Don %d: Don hang bi huy - Bo qua\n", i);
            continue;
        }

        so_don_hop_le++;
        tong_doanh_thu_goc += gia_tri_don;

        if (gia_tri_don >= 100000) {
            long long tien_giam = (long long)gia_tri_don * 10 / 100;
            long long thanh_tien = gia_tri_don - tien_giam;

            tong_tien_giam_gia += tien_giam;
            tong_doanh_thu_thuc_thu += thanh_tien;

            printf(
                "Don %d: Ap dung giam gia 10%% (%lld VND) - Thanh tien: %lld VND\n",
                i,
                tien_giam,
                thanh_tien
            );
        } else {
            tong_doanh_thu_thuc_thu += gia_tri_don;

            printf(
                "Don %d: Hop le - Thanh tien: %d VND\n",
                i,
                gia_tri_don
            );
        }
    }

    printf("\n--- TONG KET CA BAN HANG ---\n");
    printf("So don hop le: %d\n", so_don_hop_le);
    printf("Tong doanh thu goc: %lld VND\n", tong_doanh_thu_goc);
    printf("Tong tien giam gia: %lld VND\n", tong_tien_giam_gia);
    printf("Tong doanh thu thuc thu: %lld VND\n", tong_doanh_thu_thuc_thu);

    return 0;
}
