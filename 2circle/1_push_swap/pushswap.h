#ifndef _PUSH_SWAP_
# define _PUSH_SWAP_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> // 제출 전 삭제 필

typedef struct array_node_type
{
    int data;
}   array_node;

typedef struct array_stack_type
{
    int max_count; // 인자 개수
    int cur_count; // 스택에 차 있는 개수
    int front; // 프론트
    int rear; // 리어
    array_node *element;

} array_stack;

#endif