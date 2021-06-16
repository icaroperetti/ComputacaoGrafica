#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#define janela_altura 400
#define janela_largura 600

// variaveis que armazenam a translacao no quadro
float tx = 0.0;
float ty = 0.0;

// incremento em variaveis.
float xStep = 4;
float yStep = 4;
void display(void);
void tela(GLsizei w, GLsizei h);
void keyboard(unsigned char tecla, int x, int y);
void anima(int valor);
int main(int argc, char** argv)
{
	glutInit(&argc, argv); // suporte a janelas
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// PADRAO DE CORES
	glutInitWindowSize(janela_largura, janela_altura); // tamanho da janela
	glutInitWindowPosition(100, 100); // posicao que surge a janela
	glutCreateWindow("animação"); // cria janela
	//glutFullScreen();
	glutReshapeFunc(tela); // configura a tela
	glutDisplayFunc(display);
	glutKeyboardFunc(&keyboard); // chama teclado
	glutTimerFunc(150, anima, 1);
	glutMainLoop(); // redesenhar
	return(0);
}
void anima(int valor)
{
	if ((tx) > (300) || (tx) < (-300 + 28))
	{
		xStep = -xStep;
	}
	if ((ty) > (200 - 50) || (ty) < (-200 - 30))
	{
		yStep = -yStep;
	}
	tx += xStep;
	ty += yStep;
	printf("\n topo %.2f pe %.2f direita %.2f esquerda% .2f\n", ((janela_altura) / 2),
		(((janela_altura) / 2) * -1),
		((janela_largura) / 2),
		(((janela_largura) / 2) * -1));
	printf("\n step x %.2f step y %.2f\n", xStep, yStep);
	printf("\n tx %.2f ty %.2f\n", tx, ty);
	glutPostRedisplay();
	glutTimerFunc(50, anima, 1);
}
void keyboard(unsigned char tecla, int x, int y)
{
	printf("\ntecla %c\n", tecla);
	printf("\n\nDigite 1 translacao x, 2 translacao y: ");
	printf("\ntecla %c\n", tecla);
	printf("\no mouse estava em %d x %d\n", x, y);
}

void desenhar()
{
	glLoadIdentity();
	glTranslatef((janela_largura) / 2, (janela_altura) / 2, 0);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0); // cor
	glVertex2f(-100, -100);
	glVertex2f(0, 0);
	glVertex2f(100, -100);
	glEnd();
	// Especificar o local aonde o desenho acontece: bem no centro da janela
	glTranslatef(tx, ty, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0); // cor
	glVertex2f(-30, 30);


	glVertex2f(-10, 30);
	glVertex2f(-10, 50);
	glVertex2f(-30, 50);
	glEnd();
}
void display()
{
	glMatrixMode(GL_MODELVIEW); //coordenadas de desenho
	glLoadIdentity();
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // cor do fundo
	glClear(GL_COLOR_BUFFER_BIT); // EXECUTA LIMPEZA
	// Especificar o local aonde o desenho acontece: bem no centro da janela mais translacao
	//glTranslatef(janela_largura / 2, janela_altura/2, 0.0f);
	glViewport(0, 0, janela_largura, janela_altura);
	desenhar();
	glFlush(); // execute o desenho
}
void tela(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// cria a janela (esq, direita, embaixo, em cima)
	gluOrtho2D(0, janela_largura, 0, janela_altura);
	glMatrixMode(GL_MODELVIEW);
}
