#include <stdio.h>

// loop.c 전에 if문과 반복문 코딩도장 학습



int main_selfstudy_if(void)
{
    /* 참고! 의사코드란?(수도코드,슈도코드,pseudo code)
    실제 프로그래밍 언어가 아닌, 사람의 언어로
    프로그래밍 언어를 표현한 것임!
    int num1 = 10;  // c언어 코드
    정수형 변수 num1 선언, 10 할당  // 한글로 표현한 의사 코드 */



    /* 참고! 전역 변수 사용하기
    먼저 전역 변수는 지역 변수의 반대개념이라고 보면 된다.
    지역변수는 선언된 함수 안에서만 사용이 가능!
    C언어는 범위에 따라 변수의 접근을 제한하기 때문.
    함수의 범위는 함수가 시작하는 중괄호와 끝나는 중괄호 사이를 말함.
    반면,
    전역 변수는 프로그램 전체에서 공유하는 변수이다.
    다른 소스 파일에 있는 전역 변수를 사용할수도 있다!

    C언어에서 중괄호로 묶은 부분을 블록이라고 함.
    if, for, switch, while, do while, 함수에 사용한 중괄호가 블록임.
    또한, 그냥 중괄호만으로 이루어진 것도 블록임.
    (단, 배열, 구조체, 공용체 등을 초기화 할 때 사용하는 중괄호는 블록이 아님)

    전역변수는 함수 안이 아닌 함수 바깥에 선언한다.
    함수 블록 바깥에 선언이 되어있으므로 모든 함수에서 값을 가져오거나 저장할 수 있음.
    또한, 파일 자체에 변수가 선언되어 있으므로, 변수의 범위는 파일 범위이다.
    즉, 전역 변수는 모든 함수에서 접근할 수 있으며 한 번 저장한 값이 계속 유지된다.

    전역 변수는 초기값을 지정하지 않으면 0으로 초기화 됨.
    이 부분은 지역 변수가 초기화를 하지 않을때 더미값이 입력되는 것과는 다른 부분임.
    그리고 전역 변수는 프로그램이 시작될 때 생성 및 초기화되고 프로그램이 끝날 때 사라짐.
    
    이런 장점이 있지만 무분별하게 사용했을 때의 문제점은 다음과 같다.
    프로그램이 커지다 보면 어떤 함수가 전역 변수의 값을 바꾸는지 알기 어려워짐.
    즉, 유지보수가 힘들어지고 눈에 잘 띄지 않는 버그가 생기기 쉬움.
    다음으로는 지역 변수와 전역 변수의 이름이 겹칠 가능성이 커지고 의도하지 않은 결과가 도출될 수 있음.
    지역 변수와 전역 변수의 이름이 같을 때는 현재 블록의 변수를 우선으로 접근함. */
    
    /* 이번에는 소스 파일이 여러 개로 분리되어 있을 때 전역 변수를 사용하는 방법임.
    기존 소스파일에,
    Visual Studio의 솔루션 탐색기 창에서 소스 파일을 클릭하고 마우스 오른쪽 버튼을 누릅니다.
    팝업 메뉴가 나오면 추가(D) > 기존 항목(G)...를 클릭한 뒤 print.c를 선택하고 추가(A) 버튼을 클릭합니다.
    이제 main 함수가 있는 소스 파일입니다. 다음 내용을 프로젝트 디렉터리에 main.c로 저장하세요. 
    즉, print.c소스파일을 외부소스로 정하고 그곳에 있는 함수를 main.c에 당겨서 쓰려는 상황임 */

    /* 이렇게 해서 첫번째 main.c파일을 실행시켜보면 오류가 발생함.
    다른 소스 파일(외부)에 선언된 전역 변수를 사용할 때는 extern 키워드를 사용한다. 
    extern 자료형 전역변수;
    다음과 같이 사용하면 된다.

    #include <stdio.h>

extern int num1;    // 다른 소스 파일(외부)에 있는 전역 변수 num1을 사용

int main()
{
    printf("%d\n", num1);    // 전역 변수 num1의 값 출력

    return 0;
}


    main.c에 이걸 적용시켜서 작동을 시켜보면 잘 작동이 되는 것을 알 수 있다.
    따라서 다른 소스파일에 선언된 전역변수를 사용하려면 extern 뒤에 자료형과 전역 변수의 이름을
    지정해주면 된다.
    이런 식으로 사용을 할때는 소스 파일이 여러 개이면 전역 변수의 범위는
    프로그램 범위임!
    
    extern은 전역 변수뿐만 아니라 함수에도 사용할 수 있음.
    extern 반환값자료형 함수이름(매개변수자료형);
    다음과 같이 사용하면 된다.

    #include <stdio.h>

extern void printNumber();    // 다른 소스 파일(외부)에 있는 함수 printNumber를 사용

int main()
{
    printNumber();    // printNumber 호출

    return 0;
}



    사실 extern을 붙이지 않고 함수 원형만 선언해도 다른 소스 파일에 있는 함수를 사용할 수 있다.
    다음과 같이 사용하면 된다.

    #include <stdio.h>

void printNumber();    // 함수 원형을 선언하여 다른 소스 파일(외부)에 있는 함수 printNumber를 사용

int main()
{
    printNumber();    // printNumber 호출

    return 0;
}




    주의할 점으로는, 전역 변수 선언 없이 extern int num1;만 지정을 하면 
    컴파일(링크) 에러가 발생한다는 것임. 즉, extern int num1;은
    전역 변수가 파일 외부에 있다는 것만 표시할 뿐이지 변수 선언 자체를 선언하지는 않음. */




    
    // if문과 관련해서
    /* else if는 else인 상태에서 조건식을 지정할 때 사용합니다. 단, else if는 단독으로 사용할 수 없음.
    if와 else는 조건식에서 한 번씩 사용할 수 있는데 else if는 여러 번 사용할 수 있음. */

    /* switch 분기문은 조건이 많아도 손쉽게 처리할 수 있음
    다음과 같이 사용하면 된다.

    switch (버튼)
{
case 1:    // 콜라 버튼
    콜라를 내보냄
    break;
case 2:    // 사이다 버튼
    사이다를 내보냄
    break;
case 3:    // 환타 버튼
    환타를 내보냄
    break;
default: 
    제공하지 않는 메뉴
    break;
}




    switch 분기문은 항상 case와 함께 사용하는데 변수 값이 case에 지정한 값과 일치하면
    해당 코드를 실행함. 단, case에는 조건식이나 변수를 지정할 수 없음.
    즉, case 뒤에는 반드시 값(리터럴)이 와야 하며 변수나 조건식은 올 수 없음. 
    case에 값을 지정했으면 :(콜론)을 붙여서 다음 줄부터 실행할 코드를 입력한다.
    그리고 코드의 마지막에는 break를 입력한다.
    아무 case에도 해당되지 않으면 default의 코드를 실행함. default는 생략이 가능하다.

    추가적으로, 만약에 각 case에 break가 없으면 어떻게 될까?
    case1의 경우에도 switch 분기문을 탈출하지 못해서 다른 케이스의 경우도 모두 출력을 한다.
    fall through, 이런 상황을 이르는 말이다.
    물론 일부로 생략해줄때도 있다. case1,2를 함께 묶을 경우, 
    즉 if문으로 보자면 if(a||b)인 경우가 되겠다.
    그런 경우에는,
    case 1:
    case 2:
        printf("");
        break;
    이런 식으로 사용을 해주면 된다.


    case에서도 변수를 선언할 수 있다. 단, 중괄호로 묶어주어야 된다.
    다음과 같이 사용하면 된다.

    int main()
{
    int num1;

    scanf("%d", &num1);    // 값을 입력받음

    switch (num1)    // num1의 값에 따라 분기
    {
    case 1:
    {   // case에서 변수를 선언하려면 중괄호로 묶어줌
        int num2 = num1;
        printf("%d입니다.\n", num2);
        break;
    }
    case 2:
        printf("2입니다.\n");
        break;
    default:
        printf("default\n");
        break;
    }

    return 0;
}



    하지만 case 1에서 정의된 변수는 case 1에서만 작동한다.
    추가적으로, switch에서 판별할 변수는 정수 자료형만 사용할 수 있고, 실수 자료형은 사용할 수 없다.
    단, 문자 자료형도 정수 자료형이므로 switch에서 사용할 수 있다. 문자열은 당연히 안됨. */






    
    return 0;
}