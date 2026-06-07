#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PLAYLIST_SIZE 20
#define MAX_TITLE_SIZE 30
#define MAX_ARTIST_SIZE 30

#define BALLAD 1
#define POP    2
#define ROCK   3
#define HIPHOP 4

#define BALLAD_KR "발라드"
#define POP_KR    "팝"
#define ROCK_KR   "록"
#define HIPHOP_KR "힙합"

// 곡 노드 (이중연결리스트의 노드)
typedef struct Song {
    char title[MAX_TITLE_SIZE];
    char artist[MAX_ARTIST_SIZE];
    int duration;            // 곡 길이(초)
    int genre;               // 장르 (1~4)
    struct Song *prev;
    struct Song *next;
} Song;

// 전역: 헤드 더미 노드, 현재 재생 위치 포인터
Song *head;
Song *cur;
int count;   // 실제 곡 수 (헤드 제외)

// ===== 기본 제공 함수 =====

/* Name : init_list
/* Param : None
/* Return : None
/* Description : 헤드 더미 노드를 만들고 cur 을 헤드로 초기화 */
void init_list() {
    head = (Song *)malloc(sizeof(Song));
    head->prev = NULL;
    head->next = NULL;
    cur = head;
    count = 0;
}

/* Name : is_empty, is_full, list_size
/* Param : None
/* Return : bool, bool, int
/* Description : 재생목록의 공백 / 포화 / 사이즈를 확인하는 함수 */
bool is_empty()   { return head->next == NULL; }
bool is_full()    { return count >= MAX_PLAYLIST_SIZE; }
int  list_size()  { return count; }

/* Name : make_song
/* Param : string, string, int, int
/* Return : Song*
/* Description : 새 노드를 동적 할당하여 반환 */
Song* make_song(const char *title, const char *artist, int duration, int genre) {
    Song *s = (Song *)malloc(sizeof(Song));
    strcpy(s->title, title);
    strcpy(s->artist, artist);
    s->duration = duration;
    s->genre = genre;
    s->prev = NULL;
    s->next = NULL;
    return s;
}

/* Name : print_song
/* Param : Song*
/* Return : None
/* Description : 곡 정보 한 줄 출력 */
void print_song(Song *s) {
    char g[10];
    switch (s->genre) {
        case BALLAD: strcpy(g, BALLAD_KR); break;
        case POP:    strcpy(g, POP_KR);    break;
        case ROCK:   strcpy(g, ROCK_KR);   break;
        case HIPHOP: strcpy(g, HIPHOP_KR); break;
        default: return;
    }
    printf("제목:%s, 가수:%s, 길이:%d초, 장르:%s\n",
           s->title, s->artist, s->duration, g);
}

/* Name : add_song
/* Param : string, string, int, int
/* Return : bool
/* Description : 재생목록 맨 뒤에 곡 추가 */
bool add_song(const char *title, const char *artist, int duration, int genre) {
    // 코드 작성 : 재생 목록 맨 뒤에 곡을 추가

    if(is_full()) { return false; }  // 플레이리스트가 가득 찬 경우 false를 return. (-> main함수에서 "재생목록이 가득 찼습니다" 출력)

    Song *s = make_song(title, artist, duration, genre);  // 새 Song 노드를 만들어서 s에 저장
    if(is_empty())  // 플레이리스트가 비어있다면 
    {
        head->next = s;  // head더미 뒤에 s를 연결시켜줌.
        s->prev = head;  // 이중연결리스트 이기 때문에 s도 head를 가리키게 연결해줌.
        cur = s;  // 현재 재생중인 곡을 s로 설정.
    }
    else  // 플레이리스트가 비어있지 않다면
    {
        Song *t = head;  // 마지막 노드를 찾기위해서 head부터 NULL이 나올때까지 루프를 돌게할 변수 t를 생성하고 head로 초기화.
        while(t->next != NULL) t = t->next;  // head부터 NULL이 나오기 전까지 루프를 돌며 마지막 노드를 찾음.
        t->next = s;  // 마지막 노드의 다음 노드로 s를 연결시켜줌.
        s->prev = t;  // 이중연결리스트이기 때문에 s도 t를 가리키게 연결해줌.
    }
    count++;  // 플레이리스트에 곡이 하나 추가되었으므로 count를 1 증가시킴.

    return true;
}

/* Name : play_next
/* Param : None
/* Return : None
/* Description : 다음 곡으로 이동 */
void play_next() {
    // 코드 작성 : 다음 곡으로 이동

    if(is_empty()) return; // 플레이리스트가 비어있는경우 아무 동작도 하지 않음.
    if(cur->next != NULL) cur = cur->next;  // 현재 재생중인 곡의 다음 노드가 NULL이 아니라면 현재재생중인 곡을 다음 노드로 이동.
    printf("현재 재생 : ");
    print_song(cur);  // 현재 재생중인 곡 정보 출력.

    return;
}

