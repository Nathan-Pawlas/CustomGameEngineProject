#include <Azure.h>

class Sandbox : public Azure::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Azure::Application* Azure::CreateApplication()
{
	return new Sandbox();
}