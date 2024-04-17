#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"

Stage::Stage(GameObject* parent)
	:GameObject(parent, "Stage")
{
	stageWidth_ = 3;
	stageHeight_ = 60;

}

void Stage::Initialize()
{
	hFloor_ = Model::Load("Floor.fbx");
	assert(hFloor_ >= 0);
	transform_.position_.x = 5;
	transform_.position_.y = 0;
	Camera::SetPosition(XMFLOAT3(0.5, 3.0, -5.5));
	Camera::SetTarget(XMFLOAT3(0.5, 1.0, 0.0));
}

void Stage::Update()
{

}

void Stage::Draw()
{
	for (int i = 0; i < stageHeight_; i++)
	{
		for (int j = 0; j < stageWidth_; j++)
		{
			transform_.position_.x = j;
			transform_.position_.z = i;

			Model::SetTransform(hFloor_, transform_);
			Model::Draw(hFloor_);
		}
	}
	
}

void Stage::Release()
{
}
