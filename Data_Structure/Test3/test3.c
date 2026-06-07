#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WAITING_SIZE 20
#define MAX_ROOM_SIZE 10
#define MAX_NAME_SIZE 20

#define INTERNAL 1
#define SURGERY 2
#define NEURO 3

#define INTERNAL_KR "내과"
#define SURGERY_KR "외과"
#define NEURO_KR "신경과"

// Patient 구조체 정의
typedef struct Patient {
    char name[MAX_NAME_SIZE];
    int age;
    int dept;         // 진료과 (1/2/3)
    bool isUrgent;    // 응급 여부
} Patient;

// 덱 저장소 및 front/rear
Patient waiting[MAX_WAITING_SIZE];
int waitingFront, waitingRear;

Patient internal[MAX_ROOM_SIZE];
int internalFront, internalRear;

Patient surgery[MAX_ROOM_SIZE];
int surgeryFront, surgeryRear;

Patient neuro[MAX_ROOM_SIZE];
int neuroFront, neuroRear;

// 에러용 Patient
Patient ERROR_PATIENT = {0, };

/* Name : init_deque
/* Param : None
/* Return : None
/* Description : 모든 덱을 초기화 하는 함수 */
void init_deque() {
    waitingFront = waitingRear = 0;
    internalFront = internalRear = 0;
    surgeryFront = surgeryRear = 0;
    neuroFront = neuroRear = 0;
}

/* Name : is_waiting_empty, is_internal_empty, is_surgery_empty, is_neuro_empty
/* Param : None
/* Return : bool
/* Description : 각 덱이 비어있는지 확인하는 함수 */
bool is_waiting_empty()  { return waitingFront == waitingRear; }
bool is_internal_empty() { return internalFront == internalRear; }
bool is_surgery_empty()  { return surgeryFront == surgeryRear; }
bool is_neuro_empty()    { return neuroFront == neuroRear; }

/* Name : is_waiting_full, is_internal_full, is_surgery_full, is_neuro_full
/* Param : None
/* Return : bool
/* Description : 덱이 가득 차있는지 확인하는 함수 */
bool is_waiting_full()  { return waitingFront == (waitingRear + 1) % MAX_WAITING_SIZE; }
bool is_internal_full() { return internalFront == (internalRear + 1) % MAX_ROOM_SIZE; }
bool is_surgery_full()  { return surgeryFront == (surgeryRear + 1) % MAX_ROOM_SIZE; }
bool is_neuro_full()    { return neuroFront == (neuroRear + 1) % MAX_ROOM_SIZE; }

/* Name : waiting_size, internal_size, surgery_size, neuro_size
/* Param : None
/* Return : int
/* Description : 각 덱의 사이즈를 확인 하는 함수 */
int waiting_size()  { return (waitingRear - waitingFront + MAX_WAITING_SIZE) % MAX_WAITING_SIZE; }
int internal_size() { return (internalRear - internalFront + MAX_ROOM_SIZE) % MAX_ROOM_SIZE; }
int surgery_size()  { return (surgeryRear - surgeryFront + MAX_ROOM_SIZE) % MAX_ROOM_SIZE; }
int neuro_size()    { return (neuroRear - neuroFront + MAX_ROOM_SIZE) % MAX_ROOM_SIZE; }

/* Name : add_waiting_rear
/* Param : Patient
/* Return : None
/* Description : 일반 환자 대기실에 추가 */
void add_waiting_rear(Patient p) {
    // 코드 작성 : 일반 환자를 대기실에 추가하는 코드 작성.
    
}

/* Name : add_waiting_front
/* Param : Patient
/* Return : None
/* Description : 응급 환자 대기실에 추가 */
void add_waiting_front(Patient p) {
    // 코드 작성 : 응급 환자를 대기실에 추가하는 코드 작성
    
}

