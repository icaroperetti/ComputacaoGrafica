#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#define WINDOW_HEIGHT 400
#define WINDOW_WIDTH 400

void keyboard(unsigned char key, int x, int y);
void resize(GLsizei w, GLsizei h);
void display(void);


int main(int argc, char** argv) {
    // controla se o sistema operacional tem suporte a janelas
    glutInit(&argc, argv);

    // quantidade de buffer de cores e que padrão de cores é RGB ou RGBA
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // tamanho da janela
    glutInitWindowSize(400, 400);

    // posicao inicial da janela
    glutInitWindowPosition(WINDOW_HEIGHT, WINDOW_WIDTH);

    // cria janela
    glutCreateWindow("Casa - Icaro");

    glutKeyboardFunc(&keyboard);

    glutReshapeFunc(&resize);

    glutDisplayFunc(display);

    glutMainLoop();

    return EXIT_SUCCESS;
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case '\x1b':
        exit(EXIT_SUCCESS);
        break;
    }
}

void resize(GLsizei w, GLsizei h) {
    // evite divisao por zero
    if (h == 0)
        h = 1;
    // Especifica as dimensões do Viewport
    glViewport(0, 0, w, h);

    // inicializa os sistemas de cordernadas
    glMatrixMode(GL_PROJECTION);
    // limpa memoria
    glLoadIdentity();

    if (w <= h) {
        gluOrtho2D(0.0f, WINDOW_HEIGHT, 0.0f, WINDOW_WIDTH * h / w);
    }
    else {
        gluOrtho2D(0.0f, WINDOW_HEIGHT * w / h, 0.0f, WINDOW_WIDTH);
    }
    glMatrixMode(GL_MODELVIEW);
}

void display() {
    glMatrixMode(GL_MODELVIEW);
    // LIMPAR toda a matriz
    glLoadIdentity();
    // cor de fundo
    glClearColor(0, 0, 1, 1);
    // limpa a tela com a cor de fundo
    glClear(GL_COLOR_BUFFER_BIT);

    //centralizar plano cartesiano
    glTranslatef(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0);

    //Telhado
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-100, 100);
    glVertex2f(0, 200);
    glVertex2f(100, 100);

    glEnd();

    //Corpo da casa
    glBegin(GL_QUADS); // Inicie um quadrado
    glColor3f(1.0f, 1.0f, 0.0f);// cor de pintura

    glVertex2f(-100, -100); // Vertice 1 
    glVertex2f(-100, 100);  // Vertice 2

    //glColor3f(1, 1, 1);

    glVertex2f(100, 100);// Vertice 3
    glVertex2f(100, -100); // Vertice 4

    glEnd();

    //Chão
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-200, -200);
    glVertex2f(-200, -100);
    glVertex2f(200, -100);
    glVertex2f(200, -200);
    glEnd();

    //Porta
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.0);
    glVertex2f(-100, -100);
    glVertex2f(-100, -50);
    glVertex2f(-50, -50);
    glVertex2f(-50, -100);
    glEnd();

    //Janela
    glLineWidth(4.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-37, 15);
    glVertex2f(-37, 50);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0, 50);
    glVertex2f(0, 15);
    glEnd();

    //Maçaneta
    glPointSize(10.0f);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0);
    glVertex2f(-92.0f, -78.0f);
    glEnd();

    glFlush(); // executa o desenho 
}
