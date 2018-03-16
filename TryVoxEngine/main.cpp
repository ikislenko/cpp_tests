#include "src/graphics/window.h"

int main() {
	using namespace tryvox;
	using namespace graphics;

	Window window("Test Game", 600, 300);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.closed()) {
		window.clear();
#if 1	
		glBegin(GL_QUADS);
		glVertex2f( -.5f, -.5f);
		glVertex2f( -.5f,  .5f);
		glVertex2f(	.5f, .5f);
		glVertex2f(	.5f, -.5f);
		glEnd();
#else 
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
		window.update();
	}
	return 0;
}