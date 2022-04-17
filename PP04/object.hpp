class Object
{
public:
	int x, y;
	int i;
	Object()
	{
		x = 60;
		y = 7;
	}
	~Object()
	{

	}

	void isKeyPressedMove()
	{
		for (int i = 0; i > 20; i++) {
			x -= 1;
		}
	}
 
};