/* Name : add_room_rear
/* Param : Patient
/* Return : None
/* Description : 일반 환자 해당 진료실에 추가 */
void add_room_rear(Patient p) {
    switch (p.dept) {
        case INTERNAL:
            if (is_internal_full()) return;
            internalRear = (internalRear + 1) % MAX_ROOM_SIZE;
            internal[internalRear] = p;
            break;
        case SURGERY:
            if (is_surgery_full()) return;
            surgeryRear = (surgeryRear + 1) % MAX_ROOM_SIZE;
            surgery[surgeryRear] = p;
            break;
        case NEURO:
            if (is_neuro_full()) return;
            neuroRear = (neuroRear + 1) % MAX_ROOM_SIZE;
            neuro[neuroRear] = p;
            break;
    }
}

/* Name : add_room_font
/* Param : Patient
/* Return : None
/* Description : 응급 환자 해당 진료실에 추가 */
void add_room_front(Patient p) {
    switch (p.dept) {
        case INTERNAL:
            if (is_internal_full()) break;
            internal[internalFront] = p;
            internalFront = (internalFront - 1 + MAX_ROOM_SIZE) % MAX_ROOM_SIZE;
            break;
        case SURGERY:
            if (is_surgery_full()) break;
            surgery[surgeryFront] = p;
            surgeryFront = (surgeryFront - 1 + MAX_ROOM_SIZE) % MAX_ROOM_SIZE;
            break;
        case NEURO:
            if (is_neuro_full()) break;
            neuro[neuroFront] = p;
            neuroFront = (neuroFront - 1 + MAX_ROOM_SIZE) % MAX_ROOM_SIZE;
            break;
    }
}

/* Name : delete_wating_front, delete_internal_front, delete_surgery_front, delete_neuro_front
/* Param : None
/* Return : Patient
/* Description : 각 덱의 front 삭제 */
Patient delete_waiting_front() {
    if (is_waiting_empty()) return ERROR_PATIENT;
    waitingFront = (waitingFront + 1) % MAX_WAITING_SIZE;
    return waiting[waitingFront];
}
Patient delete_internal_front() {
    if (is_internal_empty()) return ERROR_PATIENT;
    internalFront = (internalFront + 1) % MAX_ROOM_SIZE;
    return internal[internalFront];
}
Patient delete_surgery_front() {
    if (is_surgery_empty()) return ERROR_PATIENT;
    surgeryFront = (surgeryFront + 1) % MAX_ROOM_SIZE;
    return surgery[surgeryFront];
}
Patient delete_neuro_front() {
    if (is_neuro_empty()) return ERROR_PATIENT;
    neuroFront = (neuroFront + 1) % MAX_ROOM_SIZE;
    return neuro[neuroFront];
}

/* Name : delete_wating_rear, delete_internal_rear, delete_surgery_rear, delete_neuro_rear
/* Param : None
/* Return : Patient
/* Description : 각 덱의 rear 삭제 (Hint. 응급 환자가 일반 환자 밀어낼 때 사용) */
Patient delete_internal_rear() {
    int prev = internalRear;
    if (is_internal_empty()) return ERROR_PATIENT;
    internalRear = (internalRear - 1 + MAX_ROOM_SIZE) % MAX_ROOM_SIZE;
    return internal[prev];
}
Patient delete_surgery_rear() {
    int prev = surgeryRear;
    if (is_surgery_empty()) return ERROR_PATIENT;
    surgeryRear = (surgeryRear - 1 + MAX_ROOM_SIZE) % MAX_ROOM_SIZE;
    return surgery[prev];
}
Patient delete_neuro_rear() {
    int prev = neuroRear;
    if (is_neuro_empty()) return ERROR_PATIENT;
    neuroRear = (neuroRear - 1 + MAX_ROOM_SIZE) % MAX_ROOM_SIZE;
    return neuro[prev];
}

