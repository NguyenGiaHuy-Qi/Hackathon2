#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n = 0, choice;
    int arr[100];
    do {
        printf("========Menu========\n");
        printf("1. Nhap phan tu va cac gia tri vao mang\n");
        printf("2. In ra cac phan tu\n");
        printf("3. Dem cac phan tu chan le trong mang\n");
        printf("4. Tim gia tri lon thu 2 trong mang\n");
        printf("5. Them mot phan tu vao dau mang\n");
        printf("6. Xoa phan tu\n");
        printf("7. Sap xep mang theo thu tu giam dan\n");
        printf("8. Nhap va tim phan tu\n");
        printf("9. In ra so nguyen to duoc binh phuong\n");
        printf("10. Sap xep theo thu tu giam dan\n");
        printf("Lua chon cua ban la: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("Nhap so phan tu vao mang: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Nhap phan tu arr[%d]: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;
            }
            case 2: {
                printf("-----Gia tri cac phan tu vua nhap la: \n");
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = %d\n", i + 1, arr[i]);
                }
                break;
            }
            case 3: {
                int chan = 0;
                int le = 0;
                for (int i = 0; i < n; i++) {
                    if (arr[i] % 2 == 0) {
                        chan++;
                    } else {
                        le++;
                    }
                }
                printf("-----So phan tu chan la: %d\n", chan);
                printf("-----So phan tu le la: %d\n", le);
                break;
            }
            case 4: {
                if (n < 2) {
                    printf("-----Khong co gia tri lon thu 2\n");
                } else {
                    int initial = arr[0], second = -1;
                    for (int i = 0; i < n; i++) {
                        if (arr[i] > initial) {
                            second = initial;
                            initial = arr[i];
                        } else if (arr[i] > second && arr[i] < initial) {
                            second = arr[i];
                        }
                    }
                    if (second != -1) {
                        printf("-----Gia tri lon thu 2 trong mang la %d\n", second);
                    } else {
                        printf("-----Khong tim thay gia tri lon thu hai.\n");
                    }
                }
                break;
            }
            case 5: {
                if (n >= 100) {
                    printf("-----Khong the them\n");
                } else {
                    int newval;
                    printf("-----Nhap phan tu muon them: ");
                    scanf("%d", &newval);
                    for (int i = n; i > 0; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[0] = newval;
                    n++;
                }
                break;
            }
            case 6: {
                int position;
                printf("-----Nhap vi tri ban muon xoa: ");
                scanf("%d", &position);
                if (position < 1 || position > n) {
                    printf("-----Vi tri khong hop le\n");
                } else {
                    for (int i = position - 1; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                }
                break;
            }
            case 7: {
                for (int i = 0; i < n; i++) {
                    int key = arr[i];
                    int j = i - 1;
                    while (j >= 0 && arr[j] < key) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                printf("-----Mang da duoc sap xep\n");
                break;
            }
            case 8: {
                int search;
                printf("Nhap vao mot gia tri de tim: ");
                scanf("%d", &search);
                int left = 0, right = n - 1;
                int foundindex = -1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (arr[mid] == search) {
                        foundindex = mid;
                        break;
                    } else if (arr[mid] < search) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                
                if (foundindex != -1) {
                    printf("-----Phan tu %d tai vi tri %d\n", search, foundindex + 1);
                } else {
                    printf("-----Khong tim thay\n");
                }
                break;
            }
            case 9: {
                printf("Cac so nguyen to duoc binh phuong trong mang la: ");
                int hasPrime = 0;
                for (int i = 0; i < n; i++) {
                    int isPrime = 1;
                    if (arr[i] < 2) {
                        isPrime = 0;
                    } else {
                        for (int j = 2; j * j <= arr[i]; j++) {
                            if (arr[i] % j == 0) {
                                isPrime = 0;
                                break;
                            }
                        }
                    }
                    if (isPrime) {
                        printf("%d ", arr[i] * arr[i]);
                        hasPrime = 1;
                    }
                }
                if (!hasPrime) {
                    printf("Khong co so nguyen to nao trong mang.\n");
                }
                printf("\n");
                break;
            }
            case 10: {
                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (arr[j] < arr[j + 1]) {
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                printf("Mang da duoc sap xep\n");
                break;
            }
        }
    } while (choice <= 10);
    return 0;
}