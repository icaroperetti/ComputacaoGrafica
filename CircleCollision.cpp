
//Colisão
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898
#define janela_altura 400
#define janela_largura 600

float trans = 168;
float rotation = 0;
float hipotenusa;

void display(void);
void tela(GLsizei w, GLsizei h);
void keyboard(unsigned char tecla, int x, int y);
float verifica();

int main(int argc, char** argv)
{
	glutInit(&argc, argv);	// suporte a janelas

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);// PADRAO DE CORES

	glutInitWindowSize(janela_largura, janela_altura);  // tamanho da janela
	glutInitWindowPosition(100, 100); // posicao que surge a janela
	glutCreateWindow("Ícaro - Colisão"); // cria janela

	//glutFullScreen();
	glutKeyboardFunc(&keyboard);  // chama teclado
	glutReshapeFunc(tela);  // configura a tela
	glutDisplayFunc(display);
	glutMainLoop(); // redesenhar

	return(0);
}


void keyboard(unsigned char tecla, int x, int y)
{
	printf("\ntecla %c\n", tecla);
	printf("\n\nDigite 1 para esquerda: ");
	printf("\ntecla %c\n", tecla);
	printf("\no mouse estava em %d x %d\n", x, y);

	if (tecla == '1')
	{
		trans = trans - 10;
		printf("\n o valor de translacao e %.2f\n", trans);
	}
	if (tecla == '2')
	{
		trans = trans + 10;
		printf("\n o valor de translacao e %.2f\n", trans);
	}

	if (tecla == '3')
	{
		rotation = rotation + 10;
		printf("Valor da rotacao %.2f\n", rotation);
	}
	if (tecla == '4')
	{
		rotation = rotation - 10;
		printf("Valor da rotacao %.2f\n", rotation);
	}


	glutPostRedisplay();


}


void desenhar()
{
	GLfloat circ_pnt = 500;
	GLfloat ang;
	GLfloat ballX = 80, ballY = 80;

	glColor3f(0, 1, 0);
	glTranslatef(0, 0, 0);

	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * ballX, sin(ang) * ballY);
		printf("%f %f\n", cos(ang) * ballX, sin(ang) * ballY);
	}

	glEnd();



	glTranslatef(trans, rotation, 0);

	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * ballX, sin(ang) * ballY);
		printf("%f %f\n", cos(ang) * ballX, sin(ang) * ballY);
	}

	glEnd();
	glutPostRedisplay();

	//glRotated(-rotation, 0, 0, 1);

}

void display()
{
	glMatrixMode(GL_MODELVIEW);  //coordenadas de desenho
	glLoadIdentity();

	float distancia = verifica();

	if (distancia >= 160)
	{
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // cor do fundo

	}
	else
	{
		glClearColor(1.0f, 0.0f, 0.0f, 0.0f); // cor do fundo
	}

	glClear(GL_COLOR_BUFFER_BIT); // EXECUTA LIMPEZA

	// Especificar o local aonde o desenho acontece: bem no centro da janela
	glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);

	glViewport(0, 0, janela_largura, janela_altura);
	desenhar();


	glFlush();  // executa o desenho

}

void tela(GLsizei w, GLsizei h)
{


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// cria a janela (esq, direita, embaixo, em cima)
	gluOrtho2D(0, janela_largura, 0, janela_altura);


	glMatrixMode(GL_MODELVIEW);

}

float verifica() {
	hipotenusa = sqrt((trans * trans) + (rotation * rotation));
	return  hipotenusa;
}
