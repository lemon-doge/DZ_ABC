;------------------------------------------------------------------------------
; filtrator.asm - единица компиляции, вбирающая функции фильтрации массива
;------------------------------------------------------------------------------

extern CAR
extern BUS
extern TRUCK

;----------------------------------------------
; Вычисление запаса хода машины
;double getRange(void *vehicle) {
;    int fuel_tank_capacity = *((int*)(vehicle+intSize))
;    float fuel_consumption = *((float*)(vehicle+2*intSize))
;    return fuel_tank_capacity/fuel_consumption;
;}
global getRange
getRange:
section .text
push rbp
mov rbp, rsp

    ; В rdi адрес машины
    add rdi, 4  ; skipping the key, rdi now points to int fuel tank capacity
    cvtsi2ss xmm0, [rdi]  ; converting int capacity to float
    add rdi, 4  ; skipping the capacity, rdi now points to float fuel consumption
    movss xmm1, [rdi]  ; moving rdi to appropriate register
    divss xmm0, xmm1 ; calculating range

    ;supposed to return contents of xmm0
leave
ret

;----------------------------------------------
;// Вычисление среднего запаса хода по контейнеру
;float getAverageRange(void *c, int len) {
;    double sum = 0.0;
;    void *tmp = c;
;    for(int i = 0; i < len; i++) {
;        sum += getRange(tmp);
;        tmp = tmp + shapeSize;
;    }
;    return sum/len;
;}
global getAverageRange
getAverageRange:
section .data
    .sum    dd  0.0
section .text
push rbp
mov rbp, rsp

    ; В rdi адрес начала контейнера
    ; В rsi длина контейнера
    mov rbx, rsi            ; сохраняем длину
    xor rcx, rcx            ; обнуляем текущий шаг
    movss xmm2, [.sum]      ; перенос накопителя суммы в регистр 2
.loop:
    cmp rcx, rbx            ; проверка на окончание цикла
    jge .return             ; перебрали все фигуры - прыгаем на возврат

    mov r10, rdi            ; сохранение начала фигуры
    call getRange           ; Получение периметра первой фигуры
    addss xmm2, xmm0        ; накопление суммы
    inc rcx                 ; добавили шаг
    add r10, 16             ; адрес следующей фигуры
    mov rdi, r10            ; восстановление для передачи параметра
    ; последние 3 строчки можно было заменить на add rdi, 4 ::stone
    jmp .loop
.return:
    movss xmm0, xmm2        ; перенесли сумму в 0й float регистр
    cvtsi2ss xmm1, rbx      ; конвертировали кол-во машин во float и положили в 1й регистр
    divss xmm0, xmm1        ; получили среднее значение

    ; вернет значение в xmm0
leave
ret