/* Name : waiting_peek, internal_peek, surgery_peek, neuro_peek
/* Param : None
/* Return : Patient, ERROR_PATIENT
/* Description : 각 덱의 front 값을 확인 */
Patient waiting_peek()  { 
    if (is_waiting_empty()) return ERROR_PATIENT; 
    return waiting[(waitingFront + 1) % MAX_WAITING_SIZE]; 
}
Patient internal_peek() { 
    if (is_internal_empty()) return ERROR_PATIENT; 
    return internal[(internalFront + 1) % MAX_ROOM_SIZE]; 
}
Patient surgery_peek()  { 
    if (is_surgery_empty()) return ERROR_PATIENT; 
    return surgery[(surgeryFront + 1) % MAX_ROOM_SIZE]; 
}
Patient neuro_peek()    { 
    if (is_neuro_empty()) return ERROR_PATIENT; 
    return neuro[(neuroFront + 1) % MAX_ROOM_SIZE]; 
}

/* Name : waiting_rear_peek, internal_rear_peek, surgery_rear_peek, neuro_rear_peek
/* Param : None
/* Return : Patient, ERROR_PATIENT
/* Description : 각 덱의 rear 값을 확인 */
Patient waiting_rear_peek() { 
    if (is_waiting_empty()) return ERROR_PATIENT; 
    return waiting[waitingRear]; 
}
Patient internal_rear_peek() { 
    if (is_internal_empty()) return ERROR_PATIENT; 
    return internal[internalRear]; 
}
Patient surgery_rear_peek()  { 
    if (is_surgery_empty()) return ERROR_PATIENT; 
    return surgery[surgeryRear]; 
}
Patient neuro_rear_peek() { 
    if (is_neuro_empty()) return ERROR_PATIENT; 
    return neuro[neuroRear]; 
}

/* Name : print_patient
/* Param : Patient
/* Return : None
/* Description : 환자 정보 출력 */
void print_patient(Patient p) {
    char dept[10];
    switch (p.dept) {
        case INTERNAL: 
            strcpy(dept, INTERNAL_KR); 
            break;
        case SURGERY:  
            strcpy(dept, SURGERY_KR);  
            break;
        case NEURO:    
            strcpy(dept, NEURO_KR);    
            break;
        default: 
            return;
    }
    printf("이름:%s, 나이:%d, 진료과:%s, 진료:%s\n",
           p.name, p.age, dept, p.isUrgent ? "응급" : "일반");
}

/* Name : add_patient
/* Param : string, int, int, char
/* Return : Pateint
/* Description : 대기실 환자 접수 */
Patient add_patient(char *name, int age, int dept, char checkUrgent) {
    // 코드 작성 : 대기실에 환자 접수하는 함수 작성. 응급인지 아닌지에 따라 덱의 front에 넣을지 rear에 넣을지 결정
    
}

/* Name : room_has_space
/* Param : Patient
/* Return : bool
/* Description : 진료실이 해당 환자를 받을 수 있는지 확인 */
bool room_has_space(Patient p) {
    switch (p.dept) {
        case INTERNAL: return !is_internal_full();
        case SURGERY:  return !is_surgery_full();
        case NEURO:    return !is_neuro_full();
    }
    return false;
}

/* Name : room_rear_is_urgent
/* Param : Patient
/* Return : bool
/* Description : rear의 환자가 응급인지 확인 */
bool room_rear_is_urgent(Patient p) {
    switch (p.dept) {
        case INTERNAL: return internal_rear_peek().isUrgent;
        case SURGERY:  return surgery_rear_peek().isUrgent;
        case NEURO:    return neuro_rear_peek().isUrgent;
    }
    return true;
}


/* Name : add_urgent_into_room
/* Param : Patient
/* Return : None
/* Description : 응급 환자인데 덱이 꽉 찬 경우 rear 환자가 응급인지 확인하고 아니라면 대기실로 돌리고 front에 삽입 */
void add_urgent_into_room(Patient p) {
    switch (p.dept) {
        case INTERNAL:
            if (is_internal_full() && internal_rear_peek().isUrgent) break;
            if (is_internal_full()) add_waiting_rear(delete_internal_rear());
            add_room_front(p);
            break;
        case SURGERY:
            if (is_surgery_full() && surgery_rear_peek().isUrgent) break;
            if (is_surgery_full()) add_waiting_rear(delete_surgery_rear());
            add_room_front(p);
            break;
        case NEURO:
            if (is_neuro_full() && neuro_rear_peek().isUrgent) break;
            if (is_neuro_full()) add_waiting_rear(delete_neuro_rear());
            add_room_front(p);
            break;
    }
}