/* Name : play_prev
/* Param : None
/* Return : None
/* Description : 이전 곡으로 이동 */
void play_prev() {
    // 코드 작성 : 이전 곡으로 이동

    if(is_empty()) return;  // 플레이리스트가 비어있는경우 아무 동작도 하지 않음.
    if(cur->prev != head) cur = cur->prev;  // 현재 재생중인 곡의 이전 노드가 head더미 노드가 아니라면 현재재생중인 곡을 이전 노드로 이동.
    printf("현재 재생 : ");
    print_song(cur);  // 현재 재생중인 곡 정보 출력.

    return;
}

/* Name : contains
/* Param : string
/* Return : bool
/* Description : 제목이 일치하는 곡이 있는지 검색 */
bool contains(const char *title) {
    // 코드 작성

    Song *t = head;  // head더미 노드부터 시작해서 제목이 일치하는 곡이 있는지 검색하기 위한 변수 t를 생성하고 head->next로 초기화.
    while(t != NULL)  // t가 NULL이 나올 때까지 루프
    {
        if(strcmp(t->title, title)==0) { return true; }  // t의 제목과 검색하려는 제목이 일치한다면 true를 반환.
        t = t->next;  // t를 다음 노드로 이동.
    }
    
    return false;  // 루프를 다 돌았음에도 제목이 일치하는 곡이 없다면 false를 반환.
}

/* Name : insert_next
/* Param : string, string, int, int
/* Return : bool
/* Description : 현재 재생 곡(cur) 바로 뒤에 새 노드 삽입 */
bool insert_next(const char *title, const char *artist, int duration, int genre) {
    // 코드 작성 : 재생목록이 비어 있는 경우는 첫 곡이 되고 cur 도 새 노드를 가리키고, 아니라면 현재 재생 곡 바로 뒤에 새 노드 삽입
    
    if(is_full()) return false;  // 플레이리스트가 가득 찬 경우 false를 return. (-> main함수에서 "재생목록이 가득 찼습니다" 출력)

    Song *s = make_song(title, artist, duration, genre);  // 새 Song 노드를 만들어서 s에 저장
    if(is_empty())  // 플레이리스트가 비어있는 경우
    {
        head->next = s;  // head더미 뒤에 s를 연결시켜줌.
        s->prev = head;  // 이중연결리스트 이기 때문에 s도 head를 가리키게 연결해줌.
        cur = s;  // 현재 재생중인 곡을 s로 설정.
    }
    else  // 플레이리스트가 비어있지 않은 경우
    {
        s->next = cur->next;  // s의 다음 노드를 현재 재생중인 곡의 다음 노드로 설정.
        if(cur->next != NULL) { cur->next->prev = s; }  // 현재 재생중인 곡의 다음 노드가 NULL이 아니라면 현재 재생중인 곡의 다음 노드의 이전 노드를 s로 설정.
        s->prev = cur;  // s의 이전 노드를 현재 재생중인 곡으로 설정.
        cur->next = s;  // 현재 재생중인 곡의 다음 노드를 s로 설정.
        
    }
    count++;  // 플레이리스트에 곡이 하나 추가되었으므로 count를 1 증가시킴.
    
    return true;
}

