#include "window.h"

namespace tryvox { 
	namespace graphics {
		
		void window_resize(GLFWwindow *window, int width, int height);
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

		Window::Window(const char *title, int width, int height) 
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;

			if (!init())
				glfwTerminate();

			INSTANCE = this;
		}

		Window::~Window() 
		{
			glfwTerminate();
		}

		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "Failed to initialize GLFW!" << std::endl;
				
				return false;
			}

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

			if (!m_Window)
			{
				glfwTerminate();
				std::cout << "Failed to create GFLW Window!" << std::endl;
				return false;
			}

			glfwMakeContextCurrent(m_Window);
			glfwSetWindowUserPointer(m_Window, this);
			glfwSetWindowSizeCallback(m_Window, window_resize);

			if (glewInit() != GLEW_OK)
			{
				std::cout << "Cold not initialize GLEW!" << std::endl;
				return false;
			}
			return true;
		}


		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update()
		{
			glfwPollEvents();
			glfwSwapBuffers(m_Window);
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}

		void window_resize (GLFWwindow *window, int width, int height) 
		{
			glViewport(0, 0, width, height);
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* win = (Window*) glfwGetWindowUserPointer(window);
		}
	}
}