#include "MapEditor.h"


MapEditor::MapEditor(sf::RenderWindow &window)
{
	MapEditor::view.reset(sf::FloatRect(0,0,800,600));
	MapEditor::view.setViewport(sf::FloatRect(0.f,0.f,0.2f,1.f));
	window.setView(view);
}


MapEditor::~MapEditor()
{
}
