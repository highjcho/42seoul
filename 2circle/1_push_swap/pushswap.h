#ifndef _PUSH_SWAP_
# define _PUSH_SWAP_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> // 제출 전 삭제 필

typedef struct Array_stack_node_type
{

}   array_stack_node;

typedef struct Array_stack_type
{
    int sort_count; // 인자 개수
    int current_count; // 스택에 차 있는 개수
    int front; // 프론트
    int rear; // 리어
    array_stack_node *element;

} Array_stack;

#endif