#pragma once
#include "azpch.h"
#include "Azure/Core.h"
#include "Azure/Events/Event.h"

namespace Azure
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Practice Engine",
			unsigned int width = 1280,
			unsigned int height = 780)
			: Title(title), Width(width), Height(height) 
		{}
	};


	//Window Interface, to be implemented PER PLATFORM
	class AZURE_API Window
	{
	public:
		using EventCallBackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Window Attribs
		virtual void SetEventCallbackFn(const EventCallBackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};

}