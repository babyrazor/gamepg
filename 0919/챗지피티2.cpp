#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ī���� �� ����
#define TOTAL_CARDS 52

// ī�� ����ü ����
typedef struct {
    int order;    // ī���� �켱����
    char shape;   // ī���� ���
    char number[3];  // ī���� ���� �Ǵ� ����
} Card;

// ī�� �ʱ�ȭ �Լ�
void initializeDeck(Card deck[]) {
    char shapes[4] = {'S', 'D', 'H', 'C'}; // ���: S = �����̵�, D = ���̾Ƹ��, H = ��Ʈ, C = Ŭ�ι�
    char numbers[13][3] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"}; // 13���� ���� �Ǵ� ����

    int cardIndex = 0;
    for (int i = 0; i < 4; i++) { // 4���� ���
        for (int j = 0; j < 13; j++) { // 13���� ���� �Ǵ� ����
            deck[cardIndex].order = i; // ī���� �켱����
            deck[cardIndex].shape = shapes[i]; // ��� ����
            snprintf(deck[cardIndex].number, sizeof(deck[cardIndex].number), "%s", numbers[j]); // ���� �Ǵ� ���� ����
            cardIndex++;
        }
    }
}

// ī�� ��� �Լ�
void printDeck(Card deck[]) {
    for (int i = 0; i < TOTAL_CARDS; i++) {
        printf("%c%-3s ", deck[i].shape, deck[i].number);
        if ((i + 1) % 13 == 0) {
            printf("\n"); // ��纰�� ���
        }
    }
}

int main() {
    Card deck[TOTAL_CARDS];

    // ī�� �ʱ�ȭ
    initializeDeck(deck);

    // ī�� �� ���
    printf("ī�� ��:\n");
    printDeck(deck);

    return 0;
}

