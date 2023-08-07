#include "azpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

Azure::Application::Application()
{
}

Azure::Application::~Application()
{
}

void Azure::Application::Run()
{
	WindowResizeEvent e(420, 69);
	AZ_TRACE(e);
	while (true);
}
