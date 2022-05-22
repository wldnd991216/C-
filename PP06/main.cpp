#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#pragma comment(lib,"opengl32") //라이브러리용으로 쓸 것이다 오픈지엘32 를 
//프로그래밍 관련된 것을 전처리기에 ~~하게 지시 하겠다 프라그마 뒤에 붙는거에 따라 달라짐 (지시자)

static void error_callback(int error, const char* description)
{
    fputs(description, stderr); // 에러 관련 메세지 핸들러를 만들어 놓음
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);//키 관련 메세지 핸들러를 만들어 놓음
}
int main(void)
{
    GLFWwindow* window; // glfw3 헤더파일에 있는거 씀  
    glfwSetErrorCallback(error_callback);  // 모니터가 발견되면 null을 반환하는데 ()안에 error_callback에 있으니 위에 작성된 에러콜백 함수를 반환함
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL); // glfw 에서 윈도우 창을 만들어 내라고 윈도우 매니저에게 명령
    if (!window)
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;


        //glClearColor(0, 0, 1, 1); //색 알비지값같은거 바꾸는거 브라운관 티비 같은 구조로 되있어서 전부 다 같은 값 주면 힌색나옴 0.3f씩
                                     //오픈 지엘은 float 를 기본 자료형ㅇ로 설계되어있다. 그래서 f씀 자료형이 작으니 금방 계산기 끝남
        //glClear(GL_COLOR_BUFFER_BIT);

         ////glBegin(GL_POINT); // 앞으로 입력하는건 포인트(점) 으로 표시하겠다 
        //glColor3f(1.0f,0.3f,0); // 뒤에 1 없는건 알파값이 필요없어서
        //glVertex2f(0.0f, 0.0f);

        //============

        //glBegin(GL_LINES); //입력하는건 라인(선) 으로 표시하겠다 //https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=kenshin122&logNo=112518707
        //                   //http://yoonbumtae.com/?p=907
        //glColor3f(1.0f, 0, 0);
        //glVertex2f(0.0f, 0.0f);
        //glVertex2f(1.0f, 1.0f);
        //glColor3f(0, 0, 1.0f); //중간에 색 변경
        //glVertex2f(0.0f, 0.0f);
        //glVertex2f(1.0f, -1.0f);

        //======================

        //glBegin(GL_TRIANGLES); //삼각형 만들기
        //glColor3f(1.0f, 0, 0);
        //glVertex2f(0, 0);
        //glColor3f(0, 0, 0);
        //glVertex2f(0.25f, 0.25f);
        ////중간에 색 변경
        //glVertex2f(0.25f, 0);

        //glEnd(); //비긴과 하나


       //===================


        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}