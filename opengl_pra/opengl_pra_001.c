/* 2016.4.28 */
/* OpenGL */
/* C */

/* �ڕW�FOpenGL��3D�Q�[�������i�������낢��j */

# include <stdio.h>
# include <GL/glut.h>

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2d(-0.5, -0.5);
	glVertex2d(0.5, -0.5);
	glVertex2d(0.5, 0.5);
	glVertex2d(-0.5, 0.5);
	glEnd();
	glFlush();
}

void init(void)
{
	glClearColor(0.0, 1.0, 1.0, 1.0);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}