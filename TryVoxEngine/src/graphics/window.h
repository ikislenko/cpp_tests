#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace tryvox {namespace graphics {	

#define MAX_KEYS		1024
#define MAX_BUTTONS		32

	class Window 
	{
	public: 
		static Window * INSTANCE;
	private:
		const char *m_Title;
		int m_Width, m_Height;
		GLFWwindow *m_Window;
		bool m_Closed;

		static bool m_Keys[MAX_KEYS];
		static bool m_Butoons[MAX_BUTTONS];
		static bool mx, my;

	public:
		Window(const char *title, int width, int height);
		~Window();
		void clear() const;
		void update();
		bool closed() const;

		inline int getWidth() const { return m_Width; }
		inline int getHeight() const { return m_Height; }
	private:
		bool init();
	};

}}