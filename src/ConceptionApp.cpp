#include "Main.h"

ConceptionApp::ConceptionApp(InputManager & InputManager)
	: App(InputManager),
	  m_CurrentProject()
{
	{
		auto MainCanvas = new Canvas(Vector2n(0, 0), true, true);

		MainCanvas->AddWidget(new ListWidget(Vector2n(-200, -300), m_CurrentProject.GetStdIncludes()));
		MainCanvas->AddWidget(new ButtonWidget(Vector2n(100, -300)));
		MainCanvas->AddWidget(new ButtonWidget(Vector2n(140, -300)));
		MainCanvas->AddWidget(new TextFieldWidget(Vector2n(-400, 0)));
		MainCanvas->AddWidget(new ConceptStringBoxWidget(Vector2n(-400, -100)));

		m_Widgets.push_back(std::unique_ptr<Widget>(MainCanvas));
	}

	{
		PopulateConcepts();

		// Load program
		m_CurrentProject.LoadSampleGenProgram(*static_cast<Canvas *>(m_Widgets[0].get()));
	}
}

ConceptionApp::~ConceptionApp()
{
}

void ConceptionApp::UpdateWindowDimensions(Vector2n WindowDimensions)
{
	// TODO: This is a hack, I should create a WindowResize listener type of thing and take care within Widget itself
	static_cast<Canvas *>(m_Widgets[0].get())->SetDimensions(WindowDimensions);
}

bool ConceptionApp::ProcessEvent(InputEvent & InputEvent)
{
	// DEBUG, TEST: System key handling
	if (false == InputEvent.m_Handled)
	{
		if (InputEvent.m_EventTypes.end() != InputEvent.m_EventTypes.find(InputEvent::EventType::BUTTON_EVENT))
		{
			if (Pointer::VirtualCategory::TYPING == InputEvent.m_Pointer->GetVirtualCategory())
			{
				auto ButtonId = InputEvent.m_InputId;
				bool Pressed = InputEvent.m_Buttons[0];		// TODO: Check if there are >1 buttons

				if (Pressed)
				{
					switch (ButtonId)
					{
					//case GLFW_KEY_F5:
					case 'R':
						if (   InputEvent.m_Pointer->GetPointerState().GetButtonState(GLFW_KEY_LSUPER)
							|| InputEvent.m_Pointer->GetPointerState().GetButtonState(GLFW_KEY_RSUPER))
						{
							m_CurrentProject.GenerateProgram();
							m_CurrentProject.RunProgram();
						}
						break;
					// TEST
					case 'B':
						if (glfwGetKey(GLFW_KEY_LCTRL) || glfwGetKey(GLFW_KEY_RCTRL))
						{
							m_CurrentProject.GetStdIncludes().push_back(FindConcept("test"));
						}
						break;
					default:
						break;
					}
				}
			}
		}
	}

	return App::ProcessEvent(InputEvent);
}