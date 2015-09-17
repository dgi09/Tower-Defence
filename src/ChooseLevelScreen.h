#include "IScreen.h"
#include "TextSprite.h"
#include "SDL_ttf.h"
#include "ScrollableContainer.h"
#include "Button.h"
#include <vector>
#include "Container.h"

class ChooseLevelScreen : public IScreen
{
	TTF_Font * font;
	TTF_Font * labelsFont;

	Container screenFrame;
	ScrollableContainer  mainContainer;
	std::vector<Widget*> widgets;	
public:

	virtual void init(SDL_Window * window);

	virtual void update();

	virtual void onEvent(SDL_Event & evt);

	virtual void onClose();

	virtual void onPause();

	virtual void onRestart();

	virtual void draw(SDL_Renderer * renderer);

private:

	void initLevelsButtons();
	void onLevelClick(Widget * widget);
};