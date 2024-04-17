#include "PlayScene.h"
#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Stage>(this);
	Instantiate<Player>(this);
	float I = (rand() % 3) + 1;
	if (I == 1)
	{
		for (int i = -1; i < 1; i++)
		{
			Enemy* p = Instantiate<Enemy>(this);
			p->SetPosition(i + space, 0.5, 50);
		}
	}
	else if (I == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			Enemy* p = Instantiate<Enemy>(this);
			p->SetPosition(i + space, 0.5, 50);
		}
	}
	else if (I == 3)
	{
		Enemy* leftE = Instantiate<Enemy>(this);
		leftE->SetPosition(-0.5, 0.5, 50);

		Enemy* rightE = Instantiate<Enemy>(this);
		rightE->SetPosition(1.5, 0.5, 50);
	}
}

void PlayScene::Update()
{
	if (FindObject("Player") == nullptr)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
	}
	
	counter -= 1;
	if (counter <= 0)
	{
		counter = 70;
		{
			float I = (rand() % 3) + 1;
			if (I == 1)
			{
				for (int i = -1; i < 1; i++)
				{
					Enemy* p = Instantiate<Enemy>(this);
					p->SetPosition(i + space, 0.5, 50);
				}
			}
			else if (I == 2)
			{
				for (int i = 0; i < 2; i++)
				{
					Enemy* p = Instantiate<Enemy>(this);
					p->SetPosition(i + space, 0.5, 50);
				}
			}
			else if (I == 3)
			{
				Enemy* leftE = Instantiate<Enemy>(this);
				leftE->SetPosition(-0.5, 0.5, 50);

				Enemy* rightE = Instantiate<Enemy>(this);
				rightE->SetPosition(1.5, 0.5, 50);
			}
		}
	}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{

}