/* Name : send_to_room
/* Param : None
/* Return : None
/* Description : 대기실의 모든 환자를 가능한 만큼 각자의 진료실로 이동 */
void send_to_room() {
    // 코드 작성 : 대기실의 모든 환자를 각자의 진료실로 이동시키는 함수 작성
    
}

/* Name : treat_patient
/* Param : None
/* Return : None
/* Description : 각 진료실마다 앞에서 3명씩 진료. 3명 미만이면 응급 환자만 진료. */
void treat_patient() {
    // 코드 작성 : 각 진료실마다 진료 규칙에 맞게 진료 진행.
    
}

/* Name : print_status
/* Param : None
/* Return : None
/* Description : 현재 상태 출력: 대기실 → 내과 → 외과 → 신경과 순서 */
void print_status() {
    int i, idx, end;

    printf("waiting : %d\n", waiting_size());
    if (!is_waiting_empty()) {
        idx = 1;
        end = waitingRear;
        if (waitingFront >= waitingRear) end += MAX_WAITING_SIZE;
        for (i = waitingFront + 1; i <= end; i++) {
            printf("%d.", idx++);
            print_patient(waiting[i % MAX_WAITING_SIZE]);
        }
    }
    
    printf("internal : %d\n", internal_size());
    if (!is_internal_empty()) {
        idx = 1;
        end = internalRear;
        if (internalFront >= internalRear) end += MAX_ROOM_SIZE;
        for (i = internalFront + 1; i <= end; i++) {
            printf("%d.", idx++);
            print_patient(internal[i % MAX_ROOM_SIZE]);
        }
    }
    
    printf("surgery : %d\n", surgery_size());
    if (!is_surgery_empty()) {
        idx = 1;
        end = surgeryRear;
        if (surgeryFront >= surgeryRear) end += MAX_ROOM_SIZE;
        for (i = surgeryFront + 1; i <= end; i++) {
            printf("%d.", idx++);
            print_patient(surgery[i % MAX_ROOM_SIZE]);
        }
    }
    
    printf("neuro : %d\n", neuro_size());
    if (!is_neuro_empty()) {
        idx = 1;
        end = neuroRear;
        if (neuroFront >= neuroRear) end += MAX_ROOM_SIZE;
        for (i = neuroFront + 1; i <= end; i++) {
            printf("%d.", idx++);
            print_patient(neuro[i % MAX_ROOM_SIZE]);
        }
    }
}

int main() {
    int choice;
    char name[MAX_NAME_SIZE] = {0,};
    int age;
    int dept;
    char isUrgent;

    printf("프로그램 시작\n");
    init_deque();

    while (1) {
        printf("1.환자 접수  2.환자 진료실 이동  3.진료 및 확인  4.현재 상태 확인  5.종료\n");
        printf("원하는 기능의 번호를 입력하세요 : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("환자 이름을 입력하세요 : ");
                scanf("%s", name);

                do {
                    printf("나이를 입력하세요(1~120) : ");
                    scanf("%d", &age);
                } while (age < 1 || age > 120);

                printf("1.내과  2.외과  3.신경과\n");
                do {
                    printf("진료과를 선택하세요 : ");
                    scanf("%d", &dept);
                } while (dept < 1 || dept > 3);

                getchar();
                printf("응급 환자 여부를 선택하세요(y/n) : ");
                scanf("%c", &isUrgent);

                add_patient(name, age, dept, isUrgent);
                break;
            case 2:
                send_to_room();
                break;
            case 3:
                treat_patient();
                break;
            case 4:
                print_status();
                break;
            case 5:
                printf("시스템 종료");
                return 0;
            default:
                printf("잘못된 입력입니다\n");
                break;
        }
    }
}