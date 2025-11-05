#pragma once

#include "Core.h"

#include "Window.h"
#include "Wez/LayerStack.h"
#include "Wez/Events/Event.h"
#include "Wez/Events/ApplicationEvent.h"

namespace Wez {

	class WEZ_API Application
	{
	public:
		Application();
		virtual ~Application();


		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

