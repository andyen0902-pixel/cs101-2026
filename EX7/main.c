#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, lotto[7];
    int i, j, k, num, duplicate;

    srand(time(NULL));

    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩：");
    scanf("%d", &n);

    if (n < 1 || n > 5) {
        printf("輸入錯誤！請輸入 1~5\n");
        return 0;
    }

    FILE *fp = fopen("lotto.txt", "w");

    if (fp == NULL) {
        printf("檔案開啟失敗！\n");
        return 1;
    }

    time_t now = time(NULL);
    char date[100];

    strftime(date, sizeof(date), "%a %b %d %H:%M:%S %Y",
             localtime(&now));

    fprintf(fp, "======== lotto649 ========\n");
    fprintf(fp, "= %s =\n", date);

    for (i = 0; i < 5; i++) {
        fprintf(fp, "[%d]: ", i + 1);

        if (i < n) {
            for (j = 0; j < 7; j++) {
                do {
                    num = rand() % 69 + 1;
                    duplicate = 0;

                    for (k = 0; k < j; k++) {
                        if (lotto[k] == num) {
                            duplicate = 1;
                            break;
                        }
                    }
                } while (duplicate == 1);

                lotto[j] = num;
            }

            for (j = 0; j < 7; j++) {
                fprintf(fp, "%02d ", lotto[j]);
            }
        } else {
            for (j = 0; j < 7; j++) {
                fprintf(fp, "-- ");
            }
        }

        fprintf(fp, "\n");
    }

    fprintf(fp, "======== csie@CGU ========\n");

    fclose(fp);

    printf("已為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);

    return 0;
}
