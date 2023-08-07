#pragma once
#include "Azure/Window.h"
#include <GLFW/glfw3.h>

namespace Azure
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override
		{
			return m_Data.Width;
		}
		inline unsigned int GetHeight() const override
		{
			return m_Data.Height;
		}

		//Attributes
		inline void SetEventCallbackFn(const EventCallBackFn& callback) override
		{
			m_Data.EventCallBack = callback;
		}
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
			EventCallBackFn EventCallBack;
		};
		WindowData m_Data;
	};
}

