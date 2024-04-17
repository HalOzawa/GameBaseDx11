#include "GameOver.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include "Engine/Image.h"

GameOver::GameOver(GameObject* parent)
	:GameObject(parent, "GameOver"), gPict_(-1)
{
}

void GameOver::Initialize()
{
	gPict_ = Image::Load("GameOver.png");
	assert(gPict_ >= 0);
}

void GameOver::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}
}

void GameOver::Draw()
{
	Image::SetTransform(gPict_, transform_);
	Image::Draw(gPict_);
}

void GameOver::Release()
{
}
