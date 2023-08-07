#include "azpch.h"
#include "Application.h"
#include <GLFW/glfw3.h>

Azure::Application::Application()
{
	m_Window = std::unique_ptr<Window>(Window::Create());
}

Azure::Application::~Application()
{
}

void Azure::Application::Run()
{
	while (m_Running)
	{
		glClearColor(0.5, 0.8, 1.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		m_Window->OnUpdate();
	}
}
