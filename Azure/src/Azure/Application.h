#pragma once
#include "Core.h"

namespace Azure {
	class AZURE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//Defined By Client
	Application* CreateApplication();
}

