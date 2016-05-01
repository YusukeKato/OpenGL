/* 2016.5.1 */
/* game */

/* ボタンを押すとスタート */

/* 「スタート」反転してる */

/* 座標：左上が０ */

#include <stdio.h>
#include <GL/glut.h>

static flag_1 = 1;

void idle(void)
{
	glutPostRedisplay();
}

void display(void)
{	
	glClear(GL_COLOR_BUFFER_BIT);
	
	if(flag_1 == 1){
		glBegin(GL_POLYGON);
		glVertex2d(0.3, 0.1);
		glVertex2d(0.3, -0.1);
		glVertex2d(-0.3, -0.1);
		glVertex2d(-0.3, 0.1);
		glEnd();
	} else if(flag_1 == 2){
		glBegin(GL_LINES);
		
		/* ス */
		glVertex2d(0.2, 0.2);
		glVertex2d(0.4, 0.2);
		
		glVertex2d(0.4, 0.2);
		glVertex2d(0.2, 0.4);
		
		glVertex2d(0.3, 0.3);
		glVertex2d(0.4, 0.4);
		
		/* タ */
		glVertex2d(0.5, 0.5);
		glVertex2d(0.35, 0.65);
		
		glVertex2d(0.5, 0.5);
		glVertex2d(0.7, 0.5);
		
		glVertex2d(0.7, 0.5);
		glVertex2d(0.4, 0.8);
		
		glVertex2d(0.4, 0.6);
		glVertex2d(0.6, 0.6);
		
		/* - */
		glVertex2d(0.7, 0.7);
		glVertex2d(0.8, 0.7);
		
		/* ト */
		glVertex2d(0.8, 0.8);
		glVertex2d(0.8, 1.0);
		
		glVertex2d(0.8, 0.9);
		glVertex2d(0.9, 1.0);
		
		glEnd();
	}
	
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
				flag_1 = 2;
				glutIdleFunc(idle);
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