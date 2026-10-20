#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>


int z1() {

    setlocale(LC_ALL, "RUS");
    int g;

    printf("Введите год: ");
    (void)scanf("%d", &g);

    int remainder = g % 4;

    if (remainder == 0) {
        printf("Год %d високосный\n", g);
    }
    else {
        printf("Год %d не високосный\n", g);
    }

    printf("\nПроверка:\n");
    if ((g % 4 == 0 && g % 100 != 0) || (g % 400 == 0)) {
        printf("Год %d високосный\n", g);
    }
    else {
        printf("Год %d не високосный\n", g);
    }

    return 0;
}

int z2() {
    setlocale(LC_ALL, "RUS");
    printf("Вариант: %d\n", 22 % 16 + 1);

    double x;
    double F;

    printf("Введите значение x: ");
    (void)scanf("%lf", &x);

    /*
       Контрольные примеры для проверки:
       1) x = 2  -> 0 <= 2 <= 3 (истина) -> F(x) = 2^2 = 4
       2) x = 5  -> x > 3 (истина)       -> F(x) = 4
       3) x = -1 -> x < 0 (истина)       -> F(x) = 4
    */

    if (x >= 0 && x <= 3) {
        F = x * x;
    }
    else {
        F = 4.0;
    }

    printf("F(x) = %.2lf\n", F);

    return 0;
}

int DZ() {
  
        setlocale(LC_CTYPE, "RUS");

        int d, m, y, c;//день, месяц, год
        int d_in_m = 31;//дней в месяце
        int d_l = 0;//осталось дней

        printf("Введите дату (день месяц год через пробел): ");
        scanf("%d %d %d", &d, &m, &y);

        //определяем колво дней в введенном месяце
        if (m == 4 || m == 6 || m == 9 || m == 11) {
            d_in_m = 30;
        }
        else if (m == 2) {
            //проверка на високосный год
            if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
                d_in_m = 29;
            }
            else {
                d_in_m = 28;
            }
        }

        //существует ли такая дата
        if (m < 1 || m > 12 || d < 1 || d > d_in_m) {
            printf("Ошибка: Введена некорректная дата\n");
            return 1;
        }

        printf("\nЧто вы хотите посчитать?\n");
        printf("1 - Дней до конца месяца\n");
        printf("2 - Дней до конца года\n");
        printf("Ваш выбор: ");
        scanf("%d", &c);

        //расчеты до конца месяца
        if (c == 1) {
            d_l = d_in_m - d;
            printf("\nДо конца месяца осталось дней: %d\n", d_l);
        }
        else if (c == 2) {
            //расчеты до конца года, считаем остаток текущего месяца
            d_l = d_in_m - d;

            //потом прибавляем дни следующих месяцев
            for (int i = m + 1; i <= 12; i++) {
                if (i == 4 || i == 6 || i == 9 || i == 11) {
                    d_l += 30;
                }
                else if (i == 2) {
                    //если текущий год високосный - добавляем 29 дней за февраль
                    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
                        d_l += 29;
                    }
                    else {
                        d_l += 28;
                    }
                }
                else {
                    d_l += 31;
                }
            }
            printf("\nДо конца года осталось дней: %d\n", d_l);
        }
        else {
            printf("\nОшибка.\n");
        }

        return 0;
    
}

int main()
{
    DZ();
}