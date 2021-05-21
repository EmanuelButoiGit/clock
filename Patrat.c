#include "glos.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <glaux.h>


void myinit(void);
void CALLBACK display(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);
void CALLBACK MutaStanga(void);
void CALLBACK MutaDreapta(void);
void CALLBACK MutaSus(void);
void CALLBACK MutaJos(void);
void CALLBACK rot_z_up(void);
void CALLBACK rot_z_down(void);
void CALLBACK rot_u_up(void);
void CALLBACK rot_d_down(void);



static GLfloat x = 0, y = 0, z = 0, alfa = 90, beta = 180, geta=90;
GLuint fontOffset;


void myinit(void) {
	glClearColor(0, 0, 0, 0);
}


void CALLBACK MutaStanga(void)
{
	x = x - 10;
}

void CALLBACK MutaDreapta(void)
{
	x = x + 10;
}
void CALLBACK MutaJos(void)
{
	y = y - 10;
}

void CALLBACK MutaSus(void)
{
	y = y + 10;
}
void CALLBACK rot_z_up(void)
{
	alfa = alfa + 10;
}
void CALLBACK rot_z_down(void)
{
	alfa = alfa - 10;
}

void CALLBACK rot_u_up(void)
{
	beta = beta + 10;
}
void CALLBACK rot_d_down(void)
{
	beta = beta - 10;
}


void CALLBACK rot_dd_down(void)
{
	geta = geta - 10;
}

void CALLBACK rot_dd_up(void)
{
	geta = geta - 10;
}

void CALLBACK display(void)
{
	GLUquadricObj *obj;
	obj = gluNewQuadric();


	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();


	glPushMatrix();
	glTranslatef(x, y, z);

	//baza ceas
	glPushMatrix();
	glColor3f(0.69,0.61,0.85);
	gluQuadricDrawStyle(obj, GLU_FILL);
	gluSphere(obj, 100, 100, 50);
	glPopMatrix();

	//ceas
	glPushMatrix();
	glColor3f(1, 1, 1);
	gluQuadricDrawStyle(obj, GLU_FILL);
	gluSphere(obj, 90, 90, 50);
	glPopMatrix();

	


	
	//sageata-minute
	glPushMatrix();
	glRotatef(alfa, 0, 0, 1);
	glColor3f(0, 0, 0);
	glRotatef(90, 1, 0, 0);
	gluQuadricDrawStyle(obj, GLU_FILL);
	gluCylinder(obj, 1.5, 1.5, 60, 50, 50);
	glPopMatrix();


	//sageata-ore
	glPushMatrix();	
	glRotatef(beta, 0, 0, 1);
	glColor3f(0, 0, 0);
	glRotatef(90, 1, 0, 0);
	gluQuadricDrawStyle(obj, GLU_FILL);
	gluCylinder(obj, 1.5, 1.5, 45, 50, 50);
	glPopMatrix();

	//centru
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	gluQuadricDrawStyle(obj, GLU_FILL);
	gluSphere(obj, 5, 50, 50);
	glPopMatrix();

	//punte
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0,90,0);
	glVertex3f(0,70,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_LINES);
	glVertex3f(0, -90, 0);
	glVertex3f(0, -70, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_LINES);
	glVertex3f(90, 0,0 );
	glVertex3f(70, 0,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_LINES);
	glVertex3f(-90, 0, 0);
	glVertex3f(-70, 0, 0);
	glEnd();
	glPopMatrix();

	glPopMatrix();


	glFlush();
}


void CALLBACK myReshape(GLsizei w, GLsizei h)
{
	if (!h) return;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-160.0, 160.0, 160.0*(GLfloat)h / (GLfloat)w,
			-160.0*(GLfloat)h / (GLfloat)w, -1000.0, 1000.0);
	else
		glOrtho(-160.0*(GLfloat)w / (GLfloat)h,
			160.0*(GLfloat)w / (GLfloat)h, -160.0, 160.0, -1000.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	auxInitDisplayMode(AUX_SINGLE | AUX_RGB);
	auxInitPosition(0, 0, 300, 200);
	auxInitWindow("Project made by Butoi Emanuel-Sebastian");
	myinit();
	auxKeyFunc(AUX_LEFT, MutaStanga);
	auxKeyFunc(AUX_RIGHT, MutaDreapta);
	auxKeyFunc(AUX_UP, MutaSus);
	auxKeyFunc(AUX_DOWN, MutaJos);
	auxMouseFunc(AUX_LEFTBUTTON, AUX_MOUSEDOWN, rot_z_up);
	auxMouseFunc(AUX_RIGHTBUTTON, AUX_MOUSEDOWN, rot_z_down);
	auxKeyFunc(AUX_a, rot_u_up);
	auxKeyFunc(AUX_d, rot_d_down);




	auxReshapeFunc(myReshape);
	auxMainLoop(display);
	return(0);
}
