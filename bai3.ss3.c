#include <stdio.h>

int main() {
    int tuoi;
    int mac_phim;
    int suat_chieu;
    int loai_ghe;
    int la_ngay_thuong;
    int doi_tuong;

    printf("=== HỆ THỐNG QUẢN LÝ BÁN VÉ CGV CINEMA ===\n");
    printf("Nhập tuổi của khách hàng: ");
    if (scanf("%d", &tuoi) != 1) return 0;

    if (tuoi < 0 || tuoi > 120) {
        printf("Lỗi: Số tuổi nhập vào không hợp lệ!\n");
        return 0;
    }

    printf("Nhập mác phim (1: P, 2: T16, 3: T18): ");
    if (scanf("%d", &mac_phim) != 1) return 0;

    if (mac_phim == 2 && tuoi < 16) {
        printf("Từ chối bán vé: Phim T16 yêu cầu khán giả từ 16 tuổi trở lên!\n");
        return 0;
    } else if (mac_phim == 3 && tuoi < 18) {
        printf("Từ chối bán vé: Phim T18 cấm khán giả dưới 18 tuổi!\n");
        return 0;
    } else if (mac_phim != 1 && mac_phim != 2 && mac_phim != 3) {
        printf("Lỗi: Mã phân loại phim không hợp lệ!\n");
        return 0;
    }

    printf("Nhập suất chiếu (1: Sáng, 2: Chiều, 3: Tối): ");
    if (scanf("%d", &suat_chieu) != 1) return 0;

    int gia_ve_goc = 0;
    switch (suat_chieu) {
        case 1:
            gia_ve_goc = 70000;
            break;
        case 2:
            gia_ve_goc = 90000;
            break;
        case 3:
            gia_ve_goc = 120000;
            break;
        default:
            printf("Lỗi: Lựa chọn suất chiếu không nằm trong menu!\n");
            return 0;
    }

    printf("Nhập loại ghế (1: Thường, 2: VIP, 3: Couple): ");
    if (scanf("%d", &loai_ghe) != 1) return 0;

    int phu_thu_ghe = 0;
    char* ten_ghe = "";
    switch (loai_ghe) {
        case 1:
            phu_thu_ghe = 0;
            ten_ghe = "Ghế Thường";
            break;
        case 2:
            phu_thu_ghe = 15000;
            ten_ghe = "Ghế VIP";
            break;
        case 3:
            phu_thu_ghe = 30000;
            ten_ghe = "Ghế Couple";
            break;
        default:
            printf("Lỗi: Loại ghế không hợp lệ!\n");
            return 0;
    }

    printf("Có phải ngày thường không? (1: Có, 0: Không): ");
    if (scanf("%d", &la_ngay_thuong) != 1) return 0;

    printf("Nhập đối tượng (1: HSSV, 2: Người cao tuổi, 3: Thường): ");
    if (scanf("%d", &doi_tuong) != 1) return 0;

    double tien_giam = 0.0;
    if (la_ngay_thuong == 1) {
        if (doi_tuong == 1) {
            tien_giam = gia_ve_goc * 0.20;
        } else if (doi_tuong == 2 || tuoi >= 60) {
            tien_giam = gia_ve_g