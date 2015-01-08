#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	virtual void Update(float DeltaTime);
	virtual void Draw();
};
#endif
