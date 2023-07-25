#include <GL/glut.h>

GLfloat xRotated, yRotated, zRotated;

int xargc = NULL;
char **xargv = NULL;

void setArgv(int argc, char **argv) {
	xargc = argc;
	xargv = argv;
}

void _Display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0,0.0,-4.0);
	glRotatef(xRotated,1.0,0.0,0.0);
	glRotatef(yRotated,0.0,1.0,0.0);
	glRotatef(zRotated,0.0,0.0,1.0);
	glScalef(2.0,1.0,1.0);
	glutWireCube(1.0);
	glFlush();			//Finish rendering
	glutSwapBuffers();
}

void _Reshape(int x, int y) {
	
	// Nothing visible so return
	if (y == 0 || x == 0) return;
	
	// Set a new projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// angle of view  = 40deg
	// Near clip = 0.5
	// Far clip  = 20.0
	gluPerspective(40.0, (GLdouble)x/(GLdouble)y, 0.5, 20.0);
	glMatrixMode(GL_MODELVIEW);

	// Use the whole window for renderinf
	glViewport(0,0,x,y);

}

void _Idle(void) {
	xRotated += 2.3;
	yRotated += 2.1;
	zRotated += -2.4;
	_Display();
}

void newWindow(char *window_name, int window_width, int window_height) {
	
	// Initialize GLUT
	glutInit(&xargc, xargv);

	// Set GLUT display mode
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	// set window size
	glutInitWindowSize(window_width, window_height);

	// give window a title
	glutCreateWindow(window_name);

	// Setting polygon mode
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	xRotated = yRotated = zRotated = 0.0;

	// clear color from screen
	glClearColor(0.0, 0.0, 0.0, 0.0);

	// set display function
	glutDisplayFunc(_Display);

	// set reshape function
	glutReshapeFunc(_Reshape);

	// idle function
	glutIdleFunc(_Idle);
}

void mainloop() {
	glutMainLoop();
}