#include "src/graphics/window.h"

int main() {
	using namespace tryvox;
	using namespace graphics;

	Window window("Test Game", 600, 300);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	while (!window.closed()) {
		window.clear();
		glBegin(GL_TRIANGLES);
		glVertex2f(-.5f, -.5f);
		glVertex2f(	.0f,  .5f);
		glVertex2f(	.5f, -.5f);
		glEnd();
		window.update();
	}
	return 0;
}