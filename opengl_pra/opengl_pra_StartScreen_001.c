/* 2016.4.30 */
/* game_startscreen */

/* OpenGL�͕�����\�����邱�Ƃ͓��ӂł͂Ȃ��炵�� */

/* ���W�F���オ�O */

#include <stdio.h>
#include <GL/glut.h>

void display(void)
{	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_POLYGON);
	glVertex2d(0.3, 0.1);
	glVertex2d(0.3, -0.1);
	glVertex2d(-0.3, -0.1);
	glVertex2d(-0.3, 0.1);
	glEnd();
	
	glFlush();
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glLoadIdentity();
	glOrtho(-0.5, (GLdouble)w - 0.5, (GLdouble)h - 0.5,
				-0.5, -1.0, -1.0);
}

void mouse(int button, int state, int x, int y)
{
	switch(button){
		case GLUT_LEFT_BUTTON:
			if(x>175&&x<325&&y>225&&y<275){
				printf("start!!\n");
			}
			//printf("x:%d y:%d\n",x ,y);
			break;
		case GLUT_MIDDLE_BUTTON:
			break;
		case GLUT_RIGHT_BUTTON:
			break;
		default:
			break;
	}
}

void init(void)
{
	glClearColor(0.0, 0.0, 1.0, 1.0);
}

int main(int argc, char *argv[])
{
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutMouseFunc(mouse);
	init();
	glutMainLoop();
	return 0;
}