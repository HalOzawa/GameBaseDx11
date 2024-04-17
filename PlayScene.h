#pragma once
#include "Engine/GameObject.h"
class PlayScene :
    public GameObject
{
    
    int lane = -1;
    float space = 0.5;
    int counter;
public:
    //�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
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

