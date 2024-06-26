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

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

