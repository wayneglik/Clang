//
//  struct_array.c
//  열혈C
//
//  Created by 안동규 on 2021/10/28.
//  열혈 C프로그래밍 p461 예제

typedef struct point {
    int xpos;
    int ypos;
}mouse;

#include <stdio.h>

int main()
{
//    struct point arr[3];  // 구조체 배열
//
//    for(int i=0;i<3;i++){
//        printf("점의 좌표를 입력해주세요 : ");
//        scanf("%d %d", &arr[i].xpos, &arr[i].ypos);
//    }
//
//    for(int i=0;i<3;i++){
//        printf("x좌표: %d, y좌표: %d\n",arr[i].xpos,arr[i].ypos);
//    }
    
    // 구조체 포인터
//    struct point pos1 = {1, 2};
//    struct point pos2 = {100, 200};
//    struct point *pptr = &pos1;
//
//    (*pptr).xpos += 4;
//    (*pptr).ypos += 5;
//    printf("pos1 x: %d, y: %d\n", pptr->xpos, pptr->ypos);
//
//    pptr = &pos2;
//    pptr->xpos += 10;
//    pptr->ypos +=20;
//    printf("pos2 x:%d, y:%d\n", (*pptr).xpos, (*pptr).ypos);
    
    // 자습 - 구조체 배열의 포인터
    mouse pos[2] = {
        {5, 2},
        {10, 20}
    };
    for(int i=0;i<2;i++){
        printf("포인터 사용 전\n%d %d\n",pos[i].xpos, pos[i].ypos);
    }
    printf("\n\n");
    
    mouse *pptr[2];
    for(int i=0;i<2;i++){
        pptr[i] = &pos[i];
    }
    
    // 확인
    for(int j=0;j<2;j++){
        printf("포인터 사용 후\n%d %d\n",pptr[j]->xpos,pptr[j]->ypos);
    }
    // 어떻게 구조체 포인터 배열을 이용해서 각 요소에 접근할 수 있을까?
    // 원래도 포인터를 배열처럼 이용할 수 있다는 것을 이용해보니 된다.
    

    return 0;
}
