#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Wez {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			WEZ_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			WEZ_TRACE(e.ToString());
		}

		while (true);
	}

}
