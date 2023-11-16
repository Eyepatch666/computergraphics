#include<windows.h>
#include<stdio.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <string>

///game speed
int FPS = 50;

///game trackers
int start_flag=0;
int gameover_flag=0;

///score
int score = 0;


///basket move
int basket_x = 0 ;

///falling balls
int ball_y1 = 0;
int ball_x1 = 0;
int ball_y2 = +35;
int ball_x2 = +15;
int ball_y3 = +70;
int ball_x3 = +25;
int ball_y4 = +105;
int ball_x4 = +30;

///text display
const int font1=(int)GLUT_BITMAP_TIMES_ROMAN_24;
const int font2=(int)GLUT_BITMAP_HELVETICA_18 ;
const int font3=(int)GLUT_BITMAP_8_BY_13;

void renderBitmapString(float x, float y, void *font,const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

///game display
void startGame(){

    ///background
    glColor3ub(102, 205, 170);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(0,100);
    glVertex2i(100,100);
    glVertex2i(100,0);
    glEnd();



    ///table
    glColor3ub(222, 184, 135);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(25,8);
    glVertex2i(70,8);
    glVertex2i(100,0);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(0,0);
    glVertex2i(25,8);
    glVertex2i(70,8);
    glVertex2i(100,0);
    glEnd();


    ///score board
    glColor3ub(102, 205, 170);
    glBegin(GL_POLYGON);
    glVertex2i(70,97);
    glVertex2i(100,97);
    glVertex2i(100,90);
    glVertex2i(70,90);
    glEnd();

    ///score
    char buffer [50];
    sprintf (buffer, "Ball Catched: %d", score);
    glColor3ub(0, 0, 0);
    renderBitmapString(70.5,95,(void *)font3,buffer);


    ///basket
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(basket_x+22,11);
    glVertex2i(basket_x+24,1);
    glVertex2i(basket_x+32,1);
    glVertex2i(basket_x+34,11);
    glEnd();



   ///ball 1 - Red Circle
    glColor3ub(255, 0, 0);
    glBegin(GL_TRIANGLE_FAN);
    float radius1 = 3;
    int numSegments1 = 50;
    float angle1;
    for (int i = 0; i <= numSegments1; i++)
    {
    angle1 = i * 2.0f * 3.14159 / numSegments1;
    float x1 = ball_x1 + 28 + (radius1 * cos(angle1));
    float y1 = ball_y1 + 96 + (radius1 * sin(angle1));
    glVertex2f(x1, y1);
    }
    glEnd();
    ball_y1--;
    if(ball_y1 < -100){
        ball_y1=0;
        ball_x1=basket_x;
    }
    //ball count 1
    if((abs(basket_x-ball_x1)<8) && (ball_y1+100<10)){


            score++;
            ball_y1=100;

    }
     if((ball_x1<8) && (ball_y1+100<10))
    {
        start_flag = 0;
        gameover_flag=1;

    }

    ///ball 2 - Orange Circle
    glColor3ub(255, 165, 0);
    glBegin(GL_TRIANGLE_FAN);
    float radius2 = 3;
    int numSegments2 = 50;
    float angle2;
    for (int i = 0; i <= numSegments2; i++) {
    angle2 = i * 2.0f * 3.14159 / numSegments2;
    float x2 = ball_x2 + 28 + (radius2 * cos(angle2));
    float y2 = ball_y2 + 96 + (radius2 * sin(angle2));
    glVertex2f(x2, y2);
    }
    glEnd();
    ball_y2--;
    if(ball_y2 < -100){
        ball_y2=0;
        ball_x2=basket_x;
    }
    //ball count 2
    if((abs(basket_x-ball_x2)<8) && (ball_y2+100<10)){

            score++;
            ball_y2=100;
    }

    if((ball_x2<23) && (ball_y2+100<10))
    {
        start_flag = 0;
        gameover_flag=1;

    }

    ///ball 3 - Green Circle
    glColor3ub(0, 128, 0);
    glBegin(GL_TRIANGLE_FAN);
    float radius3 = 3;
    int numSegments3 = 50;
    float angle3;
    for (int i = 0; i <= numSegments3; i++) {
    angle3 = i * 2.0f * 3.14159 / numSegments3;
    float x3 = ball_x3 + 28 + (radius3 * cos(angle3));
    float y3 = ball_y3 + 96 + (radius3 * sin(angle3));
    glVertex2f(x3, y3);
    }
    glEnd();
    ball_y3--;
    if(ball_y3 < -100){
        ball_y3=0;
        ball_x3=basket_x;
    }
    //ball count 3
    if((abs(basket_x-ball_x3)<8) && (ball_y3+100<10)){

         //   start_flag = 0;
         //   gameover_flag=0;

            score++;  ///flag
            ball_y3=105;
    }
    if((ball_x3<33) && (ball_y3+100<10))
    {
        start_flag = 0;
        gameover_flag=1;

    }


     ///ball 4 - Yellow Circle
    glColor3ub(255, 255, 0);
        glBegin(GL_TRIANGLE_FAN);
        float radius4 = 3;
        int numSegments4 = 50;
        float angle4;
        for (int i = 0; i <= numSegments4; i++) {
        angle4 = i * 2.0f * 3.14159 / numSegments4;
        float x4 = ball_x4 + 28 + (radius4 * cos(angle4));
        float y4 = ball_y4 + 96 + (radius4 * sin(angle4));
        glVertex2f(x4, y4);
        }
        glEnd();
        ball_y4--;
    if(ball_y4 < -100){
        ball_y4=0;
        ball_x4=15+basket_x;
    }
    //ball count 4
    if((abs(basket_x-ball_x4)<8) && (ball_y4+100<10)){

         //   start_flag = 0;
         //   gameover_flag=0;

            score++;  ///flag
            ball_y4=105;

    }
    if ((ball_x4<113) && (ball_y4+100<10))
    {
        start_flag = 0;
        gameover_flag=1;

    }


}

///inside design

void intro()  {


        ///menu
        //middle
        glColor3ub(0, 191, 255);
        glBegin(GL_POLYGON);
        glVertex2i(0,0);
        glVertex2i(100,0);
        glVertex2i(100,100);
        glVertex2i(0,100);
        glEnd();


        ///text info
        if(gameover_flag==1){

        glColor3ub(0, 191, 255);
        glBegin(GL_POLYGON);
        glVertex2i(27,45);
        glVertex2i(78,45);
        glVertex2i(78,25);
        glVertex2i(27,25);
        glEnd();

            glColor3ub(255, 0, 0);
            renderBitmapString(31,36,(void *)font1,"GAME OVER");
            glColor3ub(152, 251, 152);
            char buffer2 [50];
            sprintf (buffer2, "Your have cached : %d balls", score);
            renderBitmapString(22,31,(void *)font1,buffer2);

        }

        ///Opening ball 3 - Green Circle
        glColor3ub(0, 128, 0);
        glBegin(GL_TRIANGLE_FAN);
        float radius3 = 3;
        int numSegments3 = 50;
        float angle3;
        for (int i = 0; i <= numSegments3; i++) {
        angle3 = i * 2.0f * 3.14159 / numSegments3;
        float x3 = 48 + (radius3 * cos(angle3));
        float y3 = 83 + (radius3 * sin(angle3));
        glVertex2f(x3, y3);
        }
        glEnd();

        ///Opening ball 1 - Red Circle
        glColor3ub(255, 0, 0);
        glBegin(GL_TRIANGLE_FAN);
        float radius1 = 3;
        int numSegments1 = 50;
        float angle1;
        for (int i = 0; i <= numSegments1; i++)
        {
        angle1 = i * 2.0f * 3.14159 / numSegments1;
        float x1 = 51 + (radius1 * cos(angle1));
        float y1 = 80 + (radius1 * sin(angle1));
        glVertex2f(x1, y1);
        }
        glEnd();
        ///ball 2 - Orange Circle
        glColor3ub(255, 165, 0);
        glBegin(GL_TRIANGLE_FAN);
        float radius2 = 3;
        int numSegments2 = 50;
        float angle2;
        for (int i = 0; i <= numSegments2; i++) {
        angle2 = i * 2.0f * 3.14159 / numSegments2;
        float x2 = 45 + (radius2 * cos(angle2));
        float y2 = 80 + (radius2 * sin(angle2));
        glVertex2f(x2, y2);
        }
        glEnd();

        ///opening basket
        glColor3ub(255, 255, 255);
        glBegin(GL_POLYGON);
        glVertex2i(42,80);
        glVertex2i(44,70);
        glVertex2i(52,70);
        glVertex2i(54,80);
        glEnd();
        glColor3ub(0, 0, 0);
        glBegin(GL_LINE_STRIP);
        glVertex2i(42,80);
        glVertex2i(44,70);
        glVertex2i(52,70);
        glVertex2i(54,80);
        glEnd();
        ///ball 4 - Yellow Circle
        glColor3ub(255, 255, 0);
        glBegin(GL_TRIANGLE_FAN);
        float radius4 = 3;
        int numSegments4 = 50;
        float angle4;
        for (int i = 0; i <= numSegments4; i++) {
        angle4 = i * 2.0f * 3.14159 / numSegments4;
        float x4 = 56 + (radius4 * cos(angle4));
        float y4 = 72 + (radius4 * sin(angle4));
        glVertex2f(x4, y4);
        }
        glEnd();



        glColor3ub(179, 0, 0);
        renderBitmapString(33,65,(void *)font1,"Catch the balls");
        //opening basket

        glColor3ub(0, 0, 0);
        renderBitmapString(30,50,(void *)font1,"Press S to START");
        renderBitmapString(30,45,(void *)font1,"Press ESC to Exit");

        glColor3ub(255, 255, 255);
        renderBitmapString(20,10,(void *)font3,"Press LEFT & RIGHT button to control");

}


void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    if(start_flag==1){

        glClearColor(0, 0, 0,1);
        startGame();
    }

    else{
        intro();
    }
    glFlush();
    glutSwapBuffers();
}



