#define BLACK
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
GLfloat house[3][3]={{100.0,250.0,175.0},{100.0,100.0,300.0},{1.0,1.0,1.0}};
GLfloat rotatement[3][3]={{0},{0},{0}};
GLfloat Result[3][3]={{0},{0},{0}};
GLfloat m=0;
GLfloat n=0;
float theta;



void drawhouse()
{
 glColor3f(1.0,0.0,0.0);
 glBegin(GL_LINE_LOOP);
 glVertex2f(house[0][0],house[1][0]);
  glVertex2f(house[0][1],house[1][1]);
   glVertex2f(house[0][2],house[1][2]);
   glEnd();
   }
void display()
{
 glClear(GL_COLOR_BUFFER_BIT);
 drawhouse();
 glTranslatef(m,n,0);
 glRotatef(theta,0,0,1);
 glTranslatef(-m,-n,0);
 drawhouse();
 glFlush();
}
void myinit()
{
 glClearColor(1,1,1,1);
 glColor3f(1,0,0);
 glPointSize(1);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(-499,449,-499,499);
 }
 int main(int argc,char **argv)
 {
  int ch;
  printf("enter choice\n 1:Rotation about origin \n 2:rotation about a fixed point\n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:printf("enter the rotation angle in degree:");
          scanf("%f",&theta);
          break;
   case 2:printf("enter the fixed point:");
          scanf("%f%f",&m,&n);
          printf("enter the rotation angle:");
          scanf("%f",&theta);       
          break;
  }
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(0,0);
  glutCreateWindow("");	
  glutDisplayFunc(display);
  myinit();
  glutMainLoop();
  return 0;
  } 
 
