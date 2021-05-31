#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898
#define window_height 400 //altura
#define window_width 600 //largura

void display(void);
void tela(GLsizei w, GLsizei h);

int main(int argc, char** argv)
{
	glutInit(&argc, argv); //Suporte a janelas
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //padrao de cores

	glutInitWindowSize(window_width, window_height); //Tamanho janela
	glutInitWindowPosition(100, 100); //Posição da janela
	glutCreateWindow("Ícaro - Push and Pop");

	//glutFullScreen();
	glutReshapeFunc(tela);//configurar tela
	glutDisplayFunc(display);
	glutMainLoop(); //redesenhar

	return(0);
}

void desenhar() {
	GLfloat circ_pnt = 100;
	GLfloat ang, raioX = 40.0f, raioY = 80.0f;
	GLfloat ballX = 80, ballY = 80;
	
	glPushMatrix();
	
	glTranslatef(-150, 0, 0);
	glColor3f(1.0, 0.0, 1.0);
	//Sorvete 1
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * ballX, sin(ang) * ballY);
		printf("%f %f\n", cos(ang) * ballX, sin(ang) * ballY);
	}
	glEnd();

	glTranslatef(0, 90, 0);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * ballX, sin(ang) * ballY);
		printf("%f %f\n", cos(ang) * ballX, sin(ang) * ballY);
	}
	glEnd();

	glTranslatef(0, -320, 0);
	glColor3f(160, 82, 45);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 40);
	glVertex2f((-75), 190);
	glVertex2f(70, 190);
	glEnd();
	
	glPopMatrix();


	glPushMatrix();

	glTranslatef(30, 0, 0);
	glColor3f(1.0, 0.0, 0.0);
	//Sorvete 2
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * ballX, sin(ang) * ballY);
		printf("%f %f\n", cos(ang) * ballX, sin(ang) * ballY);
	}
	glEnd();

	glTranslatef(0, 90, 0);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * ballX, sin(ang) * ballY);
		printf("%f %f\n", cos(ang) * ballX, sin(ang) * ballY);
	}
	glEnd();

	glTranslatef(0, -320, 0);
	glColor3f(160, 82, 45);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 40);
	glVertex2f((-75), 190);
	glVertex2f(70, 190);
	glEnd();

	glPushMatrix();

	glTranslatef(190, 150, 0);
	glColor3f(1.0, 0.0, 0.0);
	//Ovo de pascoa 
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 50);
	glVertex2f((-70), 180);
	glVertex2f(70, 180);
	glEnd();

	glPopMatrix();
	
}


void display()
{
	glMatrixMode(GL_MODELVIEW); //coordenadas de desenho
	glLoadIdentity();

	glClearColor(0, 0, 1, 1); //cor de fundo
	glClear(GL_COLOR_BUFFER_BIT); //Executa limpeza

	//Especificar onde o desenho ocorre (centro)
	glTranslatef(window_width / 2, window_height / 2, 0);

	glViewport(0, 0, window_width, window_height);
	desenhar();

	glFlush(); //Executa o desenho
}

void tela(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//cria janela (esq,direita,em baixo,em cima)
	gluOrtho2D(0, window_width, 0, window_height);

	glMatrixMode(GL_MODELVIEW);
}
