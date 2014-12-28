//------------------------------------------------------------------------------
#include <windows.h>
#include <gl\glut.h>
#include <gl\gl.h>
#include <cmath>
//------------------------------------------------------------------------------
float angle = 0;
float direction = 1; // 1 == x Axis ... 2 == y Axis
//------------------------------------------------------------------------------

void Init() {
	// Set Background Color
    glClearColor(0.0,0.0,0.0,0.0);

    // Enable 3D Rendering
    glEnable(GL_DEPTH_TEST);
}
//------------------------------------------------------------------------------

// build house function

void buildHouse() {

   	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	if (direction == 1)
        glRotatef(angle,0,1,0);
    else if (direction == 2)
        glRotatef(angle, 1, 0, 0);

     // WALLS

    // Front
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
        glVertex3f(0.5, 0.5, -0.5);
        glVertex3f(-0.5, 0.5, -0.5);
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f(0.5, -0.5, -0.5);
    glEnd();

    // back
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
        glVertex3f(0.5, 0.5, 0.5);
        glVertex3f(-0.5, 0.5, 0.5);
        glVertex3f(-0.5, -0.5, 0.5);
        glVertex3f(0.5, -0.5, 0.5);
    glEnd();


    // roof
    glColor3f(0, 1, 1);
    glBegin(GL_POLYGON);
        glVertex3f(0.5, 0.5, -0.5);
        glVertex3f(0.5, 0.5, 0.5);
        glVertex3f(-0.5, 0.5, 0.5);
        glVertex3f(-0.5, 0.5, -0.5);
    glEnd();

    // floor
   glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
        glVertex3f(0.5, -0.5, -0.5);
        glVertex3f(0.5, -0.5, 0.5);
        glVertex3f(-0.5, -0.5, 0.5);
        glVertex3f(-0.5, -0.5, -0.5);
    glEnd();


    // right side
    glColor3f(1, 0, 1);
    glBegin(GL_POLYGON);
        glVertex3f(0.5, 0.5, -0.5);
        glVertex3f(0.5, 0.5, 0.5);
        glVertex3f(0.5, -0.5, 0.5);
        glVertex3f(0.5, -0.5, -0.5);
    glEnd();

    // left side
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5, 0.5, -0.5);
        glVertex3f(-0.5, 0.5, 0.5);
        glVertex3f(-0.5, -0.5, 0.5);
        glVertex3f(-0.5, -0.5, -0.5);
    glEnd();

    // ROOF

    // front
    glColor3f(0, 1, 1);
    glBegin(GL_TRIANGLES);
        glVertex3f(-0.5, 0.5, -0.5);
        glVertex3f(0, 1, 0);
        glVertex3f(0.5, 0.5, -0.5);
    glEnd();

    // back
    glColor3f(1, 1, 1);
    glBegin(GL_TRIANGLES);
        glVertex3f(-0.5, 0.5, 0.5);
        glVertex3f(0, 1, 0);
        glVertex3f(0.5, 0.5, 0.5);
    glEnd();

    // right
    glColor3f(1, 1, 0);
    glBegin(GL_TRIANGLES);
        glVertex3f(0.5, 0.5, -0.5);
        glVertex3f(0, 1, 0);
        glVertex3f(0.5, 0.5, 0.5);
    glEnd();

    // left
    glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLES);
        glVertex3f(-0.5, 0.5, -0.5);
        glVertex3f(0, 1, 0);
        glVertex3f(-0.5, 0.5, 0.5);
    glEnd();


    //
        const float degree2radius = 3.14159/180;
        float radius = 12;
    //
/*
    glColor3f(1, 0, 1);
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 180; i++) {
            float degreeInRad = i * degree2radius;
            for (float j = 0.12; j <= 0.32; j += 0.1)
            glVertex3f(cos(degreeInRad) * radius * 0.01, sin(degreeInRad) * radius * 0.01 - j, -0.5);
        }
    glEnd();
*/
	glFlush();

}


// Mouse handling
void handleMouse(int mouse,int state,int x,int y) {
    if(mouse == GLUT_LEFT_BUTTON) {
        angle += 10;
        glutPostRedisplay();
    }
    if(mouse == GLUT_RIGHT_BUTTON) {
        angle -= 10;
        glutPostRedisplay();
    }
}
//------------------------------------------------------------------------------
// Keyboard handling
void handleKey(unsigned char key,int x,int y) {
    if (key == 'l') {
        direction = 1;
    } else if (key == 'u') {
        direction = 2;
    } else if(key == 's') {
        glScaled(0.5f, 1.0f, 2.0f); // not working
        //glShadeModel(GL_SMOOTH);
        glutPostRedisplay();
        return;
    } else if(key == 'f') {
        glShadeModel(GL_FLAT);
        glutPostRedisplay();
    } else if(key == 'q') {
        exit(0);
    }
}
//------------------------------------------------------------------------------
// Drawing function
// just for test
void Display() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glRotatef(angle,1,0,1);

    // Front Layer
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5,-0.5,-0.5);
		glVertex3f(-0.5, 0.5,-0.5);
		glVertex3f( 0.5, 0.5,-0.5);
		glVertex3f( 0.5,-0.5,-0.5);
    glEnd();

    // Back Layer
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5,-0.5,0.5);
		glVertex3f(-0.5, 0.5,0.5);
		glVertex3f( 0.5, 0.5,0.5);
		glVertex3f( 0.5,-0.5,0.5);
    glEnd();

	glFlush();
}
//------------------------------------------------------------------------------
// Main function
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(200,200);
	glutCreateWindow("OpenGL Window");

	glutDisplayFunc(buildHouse);
	glutMouseFunc(handleMouse);
	glutKeyboardFunc(handleKey);

	Init();
	glutMainLoop();
}
//------------------------------------------------------------------------------
