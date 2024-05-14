#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

class PlayScene :
    public GameObject
{
    float space = 0.5;
    int counter;
    int score;
    Text* pText;
public:
    //�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g..�iSceneManager�j
    PlayScene(GameObject* parent);

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

