#pragma once
#include "azpch.h"
#include "Core.h"
#include "Azure/Window.h"

namespace Azure {
	class AZURE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//Defined By Client
	Application* CreateApplication();
}

