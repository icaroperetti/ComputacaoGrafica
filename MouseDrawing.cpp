#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#define WINDOW_HEIGHT 400
#define WINDOW_WIDTH 400

void keyboard(int key, int x, int y);
void resize(GLsizei w, GLsizei h);
void display(void);
void mouse(int button, int state, int mousex, int mousey);

float x=0,red,green,blue;
float y = 0;

bool check = false;

int main(int argc, char** argv) {
    // controla se o sistema operacional tem suporte a janelas
    glutInit(&argc, argv);

    // quantidade de buffer de cores e que padrão de cores é RGB ou RGBA
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // tamanho da janela
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    // posicao inicial da janela
    glutInitWindowPosition(100, 100);

    // cria janela
    glutCreateWindow("Ícaro - Mouse");

    glutSpecialFunc(&keyboard);

    glutReshapeFunc(&resize);

    glutDisplayFunc(display);
    
    glutMouseFunc(mouse);  

    glutMainLoop();

    return EXIT_SUCCESS;
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
        gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
    }
    else {
        gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
    }
    glMatrixMode(GL_MODELVIEW);
}


void mouse(int button, int state, int mousex, int mousey)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        check = true;

        x = mousex;
        y = 400 - mousey;
       
    }
    else 
    {
        check = false;
    }
}

void keyboard(int key, int x, int y) {
    if (key == GLUT_KEY_F1) {
        red = 1;
        green = 0;
        blue = 0;
    }

    if (key == GLUT_KEY_F2) {
        red = 0;
        green = 1;
        blue = 0;
    }

    if (key == GLUT_KEY_F3) {
        red = 0;
        green = 1;
        blue = 1;
    }
    if (key == GLUT_KEY_F4) {
        red = 1;
        green = 1;
        blue = 1;
    }
    glutPostRedisplay();
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
    //glTranslatef(WINDOW_HEIGHT / 2, WINDOW_WIDTH / 2, 0);

    if (check)
    {
        
        glColor3f(red, green, blue);
        glPointSize(50);
        glEnable(GL_POINT_SMOOTH);

        glBegin(GL_POINTS); 
        glVertex2f(x, y);  

        

        glEnd();
    }
  

    glFlush(); // executa o desenho 
}