void spe_key(int key, int x, int y){

    switch (key) {


        case GLUT_KEY_LEFT:
            if(basket_x>=0){
                basket_x = basket_x - (FPS/10);
                if(basket_x<0){

                    basket_x=-1;
                }
            }
            break;

        case GLUT_KEY_RIGHT:
            if(basket_x<=44){
                basket_x = basket_x + (FPS/10);
                if(basket_x>44){
                    basket_x = 45;
                }
            }
            break;

        default:
                break;
        }

}

void processKeys(unsigned char key, int x, int y) {

      switch (key)
            {
                case 's':
            if(start_flag==0){
                start_flag = 1;
                gameover_flag = 0;
                FPS = 50;
                basket_x = 0 ;
                ball_y1 = 0;
                ball_x1=0;
                ball_y2 = +35;
                ball_x2=+15;
                ball_y3 = +70;
                ball_x3=+25;
                ball_y4 = +105;
                ball_x4=+30;
                score=0;

                //level=0;
            }
             break;

             case 27:
                 exit(0);
             break;
             default:
                break;
        }
}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,timer,0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);

    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,20);
    glutCreateWindow("Catch the Balls");

    glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(processKeys );

    glOrtho(0,100,0,100,-1,1);
    glClearColor(0, 191, 255,1);

    glutTimerFunc(1000,timer,0);
    glutMainLoop();

    return 0;
}
