#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STACK_SIZE 20
#define MAX_INPUT_SIZE 10
#define ERROR_SUCCESS 0
#define ERROR_FAIL -1

char Stack[MAX_STACK_SIZE] = {0, };
char TmpStack[MAX_STACK_SIZE] = {0, };
int BaseStack[MAX_STACK_SIZE] = {0, };
int top = 0;
int tmpTop = 0;
int baseTop = 0;

void initStack();
bool isEmpty();
bool isFull();
int push(char value);
bool isStackAvailable(int inputSize);
char pop();
bool isTmpEmpty();
int tmpPush(char value);
char tmpPop();
int basePush(int value);
int basePop();
int basePeek();
void popAndReverseMessage();
void popAndShiftMessage();
void peekMaskedMessage();

/* Name : initStack
/* Param : None
/* Return : None
/* Description : 스택을 초기화 하는 함수 */
void initStack() {
    top = -1;
    baseTop = -1;
    tmpTop = -1;
}

/* Name : isEmpty
/* Param : None;
/* Return : true, false
/* Description : 스택이 비어있는지 확인하는 함수 */
bool isEmpty() {
    return -1 == top;
}

/* Name : isFull
/* Param : None
/* Return : true, false
/* Description : 스택이 가득 차있는지 확인하는 함수 */
bool isFull() {
    return MAX_STACK_SIZE - 1 == top;
}

/* Name : push
/* Param : char value
/* Return : top, ERROR_FAIL
/* Description : 스택에 데이터를 저장하는 함수 */
int push(char value) {
    if (!isFull()) {
        Stack[++top] = value;
        return top;
    } else {
        return ERROR_FAIL;
    }
}

/* Name : isStackAvailable
/* Param : int inputSize
/* Return : true, false
/* Description : 스택에 데이터 저장이 가능한지 확인하는 함수 */
bool isStackAvailable(int inputSize) {
    char answer;
    if (top + inputSize > MAX_STACK_SIZE - 1) {
        printf("스택 공간이 부족합니다.\n");
        printf("스택 공간을 초기화하고 저장하시겠습니까? 실행할 경우 기존 데이터가 삭제됩니다.");
        getchar();
        scanf("%c", &answer);

        if (answer == 'y') {
            initStack();
            printf("스택을 초기화 후 현재 데이터를 저장합니다. \n");
            return true;
        } else {
            printf("현재 입력 값은 무시됩니다.\n");
            return false;
        }
    } else {
        return true;
    }
}

/* Name : pop
/* Param : None
/* Return : char, NULL
/* Description : 스택에 저장된 값을 꺼내는 함수 */
char pop() {
    if (isEmpty()) {
        return '\0';
    }
    int topIndex = top;
    return Stack[top--];
}

/* Name : isTmpEmpty
/* Param : None
/* Return : true, false
/* Description : Tmp 스택이 비어있는지 확인하는 함수 */
bool isTmpEmpty() {
    return -1 == tmpTop;
}

/* Name : tmpPush
/* Param : char value
/* Return : int
/* Description : Tmp 스택에 데이터를 저장하는 함수 */
int tmpPush(char value) {
    TmpStack[++tmpTop] = value;
    return tmpTop;
}

/* Name : tmpPop
/* Param : None
/* Return : char, NULL
/* Description : Tmp 스택에 저장된 값을 꺼내는 함수
*/
char tmpPop() {
    if (isTmpEmpty()) {
        return '\0';
    }
    return TmpStack[tmpTop--];
}

/* Name : basePush
/* Param : int value
/* Return : baseTop
/* Description : Base 스택에 데이터를 저장하는 함수 */
int basePush(int value) {
    BaseStack[++baseTop] = value;
    return baseTop;
}

/* Name : basePop
/* Param : None
/* Return : int
/* Description : Base 스택에 저장된 값을 꺼내는 함수
*/
int basePop() {
    return BaseStack[baseTop--];
}

/* Name : basePeek
/* Param : None
/* Return : int
/* Description : Base 스택의 최상위 값을 조회하는 함수 */
int basePeek() {
    return BaseStack[baseTop];
}

