#include <stdio.h>
#include <string.h>

typedef struct {
    int Aviareysa;
    char VremaVilita[20];
    char VremaPrilota[20];
    char Napravlenie[20];
    char MarkaSamoleta[20];
    int Rastoianie;
} Reys;

void findAndPrintLongestFlightDuration(const Reys flights[], int numFlights) {
    int longestIndex = 0;
    int longestDuration;
    sscanf(flights[longestIndex].VremaPrilota, "%d", &longestDuration);

    for (int i = 0; i < numFlights; i++) {
        int duration;
        sscanf(flights[i].VremaPrilota, "%d", &duration);
        if (duration > longestDuration) {
            longestIndex = i;
            longestDuration = duration;
        }
    }

    printf("Авиарейс с максимальной длительностью полета: %d\n", flights[longestIndex].Aviareysa);
    printf("Продолжительность полета: %s\n", flights[longestIndex].VremaPrilota);
    printf("Направление: %s\n", flights[longestIndex].Napravlenie);
    printf("Марка самолета: %s\n", flights[longestIndex].MarkaSamoleta);
    printf("Расстояние: %d\n", flights[longestIndex].Rastoianie);
}

int main() {
    const int N = 100;

    Reys Samolety[N];
    int i, M;
    FILE* F;
    char s[80];

    F = fopen("Samoleti.dat", "rb");
    if (!F) {
        perror("Ошибка открытия файла Samoleti.dat для чтения");
        return 1;
    }

    M = fread(Samolety, sizeof(Reys), N, F);
    fclose(F);

    printf("Имеющиеся данные о рейсах:\n");
    for (i = 0; i < M; i++) {
        printf("Aviareysa: %d\n", Samolety[i].Aviareysa);
        printf("Vrema vilita: %s\n", Samolety[i].VremaVilita);
        printf("Vrema prilota: %s\n", Samolety[i].VremaPrilota);
        printf("Napravlenie: %s\n", Samolety[i].Napravlenie);
        printf("Marka samoleta: %s\n", Samolety[i].MarkaSamoleta);
        printf("Rastoianie: %d\n", Samolety[i].Rastoianie);
    }

    if (M < N) {
        printf("\nВведите поля новой структуры:\n");
        
        printf("Aviareysa: ");
        scanf("%d", &Samolety[M].Aviareysa);

        printf("Vrema vilita: ");
        fgets(s, sizeof(s), stdin);
        strncpy(Samolety[M].VremaVilita, s, sizeof(Samolety[M].VremaVilita) - 1);
        Samolety[M].VremaVilita[strcspn(Samolety[M].VremaVilita, "\n")] = '\0';

        printf("Vrema prilota: ");
        fgets(s, sizeof(s), stdin);
        strncpy(Samolety[M].VremaPrilota, s, sizeof(Samolety[M].VremaPrilota) - 1);
        Samolety[M].VremaPrilota[strcspn(Samolety[M].VremaPrilota, "\n")] = '\0';

        printf("Napravlenie: ");
        fgets(s, sizeof(s), stdin);
        strncpy(Samolety[M].Napravlenie, s, sizeof(Samolety[M].Napravlenie) - 1);
        Samolety[M].Napravlenie[strcspn(Samolety[M].Napravlenie, "\n")] = '\0';

        printf("Marka samoleta: ");
        fgets(s, sizeof(s), stdin);
        strncpy(Samolety[M].MarkaSamoleta, s, sizeof(Samolety[M].MarkaSamoleta) - 1);
        Samolety[M].MarkaSamoleta[strcspn(Samolety[M].MarkaSamoleta, "\n")] = '\0';

        printf("Rastoianie: ");
        scanf("%d", &Samolety[M].Rastoianie);

        M++;

        F = fopen("Samoleti.dat", "wb");
        if (!F) {
            perror("Ошибка открытия файла Samoleti.dat для записи");
            return 1;
        }

        fwrite(Samolety, sizeof(Reys), M, F);
        fclose(F);
    }

    findAndPrintLongestFlightDuration(Samolety, M);

    return 0;
}
