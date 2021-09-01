#include <stdio.h>



/*     자, 피라미드를 쌓아 볼거에요.
    사용자가 값을 입력하면 해당 숫자에 맞는 피라미드를 완성해봅시다.
    예를 들면, 사용자가 5를 입력한다면,
    
       *      // 빈칸이 4개 필요한 1
      ***     // 빈칸이 3개 필요한 3
     *****    // 빈칸이 2개 필요한 5
    *******   // 빈칸이 1개 필요한 5+2
   *********  // 빈칸이 필요없는 5+4
   이렇게 5층 짜리 피라미드를 출력해보자. */



//    개념   
//                         빈칸    *갯수
//    만약 1층을 짓고 싶다면?    0       1

//    만약 2층을 짓고 싶다면?    1       1
//    만약 2층을 짓고 싶다면?    0       3

//    만약 3층을 짓고 싶다면?    2       1
//    만약 3층을 짓고 싶다면?    1       3
//    만약 3층을 짓고 싶다면?    0       5

// 순번ㅇ 1 2 3 4 5
// 별갯수 1 3 5 7 9
// 증가폭  2 2 2 2
// 별개수 = 1 + i*2

// 순번ㅇ 1 2 3 4 5
// 빈칸수 0 1 2 3 4
// 증가폭  1 1 1 1

int main_loop(void)
{
    int answer;  // 사용자가 입력하는 수


    printf("피라미드를 쌓아라!\n");
    printf("몇 층의 피라미드를 쌓고 싶으신가요?\n");
    scanf("%d", &answer);


    for(int i=0; i<answer; i++)
    {
        for(int c=i; c<answer-1; c++)
        {
            printf(" ");
        }

        for(int j=0; j<1+i*2; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}



/* 소감,
빈 칸을 어떻게 구현할지가 조금 고민이었음.
결국은 정해져서 움직이지 않은 answer에 증가하는 i값을 이용해서
매 줄마다 출력되는 빈 칸의 갯수를 줄이자고 사고하는 것이 관건. */