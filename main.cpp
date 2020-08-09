#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

static GLfloat spin = 0.0;
static GLfloat spin_speed = 1.0;
float spin_x = 0;
float spin_y = 1;
float spin_z = 0;
float translate_x = 0.0;
float translate_y = 0.0;
float translate_z = -30.0;


void setSpin(float x, float y, float z)
{
	spin_x = x;
	spin_y = y;
	spin_z = z;
}
void reshape(GLsizei width, GLsizei height)
 {
   if (height == 0) height = 1;
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
   glViewport(0, 0, width, height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
    gluOrtho2D(5.0, 5.0, 0.0, 5.0);
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

}

void spinDisplay(void)
{
	spin=spin+spin_speed;
	if(spin>360.0)
	{
		spin=spin-360.0;
	}
	glutPostRedisplay();
}
void spinDisplayReverse(void)
{
	spin=spin-spin_speed;
	if(spin<360.0)
	{
		spin=spin+360.0;
	}
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
		if(key=='a')
			glutIdleFunc(spinDisplay);

		else if(key=='c')
			glutIdleFunc(spinDisplayReverse);

}

void initGL()
{
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glClearDepth(1.0f);
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LEQUAL);
}

void drawFan()
{
	glTranslatef(1.5f, 0.0f, -7.0f);
	glRotatef(spin,spin_x,spin_y,spin_z);
    glTranslatef(-1.5f, 0.0f, -6.0f);

	 glBegin(GL_TRIANGLES);

      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(1.0f, -1.0f, 1.0f);

      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);

      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);

      glColor3f(1.0f,0.0f,0.0f);
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f,0.0f,1.0f);
      glVertex3f(-1.0f,-1.0f,-1.0f);
      glColor3f(0.0f,1.0f,0.0f);
      glVertex3f(-1.0f,-1.0f, 1.0f);

       glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f( 0.0f, -1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, 1.0f, 1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(-1.0f, 1.0f, 1.0f);

       glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f(0.0f, -1.0f, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(-1.0f, 1.0f, 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);

       glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f(0.0f, -1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(1.0f, 1.0f, -1.0f);

       glColor3f(1.0f,0.0f,0.0f);
      glVertex3f( 0.0f, -1.0f, 0.0f);
      glColor3f(0.0f,0.0f,1.0f);
      glVertex3f(1.0f,1.0f,-1.0f);
      glColor3f(0.0f,1.0f,0.0f);
      glVertex3f(1.0f,1.0f, 1.0f);

   glEnd();
   //glutSwapBuffers();
}

void myDisplay()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();
   drawFan();
   glutSwapBuffers();

}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(640, 480);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("----18CS50 18CS16 18CS30---");
   glutDisplayFunc(myDisplay);
   glutReshapeFunc(reshape);
     glutKeyboardFunc(keyboard);

   initGL();
   glutMainLoop();
   return 0;
}
