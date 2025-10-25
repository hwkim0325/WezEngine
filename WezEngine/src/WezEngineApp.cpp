
#include "Wez.h"

class WezEngine : public Wez::Application
{
public :
	WezEngine()
	{

	}

	~WezEngine()
	{

	}
};

Wez::Application* Wez::CreateApplication()
{
	return new WezEngine();
}