/* Name : delete_by_title
/* Param : string
/* Return : bool
/* Description : 제목으로 곡을 찾아 삭제. 현재 재생 곡 삭제 시 cur 이동 처리. */
bool delete_by_title(const char *title) {
    // 코드 입력 : 제목으로 곡을 찾아 삭제하는데, 없는 곡이라면 false 반환. cur이 삭제 대상이면 cur을 옮김.
    // 옮기는 경우는 다음 곡이 있다면 next로 이동
    // 이전 곡이 존재하고, 이전 곡이 헤드 노드가 아니라면 이전곡으로 이동
    // 둘다 아니라면 cur은 head 노드를 가리키게 함

    Song *t = head;  // head부터 시작해서 제목이 일치하는 곡을 찾기 위한 변수 t를 생성하고 head로 초기화.
    while(t != NULL)  // t가 NULL이 나올 때까지 루프
    {
        if(strcmp(t->title, title)==0) break;  // t의 제목과 검색하려는 제목이 일치한다면 루프를 빠져나옴. t는 삭제하려는 곡을 가리키게 됨.
        t = t->next;  // t를 다음 노드로 이동.
    }
    if(t == NULL) return false; // 루프를 다 돌았음에도 제목이 일치하는 곡이 없다면 false를 반환.

    if(t == cur)  // 삭제하려는 곡이 현재 재생중인 곡이라면
    {
        if(t->next != NULL)  // 다음 곡이 존재한다면
        {
            cur = t->next;  // 현재 재생중인 곡을 다음 곡으로 이동.
            t->prev->next = t->next;  // t의 이전 노드의 다음 노드를 t의 다음 노드로 설정.
            t->next->prev = t->prev;  // t의 다음 노드의 이전 노드를 t의 이전 노드로 설정.
            free(t);  // t가 가리키는 노드를 메모리에서 해제.
        }
        else if((t->prev != NULL) || (t->prev != head))  // 다음 곡이 없고, 이전 곡이 존재하거나, 이전 곡이 헤드 노드가 아니라면
        {
            cur = t->prev;  // 현재 재생중인 곡을 이전 곡으로 이동.
            t->prev->next = NULL;  // t의 이전 노드의 다음 노드를 NULL로 설정. (t를 삭제하면 t의 이전 노드가 마지막 노드가 되기 때문)
            free(t);  // t가 가리키는 노드를 메모리에서 해제.
        }
        else { cur = head; }  // 다음 곡도 없고, 이전 곡도 없거나 이전 곩이 헤드 노드라면 현재 재생중인 곡을 head로 이동.(플레이리스트가 비어있는 상태)
    }
    else  // 삭제하려는 곡이 현재 재생중인 곡이 아니라면
    {
        t->prev->next = t->next;  // t의 이전 노드의 다음 노드를 t의 다음 노드로 설정.
        if(t->next != NULL) { t->next->prev = t->prev; }  // t의 다음 노드가 NULL이 아니라면 t의 다음 노드의 이전 노드를 t의 이전 노드로 설정.
        free(t);  // t가 가리키는 노드를 메모리에서 해제.
    }
    count--;  // 플레이리스트에서 곡이 하나 삭제되었으므로 count를 1 감소시킴.

    return true;
}

// ===== 학생 작성 부분 끝 =====

/* Name : print_status
/* Param : None
/* Return : None
/* Description : 재생목록 전체 출력 (현재 재생 곡 앞에는 ▶ 표시) */
void print_status() {
    printf("playlist : %d\n", list_size());
    Song *p = head->next;
    int idx = 1;
    while (p != NULL) {
        if (p == cur) printf("▶ ");
        printf("%d.", idx++);
        print_song(p);
        p = p->next;
    }
}

int main() {
    int choice;
    char title[MAX_TITLE_SIZE];
    char artist[MAX_ARTIST_SIZE];
    int duration;
    int genre;

    printf("프로그램 시작\n");
    init_list();

    printf("1.곡 추가  2.다음 재생 추가  3.곡 삭제  4.다음 곡  5.이전 곡  6.곡 검색  7.상태 확인  8.종료\n");

    while (1) {
        printf("원하는 기능의 번호를 입력하세요 : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            case 2:
                printf("곡 제목을 입력하세요 : ");
                scanf("%s", title);
                printf("가수를 입력하세요 : ");
                scanf("%s", artist);
                do {
                    printf("길이(초)를 입력하세요(1~1800) : ");
                    scanf("%d", &duration);
                } while (duration < 1 || duration > 1800);
                printf("1.발라드  2.팝  3.록  4.힙합\n");
                do {
                    printf("장르를 선택하세요 : ");
                    scanf("%d", &genre);
                } while (genre < 1 || genre > 4);

                if (choice == 1) {
                    if (add_song(title, artist, duration, genre)) printf("추가 완료\n");
                    else printf("재생목록이 가득 찼습니다\n");
                } else {
                    if (insert_next(title, artist, duration, genre)) printf("추가 완료\n");
                    else printf("재생목록이 가득 찼습니다\n");
                }
                break;

            case 3:
                printf("삭제할 곡 제목을 입력하세요 : ");
                scanf("%s", title);
                if (delete_by_title(title)) printf("삭제 완료\n");
                else printf("해당 곡이 없습니다\n");
                break;

            case 4:
                play_next();
                break;

            case 5:
                play_prev();
                break;

            case 6:
                printf("검색할 곡 제목을 입력하세요 : ");
                scanf("%s", title);
                if (contains(title)) printf("존재하는 곡입니다\n");
                else                 printf("존재하지 않는 곡입니다\n");
                break;

            case 7:
                print_status();
                break;

            case 8:
                printf("시스템 종료");
                return 0;

            default:
                printf("잘못된 입력입니다\n");
                break;
        }
    }
}