#include <OpenGL/gl.h>
#include <GLUT/glut.h>

void display() {
   glClear(GL_COLOR_BUFFER_BIT);  // clear the color buffer
   glColor3f(1.0, 1.0, 1.0);      // set the color to white
   glRasterPos2f(-0.5, 0.0);      // set the position of the text
   glutBitmapString(GLUT_BITMAP_HELVETICA_18, "Hello, World!");  // draw the text
   glFlush();                     // flush the buffer
}

int main(int argc, char **argv) {
   glutInit(&argc, argv);                    // initialize GLUT
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // set the display mode
   glutInitWindowSize(400, 400);             // set the window size
   glutCreateWindow("Hello, OpenGL!");       // create the window
   glClearColor(0.0, 0.0, 0.0, 0.0);         // set the background color
   glutDisplayFunc(display);                 // set the display callback
   glutMainLoop();                           // enter the main loop
   return 0;
}
