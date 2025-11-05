
#include "Wez.h"

class ExampleLayer : public Wez::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		WEZ_INFO("ExampleLayer::Update");
	}

	void OnEvent(Wez::Event& event) override
	{
		WEZ_TRACE("{0}", event.ToString());
	}
};

class WezEngine : public Wez::Application
{
public :
	WezEngine()
	{
		PushLayer(new ExampleLayer());
	}

	~WezEngine()
	{

	}
};

Wez::Application* Wez::CreateApplication()
{
	return new WezEngine();
}