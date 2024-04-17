#pragma once
#include "Engine/GameObject.h"
#include <vector>

using std::vector;

enum STAGE_OBJ
{
	FLOOR
};

class Stage :
    public GameObject
{
	int hFloor_;
	int stageWidth_, stageHeight_;
public:
	Stage(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

