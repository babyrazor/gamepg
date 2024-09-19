#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 카드의 총 개수
#define TOTAL_CARDS 52

// 카드 구조체 정의
typedef struct {
    int order;    // 카드의 우선순위
    char shape[4];   // 카드의 모양
    char number[3];  // 카드의 숫자 또는 문자
} Card;

// 카드 초기화 함수
void initializeDeck(Card deck[]) {
    char shapes[4][4] = {"♠", "◆", "♥", "♣"}; // 4가지 모양
    char numbers[13][3] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"}; // 13가지 숫자 또는 문자

    int cardIndex = 0;
    for (int i = 0; i < 4; i++) { // 4가지 모양
        for (int j = 0; j < 13; j++) { // 13가지 숫자 또는 문자
            deck[cardIndex].order = i; // 카드의 우선순위
            snprintf(deck[cardIndex].shape, sizeof(deck[cardIndex].shape), "%s", shapes[i]); // 모양 저장
            snprintf(deck[cardIndex].number, sizeof(deck[cardIndex].number), "%s", numbers[j]); // 숫자 또는 문자 저장
            cardIndex++;
        }
    }
}

// 카드 섞기 함수
void shuffleDeck(Card deck[]) {
    srand(time(NULL));
    for (int i = 0; i < TOTAL_CARDS; i++) {
        int rnd = rand() % TOTAL_CARDS; // 0부터 51 사이의 난수 생성
        // 카드의 위치를 교환
        Card temp = deck[i];
        deck[i] = deck[rnd];
        deck[rnd] = temp;
    }
}

// 카드 출력 함수
void printDeck(Card deck[]) {
    for (int i = 0; i < TOTAL_CARDS; i++) {
        printf("%s%-3s ", deck[i].shape, deck[i].number);
        if ((i + 1) % 13 == 0) {
            printf("\n"); // 모양별로 출력
        }
    }
}

int main() {
    Card deck[TOTAL_CARDS];

    // 카드 초기화
    initializeDeck(deck);

    // 카드 섞기 전 출력
    printf("카드 덱 (섞기 전):\n");
    printDeck(deck);

    // 카드 섞기
    shuffleDeck(deck);

    // 카드 섞은 후 출력
    printf("\n카드 덱 (섞은 후):\n");
    printDeck(deck);

    return 0;
}

