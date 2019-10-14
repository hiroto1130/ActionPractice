#include <stdio.h>
#include <windows.h>
#include <d3d9.h>

#include "Engine.h"

#include "Scene.h"

//Pointa point;

SceneId Scene::GetCurrentSceneId()
{
	return g_CurrentSceneId;
}

SceneStep Scene::GetCurrentSceneStep()
{
	return g_CurrentSceneStep;
}

void Scene::ChangeSceneStep(SceneStep next_step)
{
	g_CurrentSceneStep = next_step;
}


void Scene::UpdateScene(DirectX* directX,Engine engine,Device device)
{
	int current_scene_id = SceneId::TitleScene;


	engine.UpdateInput(directX,device);
	SceneId result_id = g_CurrentSceneId;

	switch (g_CurrentSceneId)
	{
		// タイトルシーン
	case SceneId::TitleScene:
		//result_id = TitleSceneMain(directX, count, flamCount);
		break;
	}

	DrawScene(directX,engine);

	if (result_id != g_CurrentSceneId)
	{
		g_CurrentSceneId = result_id;
		ChangeSceneStep(SceneStep::InitStep);
	}

}

void Scene::DrawScene(DirectX* directX,Engine engine)
{
	if (engine.DrawStart(directX) == false)
	{
		return;
	}
	if (g_CurrentSceneStep == SceneStep::MainStep)
	{
		switch (g_CurrentSceneId)
		{
		case SceneId::TitleScene:
			//DrawTitleScene(directX, count);
			break;
		}
	}


	directX->pDevice->EndScene();
	directX->pDevice->Present(NULL, NULL, NULL, NULL);
}
