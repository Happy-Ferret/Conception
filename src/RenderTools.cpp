#include "Main.h"

void InitializeOpenGL()
{
	glEnable(GL_TEXTURE_2D);
	{
		glBindTexture(GL_TEXTURE_2D, 2);
		// http://clkoerner.com/2011/10/13/apple-linen/
		if (GL_TRUE == glfwLoadTexture2D("data/Background.tga", GLFW_ORIGIN_UL_BIT | GLFW_BUILD_MIPMAPS_BIT))
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}
		else
			throw 1;
	}

	if (!OglUtilsInitFont()) glfwCloseWindow();

	glEnable(GL_CULL_FACE);

	//glClearColor(0.600f, 0.741f, 0.565f, 1);
	glClearColor(1, 1, 1, 1);
}

void DrawBox(Vector2n Position, Vector2n Size)
{
	DrawBox(Position, Size, Color(1, 1, 1));
}
void DrawBox(Vector2n Position, Vector2n Size, Color BackgroundColor)
{
	DrawBox(Position, Size, BackgroundColor, Color(0.3, 0.3, 0.3));
}
void DrawBox(Vector2n Position, Vector2n Size, Color BackgroundColor, Color BorderColor)
{
	glDisable(GL_TEXTURE_2D);

	/*glBegin(GL_LINE_LOOP);
		glColor3d(0.3, 0.3, 0.3);
		glVertex2d(X - 0.5, Y - 0.5);
		glVertex2d(X - 0.5, Y + Height + 0.5);
		glVertex2d(X + Width + 0.5, Y + Height + 0.5);
		glVertex2d(X + Width + 0.5, Y - 0.5);
	glEnd();*/
	glBegin(GL_QUADS);
		glColor3dv(BorderColor.GetComponents());
		glVertex2i(Position.X(), Position.Y());
		glVertex2i(Position.X(), Position.Y() + Size.Y());
		glVertex2i(Position.X() + Size.X(), Position.Y() + Size.Y());
		glVertex2i(Position.X() + Size.X(), Position.Y());
	glEnd();

	glBegin(GL_QUADS);
		glColor3dv(BackgroundColor.GetComponents());
		glVertex2i(+1 + Position.X(), +1 + Position.Y());
		glVertex2i(+1 + Position.X(), -1 + Position.Y() + Size.Y());
		glVertex2i(-1 + Position.X() + Size.X(), -1 + Position.Y() + Size.Y());
		glVertex2i(-1 + Position.X() + Size.X(), +1 + Position.Y());
	glEnd();

	glEnable(GL_TEXTURE_2D);
}

void DrawAroundBox(Vector2n Position, Vector2n Size)
{
	DrawAroundBox(Position, Size, Color(1, 1, 1));
}
void DrawAroundBox(Vector2n Position, Vector2n Size, Color BackgroundColor)
{
	DrawAroundBox(Position, Size, BackgroundColor, Color(0.3, 0.3, 0.3));
}
void DrawAroundBox(Vector2n Position, Vector2n Size, Color BackgroundColor, Color BorderColor)
{
	glDisable(GL_TEXTURE_2D);

	/*glBegin(GL_LINE_LOOP);
		glColor3d(0.3, 0.3, 0.3);
		glVertex2d(X - 0.5, Y - 0.5);
		glVertex2d(X - 0.5, Y + Height + 0.5);
		glVertex2d(X + Width + 0.5, Y + Height + 0.5);
		glVertex2d(X + Width + 0.5, Y - 0.5);
	glEnd();*/
	glBegin(GL_QUADS);
		glColor3dv(BorderColor.GetComponents());
		glVertex2i(-1 + Position.X(), -1 + Position.Y());
		glVertex2i(-1 + Position.X(), +1 + Position.Y() + Size.Y());
		glVertex2i(+1 + Position.X() + Size.X(), +1 + Position.Y() + Size.Y());
		glVertex2i(+1 + Position.X() + Size.X(), -1 + Position.Y());
	glEnd();

	glBegin(GL_QUADS);
		glColor3dv(BackgroundColor.GetComponents());
		glVertex2i(Position.X(), Position.Y());
		glVertex2i(Position.X(), Position.Y() + Size.Y());
		glVertex2i(Position.X() + Size.X(), Position.Y() + Size.Y());
		glVertex2i(Position.X() + Size.X(), Position.Y());
	glEnd();

	glEnable(GL_TEXTURE_2D);
}

void DrawInnerBox(Vector2n Position, Vector2n Size, Color BackgroundColor, Color BorderColor)
{
	if (   0 == Size.X()
		|| 0 == Size.Y())
	{
		return;
	}

	glDisable(GL_TEXTURE_2D);

	glBegin(GL_POLYGON);
		glColor3dv(BorderColor.GetComponents());
		glVertex2d(Position.X() + 1.5, Position.Y());
		glVertex2d(Position.X(), Position.Y() + 1.5);
		glVertex2d(Position.X(), Position.Y() - 1.5 + Size.Y());
		glVertex2d(Position.X() + 1.5, Position.Y() + Size.Y());
		glVertex2d(Position.X() - 1.5 + Size.X(), Position.Y() + Size.Y());
		glVertex2d(Position.X() + Size.X(), Position.Y() - 1.5 + Size.Y());
		glVertex2d(Position.X() + Size.X(), Position.Y() + 1.5);
		glVertex2d(Position.X() - 1.5 + Size.X(), Position.Y());
	glEnd();

	glBegin(GL_QUADS);
		glColor3dv(BackgroundColor.GetComponents());
		glVertex2i(+1 + Position.X(), +1 + Position.Y());
		glVertex2i(+1 + Position.X(), -1 + Position.Y() + Size.Y());
		glVertex2i(-1 + Position.X() + Size.X(), -1 + Position.Y() + Size.Y());
		glVertex2i(-1 + Position.X() + Size.X(), +1 + Position.Y());
	glEnd();

	glEnable(GL_TEXTURE_2D);
}