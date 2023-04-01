#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define X 0
#define Y 1

int find_parallel(int* dot1a, int* dot1b, int* dot2a, int* dot2b) {
    int is_parallel = 0;
    float d1x = 0;
    float d1y = 0;
    float d2x = 0;
    float d2y = 0;
    
    d1x = dot1b[X] - dot1a[X];
    d1y = dot1b[Y] - dot1a[Y];
    d2x = dot2b[X] - dot2a[X];
    d2y = dot2b[Y] - dot2a[Y];

    if ((d1x/d1y) == (d2x/d2y))
        is_parallel = 1;
    
    return is_parallel;
}

// dots_rows는 2차원 배열 dots의 행 길이, dots_cols는 2차원 배열 dots의 열 길이입니다.
int solution(int** dots, size_t dots_rows, size_t dots_cols) {
    int answer = 0;
    
    if ((find_parallel(dots[0], dots[1], dots[2], dots[3]))
        || (find_parallel(dots[0], dots[2], dots[1], dots[3]))
        || (find_parallel(dots[0], dots[3], dots[1], dots[2])))
        answer = 1;
    
    return answer;
}