/* Name : popAndReverseMessage
/* Param : None
/* Return : None 
/* Description : 스택에서 가장 최근 입력된 메시지를 꺼내어 거꾸로 출력하고 삭제하는 함수 */
void popAndReverseMessage() {
    if (isEmpty()) {
        printf("스택이 비어있습니다.\n");
        return;
    }

    // 코드 작성 : top과 basePop을 통해 직전 입력 메시지를 거꾸로 출력하고 스택에서 삭제
    printf("\n");
}

/* Name : popAndShiftMessage
/* Param : None
/* Return : None
/* Descriptiion : 스택에서 가장 최근 입력된 메시지를 원래 순서대로 꺼내되, 
/* 각 알파벳의 ASCII Code를 +1 쉬프트 하여 암호화하고 출력하고 삭제하는 함수 */
void popAndShiftMessage() {
    if (isEmpty()) {
        printf("스택이 비어있습니다. \n");
        return;
    }

    // 코드 작성 : TmpStack을 활용하여 메시지를 원래 순서대로 맞추고, 각 문자에 +1을 더해 출력.(예 : abc -> bcd)
    printf("\n");
}

/* Name : peekMaskedMessage 
/* Param : None 
/* Return : None
/* Description : 스택에서 가장 최근 입력된 메시지의 길이만큼 '*'로 마스킹하여 출력하는 함수. 삭제하지 않음 */
void peekMaskedMessage() {
    if (isEmpty()) {
        printf("스택이 비어있습니다.\n");
        return;
    }
    
    // 코드 작성 : 메시지를 삭제하지 않고, 가장 최근에 입력된 단어의 길이만큼 '*' 출력.
    printf("\n"); 
}

int main() {
    int nMenu = 0, inputSize = 0;
    char inputString[MAX_INPUT_SIZE] = {0, };

    initStack();

    // printf("===== Level2 Test =====\n\n");
    // printf("1. 비밀 메시지 입력(10자 이내 소문자)\n");
    // printf("2. 최근 메시지 단순 해독 (거꾸로 출력, 메모리에서 삭제)\n") // 예 : hello -> olleh
    // 시프트 암호 : 각 글자를 알파벳 순서상 다음 글자로 바꿈
    // printf("3. 최근 메시지 시프트 암호화 (원래 순서대로 각 알파벳 + 1, 메모리에서 삭제)\n"); // 예 : abc -> bcd
    // printf("4. 최근 메시지 길이 확인 (전부 *로 가려서 출력, 메모리에서 삭제하지 않음)\n"); // 예 : hello -> *****
    // printf("5. 현재 스택에 저장된 총 메시지(단어) 개수 출력, 메모리에서 삭제하지 않음\n");
    // printf("6. 프로그램 종료\n\n");

    while(1) {
        printf("원하는 기능의 번호를 입력하세요 : ");
        scanf("%d", &nMenu);
        getchar();

        switch(nMenu) {
            case 1: {
                printf("메시지를 입력하세요 : ");
                scanf("%s", inputString);
                inputSize = (int) strlen(inputString);
                if (isStackAvailable(inputSize)) {
                    for (int i = 0; i < inputSize; i++) {
                        push(inputString[i]);
                    }
                    basePush(top + 1 - inputSize);
                    printf("\n");
                    for(int i=0; i<10; i++)
                    {
                        printf("%d ", BaseStack[i]);
                    }
                    printf("\n");
                }
                break;
            }

            case 2: {
                popAndReverseMessage();
                break;
            }

            case 3: {
                popAndShiftMessage();
                break;
            }

            case 4: {
                peekMaskedMessage();
                break;
            }

            case 5: {
                int answer = 0;
                
                // 코드 작성 : answer 값에 현재 스택에 쌓여있는 단어(메시지)의 총 개수를 할당.

                printf("현재 저장된 메시지 매수 : %d\n", answer);
                break;
            }

            case 6: {
                printf("프로그램 종료\n");
                return ERROR_SUCCESS;
            }
            default :
                printf("입력이 잘못 되었습니다.\n");
        }
    }
}