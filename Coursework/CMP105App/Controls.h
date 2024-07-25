#pragma once
#include "Framework/GameObject.h"
class Controls : public GameObject
{
public:

	Controls();
	~Controls();

	void update(float dt) override;
};

