/* 2016.5.3 */
/* game */

/* ボタンを押すとスタート */

/* ボタンを押し続ける */

/* 座標：中心が0、1.0～-1.0 */

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
		/* ボタン１ */
		glBegin(GL_POLYGON);
		glVertex2d(0.3, 0.1);
		glVertex2d(0.3, -0.1);
		glVertex2d(-0.3, -0.1);
		glVertex2d(-0.3, 0.1);
		glEnd();
	}//if_1
	else if(flag_1 == 2){
		glBegin(GL_LINES);
		
		/* ス */
		glVertex2d(-0.7, 0.6);
		glVertex2d(-0.5, 0.6);
		
		glVertex2d(-0.5, 0.6);
		glVertex2d(-0.7, 0.4);
		
		glVertex2d(-0.6, 0.5);
		glVertex2d(-0.5, 0.4);
		
		/* タ */
		glVertex2d(-0.25, 0.65);
		glVertex2d(-0.4, 0.5);
		
		glVertex2d(-0.3, 0.6);
		glVertex2d(-0.1, 0.6);
		
		glVertex2d(-0.1, 0.6);
		glVertex2d(-0.3, 0.4);
		
		glVertex2d(-0.35, 0.55);
		glVertex2d(-0.2, 0.5);
		
		/* - */
		glVertex2d(-0.1, 0.5);
		glVertex2d(0.1, 0.5);
		
		/* ト */
		glVertex2d(0.2, 0.65);
		glVertex2d(0.2, 0.4);
		
		glVertex2d(0.2, 0.55);
		glVertex2d(0.35, 0.5);
		
		glEnd();
		
		/* ボタン２ */
		glBegin(GL_POLYGON);
		
		glVertex2d(0.8, -0.8);
		glVertex2d(0.9, -0.8);
		
		glVertex2d(0.9, -0.8);
		glVertex2d(0.9, -0.9);
		
		glVertex2d(0.9, -0.9);
		glVertex2d(0.8, -0.9);
		
		glVertex2d(0.8, -0.9);
		glVertex2d(0.8, -0.8);
		
		glEnd();
	}//elseif_1
	else if(flag_1 == 3){
		glBegin(GL_POLYGON);
		
		glVertex2d(-0.1, 0.1);
		glVertex2d(0.1, 0.1);
		
		glVertex2d(0.1, 0.1);
		glVertex2d(0.1, -0.1);
		
		glVertex2d(0.1, -0.1);
		glVertex2d(-0.1, -0.1);
		
		glVertex2d(-0.1, -0.1);
		glVertex2d(-0.1, 0.1);
		
		glEnd();
	}//elseif_2
	
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
			if(flag_1==1&&x>175&&x<325&&y>225&&y<275){
				printf("start!!\n");
				flag_1 = 2;
				glutIdleFunc(idle);
			}//if_1
			else if(flag_1==2&&x>450&&x<475&&y>450&&y<475){
				flag_1 = 3;
				glutIdleFunc(idle);
			}//elseif_1
			printf("\n x:%d y:%d\n",x ,y);
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